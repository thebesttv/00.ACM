/*
描述
设r是个2^k 进制数，并满足以下条件：
（1）r至少是个2位的2^k 进制数。
（2）作为2^k 进制数，除最后一位外，r的每一位严格小于它右边相邻的那一位。
（3）将r转换为2进制数q后，则q的总位数不超过w。
在这里，正整数k（1≤k≤9）和w（k＜W≤30000）是事先给定的。
问：满足上述条件的不同的r共有多少个？
我们再从另一角度作些解释：设S是长度为w 的01字符串（即字符串S由w个“0”或“1”m组成），S对应于上述条件（3）中的q。将S从右起划分为若干个长度为k 的段，每段对应一位2^k进制的数，如果S至少可分成2段，则S所对应的二进制数又可以转换为上述的2^k 进制数r。
例：设k=3，w=7。则r是个八进制数（23=8）。由于w=7，长度为7的01字符串按3位一段分，可分为3段（即1，3，3，左边第一段只有一个二进制位），则满足条件的八进制数有：
2位数：高位为1：6个（即12，13，14，15，16，17），高位为2：5个，…，高位为6：1个（即67）。共6+5+…+1=21个。
3位数：高位只能是1，第2位为2：5个（即123，124，125，126，127），第2位为3：4个，…，第2位为6：1个（即167）。共5+4+…+1=15个。
所以，满足要求的r共有36个。

格式
输入格式
输入文件只有1行，为两个正整数，用一个空格隔开：
k W

输出格式
输出文件为1行，是一个正整数，为所求的计算结果，即满足条件的不同的r的个数（用十进制数表示），要求最高位不得为0，各数字之间不得插入数字以外的其他字符（例如空格、换行符、逗号等）。
（提示：作为结果的正整数可能很大，但不会超过200位）

样例1
样例输入1
3 7

样例输出1
36

限制
1s

来源
NOIP2006第四题
*/

/*
  得分：80，2个点要高精
  解题报告：
    花了很久分析性质。

    首先，先考虑k=3，w=7的情况：
      取值范围：[2^3, 2^7-1](10)
              即[10,177](2^3)
      长度为2: 12 23 34 45 56 67
               13 24 35 46 57
               14 25 36 47
               15 26 37
               16 27
               17
        共有 6+5+4+3+2+1=21 种
      长度为3: 123 134 145 156 167
               124 135 146 157
               125 136 147
               126 137
               127
        共有 5+4+3+2+1=15 种
      因此答案为36。
    拓展到更一般的情况：
      取值范围：[2^k,2^w-1](10)
              即[10, MAX](2^k)
                其中，当k|w时，MAX = (2^k-1, 2^k-1, ..., 2^k-1)(w/k个)
                      否则，MAX = (2^(w%k)-1, 2^k-1, 2^k-1, ..., 2^k-1)(floor(w/k)个2^k-1)
      长度为2: 12 23 34 ... (2^k-2,2^k-1)
               13 ...
               ...
               (1,2^k-1)
        共有 2^k-2 + 2^k-3 + ... + 2 + 1 种
      长度为3: 123 134 ... (1,2^k-2,2^k-1)
               124 ...
               ...
               (1,2,2^k-1)
             = 2^k-3 + 2^k-4 + ... + 1 （可以看出，1XX中的XX，即为长度等于2时的2X:(2^k-2,X)

               234 ...
               ...
               (2,3,2^k-1)
             = 2^k-4 + 2^k-5 + ... + 1 （即为长度等于2时的3X:(2^k-2,X)

               ... （暂先不考虑w不能被k整除的情况）

        共有 (2^k-3 + 2^k-4 + ... + 1) + (2^k-4 + 2^k-5 + ... + 1) + (2^k-5 + ... + 1) + ... + 1 种
      我们可以看出，这是一种 self-recuring （或者说递归）的过程
      对于长度为i的情况，其值依靠上一个长度为i-1的情况求出。
      于是，就可以令一个 sum[MAX_LEN][1<<9]。其中 sum[i][j] 表示长度为i，最高位为j的符合要求的数有多少个。
        sum[1][i] = 1
        对于i!=1的sum，其值为上一层的、最高位大于j的sum[i-1][m]的和。
      为了写出递推式，还要研究最高位大小的范围。
        对于一个长为i的满足题目要求的最大数，其形式为： (2^k-i, 2^k-i+1, ..., 2^k-2, 2^k-1)，可以发现其最高位最大值为 2^k-i。
        因此，长为i-1的数，其最高位范围为最大值为 2^k-(i-1)。
        于是得到递推式：sum[i][j] = sum{ sum[i-1][m] | j+1<=m<=2^k-(i-1)}
        就可以递推了，答案即为所有sum的和。
      当然，还有w不能被k整除的情况没有被考虑。
        当w不能被k整除时，其最大数只有最高位不等于 2^k-1，其余与k|w完全相同。
        所以可以先对长为2:(i-1)的情况依照当前方法求解，对于长等于i的，让答案只加到 sum[2^(k%w)-1][m] 即可。
      最后，考虑到答案范围，要写一个高精加法。但因占用内存太，sum需要使用滚动数组的技巧。
      到这里，就可以AC了。
      但这还是太慢，对于极限数据一定会TLE，即使对于k=9，w=100的数据都很慢。
      程序还有优化的余地，下次再改。
TODO: 优化时间复杂度（可能要使用高精乘法）

    在测试数据时，还发现一个有点“显然”的性质：对每个k，当w大到一定程度时，答案不变。
      因为最长的升序序列为： (1,2,3,4,...,2^k-1)(2^k)，其长度为 2^k-1，二进制长度为 (2^k-2)*k+1。
      因此，当 w>=(2^k-2)*k+1 时，答案不变。
      有了这个性质，就可以在本地用python自带的高精算出答案，然后打表。 XD
*/

