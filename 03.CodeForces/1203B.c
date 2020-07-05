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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 420;
int n, a[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n)
      scanf("%d%d%d%d",a+4*i,a+4*i+1,a+4*i+2,a+4*i+3);

    sort(a,a+n*4);

    int s = a[0] * a[4*n-1];
#ifdef DEBUG
    printf("  get s: %d\n",s);
#endif
    bool ok = 1;
    FOR(i,0,n) if(a[i*2] != a[i*2+1]
               || a[4*n-i*2-2] != a[4*n-i*2-1]
               || a[i*2] * a[4*n-i*2-1] != s){
      ok = 0; break;
    }
    printf("%s\n", ok ? "YES" : "NO");
  }

  return 0;
}


/*
   const int MAX = 420;
   int q, n, a[MAX];
   map<int,int> ori, mp;

   bool ok(int s){
   int l, r, n, cnt = 0, tMax = sqrt(s+0.5);
   int t = rand()%(::n*4);
   if(s%a[t]) return false;
   t = rand()%(::n*4);
   if(s%a[t]) return false;

   mp = ori;
   for(auto &p : mp) if(p.second){
   if(p.first > tMax) break;

   l = p.first; r = s / p.first;
   if(l*r != s || mp.find(r)==mp.end())
   return false;

   if(l==r) n = p.second / 4;
   else n = p.second / 2;
   p.second -= n*2;

   if(mp[r]<n*2) return false;
   mp[r]-=n*2;

   cnt += n;
   if(cnt==::n) break;
   }
   return cnt==::n;
   }

   int main(void){
   int T; scanf("%d",&T);
   srand(T);
   while(T--){
   ori.clear();
   scanf("%d",&n); n<<=2;
   FOR(i,0,n){
   scanf("%d",&a[i]); ++ori[a[i]];
   }
   n >>= 2;

   bool bad = 0;
   for(auto &p : ori) if(p.second&1){
   bad = 1; break;
   }
   if(bad) { printf("NO\n"); continue; }

   bool done = 0;
   auto lt = ori.begin();
   for(auto rt = ori.rbegin(); rt!=ori.rend(); ++rt){
   if(ok(lt->first * rt->first)){
   printf("YES\n"); done = 1; break;
   }
   }
   if(!done) printf("NO\n");
   }

   return 0;
   }
 */
