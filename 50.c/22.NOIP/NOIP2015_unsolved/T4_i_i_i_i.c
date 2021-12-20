/*
描述
一年一度的“跳石头”比赛又要开始了！
这项比赛将在一条笔直的河道中进行，河道中分布着一些巨大岩石。组委会已经选择好了两块岩石作为比赛起点和终点。在起点和终点之间，有 N 块岩石（不含起点和终点的岩石）。在比赛过程中，选手们将从起点出发，每一步跳向相邻的岩石，直至到达终点。
为了提高比赛难度，组委会计划移走一些岩石，使得选手们在比赛过程中的最短跳跃距离尽可能长。由于预算限制，组委会至多从起点和终点之间移走 M 块岩石（不能移走起点和终点的岩石）。

格式
输入格式
输入第一行包含三个整数 L，N，M，分别表示起点到终点的距离，起点和终 点之间的岩石数，以及组委会至多移走的岩石数。
接下来 N 行，每行一个整数，第 i 行的整数 Di（0 <Di<L）表示第 i 块岩石与 起点的距离。这些岩石按与起点距离从小到大的顺序给出，且不会有两个岩石出现在同 一个位置。

输出格式
输出只包含一个整数，即最短跳跃距离的最大值。

样例1
样例输入1
25 5 2
2
11
14
17
21

样例输出1
4

限制
对于 20%的数据，100≤M≤N≤10。
对于 50%的数据，1000≤M≤N≤100。
对于100%的数据，500000≤M≤N≤50000，1≤L≤1000000000。

提示
对于样例。将与起点距离为 2 和 14 的两个岩石移走后，最短的跳跃距离为 4（从与起点距离17 的岩石跳到距离 21 的岩石，或者从距离 21 的岩石跳到终点）。

来源
NOIP 2015 提高组 Day 2 第一题
*/

/*
  得分：50
  解题报告：
    一开始觉得可以每次去掉最短的一段，并且在去除的时候依据两边两段的长度判断去掉哪一个石子，然后感觉答案就是去掉m次后的最短段，然而并没有成功。。。
  正解：
    二分最短长度，依据每个最短长度，计算要满足要求需要移除多少个石子并与m比较即可。（说实话“使得最短跳跃距离尽可能长”这么明显的暗示我都没发现。。。我的二分实在是太弱了。。。）
    可以二分的原因：
      去除的石子个数cnt(l)与最短长度l之间满足单调关系，即<b> cnt(l)具有单调性</b>
    在实现时要注意区间开闭等细节问题。。。
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

const int MAX=50020;
int L,n,m;
int a[MAX];

int cnt(int l){
  int sum=0,last=0;
  FORR(i,1,n+1){  //XXX
    if(a[i]-a[last]<l) sum++;
    else last=i;
  }
  return sum;
}

int main(void){
  scanf("%d%d%d",&L,&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  a[n+1]=L;

  int l=1,r=L;
  while(l<r){
    int mid=l+(r-l+1)/2;
    int t=cnt(mid);
    if(t>m) r=mid-1;
    else l=mid;
#ifdef DEBUG
  printf("  l: %d, r: %d, cnt(%d): %d\n",l,r,mid,t);
#endif
  }
  if(cnt(l+1)<=m) l++;

  printf("%d\n",l);

  return 0;
}

/*
//不知道为什么错了
const int MAX=50020;
const int INF=0x3f3f3f3f;
struct Node{
  int l,r,len;  //s: 0, t: n+1
  bool operator < (const Node & b) const {
    return len>b.len;
  }
};
PQ<Node> q;
int pos[MAX];
int n,m,l;

int main(void){
  scanf("%d%d%d",&l,&n,&m);
  Node t;
  FORR(i,1,n){
    scanf("%d",&pos[i]);
    t.l=i-1; t.r=i; t.len=pos[i]-pos[i-1];
    q.push(t);
  }
  pos[n+1]=l;
  t.l=n; t.r=n+1; t.len=l-pos[n];
  q.push(t);

  int cnt=0;
  while(cnt<m){
    t=q.top(); q.pop(); if(pos[t.l]==-1 || pos[t.r]==-1) continue;
#ifdef DEBUG
    printf("  get node: l: %d, r: %d, len: %d\n",t.l,t.r,t.len);
#endif
    int lenl,lenr,pl=-1,pr=-1;

    if(t.l==0) lenl=INF;
    else{
      pl=t.l-1;
      while(pl && pos[pl]==-1) pl--;
      lenl=pos[t.l]-pos[pl];
    }
    if(t.r==n+1) lenr=INF;
    else{
      pr=t.r+1;
      while(pr<=n && pos[pr]==-1) pr++;
      lenr=pos[pr]-pos[t.r];
    }
#ifdef DEBUG
    printf("    lenl: %d, lenr: %d, pl: %d, pr: %d\n",lenl,lenr,pl,pr);
#endif
    if(lenl<lenr){  //delete l
      pos[t.l]=-1;
      Node tt;
      tt.l=pl; tt.r=t.r; tt.len=pos[tt.r]-pos[tt.l];
      q.push(tt);
    }else{  //delete r
      pos[t.r]=-1;
      Node tt;
      tt.l=t.l; tt.r=pr; tt.len=pos[tt.r]-pos[tt.l];
      q.push(tt);
    }
    cnt++;
  }
  while(!q.empty()){  //delete illegal node
    t=q.top();
    if(pos[t.l]==-1 || pos[t.r]==-1) q.pop();
    else break;
  }
  if(q.empty()) printf("%d\n",l);
  else printf("%d\n",q.top().len);

  return 0;
}
*/
