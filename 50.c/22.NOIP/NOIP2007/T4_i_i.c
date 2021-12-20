/*
描述
帅帅经常更同学玩一个矩阵取数游戏：对于一个给定的n*m的矩阵，矩阵中的每个元素aij据为非负整数。游戏规则如下：
  1. 每次取数时须从每行各取走一个元素，共n个。m次后取完矩阵所有的元素；
  2. 每次取走的各个元素只能是该元素所在行的行首或行尾；
  3. 每次取数都有一个得分值，为每行取数的得分之和；每行取数的得分 = 被取走的元素值*2^i，其中i表示第i次取数（从1开始编号）；
  4. 游戏结束总得分为m次取数得分之和。
帅帅想请你帮忙写一个程序，对于任意矩阵，可以求出取数后的最大得分。

格式
输入格式
包括n+1行；
第一行为两个用空格隔开的整数n和m。
第2~n+1行为n*m矩阵，其中每行有m个用单个空格隔开
l<=n，m<=80，0<=aij<=1000

输出格式
仅包含1行，为一个整数，即输入矩阵取数后的最大的分。

样例1
样例输入1
2 3
1 2 3
3 4 2

样例输出1
82

限制
1s

提示
60%的数据满足：1<=n,m<=30,答案不超过10^16
100%的数据满足：1<=n,m<=80,0<=a<=1000 
*/

/*
  得分：20
  解题报告：（考后）
    考试时最先想到的是贪心，当时感觉“正确性显然”，又写了高精，然后就得了20分。。。看来贪心还是一定要证明的（然而我不会。。。）
    贪心能撞对一部分解，但当数量大了就很难得到正确解。
    反例：
      对于行：6 0 5 6 4 5
      最优解为 6 0 5 4 5 6，答案为660
      而贪心得 5 4 6 0 5 4，答案为499
    正解：
      如果使用搜索，时间复杂度太大，想到使用动规。
      想到每次操作都只对一行有影响，每一行是相对独立的，因此可以依次求解出每一行的最优解，然后求和即可。
      如果令 f(i) 表示取了i个数得到的最优解，不能由单一的i反向推出状态（即状态不确定），因此要再增加一维。
      令 f(i,j) 表示在某一行，取出i个数，其中有j个是从左边取的，那么从右边取的即为i-j个，可以确定状态，得到：
        f(i,j) = min{ f(i-1,j-1) + a[k][front]*2^i, f(i-1,j) + a[k][back]*2^i }
          其中 front 为进行完 f(i-1,j-1) 操作的最左边的数的位置，back 为进行完 f(i-1,j) 操作的最右边的数的位置。
          可以根据行的长度m得到：
            front(i,j) = i
            back(i,j) = m-i-(i-j)
      这样就可以递推出答案，最后再写一下高精即可。
    优化：
      因为 2^i 被多次求到，可以事先预处理出 2^(0:80)，对于较大的m,n有很好的效果。
      可以使用滚动数组减少空间复杂度：
        令 f[100]，可得：
          for(i 1:m) for(j i:0)
            if(j<i) f[j]+=a[k][back(i-1,j)]*2^i
            if(j) f[j]=max(f[j], f[j-1]+a[k][front(i-1,j-1)]*2^i)
  教训：
    考场上用贪心很危险，除非可以证明 -_-
    实在不行，分点答题，能暴力点的用暴力，不能暴力的点用不确定的算法。
*/

//滚动数组（高精）
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

typedef long long unsigned LLU;
const int BASE=100000000;
const int WIDTH=8;
struct BI{
  int len;
  vector<int> v;

  BI() {len=1; v.push_back(0);}
  BI(int n) {len=1; v.push_back(n);}
}zero,one,two,f[100],p2[84];
int a[100][100];
int n,m;

BI ADD(BI a, BI b);
BI MUL(BI a, BI b);
BI MUL(BI a, int b);
BI pow(BI a, int n);
void print(const BI & a);
int compare(const BI & a, const BI & b);
inline int getFront(int i, int j) {return j;}
inline int getBack(int i, int j) {return m-1-(i-j);}

int main(void){
  one.v[0]=1; two.v[0]=2; p2[0]=one; p2[1]=two;
  for(int i=2;i<=80;i++) p2[i]=MUL(p2[i-1],2);
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);

  BI ans;
  for(int k=0;k<n;k++){
    for(int i=0;i<100;i++) {f[i].len=1; f[i].v.clear(); f[i].v.push_back(0);}
    for(int i=1;i<=m;i++){
      for(int j=i;j>=0;j--){
        if(j<i) f[j] = ADD(f[j],MUL(p2[i],a[k][getBack(i-1,j)]));
        if(j){
          BI t=ADD(f[j-1],MUL(p2[i],a[k][getFront(i-1,j-1)]));
          if(compare(f[j],t)<0) f[j]=t;
        }
      }
    }
    BI tMax;
    for(int i=0;i<=m;i++) if(compare(f[i],tMax)>0) tMax=f[i];
    ans=ADD(ans,tMax);
  }
  print(ans); printf("\n");

  return 0;
}

