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

const int MAX = 220;
int n,m,l,a[100020],ans[100020];
char s[MAX],s1[MAX],s2[MAX];
bool fr[MAX][MAX];
VR<int> G[100020];
int to[100020];

string v[MAX];
int ID(string s){
  return lower_bound(v+1,v+1+m,s) - v;
}

struct Node{
  int idx, v;
  bool operator < (const Node &b) const {
    // return v > b.v;
    return ::v[v] + ::v[b.v] > ::v[b.v] + ::v[v];
  }
};

int main(void){
  scanf("%d%d%d",&m,&l,&n);
  FORR(i,1,m) cin >> v[i];
  sort(v+1,v+1+m);

  while(l--){
    scanf("%s%s",s1,s2);
    int u = ID(s1), v = ID(s2);
    fr[u][v] = fr[v][u] = 1;
#ifdef DEBUG
    printf("  %d - %d\n",min(u,v),max(u,v));
#endif
  }
  FORR(i,1,n) scanf("%s",s), a[i] = ID(s);
#ifdef DEBUG
  FORR(i,1,m) printf("v[%d]: %s\n",i,v[i].c_str());
  FORR(i,1,n) printf("%d ",a[i]); putchar('\n');
#endif

  FORR(i,1,m){
    int last = 0;
    ROR(j,n,0) if(a[j] == i || !fr[a[j]][i]){
      if(last){
        G[j].push_back(last); ++to[last];
#ifdef DEBUG
        printf("  %d -> %d\n",j,last);
#endif
      }
      if(a[j]==i) last = j;
    }
  }

  PQ<Node> q; q.push({0,0});
  while(!q.empty()){
    Node t = q.top(); q.pop();
    if(t.idx){
      printf("%s ",v[t.v].c_str());
    }
    for(int v : G[t.idx]){
      if(--to[v]) continue;
      q.push({v,a[v]});
    }
  }
  putchar('\n');

  return 0;
}
