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

int n;
map<string,string> mp;
char ori[20];

void cal(char *s){
  string cmd = "";
  FOR(i,0,6) cmd += s[i];

  for(auto p : mp) if(p.SE == cmd){
    int a = 0, b = 0;

    FORR(i,6,10)
      a = a*2 + (s[i]=='1');

    FORR(i,11,15)
      b = b*2 + (s[i]=='1');

    if(p.FI=="SET"){
      if(b || a==0){
        printf("Error\n"); return;
      }
      cout << p.FI << ' ';
      printf("R%d\n",a);
    }else{
      if(a==0 || b==0){
        printf("Error\n"); return;
      }
      cout << p.FI << ' ';
      printf("R%d,R%d\n",a,b);
    }
    return;
  }

  printf("Error\n");
}

int main(void){
  mp["ADD"] = "111111";
  mp["SUB"] = "111110";
  mp["DIV"] = "111101";
  mp["MUL"] = "111100";
  mp["MOVE"] = "111011";
  mp["SET"] = "111010";

  scanf("%d",&n); int op;
  while(n--){
    scanf("%d",&op);
    if(op==1){
      string s; cin >> s;
      int a=0, b=0;
      if(s=="SET"){
        scanf(" R%d",&a);

        printf("111010");
        ROR(i,4,0) printf("%d",bool(a&(1<<i)));
        printf("00000\n");
      }else{
        scanf(" R%d,R%d",&a,&b);

        cout << mp[s];
        ROR(i,4,0) printf("%d",bool(a&(1<<i)));
        ROR(i,4,0) printf("%d",bool(b&(1<<i)));
        putchar('\n');
      }
#ifdef DEBUG
      cout << "get " << s ; printf(" %d, %d\n",a,b);
#endif
    }else{
      scanf("%s",ori);
      cal(ori);
    }
  }

  return 0;
}
