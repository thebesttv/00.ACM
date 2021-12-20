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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=320;
int n,m; bool vis[MAX];

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    FOR(i,0,n) vis[i]=0;
    int left=n,cur=0;
    while(left>1){
      for(int i=0;i<m;i++){
        while(vis[cur]) cur = (cur+1)%n;
        cur = (cur+1)%n;
      }
      cur = (cur-1+n)%n;
      vis[cur]=1; left--;
    }
    while(vis[cur]) cur = (cur+1)%n;
    printf("%d\n",cur+1);
  }

  return 0;
}
