// Tag: 2D 离散化
// Link: [UVa 12171]
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

const int MAX = 120;
int n,G[MAX*2][MAX]; VR<double> vx, vh;
struct Node{
  double x,y,w,d,h; int no;
  bool operator < (const Node &b) const {
    return x != b.x ? x < b.x : y < b.y;
  }
}node[MAX];
bool vis[MAX];

int IDx(double x) { return lower_bound(ALL(vx),x) - vx.begin(); }
int IDh(double x) { return lower_bound(ALL(vh),x) - vh.begin(); }

void fill(int l, int r, int h, int no){
  FOR(i,l,r) FOR(j,0,h)
    G[i][j] = no;
}

int main(void){
  int kase = 0;
  while(scanf("%d",&n)==1 && n){
    if(kase) putchar('\n');
    MST(G,0); MST(vis,0); vx.clear(); vh.clear();
    vh.push_back(0);
    FOR(i,0,n){
      Node &t = node[i]; t.no = i + 1;
      scanf("%lf%lf%lf%lf%lf",&t.x,&t.y,&t.w,&t.d,&t.h);
      vx.push_back(t.x);
      vx.push_back(t.x + t.w);
      vh.push_back(t.h);
    }
    sort(ALL(vx)), vx.erase(unique(ALL(vx)), vx.end());
    sort(ALL(vh)), vh.erase(unique(ALL(vh)), vh.end());

    sort(node,node+n, [](const Node &a, const Node &b){
        return a.y > b.y;
    });
    FOR(i,0,n) fill(IDx(node[i].x), IDx(node[i].x + node[i].w), IDh(node[i].h), node[i].no);

    FOR(i,0,vx.size()) FOR(j,0,vh.size()) vis[G[i][j]] = 1;
    printf("For map #%d, the visible buildings are numbered as follows:\n",++kase);
    sort(node,node+n);
    bool first = 1;
    FOR(i,0,n) if(vis[node[i].no]){
      if(first) first = 0;
      else putchar(' ');
      printf("%d",node[i].no);
    }
    putchar('\n');
  }

  return 0;
}
