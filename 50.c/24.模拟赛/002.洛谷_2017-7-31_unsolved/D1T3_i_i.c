/*
题目背景
大芳有一个不太好的习惯：在车里养青蛙。青蛙在一个n厘米（11n毫米s）的Van♂ 杆子上跳来跳去。她时常盯着青蛙看，以至于突然逆行不得不开始躲交叉弹。有一天他突发奇想，在杆子上每1厘米为一个单位，瞎涂上了墨水，并且使用mOgic，使青蛙跳过之处墨水浓度增加x。当然，他还会闲着无聊滴几滴墨水再涂♂抹均匀。
他现在无时无刻都想知道，第l厘米到第r厘米墨水的浓度是多少？
哦不!等等，他现在找到了一个计算器，可以输入几个数字与x，计算他们的<b> x次幂和</b>，所以。。。他想知道的是第l厘米到第r厘米墨水的浓度的x次幂和是多少？

题目描述
大芳有3种舰长技能骚操作
1.续：把青蛙放到第l厘米处，戳青蛙使其跳至r。效果：第l厘米至第r厘米墨水浓度增加x
2.抚♂ 摸：擦干杆子某一部分，重新滴加墨水并抹匀。效果：使第l厘米至第r厘米墨水浓度都变成x
3.最后一种是：
  压线逆行，将车流看做⑨ 弹幕找安定点，掏出计算器，大喊板载后计算：
  第l厘米至第r厘米墨水浓度的<b> x 次幂和</b>是几何？记得答案要模1000000007

输入输出格式
输入格式：
第一行n和m，表示杆子长n厘米，大芳要进行m次骚操作。
第二行n个数字，表示初始墨水浓度。第i个数字为第i厘米墨水浓度
接下来每行4个数字，依次为：操作编号（1、2或3），l,r,x

输出格式：
每次进行3操作，输出一行表示答案
记得膜模1000000007

输入输出样例
输入样例#1：
5 5
19844 14611 26475 4488 6967
2 1 3 15627
2 1 2 30113
2 3 5 14686
2 5 5 32623
3 1 2 8

输出样例#1：
466266421

说明
k表示询问的幂的大小，也就是操作3对应的x。
对于20%的数据，满足n,m≤1000n
对于另外20%的数据，满足k≤1
对于另外20%的数据，满足k≤2
对于另外20%的数据，满足n,m≤50000n
对于100%的数据，满足n,m≤100000,0≤k≤10
操作1，2对应的x≤10^9 + 7
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100000+20;
const int MOD=1000000007;
struct Node{
  int sum[11];
  int addMark,setMark;
  int l,r;
}st[MAX<<2];
int a[MAX];
int Cnk[11][11];

void build(int root, int * a, int l, int r);
void add(int root, int l, int r, int addVal);
void set(int root, int l, int r, int setVal);
void add_(int root, int addVal);
void set_(int root, int setVal);
void pushDown(int root);
void pushUp(int root);
int sum(int root, int l, int r, int k);

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
  freopen("out","w",stdout);
#endif
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  //Cnk
  Cnk[0][0]=1;
  for(int i=1;i<=10;i++){
    Cnk[i][0]=Cnk[i][i]=1;
    for(int j=1;j<i;j++) Cnk[i][j]=(Cnk[i-1][j-1]+Cnk[i-1][j])%MOD;
  }

  build(1,a,1,n);
  int type,l,r,x;
  for(int i=0;i<m;i++){
    scanf("%d%d%d%d",&type,&l,&r,&x);
    if(type==1) add(1,l,r,x);
    else if(type==2) set(1,l,r,x);
    else printf("%d\n",sum(1,l,r,x));
  }

  return 0;
}

void build(int root, int * a, int l, int r){
  st[root].addMark=0; st[root].setMark=-1;
  st[root].l=l; st[root].r=r;
  if(l==r){
    //int v=1;
    //for(int j=0;j<=10;j++){
    //  st[root].sum[j]=v; v=1LL*v*a[l]%MOD;
    //}
    st[root].sum[0]=1;
    for(int j=1;j<=10;j++) st[root].sum[j]=1LL*st[root].sum[j-1]*a[l]%MOD;
    return;
  }
  int m=l+r>>1;
  build(root<<1,a,l,m);
  build(root<<1|1,a,m+1,r);
  pushUp(root);
}
void add(int root, int l, int r, int addVal){
  int cl=st[root].l,cr=st[root].r;
  if(l<=cl && r>=cr){
    add_(root,addVal);
    return;
  }
  pushDown(root);
  int m=cl+cr>>1;
  if(l<=m) add(root<<1,l,r,addVal);
  if(r>m) add(root<<1|1,l,r,addVal);
  pushUp(root);
}
void set(int root, int l, int r, int setVal){
  int cl=st[root].l,cr=st[root].r;
  if(l<=cl && r>=cr){
    set_(root,setVal);
    return;
  }
  pushDown(root);
  int m=cl+cr>>1;
  if(l<=m) set(root<<1,l,r,setVal);
  if(r>m) set(root<<1|1,l,r,setVal);
  pushUp(root);
}
void add_(int root, int addVal){  //?
  for(int j=10;j>=0;j--){
    int sum=0,t=1;
    for(int i=j;i>=0;i--){
      sum = (1LL*st[root].sum[i]*Cnk[j][i]%MOD*t%MOD + sum)%MOD;
      t = 1LL*t*addVal%MOD;
    }
    st[root].sum[j]=sum;
  }
  st[root].addMark=(st[root].addMark+addVal)%MOD; //?
}
void set_(int root, int setVal){
  int t=1,l=st[root].l,r=st[root].r;
  for(int j=0;j<=10;j++){
    st[root].sum[j]=1LL*t*(r-l+1)%MOD;
    t=1LL*t*setVal%MOD;
  }
  st[root].addMark=0;
  st[root].setMark=setVal;
}
void pushDown(int root){
  if(st[root].setMark!=-1){
    int setVal=st[root].setMark;
    set_(root<<1,setVal);
    set_(root<<1|1,setVal);
    st[root].setMark=-1;
    //st[root].addMark=0; //??
  }
  if(st[root].addMark){
    int addVal=st[root].addMark;
    add_(root<<1,addVal);
    add_(root<<1|1,addVal);
    st[root].addMark=0;
  }
}
void pushUp(int root){
  for(int i=0;i<=10;i++)
    st[root].sum[i] = (st[root<<1].sum[i] + st[root<<1|1].sum[i])%MOD;
}
int sum(int root, int l, int r, int k){
  int cl=st[root].l,cr=st[root].r;
  if(l<=cl && r>=cr) return st[root].sum[k];
  pushDown(root); //<b></b> ??
  int m=cl+cr>>1;
  if(r<=m) return sum(root<<1,l,r,k);
  else if(l>m) return sum(root<<1|1,l,r,k);
  else return (sum(root<<1,l,r,k) + sum(root<<1|1,l,r,k))%MOD;
}

/*
  得分：0
*/

