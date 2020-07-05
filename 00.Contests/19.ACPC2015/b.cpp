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

const int MAX = 5020;
const LL MOD = 100000007;
int n,l[MAX*2],r[MAX*2];
struct Point{
  int x,no;
  bool operator < (const Point &b) const {
    return x < b.x;
  }
};
VR<Point> vy[MAX*2];

struct ST{
  int n,v[MAX*2];
  int sum(int x){
    int s = 0;
    while(x){
      s += v[x]; x -= x&-x;
    }
    return s;
  }
  void add(int x, int a){
    while(x<=n){
      v[x] += a; x += x&-x;
    }
  }
}s1,s2;

int main(void){
  int T; scanf("%d",&T);
  int x,y;
  s1.n = s2.n = 10020;
  while(T--){
    FORR(i,20,10020) vy[i].clear();

    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&x,&y);
      x += 5020, y += 5020;
      vy[y].push_back({x,i});
    }

    LL ans = 0;
    ROR(i,10020,20) for(Point p : vy[i]){
      MST(s1.v,0), MST(s2.v,0);
      FOR(j,20,i){
        if(vy[j].size()>=2){
          LL sl = 0, sr = 0;
          for(Point p2 : vy[j]){
            // printf("  (%d, %d), %d, %d\n",p2.x-5020,j-5020,s1.sum(p2.x-1),s2.sum(10040-p2.x-1));
            if(p2.x<p.x){
              sl += s2.sum(10040-(p2.x+1));
            } else if(p2.x>p.x){
              sr += s1.sum(p2.x-1);
            }
          }
#ifdef DEBUG
          printf("  point(%d,%d): sl: %lld, sr: %lld\n",p.x-5020,i-5020,sl,sr);
#endif
          ans = (ans + sl*sr)%MOD;
        }

        for(Point p2 : vy[j]){
          if(p2.x<p.x)
            s2.add(10040-p2.x,1);
          else if(p2.x>p.x)
            s1.add(p2.x,1);
        }
      }
    }
    printf("%lld\n",ans);

  }

  return 0;
}

    /*
    FORR(j,20,10020) if(vy[j].size()){
      sort(ALL(vy[j]));
      for(Point p : vy[j]){
        l[p.no] = s1.sum(p.x-1);
        r[p.no] = s2.sum(10040-(p.x+1));
#ifdef DEBUG
        printf(" (%d, %d) l: %d, r: %d\n",p.x-5020,j-5020,l[p.no],r[p.no]);
#endif
      }
      for(Point p : vy[j]){
        s1.add(p.x,1);
        s2.add(10040-p.x,1);
      }
    }
#ifdef DEBUG
    FOR(i,0,n) printf("  l[%d]: %d, r[%d]: %d\n",i,l[i],i,r[i]);
#endif

    LL ans = 0;
    ROR(i,10020,20) if(vy[i].size()) for(Point p : vy[i]){
      FOR(j,20,i) if(vy[j].size()>=2){
        LL sl=0, sr=0;
        for(Point p2 : vy[j]){
#ifdef DEBUG
          printf("    V (%d, %d), l: %d, r: %d, for (%d, %d)\n",p2.x-5020,j-5020,l[p2.no],r[p2.no],p.x-5020,i-5020);
#endif
          if(p2.x<p.x)      sl += l[p2.no];
          else if(p2.x>p.x) sr += r[p2.no];
        }
#ifdef DEBUG
        printf("  point(%d,%d): sl: %lld, sr: %lld\n",p.x-5020,i-5020,sl,sr);
#endif
        ans = (ans + sl*sr)%MOD;
      }
    }
    */
