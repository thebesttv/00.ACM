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

const int MAX = 150000, MAX_ = MAX+20;
int n,a[MAX_];
bool vis[MAX_];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);

  FOR(i,0,n){
    if(a[i]>1 && !vis[a[i]-1])
      vis[a[i]-1]=1;
    else if(!vis[a[i]])
      vis[a[i]]=1;
    else if(!vis[a[i]+1])
      vis[a[i]+1]=1;
  }
  /*
  FOR(i,0,n) if(!vis[a[i]]){
    vis[a[i]]=1; a[i]=0;
  }

  FOR(i,0,n) if(a[i]){
    if(a[i]>1 && !vis[a[i]-1]){
      vis[a[i]-1]=1;
      a[i]=0;
    }else if(!vis[a[i]+1]){
      vis[a[i]+1]=1;
      a[i]=0;
    }
  }
  */

  int cnt = 0;
  FORR(i,1,MAX+1) cnt += vis[i];
  printf("%d\n",cnt);

  return 0;
}
