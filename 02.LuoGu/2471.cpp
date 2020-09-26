// Tag: notag
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

const int MAX = 50000 + 20;
int n, m, v[MAX], a[MAX];

int ID(int x){
  return lower_bound(v+1,v+1+n,x) - v;
}

struct ST{
  int f[MAX][20], n;
  void build(int *a, int n){
    this->n = n;
    FORR(i,1,n) f[i][0]=a[i];
    ROR(i,n,1) for(int j=1;i+(1<<j)-1<=n;j++)
      f[i][j] = max( f[i][j-1], f[i+(1<<(j-1))][j-1] );
  }
  int qMax(int l, int r){
    if(l > r) return 0;
    int k=log(r-l+1)/log(2);
    return max( f[l][k], f[r-(1<<k)+1][k] );
  }
}sg;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d%d",&v[i],&a[i]);
  sg.build(a,n);

  scanf("%d",&m);
  while(m--){
    int l, r; scanf("%d%d",&l,&r);
    int cl = ID(l), cr = ID(r);
    if(cl == n+1){
      printf("maybe\n");
    }else{
      bool ok = true;

      if(cr == n+1 || v[cr] > r) --cr;

      if(v[cr] == r){
        if(v[cl] == l){
          if(sg.qMax(cl,cl) < sg.qMax(cr, cr)
              || sg.qMax(cl+1, cr-1) >= sg.qMax(cr, cr))
            ok = false;
        }else{  // l < v[cl]
          if(sg.qMax(cl,cr-1) >= sg.qMax(cr, cr))
            ok = false;
        }
      }else{
        if(v[cl] == l && sg.qMax(cl,cl) <= sg.qMax(cl+1, cr))
          ok = false;
      }

      printf("%s\n", !ok ? "false" : (r-l+1 == cr-cl+1 ? "true" : "maybe"));
    }
  }

  return 0;
}
