/*
题目描述
S 城现有两座监狱，一共关押着N 名罪犯，编号分别为1~N。他们之间的关系自然也极不和谐。很多罪犯之间甚至积怨已久，如果客观条件具备则随时可能爆发冲突。我们用“怨气值”（一个正整数值）来表示某两名罪犯之间的仇恨程度，怨气值越大，则这两名罪犯之间的积怨越多。如果两名怨气值为c 的罪犯被关押在同一监狱，他们俩之间会发生摩擦，并造成影响力为c 的冲突事件。
每年年末，警察局会将本年内监狱中的所有冲突事件按影响力从大到小排成一个列表，然后上报到S 城Z 市长那里。公务繁忙的Z 市长只会去看列表中的第一个事件的影响力，如果影响很坏，他就会考虑撤换警察局长。
在详细考察了N 名罪犯间的矛盾关系后，警察局长觉得压力巨大。他准备将罪犯们在两座监狱内重新分配，以求产生的冲突事件影响力都较小，从而保住自己的乌纱帽。假设只要处于同一监狱内的某两个罪犯间有仇恨，那么他们一定会在每年的某个时候发生摩擦。
那么，应如何分配罪犯，才能使Z 市长看到的那个冲突事件的影响力最小？这个最小值是多少？

输入输出格式
输入格式：
输入文件的每行中两个数之间用一个空格隔开。第一行为两个正整数N 和M，分别表示罪犯的数目以及存在仇恨的罪犯对数。接下来的M 行每行为三个正整数aj，bj，cj，表示aj 号和bj 号罪犯之间存在仇恨，其怨气值为cj。数据保证1<aj=<=bj<=N ，0 < cj≤ 1,000,000,000，且每对罪犯组合只出现一次。

输出格式：
共 1 行，为Z 市长看到的那个冲突事件的影响力。如果本年内监狱中未发生任何冲突事件，请输出0。

输入输出样例
输入样例#1：
4 6
1 4 2534
2 3 3512
1 2 28351
1 3 6618
2 4 1805
3 4 12884

输出样例#1：
3512

数据范围
对于30%的数据有N≤ 15。
对于70%的数据有N≤ 2000，M≤ 50000。
对于100%的数据有N≤ 20000，M≤ 100000。
*/

/*
  解题报告：
    若x,y之间有仇恨值z，则建立一条边(x,y)，权值为z。
    显然，两个监狱里是一个二分图。
    按权值降序在原本空的二分图中添加边，若对于权值为z的边，如果加入后不能在成为二分图，则答案即为z。
    使用并查集完成操作。
    因为可以将监狱A,B中的囚犯整个对调，答案依旧不变，那么就要相对地建立关系。
    令 x 和 x+n 在不同的两个监狱中，则对于x,y：
      若 p[x]==p[y]，则x,y在相同的监狱。
      若 p[x]==p[y+n] 或 p[y]==p[x+n]，则x,y已确定在不同监狱，就不能再加边，答案也就是边(x,y)的权值了。
      否则 x,y相对位置不定。
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

const int MAXN=20020;
const int MAXM=100020;

int n,m,p[MAXN<<1];
struct Edge{
  int u,v,w;
  bool operator < (const Edge & b) const {return w>b.w;}
}edge[MAXM];

inline int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void merge(int x, int y){
  x=find(x),y=find(y);
  if(x==y) return;
  if(p[x]<p[y]){
    p[x]+=p[y]; p[y]=x;
  }else{
    p[y]+=p[x]; p[x]=y;
  }
}

int main(void){
  MST(p,-1);
  scanf("%d%d",&n,&m);
  FOR(i,0,m) scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
  sort(edge,edge+m);

  int ans=0;
  FOR(i,0,m){
    int x=edge[i].u,y=edge[i].v;
    if(find(x)==find(y)) {ans=edge[i].w; break;}
    else{
      merge(x,y+n); merge(y,x+n);
      //if(find(x)!=find(y+n))  //<b> 一定要判断是否祖先相同 </b>
      //  p[find(x)]=find(y+n);
      //if(find(y)!=find(x+n))  //<b> </b>
      //  p[find(y)]=find(x+n);
    }
  }
  printf("%d\n",ans);

  return 0;
}
