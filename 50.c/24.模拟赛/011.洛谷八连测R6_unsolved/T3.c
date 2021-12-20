#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=200020;
const int MOD=1000000007;
int n,m,a[MAX];
struct ST{
  int n,addVal;
}st[MAX<<2];

void build(int root, int L, int R);
void pushDown(int root, int L, int R);
void add(int root, int cL, int cR, int aL, int aR, int addVal);
int sum(int root, int cL, int cR, int qL, int qR);

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  build(1,1,n);
  int type,l,r,x,y,z;
  FOR(i,0,m){
    scanf("%d",&type);
    if(type==1){
      scanf("%d%d%d",&x,&y,&z);
      if(x==1){
        add(1,1,n,y,n,z);
      }else while(y<=n){
        add(1,1,n,y,y,z); y+=x;
      }
    }else{
      scanf("%d%d",&l,&r);
      printf("%d\n",sum(1,1,n,l,r));
    }
  }

  return 0;
}

void build(int root, int L, int R){
  if(L==R) {st[root].n=a[L]; return;}
  int M=(L+R)>>1;
  build(root<<1,L,M); build(root<<1|1,M+1,R);
  st[root].n=(st[root<<1].n+st[root<<1|1].n)%MOD;
}
void pushDown(int root, int L, int R){
  if(!st[root].addVal) return;
  int M=(L+R)>>1;
  ST &t=st[root],&l=st[root<<1],&r=st[root<<1|1];
  l.addVal = (l.addVal + t.addVal)%MOD;
  l.n = (l.n + 1LL*(M-L+1)*t.addVal)%MOD;
  r.addVal = (r.addVal + t.addVal)%MOD;
  r.n = (r.n + 1LL*(R-M)*t.addVal)%MOD;
  t.addVal=0;
}
void add(int root, int cL, int cR, int aL, int aR, int addVal){
  if(cL>aR || cR<aL) return;
  if(cL>=aL && cR<=aR){
    st[root].addVal = (st[root].addVal+addVal)%MOD;
    st[root].n = (st[root].n + 1LL*(cR-cL+1)*addVal)%MOD;
    return;
  }
  pushDown(root,cL,cR);
  int M=(cL+cR)>>1;
  add(root<<1,cL,M,aL,aR,addVal);
  add(root<<1|1,M+1,cR,aL,aR,addVal);
  st[root].n = (st[root<<1].n+st[root<<1|1].n)%MOD;
}
int sum(int root, int cL, int cR, int qL, int qR){
  if(cL>qR || cR<qL) return 0;
  if(cL>=qL && cR<=qR) return st[root].n;
  pushDown(root,cL,cR);
  int M=(cL+cR)>>1;
  return (sum(root<<1,cL,M,qL,qR) + sum(root<<1|1,M+1,cR,qL,qR))%MOD;
}
