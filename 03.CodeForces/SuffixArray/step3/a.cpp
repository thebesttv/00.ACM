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

const int MAX = 300020;
int n; char s[MAX],t[MAX];
int p[MAX],p2[MAX],c[MAX],c2[MAX];
pii v[MAX];

int pos[MAX], cnt[MAX];
void count_sort(){
  MST(cnt,0);
  // FOR(i,0,n) ++cnt[c[p[i]]];
  FOR(i,0,n) ++cnt[c[i]];
  pos[0] = 0;
  FOR(i,1,n) pos[i] = pos[i-1] + cnt[i-1];
  FOR(i,0,n) p2[pos[c[p[i]]]++] = p[i];
  memcpy(p,p2,sizeof(p));
}

void build(){
  FOR(i,0,n) v[i] = {s[i],i};
  sort(v,v+n);
  p[0] = v[0].SE; c[p[0]] = 0;
  FOR(i,1,n){
    p[i] = v[i].SE;
    if(v[i].FI == v[i-1].FI)
      c[p[i]] = c[p[i-1]];
    else
      c[p[i]] = c[p[i-1]] + 1;
  }

  for(int k = 0; (1<<k) < n; ++k){
    FOR(i,0,n) p[i] = (p[i] - (1<<k) + n)%n;
    count_sort();

    c2[p[0]] = 0;
    FOR(i,1,n){
      pii cur = {c[p[i]], c[(p[i] + (1<<k))%n]};
      pii prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
      if(cur == prev)
        c2[p[i]] = c2[p[i-1]];
      else
        c2[p[i]] = c2[p[i-1]] + 1;
    }
    memcpy(c,c2,sizeof(c));
  }
}

int main(void){
  scanf("%s",s); n = strlen(s);
  s[n++] = '$'; s[n] = 0;
  build();
#ifdef DEBUG
  FOR(i,0,n) printf("p[%d]: %d, %s\n",i,p[i],s+p[i]);
#endif

  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",t); int m = strlen(t);
    int l = 0, r = n - 1;
    while(l<r){
      int mid = (l+r+1)/2;
      if(strncmp(s + p[mid], t, m) <= 0) l = mid;
      else r = mid - 1;
    }
    printf("%s\n", strncmp(s+p[l],t,m)==0 ? "Yes" : "No");
  }

  return 0;
}
