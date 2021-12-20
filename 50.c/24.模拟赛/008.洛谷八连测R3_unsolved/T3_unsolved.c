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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

typedef long long LL;
const int MAX=500020;
int MOD;
int n,m,a[MAX];
struct ST{
  int n,addVal;
}st[MAX<<2];

void build(int root, int L, int R);
void pushDown(int root);
void add(int root, int cL, int cR, int aL, int aR, int addVal);
int sum(int root, int cL, int cR, int n);
int pow(int n, int a);

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  build(1,1,n);

  int type,l,r,x;
  FOR(i,0,m){
    scanf("%d%d%d",&type,&l,&r);
    if(type==1){
      scanf("%d",&x); add(1,1,n,l,r,x);
    }else{
      scanf("%d",&MOD);
      int ans=sum(1,1,n,r)%MOD;
      ROR(j,r-1,l){
#ifdef DEBUG
        printf("  %d ^ %d %% %d = %d\n",sum(1,1,n,j),ans,MOD,pow(sum(1,1,n,j),ans));
#endif
        ans=pow(sum(1,1,n,j)%MOD,ans);
      }
      printf("%d\n",ans);
    }
  }

  return 0;
}

void build(int root, int L, int R){
  if(L==R) {st[root].n=a[L]; return;}
  int M=(L+R)>>1;
  build(root<<1,L,M); build(root<<1|1,M+1,R);
}
void pushDown(int root){
  if(!st[root].addVal) return;
  if(st[root<<1].n) st[root<<1].n+=st[root].addVal;
  st[root<<1].addVal+=st[root].addVal;
  if(st[root<<1|1].n) st[root<<1|1].n+=st[root].addVal;
  st[root<<1|1].addVal+=st[root].addVal;
  st[root].addVal=0;
}
void add(int root, int cL, int cR, int aL, int aR, int addVal){
  if(cL>aR || cR<aL) return;
  if(cL>=aL && cR<=aR){
    st[root].n+=addVal; st[root].addVal+=addVal;
    return;
  }
  pushDown(root);
  int M=(cL+cR)>>1;
  if(aL<=M) add(root<<1,cL,M,aL,aR,addVal);
  if(aR>M) add(root<<1|1,M+1,cR,aL,aR,addVal);
}
int sum(int root, int cL, int cR, int n){
  if(cL>n || cR<n) return 0;
  if(cL==n && cR==n) return st[root].n;
  pushDown(root);
  int M=(cL+cR)>>1;
  if(n<=M) return sum(root<<1,cL,M,n);
  else return sum(root<<1|1,M+1,cR,n);
}
int pow(int n, int a){
  if(!a) return 1;
  else if(a==1) return n%MOD;
  int ans=pow(n,a/2);
  ans = 1LL*ans*ans%MOD;
  if(a&1) ans = 1LL*ans*n%MOD;
  return ans;
}
