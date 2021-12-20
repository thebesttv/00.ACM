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

const int MAX=20;
int s[MAX],n,cnt=0;
bool vis[3][MAX*2]; //<b>数组要开两倍</b>

void dfs(int cur){
  if(cur==n){
    if(cnt<3) {printf("%d",s[0]+1); FOR(i,1,n) printf(" %d",s[i]+1); printf("\n");}
    cnt++; return;
  }
  FOR(i,0,n) if(!vis[0][i] && !vis[1][i+cur] && !vis[2][i-cur+n]){
    vis[0][i]=vis[1][i+cur]=vis[2][i-cur+n]=1;
    s[cur]=i; dfs(cur+1);
    vis[0][i]=vis[1][i+cur]=vis[2][i-cur+n]=0;
  }
}

int main(void){
  scanf("%d",&n);
  dfs(0);
  printf("%d\n",cnt);

  return 0;
}
