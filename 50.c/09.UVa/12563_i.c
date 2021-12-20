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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()

const int MAX=10000; //>50*3*60 + 678
int f[MAX],g[MAX],tt[60]; //f[i]表示还剩is时，最多能唱几首歌，g[i]表示当前f[i]下的最大长度
                          //因题目要求“使得唱的曲目尽量多，<b>在此前提下</b>时间尽量长”，因此g附属于f，每次对f进行更新（如果反过来则
int n,t;

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&t);
    FOR(i,0,n) scanf("%d",&tt[i]);
    MST(f,0); MST(g,0);
    FOR(i,0,n) ROR(j,t,tt[i]){
      if(f[j]<f[j-tt[i]]+1){
        f[j]=f[j-tt[i]]+1;
        g[j]=g[j-tt[i]]+tt[i];
      }else if(f[j]==f[j-tt[i]]+1)
        g[j]=max(g[j],g[j-tt[i]]+tt[i]);
    }
    printf("Case %d: %d %d\n",kase,f[t-1]+1,g[t-1]+678);
  }

  return 0;
}
