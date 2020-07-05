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

const int MAX=100020;
int n,q; char s[MAX];

struct SetTree{
  int node[MAX<<2];

  void pushUp(int u){
    node[u] = node[u<<1] | node[u<<1|1];
  }
  void build(int u, int cl, int cr){
    if(cl==cr){
      node[u]=1<<(s[cl]-'a');
    }else{
      int m=(cl+cr)>>1;
      build(u<<1,cl,m);
      build(u<<1|1,m+1,cr);
      pushUp(u);
    }
  }
  void set(int u, int cl, int cr, int ql, int qr, int v){
    if(ql<=cl && cr<=qr){
      node[u] = v;
    }else{
      int m=(cl+cr)>>1;
      if(ql<=m) set(u<<1,cl,m,ql,qr,v);
      if(m<qr) set(u<<1|1,m+1,cr,ql,qr,v);
      pushUp(u);
    }
  }
  int sum(int u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr){
      return node[u];
    }else{
      int m=(cl+cr)>>1; int ans=0;
      if(ql<=m) ans=sum(u<<1,cl,m,ql,qr);
      if(m<qr) ans|=sum(u<<1|1,m+1,cr,ql,qr);
      return ans;
    }
  }
}sg;

int main(void){
  scanf("%s%d",s+1,&q);
  n = strlen(s+1);
  sg.build(1,1,n);

  int op,pos,l,r,ch;
  while(q--){
    scanf("%d",&op);
    if(op==1){
      scanf("%d",&pos);
      do ch=getchar(); while(!isalpha(ch));
      sg.set(1,1,n,pos,pos, 1<<(ch-'a'));
    }else{
      scanf("%d%d",&l,&r);
      int sum = sg.sum(1,1,n,l,r);
      int cnt=0;
      while(sum){
        if(sum&1) cnt++;
        sum>>=1;
      }
      printf("%d\n",cnt);
    }
  }

  return 0;
}
