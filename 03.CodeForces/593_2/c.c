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
int n,n2,cnt[MAX],a[MAX*MAX],r[MAX*MAX];
int f[MAX][MAX],ansMax;
VR<int> v[MAX];

int cal(){
  MST(f,0);
  FORR(i,2,n2) FOR(j,1,i)
    f[a[i]][a[j]]++;
  int tMin=0x3f3f3f3f;
  FORR(i,1,n) FORR(j,1,n)
    if(i!=j) tMin=min(tMin,f[i][j]);
  return tMin;
}

void dfs(int cur){
  if(cur==n2+1){
    int t=cal();
    if(t>ansMax){
      ansMax=t; memcpy(r,a,SIZ(a));
    }
    return;
  }
  FORR(i,1,n) if(cnt[i]<n){
    cnt[i]++; a[cur]=i;
    dfs(cur+1);
    cnt[i]--;
  }
}

int main(void){
  scanf("%d",&n); n2=n*n;
  dfs(1);
  FORR(i,1,n){
    FORR(j,1,n2) if(r[j]==i) printf("%d ",j);
    printf("\n");
  }

  return 0;
}

/*
const int MAX=320;
int a[MAX*MAX];
VR<int> v[MAX];

int main(void){
  int n; scanf("%d",&n);
  FOR(i,0,n){
    int l=i*n+1;
    int r=l+n;
    int s=i+1;
    FOR(k,l,r){
      a[k] = s;
      v[s].push_back(k);
      s = s==n ? 1 : s+1;
    }
  }

  FORR(i,1,n){
    printf("%d",v[i][0]);
    FOR(j,1,n) printf(" %d",v[i][j]);
    putchar('\n');
  }

  return 0;
}
*/
