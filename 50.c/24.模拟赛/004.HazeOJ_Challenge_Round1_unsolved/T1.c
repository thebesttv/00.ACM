#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100020;
const int MOD=(1e9)+7;
struct SG{
  int sum;
  int addV;
  int l,r;
}sg[MAX<<2];

void build(int root, int l, int r);
void add(int root, int ul, int ur, int v);
int sum(int root, int ql, int qr);
void pushDown(int root);
void pushUp(int root);

int main(void){
  int m; scanf("%d",&m);
  build(1,0,50000);
  int type,l,r,n,a[12];
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&type,&l,&r);
    if(type==1){
      scanf("%d",&n);
      for(int j=0;j<=n;j++) scanf("%d",&a[j]);
      if(n==0) add(1,l,r-1,a[0]);
    }else{
      printf("%d\n",sum(1,l,r-1));
    }
  }

  return 0;
}

void build(int root, int l, int r){
  sg[root].l=l, sg[root].r=r;
  if(l==r) return;
  int m=l+r>>1;
  build(root<<1,l,m); build(root<<1|1,m+1,r);
}
void add(int root, int ul, int ur, int v){
  int cl=sg[root].l,cr=sg[root].r;
  if(ul<=cl && ur>=cr){
    (sg[root].sum += v*(cr-cl+1))%=MOD;
    (sg[root].addV+=v)%=MOD;
    return;
  }
  pushDown(root);
  int m=cl+cr>>1;
  if(ul<=m) add(root<<1,ul,ur,v);
  if(ur>m) add(root<<1|1,ul,ur,v);
  pushUp(root);
}
int sum(int root, int ql, int qr){
  int cl=sg[root].l,cr=sg[root].r;
  if(ql<=cl && qr>=cr) return sg[root].sum;
  pushDown(root);
  int m=cl+cr>>1;
  if(qr<=m) return sum(root<<1,ql,qr);
  else if(ql>m) return sum(root<<1|1,ql,qr);
  else return ((long long)(sum(root<<1,ql,qr)+sum(root<<1|1,ql,qr)))%MOD;
}
void pushDown(int root){
  int & v=sg[root].addV;
  if(v){
    (sg[root<<1].addV+=v)%=MOD;
    (sg[root<<1|1].addV+=v)%=MOD;
    (sg[root<<1].sum += 1LL*v*(sg[root<<1].r-sg[root<<1].l+1))%=MOD;
    (sg[root<<1|1].sum = 1LL*v*(sg[root<<1|1].r-sg[root<<1|1].l+1))%=MOD;
    v=0;
  }
}
void pushUp(int root){
  sg[root].sum = (sg[root<<1].sum+sg[root<<1|1].sum)%MOD;
}

/*
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100020;
const int MOD=(1e9)+7;
const int EPS=1e5;
struct SG{
  int v,a;
  float sum;  //??
  int addV,addA;
  int l,r;
}sg[MAX<<2];

void build(int root, int l, int r);
void add(int root, int ul, int ur, int v, int a);
float sum(int root, int ql, int qr);
void pushDown(int root);
void pushUp(int root);

int main(void){
  int m; scanf("%d",&m);
  build(1,0,50000);
  int type,l,r,n,a[12];
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&type,&l,&r);
    if(type==1){
      scanf("%d",&n);
      for(int j=0;j<=n;j++) scanf("%d",&a[j]);
      if(n==0) add(1,l,r,a[0],0);
      else if(n==1) add(1,l,r,a[0],a[1]);
    }else{
      float t=sum(1,l,r);
      printf("%d\n",(int)((long long)t%MOD));
    }
  }

  return 0;
}

void build(int root, int l, int r){
  sg[root].l=l, sg[root].r=r;
  if(l==r) return;
  int m=l+r>>1;
  build(root<<1,l,m); build(root<<1|1,m+1,r);
}
void add(int root, int ul, int ur, int v, int a){
  int cl=sg[root].l,cr=sg[root].r;
  if(ul<=cl && ur>=cr){
    int t=cl-ul;
    (sg[root].v+=v+t*a)%=MOD; (sg[root].a+=a)%=MOD;
    sg[root].sum = sg[root].v*t + sg[root].a*t*t/2.0; //
    (sg[root].addV+=v+t*a)%=MOD;
    return;
  }
  pushDown(root);
  int m=cl+cr>>1;
  if(ul<=m) add(root<<1,ul,ur,v,a);
  if(ur>m) add(root<<1|1,ul,ur,v,a);
  pushUp(root);
}
float sum(int root, int ql, int qr){
  int cl=sg[root].l,cr=sg[root].r;
  if(ql<=cl && qr>=cr) return sg[root].sum;
  int m=cl+cr>>1;
  if(qr<=m) return sum(root<<1,ql,qr);
  else if(ql>m) return sum(root<<1|1,ql,qr);
  else return ((long long)(sum(root<<1,ql,qr)+sum(root<<1|1,ql,qr)))%MOD;
}
void pushDown(int root){
  int & v=sg[root].addV;
  int & a=sg[root].addA;
  if(v){
    int t=sg[root<<1|1].l-sg[root].l;
    (sg[root<<1].v+=v)%=MOD;
    (sg[root<<1|1].v += sg[root].a*t+v)%=MOD;
    t=sg[root<<1].r-sg[root<<1].l;
    sg[root<<1].sum = sg[root<<1].v*t + sg[root<<1].a*t*t/2.0;
    t=sg[root<<1|1].l-sg[root].l;
    sg[root<<1|1].sum = sg[root<<1|1].v*t + sg[root<<1|1].a*t*t/2.0;
    v=0;
  }
  if(a){
    int t=sg[root<<1|1].l-sg[root].l;
    (sg[root<<1].v+=v)%=MOD;
    (sg[root<<1|1].a+=a)%=MOD;
    t=sg[root<<1].r-sg[root<<1].l;
    sg[root<<1].sum = sg[root<<1].v*t + sg[root<<1].a*t*t/2.0;
    t=sg[root<<1|1].l-sg[root].l;
    sg[root<<1|1].sum = sg[root<<1|1].v*t + sg[root<<1|1].a*t*t/2.0;
    a=0;
  }
}
void pushUp(int root){
  sg[root].sum = (float)((long long)(sg[root<<1].sum+sg[root<<1|1].sum)%MOD);
}
*/
