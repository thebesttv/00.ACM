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
const int INF = 0x3f3f3f3f;
int n,m; char G[MAX][MAX];
int f[MAX][MAX][2], up[MAX][2], down[MAX][2], len[MAX][MAX];

struct ST{
  int n, a[MAX], vMax[MAX<<2], vMin[MAX<<2];
  void build(int u, int l, int r){
    if(l==r){
      vMax[u] = vMin[u] = a[l];
      return;
    }
    int m = (l+r)>>1;
    build(u<<1,l,m);
    build(u<<1|1,m+1,r);
    vMax[u] = max(vMax[u<<1],vMax[u<<1|1]);
    vMin[u] = min(vMin[u<<1],vMin[u<<1|1]);
  }
  int qMax(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return vMax[u];
    }
    int m = (cl+cr)>>1, s=0;
    if(ql<=m) s = qMax(u<<1,cl,m,ql,qr);
    if(qr>=m+1) s = max(s, qMax(u<<1|1,m+1,cr,ql,qr));
    return s;
  }
  int qMin(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return vMin[u];
    }
    int m = (cl+cr)>>1, s=INF;
    if(ql<=m) s = qMin(u<<1,cl,m,ql,qr);
    if(qr>=m+1) s = min(s, qMin(u<<1|1,m+1,cr,ql,qr));
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n){
    scanf("%s",G[i]+1);
    int j = 1, ch;
    while(j<=m){
      ch = G[i][j]; int r = j;
      while(r+1<=m && G[i][r+1]==ch) ++r;
      FORR(k,j,r)
        f[i][k][0]=j,
        f[i][k][1]=r,
        len[i][j] = r-j+1;
      j = r+1;
    }
  }
#ifdef DEBUG
  FORR(i,1,n){
    FORR(j,1,m) printf("[%d,%d] ",f[i][j][0],f[i][j][1]);
    putchar('\n');
  }
#endif

  int ans = 1; sg.n = n;
  FORR(j,1,m){
    FORR(i,1,n) sg.a[i] = f[i][j][0];
    sg.build(1,1,n);
    FORR(i,1,n) if(len[i][j]>ans){
      int l = 1, r = i, h = f[i][j][0];
      while(l < r){
        int m = (l+r)>>1;
        if(sg.qMax(1,1,n,m,r) > h)
          l = m + 1;
        else
          r = m;
      }
      up[i][0] = l;

      l = i, r = n;
      while(l<r){
        int m = (l+r+1)>>1;
        if(sg.qMax(1,1,n,l,m) > h)
          r = m - 1;
        else
          l = m;
      }
      down[i][0] = l;
    }

    FORR(i,1,n) sg.a[i] = f[i][j][1];
    sg.build(1,1,n);
    FORR(i,1,n) if(len[i][j]>ans){
      int l = 1, r = i, h = f[i][j][1];
      while(l<r){
        int m = (l+r)>>1;
        if(sg.qMin(1,1,n,m,r) < h)
          l = m + 1;
        else
          r = m;
      }
      up[i][1] = l;

      l = i, r = n;
      while(l<r){
        int m = (l+r+1)>>1;
        if(sg.qMin(1,1,n,l,m) < h)
          r = m - 1;
        else
          l = m;
      }
      down[i][1] = l;
    }

#ifdef DEBUG
    printf("Col %d\n",j);
    FORR(i,1,n){
      printf("  [%d, %d], [%d, %d]\n",
          up[i][0],down[i][0],
          up[i][1],down[i][1]);
    }
#endif

    FORR(i,1,n){
      int w = f[i][j][1] - f[i][j][0] + 1,
          h = min(down[i][0],down[i][1])
            - max(up[i][0],up[i][1]) + 1;
      ans = max(ans, min(w,h));
    }
  }
  printf("%d\n",ans*ans);

  return 0;
}
