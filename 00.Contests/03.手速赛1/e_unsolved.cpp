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

const int MAX = 2020;
int n, a, b;
int ansMin = 0x3f3f3f3f;
int f[10][10][10][10][10];
int cnt[10][10][10][10][10];

int main(void){
  scanf("%d",&n);
  MST(f,0x3f);
  cnt[1][0][0][0][0] = 1;
  f[1][0][0][0][0] = 0;
  FORR(col,1,n){
    scanf("%d%d",&a,&b);
    FORR(j,1,9) FORR(a1,0,9) FORR(a2,0,a1) FORR(a3,0,a2) FORR(a4,0,a3)
      if(cnt[j][a1][a2][a3][a4] == col){
        int &ori = f[j][a1][a2][a3][a4];
        int left = 4;

        if(a1){
          --left;
          int dif = abs(j - a1);
          int &ans = f[a1][a2][a3][a4][0];
          ans = min(ans, ori + dif);
          cnt[a1][a2][a3][a4][0] = col+1;
        }

        if(a2){
          --left;
          int dif = abs(j - a2);
          int &ans = f[a2][a1][a3][a4][0];
          ans = min(ans, ori + dif);
          cnt[a2][a1][a3][a4][0] = col+1;
        }

        if(a3){
          --left;
          int dif = abs(j - a3);
          int &ans = f[a3][a1][a2][a4][0];
          ans = min(ans, ori + dif);
          cnt[a3][a1][a2][a4][0] = col+1;
        }

        if(a4){
          --left;
          int dif = abs(j - a4);
          int &ans = f[a4][a1][a2][a2][0];
          ans = min(ans, ori + dif);
          cnt[a4][a1][a2][a3][0] = col+1;
        }

        if(left &&){
        }
      }
  }

  return 0;
}
