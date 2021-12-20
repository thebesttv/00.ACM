/*
题目描述
猫猫TOM和小老鼠JERRY最近又较量上了，但是毕竟都是成年人，他们已经不喜欢再玩那种你追我赶的游戏，现在他们喜欢玩统计。最近，TOM老猫查阅到一个人类称之为“逆序对”的东西，这东西是这样定义的：对于给定的一段正整数序列，逆序对就是序列中ai>aj且i<j的有序对。知道这概念后，他们就比赛谁先算出给定的一段正整数序列中逆序对的数目。

输入输出格式
输入格式：
第一行，一个数n(n<=40000)，表示序列中有n个数。
第二行n个数，表示给定的序列。

输出格式：
给定序列中逆序对的数目。
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=40020;
int n,a[MAX],t[MAX];
int cnt=0;

/*
void merge_sort(int l, int r){
  if(l+1>=r) return;
  int m=(l+r)>>1;
  merge_sort(l,m);
  merge_sort(m,r);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && a[p]<=a[q])) t[tail++]=a[p++];  //a[p] < a[q]
    else {t[tail++]=a[q++]; cnt+=m-p;}  //a[p] > a[q]
  }
  FOR(i,l,r) a[i]=t[i];
}
*/

void merge_sort(int l, int r){
  if(l+1>=r) return;
  int m=(l+r)>>1;
  merge_sort(l,m);
  merge_sort(m,r);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && a[p]<a[q])) t[tail++]=a[p++];
    else t[tail++]=a[q++],cnt+=m-p;
  }
  FOR(i,l,r) a[i]=t[i];
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  
  merge_sort(0,n);

  printf("%d\n",cnt);

  return 0;
}

/*
//分治，归并排序改写
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=40000+20;
int A[MAX],T[MAX];
int tot=0;

void merge_sort(int * A, int L, int R, int * T){
  if(L+1>=R) return;
  int M=L+(R-L)/2;
  merge_sort(A,L,M,T);
  merge_sort(A,M,R,T);
  int x=L,y=M,tail=L;
  while(x<M || y<R){
    if(y>=R || (x<M && A[x]<=A[y])) T[tail++]=A[x++];
    else {T[tail++]=A[y++]; tot+=M-x;}
  }
  for(int i=L;i<R;i++) A[i]=T[i];
}

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&A[i]);
  merge_sort(A,0,n,T);
  printf("%d\n",tot);

  return 0;
}
*/
