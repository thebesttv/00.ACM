/*
首先考虑贪心，将所有人按吃饭时间降序排列，决策时按顺序决策第 i 个人在哪个窗口打饭。显然这样得到的答案一定不会更坏。
既然决策已经有了顺序，就可以轻松地递推了。
令 f[i][j] 表示：当前已经考虑完第 i 个人，第一个窗口打饭所花费的时间为 j 的最小结束时间，则第二个窗口的打饭时间即为 sum{a[1:i]}-j ，那么就可以更新 f[i][j] 和 f[i][j+a[i]] 了。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=220;
const int INF=0x3f3f3f3f;
int n,s[MAX],f[MAX][MAX*MAX];
struct Ind{
  int a,b;
  bool operator < (const Ind &bi) const {
    return b > bi.b;
  }
}ind[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d%d",&ind[i].a,&ind[i].b);
  sort(ind+1,ind+1+n);
  FORR(i,1,n) s[i]=s[i-1]+ind[i].a;
#ifdef DEBUG
  FORR(i,1,n) printf("  ind[%d]: %d, %d\n",i,ind[i].a,ind[i].b);
#endif

  MST(f,0x3f); f[0][0]=0;
  FOR(i,0,n){
    int a=ind[i+1].a,b=ind[i+1].b;  //<b> i+1 </b>
    FORR(j,0,s[i]) if(f[i][j]<INF){
      int t=f[i][j];
      f[i+1][j] = min( f[i+1][j], max( t, s[i]-j + a+b ));  //去二号窗口
      f[i+1][j+a] = min( f[i+1][j+a], max( t, j + a+b ));   //去一号窗口
    }
  }
#ifdef DEBUG
  FORR(i,1,n) FORR(j,0,s[i]) if(f[i][j]<INF) printf("f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
  int ansMin=INF;
  FORR(i,0,s[n]) ansMin=min(ansMin,f[n][i]);
  printf("%d\n",ansMin);

  return 0;
}
