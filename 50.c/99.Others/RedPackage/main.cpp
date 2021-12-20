#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include <QApplication>
#include <QClipboard>
#include <QTimer>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int GROUP_SIZE = 100;
const int INITIAL_AMOUNT = GROUP_SIZE * 100;
double FLUCTUATION = 0.2; // plus minus half
double DROPPACKAGE = 0.2;
int ROUND = 10000;

struct RedPackage{
  int size, money;
  RedPackage(int size, int money): size(size), money(money) { }
};

// 1/Exp[1/2 (x - 0.5)^2]
double f(int idx){
  /*
    double x = 1.0 * idx / (GROUP_SIZE + 1);
    // double original = 1.0 / exp(0.5 * pow( (x - 0.5) / 0.1, 2));
    double original = 0.1 / x;
    double offset = (2.0*rand()/RAND_MAX - 1) * FLUCTUATION;
    return original + offset;
    */
  double offset = (2.0*rand()/RAND_MAX - 1) * FLUCTUATION;
  return 1 + offset;
}

double allRoundAmount[GROUP_SIZE + 20];
struct Individual{
  int money, lastReceived, idx;
  double precidence;
  bool operator < (const Individual &b) const {
    return precidence > b.precidence;
  }
}ind[GROUP_SIZE + 20];

int getRandomMoney(RedPackage &p){
  if(p.size == 1){
    --p.size; return p.money;
  }
  double x = 1.0*rand()/RAND_MAX;
  int l = 1, r = p.money * 2.0 / p.size;
  int res = max(l * 1.0, x * r);
  --p.size;
  p.money -= res;
  return res;
}

void distribute(RedPackage &package) {
    FORR(i,1,GROUP_SIZE) {
        ind[i].precidence = f(ind[i].idx);
    }
    sort(ind+1, ind+1+GROUP_SIZE);

    int idx = 1;
    while(package.size) {
        if(1.0 * rand() / RAND_MAX > DROPPACKAGE) {
            ind[idx].lastReceived += getRandomMoney(package);
            ind[idx].money += ind[idx].lastReceived;
        }
        idx = idx == GROUP_SIZE ? 1 : idx + 1;
    }
#ifdef DEBUG
    FORR(i,1,10) printf("  ind[%d], precidence: %lf, last received: %.2lf\n",ind[i].idx,ind[i].precidence,
                        ind[i].lastReceived/100.0);
    printf("\n");
#endif
}

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    srand(time(NULL));
    FORR(round, 1, ROUND) {
        MST(ind, 0);
        VR<RedPackage> package;
        package.push_back(RedPackage(GROUP_SIZE, INITIAL_AMOUNT));
        FORR(i,1,GROUP_SIZE) ind[i].idx = i;

        do{
            for(auto &p : package) distribute(p);
            package.clear();

            int cntLessThen100 = 0;
            FORR(i,1,GROUP_SIZE) if(ind[i].lastReceived < 100)
                    ++cntLessThen100;

            FORR(i,1,GROUP_SIZE){
                if(ind[i].lastReceived >= 100) {
                    //              int d = max(100, ind[i].lastReceived / 2);
                    int newAmount = ind[i].lastReceived / 2;
                    ind[i].money -= newAmount;
                    int newSize = min(newAmount, cntLessThen100);
                    package.push_back(RedPackage(newSize, newAmount));
                }
                ind[i].lastReceived = 0;
            }
        }while(!package.empty());

        FORR(i,1,GROUP_SIZE) {
            allRoundAmount[ind[i].idx] += ind[i].money;
        }
    }

//    FORR(i,1,GROUP_SIZE) {
//        allRoundAmount[i] /= 100 * ROUND;
//        printf("ind[%d] total amount: %.2lf\n",i,allRoundAmount[i]);
//    }
//    printf("\n");

//    QString cmd("ListPlot[{");
//    cmd += QString("%1").arg(allRoundAmount[1]);
//    FORR(i,2,GROUP_SIZE){
//        cmd += QString(",%1").arg(allRoundAmount[i]);
//    }
//    cmd += "}, Filling -> Axis]";
//    printf("%s\n",cmd.toStdString().c_str());
//    QGuiApplication::clipboard()->setText(cmd);

    double total = 0;
    FORR(i,1,GROUP_SIZE) total += allRoundAmount[i];
    FORR(i,1,GROUP_SIZE) allRoundAmount[i] /= total;
    QString data;
    FORR(i,2,GROUP_SIZE){
        data += QString("{%1,%2},")
                .arg(1.0 * i / GROUP_SIZE)
                .arg(allRoundAmount[i]);
    }
    data = "{" + data + "}";
    QString cmd = QString(
                "Module[{data = { %1 }},\n"
                "  Grid[{{\"fluctuation = %2, drop package = %3\"},\n"
                "   {Plot[%4, {x, 0, 1}, PlotRange -> {{0, 1}, {0, 1}}, ImageSize -> Medium],\n"
                "    ListLinePlot[data, ImageSize -> Medium]},\n"
                "   {\"possibility\", \"result\"}}\n"
                "  ]]\n")
            .arg(data)
            .arg(FLUCTUATION)
            .arg(DROPPACKAGE)
            .arg(argv[1]);
    printf("%s",cmd.toStdString().c_str());

    QTimer::singleShot(500, qApp, SLOT(quit()));
    return app.exec();
}

/*
  */
