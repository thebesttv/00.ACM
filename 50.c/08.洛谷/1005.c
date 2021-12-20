/*
题目描述
帅帅经常跟同学玩一个矩阵取数游戏：对于一个给定的 n*m 的矩阵，矩阵中的每个元素 aij 均为非负整数。游戏规则如下：
  1.每次取数时须从每行各取走一个元素，共n个。m次后取完矩阵所有元素；
  2.每次取走的各个元素只能是该元素所在行的行首或行尾；
  3.每次取数都有一个得分值，为每行取数的得分之和，每行取数的得分 = 被取走的元素值*2^i，其中i表示第i次取数（从1开始编号）；
  4.游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

输入输出格式
输入格式：
输入文件game.in包括n+1行：
第1行为两个用空格隔开的整数n和m。
第2~n+1行为n*m矩阵，其中每行有m个用单个空格隔开的非负整数。

输出格式：
输出文件game.out仅包含1行，为一个整数，即输入矩阵取数后的最大得分。

输入输出样例
输入样例#1：
2 3
1 2 3
3 4 2
输出样例#1：
82

数据范围：
60%的数据满足：1<=n, m<=30，答案不超过10^16
100%的数据满足：1<=n, m<=80，0<=aij<=1000

说明
NOIP2007 提高T3
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

//滚动数组（高精）
const int MAX_LEN=500;
struct BI{
  int len;
  int v[MAX_LEN];

  BI() {MST(v,0); len=0;}
  BI::BI(char * s){
    MST(v,0); len=strlen(s);
    FOR(i,0,len) v[i]=s[len-i-1]-'0';
  }
  BI::BI(int n){
    MST(v,0); len=0;
    while(n) {v[len++]=n%10; n/=10;}
  }
  void print();
}zero(0),one(1),two(2),f[100],p2[84],a[100];
int n,m;

BI add(const BI & a, const BI & b);
BI sub(const BI & a, const BI & b);
BI mul(const BI & a, const BI & b);

bool operator < (const BI & a, const BI & b) {
  if(a.len!=b.len) return a.len<b.len;
  ROR(i,a.len-1,0) if(a.v[i]!=b.v[i])
    return a.v[i]<b.v[i];
  return false;
}
bool operator > (const BI & a, const BI & b) {return b<a;}
bool operator <= (const BI & a, const BI & b) {return !(b<a);}
bool operator >= (const BI & a, const BI & b) {return !(a<b);}
bool operator == (const BI & a, const BI & b) {return !(a<b) && !(b<a);}
bool operator != (const BI & a, const BI & b) {return a<b || b<a;}

int main(void){
  p2[0]=one; p2[1]=two;
  for(int i=2;i<=80;i++) p2[i]=mul(p2[i-1],two);

  scanf("%d%d",&n,&m);
  BI ans=zero;
  FOR(i,0,n){
    FORR(j,0,m) f[j]=zero;
    for(int j=0,t;j<m;j++) {scanf("%d",&t); a[j]=BI(t);}
    f[1]=mul(two,a[0]);
    f[0]=mul(two,a[m-1]);
    FORR(t,2,m) ROR(l,t,0){
      f[l] = add(f[l],mul(p2[t],a[m-(t-l)]));
      if(l){
        BI tmp=add(f[l-1],mul(p2[t],a[l-1]));
        if(tmp>f[l]) f[l]=tmp;
      }
    }
    BI ansMax=zero;
    FORR(j,0,m) if(f[j]>ansMax) ansMax=f[j];
    ans=add(ans,ansMax);
  }
  ans.print(); putchar('\n');

  return 0;
}

void BI::print(){
  if(!len) return;
  ROR(i,len-1,0) putchar(v[i]+'0');
}
BI add(const BI & a, const BI & b){
  BI c;
  int len=max(a.len,b.len);
  int carry=0;
  FOR(i,0,len){
    c.v[i]=a.v[i]+b.v[i]+carry;
    carry=c.v[i]/10; c.v[i]%=10;
  }
  if(carry) c.v[len++]=carry;
  c.len=len;
  return c;
}
BI sub(const BI & a, const BI & b){
  BI c=a;
  int len=a.len;
  FOR(i,0,len){
    if(c.v[i]<b.v[i]) {c.v[i]+=10; c.v[i+1]--;}
    c.v[i]-=b.v[i];
  }
  while(len>1 && !c.v[len-1]) len--;
  c.len=len;
  return c;
}
BI mul(const BI & a, const BI & b){
  BI c;
  FOR(i,0,a.len) FOR(j,0,b.len){
    c.v[i+j]+=a.v[i]*b.v[j];
  }
  int len=a.len+b.len;
  FOR(i,0,len){
    c.v[i+1]+=c.v[i]/10;
    c.v[i]%=10;
  }
  while(len>1 && !c.v[len-1]) len--;
  c.len=len;
  return c;
}
