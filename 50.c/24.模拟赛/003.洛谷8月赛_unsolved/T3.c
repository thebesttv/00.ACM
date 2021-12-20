/*
题目描述
给定一个长度为 n 的序列，给出 q 个操作，形如：
1 l r x 表示将序列下标介于 [l,r] 的元素加上 x （请注意，x 可能为负）
2 p y 表示查询 ap 在过去的多少秒时间内不小于 y （不包括这一秒，细节请参照样例）
开始时为第 0 秒，第 i 个操作发生在第 i 秒。

输入输出格式
输入格式：
第一行两个整数 n,q，意义如描述所述。
接下来一行 n 个整数 ai，表示序列的每个元素的初始值。
接下来 q 行，每行第一个数为 opt，表示这次操作的类型。如果 opt=1，后面紧跟三个整数 l,r,x，意义如描述所述；如果 opt=2，后面紧跟两个整数 p,y，意义如描述所述。

输出格式：
对于每个操作 2，在一行内输出一个数表示答案。

输入输出样例
输入样例#1：
3 3
1 3 5
2 1 2
1 1 2 -3
2 1 1

输出样例#1：
0
2

说明
样例一说明：位置 1 在第 0 秒到第 3 秒的值为 1,1,−2,−2。对于第一个查询，前 1−1=0 秒中有 0 秒时间不小于 2；对于第二个查询，前 3−1=2 秒中有 2 秒时间不小于 1，分别为第 0 秒，第 1 秒。
对于 30% 的数据，保证 n,q≤1000
对于 70% 的数据，保证 n,q≤50000
对于 100% 的数据，保证 2≤n,q≤100000， 1≤l≤r≤n， 1≤p≤n，−10^9≤x,y,ai≤10^9
*/











































/*
  得分：0
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=100000+4;
struct P1{
  int l,r,addVal;
  int time;

  bool operator < (const P1 & b) const {
    return l<b.l;
  }
}p1[MAX];
struct P2{
  int n,y;  //>=y
  int time;
  int ans;

  bool operator < (const P2 & b) const {
    return n!=b.n ? n<b.n : time<b.time;
  }
}p2[MAX];
int tail1=1,tail2=1;
int tl[MAX];  //每个点进行模拟时使用的差分数组
int ori[MAX],n,m;
int ans[MAX];

void add(int n, int from, int to);  //模拟

int main(void){
  memset(ans,-1,sizeof(ans));
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&ori[i]);
  int type,l,r,x,p,y;
  for(int i=1;i<=m;i++){
    scanf("%d",&type);
    if(type==1){
      scanf("%d%d%d",&l,&r,&x);
      p1[tail1].l=l; p1[tail1].r=r; p1[tail1].addVal=x; p1[tail1++].time=i;
    }else{
      scanf("%d%d",&p,&y);
      p2[tail2].n=p; p2[tail2].y=y; p2[tail2++].time=i;
    }
  }
  stable_sort(p1+1,p1+tail1); sort(p2+1,p2+tail2);
  int pos=1;
  for(int node=1;node<=n;node++){ //对每一个点node
#ifdef DEBUG
    printf("  node: %d\n",node);
#endif
    memset(tl,0,sizeof(tl)); tl[0]=ori[node];
    while(p2[pos].n<node && pos<tail2) pos++;
    for(;p2[pos].n==node;pos++){
      add(node,pos-1,pos);
      int delta=0;
#ifdef DEBUG
      printf("  ");
      for(int i=0;i<p2[pos].time;i++) printf("%d ",tl[i]); printf("\n");
#endif
      for(int t=0;t<p2[pos].time-1;t++){
        delta+=tl[t];
        if(delta>=p2[pos].y) p2[pos].ans++;
      }
      ans[p2[pos].time]=p2[pos].ans;
#ifdef DEBUG
    printf("  ans[%d]: %d\n",p2[pos].time+1,p2[pos].ans);
#endif
    }
  }
  for(int i=1;i<=m;i++) if(ans[i]!=-1) printf("%d\n",ans[i]);

  return 0;
}

void add(int n, int from, int to){  //模拟
  int pos=1;
  for(;p1[pos].l<=n;pos++){
    if(n<=p1[pos].r && p1[pos].time>p2[from].time && p1[pos].time<p2[to].time)
      tl[p1[pos].time]+=p1[pos].addVal;
  }
}
*/