BI ADD(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
  int carry=0;
  for(int i=0;i<a.len;i++){
    a.v[i]+=carry;
    if(i<b.len) a.v[i]+=b.v[i];
    carry=a.v[i]/BASE; a.v[i]%=BASE;
  }
  if(carry) a.v.push_back(carry),a.len++;
  return a;
}
BI MUL(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
  BI res;
  for(int i=0;i<b.len;i++){
    BI t=MUL(a,b.v[i]); vector<int> tv;
    for(int j=0;j<i;j++) tv.push_back(0);
    for(int j=0;j<t.len;j++) tv.push_back(t.v[j]);
    t.v=tv; t.len=tv.size();
    res=ADD(res,t);
  }
  return res;
}
BI MUL(BI a, int b){
  if(b==0) return zero;
  int carry=0; LLU ans=0;
  for(int i=0;i<a.len;i++){
    ans=1LL*a.v[i]*b+carry;
    a.v[i]=ans%BASE; carry=ans/BASE;
  }
  if(carry) a.v.push_back(carry),a.len++;
  return a;
}
BI pow(BI a, int n){
  if(n==0) return one;
  else if(n==1) return a;
  BI ans=pow(a,n/2);
  ans=MUL(ans,ans);
  if(n&1) ans=MUL(ans,a);
  return ans;
}
void print(const BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
}
int compare(const BI & a, const BI & b){
  if(a.len!=b.len) return a.len-b.len;
  else for(int i=a.len-1;i>=0;i--) if(a.v[i]!=b.v[i]) return a.v[i]-b.v[i];
  return 0; //<b></b>
}

/*
//滚动数组（单精）
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long unsigned LLU;
int a[100][100];
LLU f[100];
int n,m;

inline int getFront(int i, int j){
  return j;
}
inline int getBack(int i, int j){
  return m-1-(i-j);
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);

  LLU ans=0;
  for(int k=0;k<n;k++){
    memset(f,0,sizeof(f));
    for(int i=1;i<=m;i++){
      for(int j=i;j>=0;j--){
        if(j<i) f[j]+=1LL*a[k][getBack(i-1,j)]*(1<<i);
        if(j) f[j]=max(f[j],f[j-1]+1LL*a[k][getFront(i-1,j-1)]*(1<<i));
      }
    }
    LLU tMax=0;
    for(int i=0;i<=m;i++) tMax=max(tMax,f[i]);
    ans+=tMax;
  }
  printf("%llu\n",ans);

  return 0;
}
*/

/*
//动规（单精）
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long unsigned LLU;
int a[100][100];
LLU f[100][100];
int n,m;

inline int getFront(int i, int j){
  return j;
}
inline int getBack(int i, int j){
  return m-1-(i-j);
}

int main(void){
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&a[i][j]);

  LLU ans=0;
  for(int k=0;k<n;k++){
    memset(f,0,sizeof(f));
    for(int i=1;i<=m;i++){
      for(int j=i;j>=0;j--){
        if(j<i) f[i][j]=f[i-1][j]+1LL*a[k][getBack(i-1,j)]*(1<<i);  //<b>在进行计算时要先将a转化为LLU</b>
        if(j) f[i][j]=max(f[i][j],f[i-1][j-1]+1LL*a[k][getFront(i-1,j-1)]*(1<<i));
      }
    }
    LLU tMax=0;
    for(int i=0;i<=m;i++) tMax=max(tMax,f[m][i]);
    ans+=tMax;
  }
  printf("%llu\n",ans);

  return 0;
}
*/

/*
//贪心（错误）
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

typedef long long unsigned LLU;
deque<int> q[100];
int n,m;

int main(void){
  scanf("%d%d",&n,&m);
  int t;
  for(int i=0;i<n;i++) for(int j=0;j<m;j++){
    scanf("%d",&t); q[i].push_back(t);
  }
  LLU sum=0;
  for(int j=1;j<=m;j++){
    LLU tot=0;
    for(int i=0;i<n;i++){
      if(q[i].front() > q[i].back()) {tot+=q[i].back(); q[i].pop_back();}
      else {tot+=q[i].front(); q[i].pop_front();}
    }
    sum+=tot*(1<<j);
  }
  printf("%llu\n",sum);

  return 0;
}
*/
