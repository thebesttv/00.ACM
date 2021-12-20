/*
Problem Description
Whuacmers use coins.They have coins of value A1,A2,A3...An Silverland dollar. One day Hibix opened purse and found there were some coins. He decided to buy a very nice watch in a nearby shop. He wanted to pay the exact price(without change) and he known the price would not more than m.But he didn't know the exact price of the watch.
You are to write a program which reads n,m,A1,A2,A3...An and C1,C2,C3...Cn corresponding to the number of Tony's coins of value A1,A2,A3...An then calculate how many prices(form 1 to m) Tony can pay use these coins.
 
Input
The input contains several test cases. The first line of each test case contains two integers n(1 ≤ n ≤ 100),m(m ≤ 100000).The second line contains 2n integers, denoting A1,A2,A3...An,C1,C2,C3...Cn (1 ≤ Ai ≤ 100000,1 ≤ Ci ≤ 1000). The last test case is followed by two zeros.
 
Output
For each test case output the answer on a single line.
 
Sample Input
3 10
1 2 4 2 1 1
2 5
1 4 2 1
0 0
 
Sample Output
8
4
*/

/*
  解题报告：
    首先，因为硬币的数目是有限制的，而非无限，那么就不能通过建图的方式解题。
    可以使用多重背包求解。
    按照背包的方式定义 f[i][j] 表示考虑前i个硬币、恰好组成价值为j（装入容积为j的背包中）是否可行（现在没有“最优解”这一说，只说是否可行）。
    定义每个硬币i的cost为其面值，weight可以是任意数，不过方便起见要么为1，要么也为面值。
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

const int MAXN=120;
const int MAXM=100020;
const int INF=0x3f3f3f3f;
int n,m,f[MAXM];
struct Coin{
  int a,c;
}coin[MAXN];

inline void ZeroOnePack(int cost, int weight){
  ROR(i,m,cost) f[i]=max(f[i],f[i-cost]+weight);
}
inline void CompletePack(int cost, int weight){
  FORR(i,cost,m) f[i]=max(f[i],f[i-cost]+weight);
}
inline void MultiPack(int cost, int weight, int amount){
  if(cost*amount>=m) {CompletePack(cost,weight); return;}
  int k=1;
  while(k<amount){
    ZeroOnePack(cost*k,k*weight);
    amount-=k; k<<=1;
  }
  ZeroOnePack(amount*cost,amount*weight);
}

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    FORR(i,1,m) f[i]=-INF;
    FORR(i,1,n) scanf("%d",&coin[i].a);
    FORR(i,1,n) scanf("%d",&coin[i].c);

    //FORR(i,1,n) MultiPack(coin[i].a,coin[i].a,coin[i].c);
    FORR(i,1,n) MultiPack(coin[i].a,1,coin[i].c);            //两种都可以

    int cnt=0;
    FORR(i,1,m) if(f[i]>0) cnt++;
    printf("%d\n",cnt);
  }

  return 0;
}
