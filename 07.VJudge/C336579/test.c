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

const int MAX=100020;
const int INF=0x3f3f3f3f;
int n,k;
struct Node{
  int s,pos;
  bool operator < (const Node &b) const {
    return s < b.s;
  }
  bool operator == (const Node &b) const {
    return s == b.s;
  }
}v[MAX];

int solve(int q, int &rl, int &rr){
#ifdef DEBUG
  printf("q: %d\n",q);
#endif
  int l=0, r=lower_bound(v,v+n,Node{v[0].s+q,0})-v;
  r = max(r,1); // r 至少要从 1 开始
  int delta=INF;
  while(l<n){
    while(r<n && (r<=l || v[r].s-v[l].s<q)) r++;
#ifdef DEBUG
    printf("  (%d, %d)\n",l,r);
#endif
    int t = abs(v[r-1].s - v[l].s - q); // new delta
    if(r-1>l && delta > t){
      delta=t; rl=l, rr=r;
    }
    if(r==n) break; // r hits the edge
    t = abs(v[r].s - v[l].s - q);
    if(delta > t){
      delta=t; rl=l, rr=r;
    }
    l++;
  }

  int ans = v[rr].s - v[rl].s;
  rl = v[rl].pos, rr = v[rr].pos;
  if(rl>rr) swap(rl,rr);
  rl++;
  return delta;
}

int main(void){
  while(scanf("%d%d",&n,&k)==2 && n){
    v[0].s=v[0].pos=0;
    FORR(i,1,n){
      scanf("%d",&v[i].s);
      v[i].s+=v[i-1].s; v[i].pos=i;
    }
    sort(v,v+n+1);  // [0:n] 共 n+1 个
#ifdef DEBUG
    printf("ori s(%d):",n+1); FORR(i,0,n) printf(" %d",v[i].s); putchar('\n');
#endif
    //n = unique(v,v+n+1)-v;
    n++;
#ifdef DEBUG
    printf("s(%d):",n); FOR(i,0,n) printf(" %d",v[i].s); putchar('\n');
#endif
    FOR(i,0,k){
      int t,l,r; scanf("%d",&t);
      int ans=solve(t,l,r);
      //printf("%d %d %d\n",ans,l,r);
      printf("%d\n",ans);
    }
  }

  return 0;
}

/*
const int MAX=100020;
const int INF=0x3f3f3f3f;
int n,k;
struct Node{
  int s,pos;
  bool operator < (const Node &b) const {
    return s < b.s;
  }
  bool operator == (const Node &b) const {
    return s == b.s;
  }
}v[MAX];

int solve(int q, int &rl, int &rr){
#ifdef DEBUG
  printf("q: %d\n",q);
#endif
  int l=0, r=lower_bound(v,v+n,Node{v[0].s+q,0})-v;
  int delta=INF;
  while(l<n){
    while(r<n && v[r].s-v[l].s<q) r++;
#ifdef DEBUG
    printf("  (%d, %d)\n",l,r);
#endif
    int t = abs(v[r-1].s - v[l].s - q);
    if(delta > t){
      delta=t; rl=l, rr=r;
    }
    //if(r==n) break;
    t = abs(v[r].s - v[l].s - q);
    if(delta > t){
      delta=t; rl=l, rr=r;
    }
    l++;
  }

  int ans = v[rr].s - v[rl].s;
  rl = v[rl].pos, rr = v[rr].pos;
  if(rl>rr) swap(rl,rr);
  rl++;
  return ans;
}

int main(void){
  while(scanf("%d%d",&n,&k)==2 && n){
    scanf("%d",&v[0].s); v[0].pos=1;
    FOR(i,1,n){
      scanf("%d",&v[i].s);
      v[i].s+=v[i-1].s; v[i].pos=i+1;
    }
    sort(v,v+n);
#ifdef DEBUG
    printf("ori s(%d):",n); FOR(i,0,n) printf(" %d",v[i].s); putchar('\n');
#endif
    n = unique(v,v+n)-v;
#ifdef DEBUG
    printf("s:"); FOR(i,0,n) printf(" %d",v[i].s); putchar('\n');
#endif
    FOR(i,0,k){
      int t,l,r; scanf("%d",&t);
      int ans=solve(t,l,r);
      printf("%d %d %d\n",ans,l,r);
    }
  }

  return 0;
}
*/
