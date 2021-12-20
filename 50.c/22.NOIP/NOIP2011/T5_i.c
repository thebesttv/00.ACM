/*
描述
小 T 是一名质量监督员，最近负责检验一批矿产的质量。这批矿产共有n个矿石，从1到n逐一编号，每个矿石都有自己的重量wi以及价值vi。
检验矿产的流程是：
  1. 给定m个区间[Li，Ri]；
  2. 选出一个参数W；
  3. 对于一个区间[Li，Ri]，计算矿石在这个区间上的 检验值Yi：
    Yi = t * sum{vj | j在[Li,Ri]中且wj>=W}, j是矿石编号, t为符合条件的j的个数
这批矿产的 检验结果Y 为各个区间的检验值之和 。即：Y = ∑Yi
若这批矿产的 检验结果 与所给标准值S相差太多，就需要再去检验另一批矿产。小T不想费时间去检验另一批矿产，所以他想通过调整参数W的值，让 检验结果 尽可能的靠近标准值S，即使得 S-Y 的绝对值最小。请你帮忙求出这个最小值。

格式
输入格式
第一行包含三个整数n，m，S，分别表示矿石的个数、区间的个数和标准值。
接下来的n行，每行2个整数，中间用空格隔开，第i+1行表示i号矿石的重量wi和价值vi 。
接下来的m行，表示区间，每行2个整数，中间用空格隔开，第i+n+1行表示区间[Li,Ri]的两个端点Li和Ri。 注意：不同区间可能重合或相互重叠。

输出格式
输出只有一行，包含一个整数，表示所求的最小值。

样例1
样例输入1
5 3 15
1 5
2 5
3 5
4 5
5 5
1 5
2 4
3 3

样例输出1
10

限制
1s

提示
样例说明：当W选4的时候，三个区间上检验值分别为20、5、0，这批矿产的检验结果为25，此时与标准值S相差最小为10。
对于10%的数据，有1 ≤ n，m ≤ 10；
对于30%的数据，有1 ≤ n，m ≤ 500；
对于50%的数据，有1 ≤ n，m ≤ 5,000；
对于70%的数据，有1 ≤ n，m ≤ 10,000；
对于100%的数据，有1 ≤ n，m ≤ 200,000，0 < wi, vi ≤ 10^6，0 < S ≤ 10^12，1 ≤ Li ≤ Ri ≤ n。

来源
NOIp2011提高组Day2第二题
*/

/*
  得分：100
  解题报告：
    二分查找 + 前缀和
    因为对于矿石i，只有当wi>=w时才会被计入，可以得到：检验结果Y随着w的降低而升高，随着w的升高而降低，也就是说，Y对w具有单调性。
    那么就可以使用二分查找，在区间[0,max_w]内二分w，寻找最接近s的结果。
      对于每次二分循环，先计根据二分中值w计算当前检验结果Y，同时更新答案。
      如果Y小于s，则答案一定小于等于w，否则答案一定大于w。
    二分中的计算：
      遍历所有矿石，使用前缀和维护所有有效矿石的w之和与有效矿石的个数。
*/

//TODO: 弄清这样二分能成功的原因。

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

typedef long long LL;
const int MAX=200020;
LL sum[MAX];
int cnt[MAX], quest[MAX][2];
struct Ind{
  int w,v;
}ind[MAX];
int n,m;
LL s;

LL check(int w);
void init(int w);

int main(void){
  scanf("%d%d%lld",&n,&m,&s);
  int wMax=0;
  for(int i=1;i<=n;i++) {scanf("%d%d",&ind[i].w,&ind[i].v); ind[i].w>wMax ? wMax=ind[i].w : 0 ;}
  for(int i=0;i<m;i++) scanf("%d%d",&quest[i][0],&quest[i][1]);

  int L=0,R=wMax+1;
  LL ans=s;
  int u;
  while(L<R){
    int M=L+(R-L)/2;
    LL t=check(M);
#ifdef DEBUG
    printf("  with w: %d, get %lld, before ans: %lld, L: %d, R: %d\n",M,t,ans,L,R);
#endif
    //ans=min(ans,(LL)abs(t-s));
    if((LL)abs(t-s)<ans) {ans=abs(t-s); u=M;}
    if(t<s) R=M;
    else L=M+1;
  }
#ifdef DEBUG
  printf("%d\n",u);
#endif
  printf("%lld\n",ans);

  return 0;
}

LL check(int w){
  init(w);
  LL ans=0;
  for(int i=0;i<m;i++){
    int l=quest[i][0],r=quest[i][1];
    ans+=(cnt[r]-cnt[l-1])*(sum[r]-sum[l-1]);
  }
  return ans;
}
void init(int w){
  sum[0]=cnt[0]=0;
  for(int i=1;i<=n;i++){
    sum[i] = sum[i-1] + (ind[i].w>=w ? ind[i].v : 0);
    cnt[i] = cnt[i-1] + (ind[i].w>=w ? 1 : 0);
  }
}
