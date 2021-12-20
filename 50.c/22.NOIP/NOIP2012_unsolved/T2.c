/*
描述
恰逢H国国庆，国王邀请n位大臣来玩一个有奖游戏。首先，他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数。然后，让这n位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整得到的结果。 
国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少。注意，国王的位置始终在队伍的最前面。

格式
输入格式
第一行包含一个整数n，表示大臣的人数。 
第二行包含两个整数a和b，之间用一个空格隔开，分别表示国王左手和右手上的整数。接下来n行，每行包含两个整数a和b，之间用一个空格隔开，分别表示每个大臣左手和右手上的整数。

输出格式
输出只有一行，包含一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。

样例1
样例输入1
3 
1 1 
2 3 
7 4 
4 6 

样例输出1
2

限制
每个测试点1s

提示
对于20%的数据，有1≤ n≤ 10，0 < a、b < 8； 
对于40%的数据，有1≤ n≤20，0 < a、b < 8； 
对于60%的数据，有1≤ n≤100； 
对于60%的数据，保证答案不超过10^9； 
对于100%的数据，有1 ≤ n ≤1,000，0 < a、b < 10000。

来源
Noip2012提高组复赛Day1T2
*/

/*
  得分：60
  解题报告：
    贪心，将每个人按照左右手的乘积升序排列，即可得到最优解。
    证明：
      对于任意排列中的相邻的两人i和i+1，可以知道，如果将两人交换位置，其他人得到的奖金是不变的，只有那两人的奖金可能改变。
      交换前，ai和ai+1的奖金分别为：
        a1*a2*...*ai-1/bi, a1*a2*...*ai/bi+1
      两人中较大的奖金c1为：
        c1=max{a1*a2*...*ai-1/bi, a1*a2*...*ai/bi+1}
      交换后，ai和ai+1的奖金分别为：
        a1*a2*...*ai-1*ai+1/bi, a1*a2*...*ai-1/bi+1
      两人中较大的奖金c2为：
        c2=max{a1*a2*...*ai-1*ai+1/bi, a1*a2*...*ai-1/bi+1}
      因为只比较大小，将c1和c2公因式约去，得
        c1=max{1/bi, ai/bi+1}
        c2=max{ai+1/bi, 1/bi+1}
      又因 1/bi <= ai+1/bi 且 ai/bi+1 >= 1/bi+1，那么等效于
        c1=ai/bi+1
        c2=ai+1/bi
      如果要使得 c1<c2，要满足 ai/bi+1 < ai+1/bi，交叉相乘得：
        ai*bi<ai+1*bi+1
      因此，对任意相邻两人，如果想要使得交换前奖金小于交换后奖金（也就是说在当前位置下最大奖金一定是最小的），必须满足 ai*bi < ai+1*bi+1，命题得证。
    至此，得到了60%的分数，剩下的40%需要使用高精度求解。而且，因为每个人右手上的数小于10000，可以使用高精除以单精，但如果使用高精除以高精会TLE。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long unsigned LLU;
const int BASE=100000000;
const int WIDTH=8;
struct Ind{
  int l,r,tot;

  bool operator < (const Ind & b) const {
    return tot<b.tot;
  }
}ind[1020];
struct BI{
  int len;
  vector<int> v;

  BI() {len=1; v.push_back(0);}
  BI(int n) {len=1; v.push_back(n);}
}zero,one,two;

BI add(BI a, BI b);
BI mul(BI a, BI b);
BI mul(BI a, int b);
BI div(BI a, int b);
int compare(const BI & a, const BI & b);
void print(const BI & a);

int main(void){
  one.v[0]=1; two.v[0]=2;
  int n; scanf("%d",&n);
  for(int i=0;i<=n;i++) {scanf("%d%d",&ind[i].l,&ind[i].r); ind[i].tot=ind[i].l*ind[i].r;}
  sort(ind+1,ind+1+n);
  BI ansMax,sum=one;
  for(int i=1;i<=n;i++){
    sum = mul(sum,ind[i-1].l);
    BI t=div(sum,ind[i].r);
    if(compare(ansMax,t)<0) ansMax=t;
  }
  print(ansMax); printf("\n");

  return 0;
}

BI add(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
  int carry=0;
  for(int i=0;i<a.len;i++){
    a.v[i]+=carry;
    if(i<b.len) a.v[i]+=b.v[i];
    carry=a.v[i]/BASE; a.v[i]%=BASE;
  }
  if(carry) {a.v.push_back(carry); a.len++;}
  return a;
}
BI mul(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
  BI ans,t;
  for(int i=0;i<b.len;i++){
    t=mul(a,b.v[i]);
    vector<int> tv;
    for(int j=0;j<i;j++) tv.push_back(0);
    for(int j=0;j<t.len;j++) tv.push_back(t.v[j]);
    t.v=tv; t.len=t.v.size();
    ans=add(ans,t);
  }
  return ans;
}
BI mul(BI a, int b){
  LLU carry=0;
  for(int i=0;i<a.len;i++){
    carry+=1LL*a.v[i]*b;
    a.v[i]=carry%BASE; carry/=BASE;
  }
  if(carry) {a.v.push_back(carry); a.len++;}
  return a;
}
BI div(BI a, int b){
  LLU carry=0;
  for(int i=a.len-1;i>=0;i--){
    carry=carry*BASE+a.v[i];
    if(carry>=b) {a.v[i]=carry/b; carry%=b;}
    else a.v[i]=0;
  }
  vector<int>::iterator it=a.v.end(); it--;
  while(!(*it) && it!=a.v.begin()) {a.v.erase(it); it--;}
  a.len=a.v.size();
  return a;
}
int compare(const BI & a, const BI & b){
  if(a.len!=b.len) return a.len-b.len;
  else for(int i=a.len-1;i>=0;i--) if(a.v[i]!=b.v[i])
    return a.v[i]-b.v[i];
  return 0;
}
void print(const BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long unsigned LLU;
struct Ind{
  int l,r,tot;

  bool operator < (const Ind & b) const {
    return tot<b.tot;
  }
}ind[1020];


int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<=n;i++) {scanf("%d%d",&ind[i].l,&ind[i].r); ind[i].tot=ind[i].l*ind[i].r;}
  sort(ind+1,ind+1+n);
  LLU ansMax=0,sum=1;
  for(int i=1;i<=n;i++){
    sum*=ind[i-1].l;
    ansMax = max(ansMax,sum/ind[i].r);
  }
  printf("%llu\n",ansMax);

  return 0;
}
*/
