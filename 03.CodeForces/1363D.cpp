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
int n,k; VR<int> v[MAX];
int ans[MAX];
bool vis[MAX];

int askNeg(int c){
  MST(vis,0);
  if(c) for(int x : v[c])
    vis[x] = 1;

  int sum = 0;
  FORR(i,1,n) if(!vis[i]) ++sum;
  printf("? %d",sum);
  FORR(i,1,n) if(!vis[i]) printf(" %d",i);
  putchar('\n');
  fflush(stdout);

  int ans; scanf("%d",&ans);
  return ans;
}

int ask(int l, int r){
  int sum = 0;
  FORR(i,l,r) sum += v[i].size();
  printf("? %d",sum);
  FORR(i,l,r) for(int x : v[i])
    printf(" %d",x);
  putchar('\n');
  fflush(stdout);

  int ans; scanf("%d",&ans);
  return ans;
}

int ask(VR<int> &c){
  int sum = 0;
  for(int i : c) sum += v[i].size();
  printf("? %d",sum);
  for(int i : c) for(int x : v[i])
    printf(" %d",x);
  putchar('\n');
  fflush(stdout);

  int ans; scanf("%d",&ans);
  return ans;
}

void answer(){
  printf("!");
  FORR(i,1,k) printf(" %d",ans[i]);
  putchar('\n');
  fflush(stdout);
  char ans[20]; scanf("%s",ans);
  if(ans[0] != 'C') exit(0);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    FORR(i,1,k){
      int c, x; v[i].clear();
      scanf("%d",&c);
      while(c--) scanf("%d",&x), v[i].push_back(x);
    }
    if(k<=12){
      FORR(i,1,k) ans[i] = askNeg(i);
      answer();
      continue;
    }

    int aMax = askNeg(0), l = 1, r = k;
    while(l < r){
      int m = (l+r)/2;
      int t = ask(l,m);
      if(t == aMax) r = m;
      else l = m+1;
    }

    int aSec = askNeg(l);
    FORR(i,1,k) ans[i] = aMax;
    if(aSec != aMax) ans[l] = aSec; // only one max
    answer();
  }

  return 0;
}
