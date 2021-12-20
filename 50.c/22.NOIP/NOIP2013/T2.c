/*
描述
涵涵有两盒火柴，每盒装有 n 根火柴，每根火柴都有一个高度。现在将每盒中的火柴各自排成一列，同一列火柴的高度互不相同，两列火柴之间的距离定义为：sum{(ai-bi)^2|1<=i<=n}
其中 ai 表示第一列火柴中第 i 个火柴的高度，bi 表示第二列火柴中第 i 个火柴的高度。
每列火柴中相邻两根火柴的位置都可以交换，请你通过交换使得两列火柴之间的距离最小。请问得到这个最小的距离，最少需要交换多少次？如果这个数字太大，请输出这个最小交换次数对 99,999,997 取模的结果。

格式
输入格式
共三行，第一行包含一个整数 n，表示每盒中火柴的数目。
第二行有 n 个整数，每两个整数之间用一个空格隔开，表示第一列火柴的高度。
第三行有 n 个整数，每两个整数之间用一个空格隔开，表示第二列火柴的高度。

输出格式
输出共一行，包含一个整数，表示最少交换次数对 99,999,997 取模的结果。

样例1
样例输入1
4
2 3 1 4
3 2 1 4

样例输出1
1

样例2
样例输入2
4
1 3 4 2
1 7 2 4

样例输出2
2

限制
每个测试点1s。

样例说明
样例1
最小距离是 0，最少需要交换 1 次，比如：交换第 1 列的前 2 根火柴或者交换第 2 列的前 2 根火柴。
样例2
最小距离是 10，最少需要交换 2 次，比如：交换第 1 列的中间 2 根火柴的位置，再交换第 2 列中后 2 根火柴的位置。

数据范围
对于 10%的数据，1 ≤ n ≤ 10； 
对于 30%的数据，1 ≤ n ≤ 100； 
对于 60%的数据，1 ≤ n ≤ 1,000； 
对于 100%的数据，1 ≤ n ≤ 100,000，0 ≤火柴高度≤ 2^31 − 1。

来源
NOIP 2013 提高组 Day 1
*/

/*
  得分：80
  解题报告：（考试时）
    首先，要找出最优组合，然后再计算最少的交换次数。
    而想要找到最优组合，可以利用贪心的思想：只有当a和b都为升序或降序时，ai和bi之间的一一对应的关系才能构成最优组合。
    证明：
      可以发现，在序列中交换任意两根相邻的火柴对其他火柴没有影响。
      那么，对a和b中的任意相邻火柴ai,ai+1和bi,bi+1，其对答案的贡献y1为：
        y1=(ai-bi)^2 + (ai+1-bi+1)^2
      如果将ai和ai+1交换顺序，他们对答案的贡献y2为：
        y2=(ai-bi+1)^2 + (ai+1-bi)^2
      因为只比较y1和y2的大小关系，可以将两式展开并去掉相同项，得：
        y1=-2(ai*bi + ai+1*bi+1)
        y2=-2(ai*bi+1 + ai+1*bi)
      因为要使得交换前尽量小，即y1<y2，则带入得：
        ai*bi + ai+1*bi+1 > ai*bi+1 + ai+1*bi
        ai(bi-bi+1) > ai+1(bi-bi+1)
      无论bi和bi+1的大小关系，ai和ai+1也一定有相同的大小关系，那么想要使得答案最小，每个ai,ai+1和bi,bi+1都要有相同的大小关系，排序即可解决。
      对排序后的a,b，我们可以得到ai和bj之间一一对应的关系，然后就只要求最少交换次数了。
      而在此我只写出了O(n^2)的计算代码，然后就只要80分了。

  正解：
    根据排序不等式，得：
      设有两组数a[1:n]和b[1:n]，如果有 a1<=a2<=...<=an && b1<=b2<=...<=bn，则有
        a1*bn + a2*bn-1 + ... + an*b1 <= sum{ ai*bj | (i,j)任意且不重 } <= a1*b1 + a2*b2 + ... + an*bn
      简记为：反序和<=乱序和<=同序和
    因题目要求 sum{ (ai-bj)^2 } 最小，即 -2*sum{ ai*bj } 最小，那么也就是 sum{ ai*bj } 最大，就可以使用排序不等式，当a,b同序时，为最优解。
    又因要求出最小移动，只需移动一组即可，在此移动a组。
      先对a,b中的元素进行排序，得到a[i]在最优解中应在的位置j，即to[i]=j。
      因为只能移动相邻的火柴，想到逆序对，求出to中的逆序对数即可。  //???
    而求逆序对有两种方法，归并排序和树状数组。
    树状数组：
      类似于桶排的方法，但使用树状数组将O(n)的查找时间降低为O(logn)。
      使用c[i]记录i是否出现，按顺序用a[i]更新c[a[i]]，并加上c中大于a[i]的数的个数，即sum(MAX)-sum(a[i])（或更好，因为i可以代表一共的个数，可以直接用i-sum(a[i])，但要注意更新a[i]和计算逆序对的顺序和i从1开始还是从0开始）。因为a[i]是按顺序更新的，所以每个a[i]在被放入前，c中的所有数都是在a[i]之前出现的，这种方法也就合理了。
      当然，对于范围较大的数或负数，可以离散化。
*/

