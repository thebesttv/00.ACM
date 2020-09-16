// Tag: ii
// Link: [LuoGu 1972]
// 统计全局不同数字：仅记录每个数子最后出现次数
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2e5 + 20;
int n,k,a[MAX],pos[MAX];
bool vis[MAX]; set<int> st;

int main(void){
  scanf("%d%d",&n,&k);
  FORR(i,1,n) scanf("%d",&a[i]), pos[a[i]] = i;
  FORR(i,1,k) st.insert(pos[i]);

  int i = 1;

  while(k--){
#ifdef DEBUG
    printf("i: %d, (get(%d): %d)\n",i,k,get(k)); fflush(stdout);
#endif
    int j = *st.begin();
    int tMin = n+1, r = j+1;
    ROR(x,j,i) if(!vis[a[x]])
      if(a[x] < tMin) tMin = a[r=x];
      else if(a[x] == tMin) r = x;
    vis[tMin] = 1; st.erase(pos[tMin]);
    printf("%d ",tMin);
    i = r + 1;
  }
  putchar('\n');

  return 0;
}

/*
const int MAX = 2e5 + 20;
int n,k,a[MAX],pos[MAX];
bool vis[MAX];

struct ST{
  int v[MAX];

  int sum(int l, int r){
    return sum(r) - sum(l-1);
  }
  int sum(int x){
    int ans=0;
    while(x) { ans+=v[x]; x-=x&-x; }
    return ans;
  }
  void add(int x, int d){
#ifdef DEBUG
    printf("add (%d ,%d)\n",x,d);
#endif
    while(x<=n) { v[x]+=d; x+=x&-x; }
  }
}sg;

int get(int x){
  int l = 1, r = n;
  while(l < r){
    int m = (l + r + 1)/2;
#ifdef DEBUG
    printf("  l: %d, r: %d, sum(%d, %d): %d\n",l,r,m,r,sg.sum(m,r));
#endif
    if(sg.sum(m,n) >= x) l = m;
    else r = m-1;
  }
  return l;
}

int main(void){
  scanf("%d%d",&n,&k);
  FORR(i,1,n) scanf("%d",&a[i]), pos[a[i]] = i;
  FORR(i,1,k) sg.add(pos[i],1);

  int i = 1;
  while(k){
#ifdef DEBUG
    printf("i: %d, (get(%d): %d)\n",i,k,get(k)); fflush(stdout);
#endif
    int j = get(k--);
    int tMin = n+1, r = j+1;
    ROR(kk,j,i) if(!vis[a[kk]])
      if(a[kk] < tMin) tMin = a[r=kk];
      else if(a[kk] == tMin) r = kk;
    vis[tMin] = 1; sg.add(pos[tMin],-1);
    printf("%d ",tMin);
    i = r + 1;
  }
  putchar('\n');

  return 0;
}
*/