//高精版
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long unsigned LLU;
const int BASE=100000000;
const int WIDTH=8;
const int MAX_LEN=25000;
//LLU sum[MAX_LEN][1<<9];
int head[MAX_LEN];
struct BI{
  int len;
  vector<int> v;

  BI() {len=1; v.push_back(0);}
}sum[1<<9],tsum[1<<9];

BI ADD(BI a, BI b);
int compare(const BI & a, const BI & b);
void print(const BI & a);

int main(void){
  int k,w; scanf("%d%d",&k,&w);
  int len=ceil(1.0*w/k);
  for(int i=1;i<len;i++) head[i]=(1<<k)-1;
  head[len] = w%k==0 ? (1<<k)-1 : (1<<(w%k))-1;
  for(int i=1;i<=(1<<k);i++) sum[i].v[0]=1;
  BI tot;
  for(int i=2;i<=len;i++){
    int t=min(head[i],(1<<k)-i);
    for(int j=1;j<=t;j++){
      for(int m=j+1;m<=(1<<k)-(i-1);m++)
        tsum[j] = ADD(tsum[j],sum[m]);
      tot = ADD(tot,tsum[j]);
    }
    memcpy(sum,tsum,sizeof(tsum));
    memset(tsum,0,sizeof(tsum));
  }
  print(tot); printf("\n");

  return 0;
}

BI ADD(BI a, BI b){
  if(compare(a,b)<0) swap(a,b);
  int carry=0;
  for(int i=0;i<a.len;i++){
    if(i<b.len) carry+=b.v[i];
    a.v[i]+=carry;
    carry=a.v[i]/BASE; a.v[i]%=BASE;
  }
  if(carry) {a.v.push_back(carry); a.len++;}
  return a;
}
int compare(const BI & a, const BI & b){
  if(a.len!=b.len) return a.len-b.len;
  else for(int i=a.len-1;i>=0;i--) if(a.v[i]!=b.v[i]) return a.v[i]-b.v[i];
}
void print(const BI & a){
  printf("%d",a.v[a.len-1]);
  for(int i=a.len-2;i>=0;i--) printf("%08d",a.v[i]);
}





























/*
//低精版
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

typedef long long unsigned LLU;
const int MAX_LEN=25000;
LLU sum[MAX_LEN][1<<9];
int head[MAX_LEN];

int main(void){
  int k,w; scanf("%d%d",&k,&w);
  int len=ceil(1.0*w/k);
  for(int i=1;i<len;i++) head[i]=(1<<k)-1;
  head[len] = w%k==0 ? (1<<k)-1 : (1<<(w%k))-1;
#ifdef DEBUG
  printf("  head:"); for(int i=len;i>=1;i--) printf(" %d",head[i]); printf("\n");
#endif
  for(int i=1;i<=(1<<k);i++) sum[1][i]=1;
  LLU tot=0;
  for(int i=2;i<=len;i++){
    int t=min(head[i],(1<<k)-i);
    for(int j=1;j<=t;j++){
      for(int m=j+1;m<=(1<<k)-(i-1);m++)
        sum[i][j] += sum[i-1][m];
      tot+=sum[i][j];
    }
  }
  printf("%llu\n",tot);

  return 0;
}
*/
