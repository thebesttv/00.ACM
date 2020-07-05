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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=200020;
int n,m,x[MAX]; LL s[MAX];

void add(int l, int r, int v){
  s[l]+=v; s[r+1]-=v;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m) scanf("%d",&x[i]);

  FOR(j,1,m){ // x[j] & x[j+1]
    int x1 = x[j], x2 = x[j+1];
    if(x1==x2) continue;
    if(x1>x2) swap(x1,x2);

    // x1 < x2
    int d;
    // 1. i < x1 < x2
    if(x1>1){
      d = x2 - x1;
      add(1,x1-1,d);
    }
    // 2. i = x1 < x2
    d = x2 - 1;
    add(x1,x1,d);
    // 3. x1 < i < x2
    if(x1 + 1 < x2){
      d = x2 - x1 - 1;
      add(x1+1,x2-1,d);
    }
    // 4. x1 < x2 = i
    d = x1 + 1 - 1;
    add(x2,x2,d);
    // 5. x1 < x2 < i
    if(x2<n){
      d = x2 - x1;
      add(x2+1,n,d);
    }
  }

  LL ans = 0;
  FORR(i,1,n){
    ans += s[i];
    if(i>1) putchar(' ');
    printf("%lld",ans);
  }
  putchar('\n');

  return 0;
}

/*
const int MAX=200020;
int n,m,x[MAX]; LL s[MAX];

struct Node{
  LL sum,av;
};
struct SetTree{
  Node node[MAX<<2];

  void pushUp(int u){
    node[u].sum = node[u<<1].sum + node[u<<1|1].sum;
  }
  void pushDown(int u, int cl, int cr){
    int m=(cl+cr)>>1; Node &t=node[u];
    if(t.av){
      node[u<<1].sum += t.av*(m-cl+1);
      node[u<<1].av += t.av;

      node[u<<1|1].sum += t.av*(cr-m);
      node[u<<1|1].av += t.av;

      t.av=0;
    }
  }
  void add(int u, int cl, int cr, int ql, int qr, LL av){
    if(ql<=cl && cr<=qr){
      node[u].sum += av*(cr-cl+1);
      node[u].av += av;
    }else{
      pushDown(u,cl,cr);
      int m=(cl+cr)>>1;
      if(ql<=m) add(u<<1,cl,m,ql,qr,av);
      if(m<qr) add(u<<1|1,m+1,cr,ql,qr,av);
      pushUp(u);
    }
  }
  LL sum(int u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr){
      return node[u].sum;
    }else{
      pushDown(u,cl,cr);
      int m=(cl+cr)>>1; LL ans=0;
      if(ql<=m) ans=sum(u<<1,cl,m,ql,qr);
      if(m<qr) ans+=sum(u<<1|1,m+1,cr,ql,qr);
      return ans;
    }
  }
}sg;

int pos(int i, int v){
  if(i==v) return 1;
  if(v<i) return v+1;
  return v;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m) scanf("%d",&x[i]);

  FOR(j,1,m){ // x[j] & x[j+1]
    int x1 = x[j], x2 = x[j+1];
    if(x1==x2) continue;
    if(x1>x2) swap(x1,x2);

    // x1 < x2
    int d;
    // 1. i < x1 < x2
    if(x1>1){
      d = abs( x2 - x1 );
      sg.add(1,1,n,1,x1-1,d);
    }
    // 2. i = x1 < x2
    d = abs( 1 - x2 );
    sg.add(1,1,n,x1,x1,d);
    // 3. x1 < i < x2
    if(x1 + 1 < x2){
      d = abs( x1 + 1 - x2);
      sg.add(1,1,n,x1+1,x2-1,d);
    }
    // 4. x1 < x2 = i
    d = x1 + 1 - 1;
    sg.add(1,1,n,x2,x2,d);
    // 5. x1 < x2 < i
    if(x2<n){
      d = abs( x1 - x2 );
      sg.add(1,1,n,x2+1,n,d);
    }
  }

  s[0]=0;
  FORR(i,1,n){
    s[i] = sg.sum(1,1,n,1,i);
    if(i>1) putchar(' ');
    printf("%lld",s[i]-s[i-1]);
  }
  putchar('\n');

  return 0;
}
*/
