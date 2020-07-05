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

const int MAX = 1e6 + 20;
int n, a[MAX], val[MAX];  // a[i]: possible max, val[i]: all elements
LL b[MAX], len[MAX], cnt[MAX];

struct Node{
  int type, l, r; // [l,r)
}q[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    int op,k,x,y;
    int tail = 0;
    FORR(i,1,n){
      scanf("%d",&op);
      a[i] = b[i] = 0;
      if(op==1){
        scanf("%d",&k);
        q[i] = {1, tail, tail + k};
        len[i] = k;
        while(k--){
          scanf("%d",&x);
          val[tail++] = x;
          if(a[i] == x) ++b[i];
          else if(b[i]) --b[i];
          else a[i]=x, b[i]=1;
        }
      }else{
        scanf("%d%d",&x,&y);
        len[i] = len[x] + len[y];
        q[i] = {2, x, y};
        if(b[x] < b[y]) swap(x,y);
        if(a[x]==a[y]){
          a[i] = a[x];
          b[i] = b[x] + b[y];
        }else{
          a[i] = a[x];
          b[i] = b[x] - b[y];
        }
      }
    }
    int v = a[n];
#ifdef DEBUG
    printf("v: %d\n",v);
#endif
    FORR(i,1,n){
      cnt[i] = 0;
      if(q[i].type==1){
        FOR(j,q[i].l,q[i].r){
          if(val[j]==v) ++cnt[i];
        }
      }else{
        cnt[i] = cnt[q[i].l] + cnt[q[i].r];
      }
#ifdef DEBUG
      printf("  cnt[%d]: %lld\n",i,cnt[i]);
#endif
    }
    if(cnt[n] > len[n]/2)
      printf("%lld\n", 2 * (len[n] - cnt[n]));
    else printf("%lld\n",len[n]);
  }

  return 0;
}
