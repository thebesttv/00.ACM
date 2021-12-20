/*
题目描述
悬浮大陆群边境地带68号岛，妖精仓库。
在威廉的面前有着数不清的护符，这些护符的功能值从0到(2^30)-1，且每种功能值的护符都可以多次使用。为了调整圣剑，迎战接下来的巨大的六号兽，为了让珂朵莉能够在那场战斗中存活下来，他需要用这些护符重新恢复瑟尼欧尼斯。
这个拼接的过程首先将n个护符排成一排。
圣剑是由无数护符用咒力线相连，产生复杂的作用之后形成的强大武器。这排护符需要满足全部的m个条件才能被称为是真正的“瑟尼欧尼斯”。
第i个条件为将第li个护符的功能值 Xli 按顺序按位或上第 li+1, li+2, ..., ri 个护符的功能值 Xli+1, Xli+2, ..., Xri 后的结果需为pi。
大战即将来临，珂朵莉能否击败前所未闻的巨大的六号兽，最后平安的回到妖精仓库，取决于您能否快速的完成这个计算了。
《NOIP时在做什么？有没有空？可以来AK吗？》

输入输出格式
输入格式：
第一行两个整数n,m。接下来m行每行三个整数li,ri,pi

输出格式：
如果存在这样的护符序列x，第一行输出Yes，第二行输出n个不超过(2^30)−1的非负整数表示x1, x2, ..., xn（如果有多种方案，你可以输出任意一种），否则输出一行No。

输入输出样例
输入样例#1：
2 1
1 2 1

输出样例#1：
Yes
1 1

说明
对于30%的数据，n,m<=1000
对于另外30%的数据，pi<=1
对于100%的数据，n,m<=100000, 1<=li<=ri<=n, 0<=pi<2^30 。
*/

/*
  得分：60
  解题报告：
    题目要求的就是一个长为n的序列，使得对每个问题i，区间[li,ri]上所有元素的or为pi。
    想到可以先令序列都为(2^30)-1，然后对每个区间[li,ri]中的元素都与上pi，这样就可以最大限度地保证能够满足答案。但与完后，还要检查最后的答案是否满足所有的规则。
    如果使用普通的遍历操作，复杂度为O(m*n)，太大，要优化O(n)的遍历操作。
    一开始我想用差分，结果怎么都弄不出来，于是就60分了。
  正解：
    使用线段树优化。
  更好的解：
    用ZKW线段树优化。。。
*/

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

//网络，ZKW线段树
#define N 100005
int f[N<<2],l[N],r[N],x[N];

void add(int id,int l,int r,int L,int R,int v){
  if(L<=l&&r<=R) {f[id]&=v; return;}
  int mid=(l+r)>>1;
  if(L<=mid) add(id<<1,l,mid,L,R,v);
  if(R>mid) add(id<<1|1,mid+1,r,L,R,v);
}
int sum(int id,int l,int r,int L,int R){
  if(L<=l&&r<=R) return f[id];
  int mid=(l+r)>>1;
  int p=0;
  if(L<=mid) p|=sum(id<<1,l,mid,L,R);
  if(R>mid) p|=sum(id<<1|1,mid+1,r,L,R);
  return p;
}
int main(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++) scanf("%d%d%d",&l[i],&r[i],&x[i]);
  int k;
  for(k=1;k<n;k<<=1);
  for(int i=1;i<k*2;i++) f[i]=(1<<30)-1;

  for(int i=0;i<m;i++) add(1,1,k,l[i],r[i],x[i]);
  for(int i=1;i<k;i++){
    f[i<<1]&=f[i]; f[i<<1|1]&=f[i];
  }
  for(int i=k-1;i>0;i--)
    f[i]|=f[i<<1]|f[i<<1|1];
  int i;
  for(i=0;i<m;i++) if(sum(1,1,k,l[i],r[i])!=x[i]) break;

  if(i<m)printf("No\n");
  else{
    printf("Yes\n");
    for(int i=0;i<n;i++) printf("%d ",f[i+k]);
    printf("\n");
  }
  return 0;
}

/*
//线段树
const int MAX=100020;
const int ORI=(1<<30)-1;
struct Quest{
  int l,r,p;
}Q[MAX];
struct ST{
  int S,andVal;  //S: "or" of a[l:r]
  int l,r;
}st[MAX<<2];
int n,m;

void build(int root, int l, int r); //set a[l:r] to (1<<30)-1
void setAnd(int root, int cl, int cr, int andVal);
void pushDown(int root);
int getOr(int root, int ql, int qr);

int main(void){
  scanf("%d%d",&n,&m);
  build(1,1,n);
  FOR(i,0,m){
    scanf("%d%d%d",&Q[i].l,&Q[i].r,&Q[i].p);
    setAnd(1,Q[i].l,Q[i].r,Q[i].p);
  }
  bool ok=1;
  FOR(i,0,m){
    int t=getOr(1,Q[i].l,Q[i].r);
    if(t!=Q[i].p) {ok=0; break;}
  }
  if(ok){
    printf("Yes\n");
    printf("%d",getOr(1,1,1));
    FORR(i,2,n) printf(" %d",getOr(1,i,i)); printf("\n"); //to be improved
  }else printf("No\n");

  return 0;
}

void build(int root, int l, int r){ //set a[l:r] to (1<<30)-1
  st[root].l=l; st[root].r=r;
  st[root].S=ORI; st[root].andVal=ORI;
  if(l==r) return;
  int m=l+((r-l)>>1);
  build(root<<1,l,m); build(root<<1|1,m+1,r);
}
void setAnd(int root, int cl, int cr, int andVal){
  int l=st[root].l,r=st[root].r;
  if(l>cr || r<cl) return; //no overlap
  if(l>=cl && r<=cr){ //full overlap
    st[root].S&=andVal;
    st[root].andVal&=andVal;
    return;
  }
  //partial overlap
  pushDown(root);
  setAnd(root<<1,cl,cr,andVal); setAnd(root<<1|1,cl,cr,andVal);
  st[root].S=st[root<<1].S | st[root<<1|1].S;
}
void pushDown(int root){
  if(st[root].andVal==ORI) return;
  int lc=root<<1,rc=root<<1|1,andVal=st[root].andVal;
  st[lc].S&=andVal; st[lc].andVal&=andVal;
  st[rc].S&=andVal; st[rc].andVal&=andVal;

  st[root].andVal=ORI;
}
int getOr(int root, int ql, int qr){
  int l=st[root].l,r=st[root].r;
  if(l>qr || r<ql) return 0;
  if(l>=ql && r<=qr) return st[root].S;
  pushDown(root); //???
  return getOr(root<<1,ql,qr) | getOr(root<<1|1,ql,qr);
}
*/