//TODO: 使用树状数组+离散化求出逆序对

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=100020;
const int MOD=99999997;
int to[MAX],b[MAX],temp[MAX];
struct Node{
  int h,num;
  bool operator < (const Node & b) const {
    return h<b.h;
  }
}nodea[MAX],nodeb[MAX];
int cnt=0;

void merge_sort(int * A, int l, int r, int * T);

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) {scanf("%d",&nodea[i].h); nodea[i].num=i;}
  for(int i=0;i<n;i++) {scanf("%d",&b[i]); nodeb[i].h=b[i]; nodeb[i].num=i;}
  sort(nodea,nodea+n); sort(nodeb,nodeb+n);
  for(int i=0;i<n;i++)
    to[nodea[i].num]=nodeb[i].num;  //<b></b>

  merge_sort(to,0,n,temp);
  printf("%d\n",cnt);

  return 0;
}

void merge_sort(int * A, int l, int r, int * T){  //[l,r)
  if(l>=r-1) return;
  //int m=l+(r-l)>>1; //<b>错误</b>
  int m=l+(r-l>>1);   //右移的优先级小，如果使用第一种，会在计算完 l+(r-l) 再右移
  merge_sort(A,l,m,T); merge_sort(A,m,r,T);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && A[p]<A[q])) T[tail++]=A[p++];
    else {T[tail++]=A[q++]; (cnt+=m-p)%=MOD;}
  }
  for(int i=l;i<r;i++) A[i]=T[i];
}

/*
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=100020;
const int MOD=99999997;
struct Node{
  int n,num;
  bool operator < (const Node & b) const {
    return n<b.n;
  }
}na[MAX],nb[MAX];
struct Node2{
  int n;
  int l,r;
}la[MAX];
int b[MAX],n;
int to[MAX];  //to[i]=j: b[i]对应于a中值为j的那个

inline int find(int cur, int n, int & len){
  len=0;
  while(la[cur].n!=n){
    cur=la[cur].r; len++;
  }
  return cur;
}

int main(void){
  scanf("%d",&n);
  int t;
  //Node2 *head = new Node2; Node2 *last=head;
  for(int i=1;i<=n;i++){
    scanf("%d",&t);
    na[i].n=t; //na[i].num=i;
    la[i].n=t; la[i].l=i-1; la[i].r=i+1;
  }
  for(int i=1;i<=n;i++){
    scanf("%d",&b[i]);
    nb[i].n=b[i]; nb[i].num=i;
  }
  sort(na+1,na+1+n); sort(nb+1,nb+1+n);
  for(int i=1;i<=n;i++) to[nb[i].num]=na[i].n;
#ifdef DEBUG
  for(int i=1;i<=n;i++) printf("  to[%d]: %d\n",i,to[i]);
  for(int i=1;i<=n;i++) printf("  la[%d]={%d,%d,%d}\n",i,la[i].l,la[i].n,la[i].r);
#endif

  int cnt=0,cur=1;
  for(int i=1;i<=n;i++){  //对每个b[i]
    if(la[cur].n==to[i]) {cur=la[cur].r; continue;}
    int len,pos;
    pos=find(cur,to[i],len);
#ifdef DEBUG
    printf("  find(%d,%d,%d)=%d\n",cur,to[i],len,pos);
#endif
    //出链表
    la[la[pos].l].r=la[pos].r;
    la[la[pos].r].l=la[pos].l;
    //插入la[cur]之前
    la[pos].l=la[cur].l;
    la[pos].r=cur;
    la[la[cur].l].r=la[cur].l=pos;
    cnt+=len; cnt>=MOD ? cnt%=MOD : 0 ;
  }
  printf("%d\n",cnt);

  return 0;
}
*/
