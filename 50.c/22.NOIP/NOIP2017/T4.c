/*
  得分：100
  解题报告：
    讨厌的浮点误差……
    考试的时候一开始被计算几何吓到了，然而仔细看了看才发现原来还是比较简单的。
    考场上我想到的是图的做法。
    先判断点 i,j 之间是否联通，如果联通则连接 i,j 。
    然后遍历，判断点与上下表面是否连通，连通则建边（下表面为 0 ，上表面为 n+1 ）
    然后再跑个 Dij ，判断起点和终点是否连通。
  正解：
  [1]并查集
    同一个集合中的元素两两直接或间接连通。
    同样进行三次遍历，判断点与点、点与下表面、点与上表面分别是否连通，如果连通则合并。
    最后判断下表面（0）和上表面（n+1）是否连通即可。
  [2]dfs
    好像并没有什么可说的……
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
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1020;
int n,h,r;
struct Node{
  int x,y,z;
}node[MAX];
bool vis[MAX],flag;

inline double dis(Node & a, Node & b){
  double dx=a.x-b.x, dy=a.y-b.y, dz=a.z-b.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}
void dfs(int u){
  vis[u]=1;
  if(node[u].z+r>=h) {flag=1; return;}
  FORR(i,1,n) if(dis(node[i],node[u])<=(r<<1) && !vis[i])
    dfs(i);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    flag=0; MST(vis,0);
    scanf("%d%d%d",&n,&h,&r);
    FORR(i,1,n){
      scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].z);
    }
    FORR(i,1,n) if(node[i].z<=r && !vis[i])
      dfs(i);

    printf("%s\n", flag ? "Yes" : "No" );
  }

  return 0;
}

/*
const int MAX=1020;
int n,h,r;
struct Node{
  int x,y,z;
}node[MAX];
int p[MAX];

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void merge(int x, int y){
  x=find(x); y=find(y);
  if(x==y) return;
  if(p[x]<p[y]){
    p[x]+=p[y]; p[y]=x;
  }else{
    p[y]+=p[x]; p[x]=y;
  }
}
inline double dis(Node & a, Node & b){
  double dx=a.x-b.x, dy=a.y-b.y, dz=a.z-b.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(p,-1);
    scanf("%d%d%d",&n,&h,&r);
    FORR(i,1,n){
      scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].z);
    }
    double dr=r<<1;
    FORR(i,1,n) FORR(j,i+1,n)
      if(dis(node[i],node[j])<=dr) merge(i,j);
      //if(dis(node[i],node[j])-dr<EPS) merge(i,j);
      //不使用 EPS 进行比较，除非开得够小（只在判断是否相等时使用 EPS ）
    FORR(i,1,n) if(node[i].z<=r) merge(0,i);
    FORR(i,1,n) if(node[i].z+r>=h) merge(i,n+1);

    printf("%s\n", find(0)==find(n+1) ? "Yes" : "No" );
  }

  return 0;
}
*/
