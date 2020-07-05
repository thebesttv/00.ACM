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

const int MAX = 1e6 + 20;
const int INF = 0x3f3f3f3f;
int n,cur=1; char s[MAX];

struct Node{
  LL sum,vmax,vmin,av;
};
struct SetTree{
  Node node[MAX<<2];

  void pushUp(int u){
    node[u].sum = node[u<<1].sum + node[u<<1|1].sum;
    node[u].vmin = min(node[u<<1].vmin, node[u<<1|1].vmin);
    node[u].vmax = max(node[u<<1].vmax, node[u<<1|1].vmax);
  }
  void pushDown(int u, int cl, int cr){
    int m=(cl+cr)>>1; Node &t=node[u];
    if(t.av){
      node[u<<1].sum += t.av*(m-cl+1);
      node[u<<1].vmin += t.av;
      node[u<<1].vmax += t.av;
      node[u<<1].av += t.av;

      node[u<<1|1].sum += t.av*(cr-m);
      node[u<<1|1].vmin += t.av;
      node[u<<1|1].vmax += t.av;
      node[u<<1|1].av += t.av;

      t.av=0;
    }
  }
  void build(int u, int cl, int cr){
    if(cl==cr){
      node[u].vmax = node[u].vmin = 0;
    }else{
      int m=(cl+cr)>>1;
      build(u<<1,cl,m);
      build(u<<1|1,m+1,cr);
      pushUp(u);
    }
  }
  void add(int u, int cl, int cr, int ql, int qr, LL av){
#ifdef DEBUG
    if(u==1) printf("  add %d, %d, %lld\n",ql,qr,av);
#endif
    if(ql<=cl && cr<=qr){
      node[u].sum += av*(cr-cl+1);
      node[u].av += av;
      node[u].vmin += av;
      node[u].vmax += av;
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
  LL qmin(int u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr){
      return node[u].vmin;
    }else{
      pushDown(u,cl,cr);
      int m=(cl+cr)>>1; LL ans=INF;
      if(ql<=m) ans=qmin(u<<1,cl,m,ql,qr);
      if(m<qr) ans=min(ans,qmin(u<<1|1,m+1,cr,ql,qr));
      return ans;
    }
  }
  LL qmax(int u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr){
      return node[u].vmax;
    }else{
      pushDown(u,cl,cr);
      int m=(cl+cr)>>1; LL ans=-INF;
      if(ql<=m) ans=qmax(u<<1,cl,m,ql,qr);
      if(m<qr) ans=max(ans,qmax(u<<1|1,m+1,cr,ql,qr));
      return ans;
    }
  }
}sg;

int main(void){
  scanf("%d",&n); getchar();
  sg.build(1,1,n);
  int ch;
  FOR(i,0,n){
    ch = getchar();
    if(ch=='('){
      if(s[cur]==')'){
        sg.add(1,1,n,cur,n,2);
      }else if(s[cur]!='('){
        sg.add(1,1,n,cur,n,1);
      }
      s[cur] = '(';
    }else if(ch==')'){
      if(s[cur]=='('){
        sg.add(1,1,n,cur,n,-2);
      }else if(s[cur]!=')'){
        sg.add(1,1,n,cur,n,-1);
      }
      s[cur] = ')';
    }else if(isupper(ch)){
      if(ch=='R') ++cur;
      else cur = max(cur-1, 1);
    }else{  // isalpha
      if(s[cur]=='('){
        sg.add(1,1,n,cur,n,-1);
      }else if(s[cur]==')'){
        sg.add(1,1,n,cur,n,1);
      }
      s[cur] = ch;
    }
#ifdef DEBUG
    printf("** %d **\n",cur);
#endif

    int tmin = sg.qmin(1,1,n,1,n);
    if(tmin < 0 || sg.sum(1,1,n,n,n)!=0){
      printf("-1 ");
    }else{
      int tmax = sg.qmax(1,1,n,1,n);
      printf("%d ",tmax);
    }
  }
  putchar('\n');

  return 0;
}
