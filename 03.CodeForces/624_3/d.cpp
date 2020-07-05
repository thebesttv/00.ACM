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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 4e4;
int a,b,c;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a,&b,&c);
    int ansMin = 0x3f3f3f3f,ri,rj,rk,t;
    FORR(i,1,MAX){
      if(i-a>ansMin) break;
      for(int j=i;j<=MAX;j+=i){
        if(abs(i-a)+j-b>ansMin) break;
        for(int k=j;k<=MAX;k+=j){
          t=abs(a-i)+abs(b-j)+abs(c-k);
          if(t<ansMin){
            ansMin = t;
            ri=i,rj=j,rk=k;
          }
        }
      }
    }
    printf("%d\n",ansMin);
    printf("%d %d %d\n",ri,rj,rk);
  }

  return 0;
}
