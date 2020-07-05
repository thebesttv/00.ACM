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

const int MAX = 1020;
int n,a[MAX],b[MAX];
bool vis[MAX];

int find(int x){
  for(int i=2;i<=n*2;i+=2)
    if(a[i-1]<x && a[i]==0) return i;
  return -1;
}

bool ok(){
  VR<int> v;
  FORR(i,1,n*2) if(!vis[i])
    v.push_back(i);
  FORR(i,1,n) a[i*2-1]=b[i];
  for(int x : v){
    int i=find(x);
#ifdef DEBUG
    printf("  find(%d): %d\n",x,i);
#endif
    if(i==-1) return false;
    a[i]=x;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0); MST(a,0);
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&b[i]), vis[b[i]]=1;
    if(ok()) FORR(i,1,2*n) printf("%d ",a[i]);
    else printf("-1");
    putchar('\n');
  }

  return 0;
}
