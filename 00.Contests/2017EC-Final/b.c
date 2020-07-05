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
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

int n,m;

struct Node{
  int a,n; double x;
  Node(int a, int n): a(a), n(n) {
    x = double(a)*a / n / (n+1);
  }
  bool operator < (const Node &b) const {
    return x < b.x;
  }
};
PQ<Node> q;

auto f = [](double x) { return x*x; };

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&m);
    int x, sum = 0;
    FOR(i,0,n){
      scanf("%d",&x);
      q.push(Node(x,1)); sum += x;
    }

    int tm = m-n;
    while(tm--){
      Node t= q.top(); q.pop();
      q.push(Node(t.a,t.n+1));
    }

    double ave = 1.0*sum / m, ans = 0;
#ifdef DEBUG
    printf("  ave: %lf\n",ave);
#endif
    while(!q.empty()){
      Node t = q.top(); q.pop();
#ifdef DEBUG
      printf("  %d, %d, %lf\n",t.a, t.n,f( 1.0*t.a/t.n - ave) * t.n);
#endif
      ans += f( 1.0*t.a/t.n - ave) * t.n;
    }
#ifdef DEBUG
    printf("  %lf\n",ans);
#endif
    ans /= m;
    printf("Case #%d: %.12lf\n",kase,ans);
  }

  return 0;
}


/*
int read(){
  int ch, sum=0;
  do ch=getchar(); while(!isdigit(ch));
  do sum = sum*10 + ch-'0', ch=getchar(); while(isdigit(ch));
  return sum;
}

const int MAX = 2e5 + 20;
int n,m,a[MAX];
PQ<double> q;

int main(void){
  int T=read();
  FORR(kase,1,T){
    n = read(), m = read();
    double ave = 0, ans = 0;
    FOR(i,0,n){
      ave += (a[i] = read());
    }
    ave /= m;

    FOR(i,0,n){
      if(a[i] <= ave) ans += (a[i]-ave)*(a[i]-ave);
      else q.push(a[i]);
    }

    int tm = m-n;
    while(tm){
      double t = q.top(); q.pop();
      int l = floor(t / ave), r = ceil(t / ave);
      int cnt;
      if(fabs(t/l-ave) < fabs(t/r-ave)){
        cnt = l;
      }else{
        cnt = r;
      }

      cnt = min(cnt, tm + 1);
      t /= cnt; tm = tm + 1 - cnt;
      if(t <= ave) ans += (ave-t)*(ave-t)*cnt;
      else FOR(i,0,cnt) q.push(t);
    }

    while(!q.empty()){
      double t = q.top(); q.pop();
      ans += (t-ave)*(t-ave);
    }
    ans /= m;
    printf("Case #%d: %.12lf\n",kase,ans);
  }

  return 0;
}
*/
