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
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=0;
int n,m,k,tot=0;

void dfs(int cur, int s){
  if(cur==k) {tot+=(s==n); return;}
  FORR(i,1,m)
    if(s+i<=n) dfs(cur+1,s+i);
    else break;
}

int main(void){
  int ans=0;
  for(n=1;n<=33;n++) for(m=1;m<=n;m++) for(k=1;k<=n;k++){
    tot=0;
    dfs(0,0);
    printf("%d\n",tot);
    ans=max(ans,tot);
  }
  return 0;
}