/*
#include<iostream>
#include<cstdio>
using namespace std;

typedef unsigned long long LLU;
const int MAX=100000;
const int MOD=1000000007;
int a[MAX];
struct Node{
  unsigned long long sum;
  unsigned long long addMark;
  unsigned long long setMark;
}st[MAX*4];
LLU x;

void build(int root, int * array, int L, int R);
void pushDown(int root, int L, int R);
void set(int root, int cL, int cR, int uL, int uR, LLU setVal);
void add(int root, int cL, int cR, int uL, int uR, LLU addVal);
LLU sum(int root, int cL, int cR, int qL, int qR);
LLU pow_mod(LLU a, int n);

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  build(1,a,1,n);
  int type,l,r;
  for(int i=0;i<m;i++){
    scanf("%d%d%d%llu",&type,&l,&r,&x);
    if(type==1){
      add(1,1,n,l,r,x);
    }else if(type==2){
      set(1,1,n,l,r,x);
    }else{
      LLU s=sum(1,1,n,l,r);
      printf("%llu\n",s);
    }
  }

  return 0;
}

void build(int root, int * array, int L, int R){
  st[root].addMark=0, st[root].setMark=-1;
  if(L==R) st[root].sum=array[L];
  else{
    int M=L+(R-L)/2;
    build(root*2,array,L,M);
    build(root*2+1,array,M+1,R);
    st[root].sum = (st[root*2].sum+st[root*2+1].sum)%MOD;
  }
}
void pushDown(int root, int L, int R){
  int M=L+(R-L)/2;
  if(st[root].setMark!=-1){
    st[root*2].setMark=st[root].setMark;
    st[root*2+1].setMark=st[root].setMark;
    st[root*2].sum = (M-L+1)*st[root].setMark%MOD;
    st[root*2+1].sum = (R-M)*st[root].setMark%MOD;
    st[root].setMark=-1;
    return;
  }
  if(st[root].addMark){
    st[root*2].sum = (st[root*2].sum + (M-L+1)*st[root].addMark) % MOD;
    st[root*2+1].sum = (st[root*2+1].sum + (R-M)*st[root].addMark) % MOD;
    st[root*2].addMark = (st[root*2].addMark + st[root].addMark) % MOD;
    st[root*2+1].addMark = (st[root*2+1].addMark + st[root].addMark) % MOD;
    st[root].addMark=0;
  }
}
void set(int root, int cL, int cR, int uL, int uR, LLU setVal){
  if(uL>cR || uR<cL) return;
  if(uL<=cL && uR>=cR){
    st[root].setMark=setVal;
    st[root].sum = (cR-cL+1)*setVal%MOD;
    return;
  }
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  set(root*2,cL,M,uL,uR,setVal);
  set(root*2+1,M+1,cR,uL,uR,setVal);
  st[root].sum=(st[root*2].sum+st[root*2+1].sum)%MOD;
}
void add(int root, int cL, int cR, int uL, int uR, LLU addVal){
  if(uL>cR || uR<cL) return;
  if(uL<=cL && uR>=cR){
    st[root].addMark+=addVal;
    st[root].sum = (st[root].sum + (cR-cL+1)*addVal) % MOD;
    return;
  }
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  add(root*2,cL,M,uL,uR,addVal);
  add(root*2+1,M+1,cR,uL,uR,addVal);
  st[root].sum=(st[root*2].sum+st[root*2+1].sum)%MOD;
}
LLU sum(int root, int cL, int cR, int qL, int qR){
  LLU a;
  if(qL>cR || qR<cL) a=0;
  else if(cL==cR){
    a=pow_mod(st[root].sum,x);
  }else{
    pushDown(root,cL,cR);
    int M=cL+(cR-cL)/2;
    a = (sum(root*2,cL,M,qL,qR) + sum(root*2+1,M+1,cR,qL,qR))%MOD;
  }
  return a;
}
LLU pow_mod(LLU a, int n){
  if(n==0) return 1;
  else if(n==1) return a%MOD;
  LLU sum_=pow_mod(a,n/2);
  sum_ = sum_*sum_%MOD;
  if(n&1) sum_ = sum_*a%MOD;
  return sum_;
}
*/
