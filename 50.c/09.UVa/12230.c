/*
  解题报告：
    应该算是一道很简单的数学期望的题吧（然而我一开始不会……）
    首先，因为船的位置在0时刻是随机的，且船的运动是稳定的（即船不会在某个时刻一定在某处），那么也就可以看成船的位置在任意时刻是随机的。
    ans = 在每条河i上的期望时间 + 在路上的期望时间
    对于每条河，一开始到左岸的时候船的位置在[0,Li]均匀分布，且朝向随机，那么从该时刻直到到达对岸，船的路程在**[Li,3Li]**均匀分布，那么期望时间就是 (Li+3Li)/2/v ，即 2Li/v 。
    而在路上的时间是一定的，为 D - sum{Li} 。
    那么答案即为 sum{2Li/v} + D - sum{Li} 。
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

int n,d;

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&d)==2 && (n||d)) {
    int p,l,v;
    double ans=d;
    FOR(i,0,n){
      scanf("%d%d%d",&p,&l,&v);
      ans += 2.0*l/v - l;
    }
    printf("Case %d: %.3lf\n\n",++kase,ans);
  }

  return 0;
}
