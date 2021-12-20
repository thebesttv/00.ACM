/*
  解题报告：
    表示这道题是看了训练指南又咨询了 gr 大佬才弄懂的……
    首先，每个麻球是独立的，那么就可以求出一个麻球 m 天后灭亡的概率 P ，那么答案即为 P^k 。
    可以递推求得。
    令 f[i] 表示一个麻球 i 天后灭亡的概率（包含在第 i 天之前的），则
      f[i] = sum{ p[j]*(f[i-1]^j) | 0<=j<n }
    其中，p[j]*(f[i-1]^j) 表示一只麻球在第一天生下 j 只新麻球，而这 j 只新麻球在之后的第 2:i 天（共i-1天）中灭亡的概率。
    边界为 f[0]=0 。
    答案即为 f[m]^k 。
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
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1020;
int n,k,m;
double p[MAX];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d%d",&n,&k,&m);
    FOR(i,0,n) scanf("%lf",&p[i]);
    double f=0; //f0
    FORR(i,1,m){  //f[1:n]
      double tf=0;
      FOR(j,0,n) tf+=p[j]*pow(f,j);
      f=tf;
    }
    printf("Case #%d: %.7lf\n",kase,pow(f,k));
  }

  return 0;
}
