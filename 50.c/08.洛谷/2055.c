/*
题目描述
学校放假了…… 有些同学回家了，而有些同学则有以前的好朋友来探访，那么住宿就是一个问题。比如 A 和 B 都是学校的学生，A 要回家，而 C 来看B，C 与 A 不认识。我们假设每个人只能睡和自己直接认识的人的床。那么一个解决方案就是 B 睡 A 的床而 C 睡 B 的床。而实际情况可能非常复杂，有的人可能认识好多在校学生，在校学生之间也不一定都互相认识。我们已知一共有 n 个人，并且知道其中每个人是不是本校学生，也知道每个本校学生是否回家。问是否存在一个方案使得所有不回家的本校学生和来看他们的其他人都有地方住。

输入输出格式
输入格式：
第一行一个数 T 表示数据组数。接下来 T 组数据，每组数据第一行一个数n 表示涉及到的总人数。接下来一行 n 个数，第 i 个数表示第 i 个人是否是在校学生 (0 表示不是，1 表示是)。再接下来一行 n 个数，第 i 个数表示第 i 个人是否回家 (0 表示不会家，1 表示回家，注意如果第 i 个人不是在校学生，那么这个位置上的数是一个随机的数，你应该在读入以后忽略它)。接下来 n 行每行 n 个数，第 i 行第 j 个数表示 i 和 j 是否认识 (1 表示认识，0 表示不认识，第 i 行 i 个的值为 0，但是显然自己还是可以睡自己的床)，认识的关系是相互的。

输出格式：
对于每组数据，如果存在一个方案则输出 “^_^”(不含引号) 否则输出“T_T”(不含引号)。(注意输出的都是半角字符，即三个符号的 ASCII 码分别为94,84,95)

输入输出样例
输入样例#1： 复制
1
3
1 1 0
0 1 0
0 1 1
1 0 0
1 0 0

输出样例#1： 复制
^_^

说明
对于 30% 的数据满足 1 ≤ n ≤ 12。
对于 100% 的数据满足 1 ≤ n ≤ 50,1 ≤ T ≤ 20。
*/

/*
  解题报告：
    还算是很简单的网络流吧。
    只要将学生与他能睡的床连边，求最大流是否等于需要睡觉的学生人数即可。
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

const int MAX=60;
const int INF=0x3f3f3f3f;
int n,s,t;
int isS[MAX],isH[MAX];
struct Edge{
  int u,v,cap,flow;
}; VR<Edge> edge;
VR<int> G[MAX<<3];
bool vis[MAX<<3];
int d[MAX<<3],cur[MAX<<3];
int q[MAX<<3],head,tail;

inline void addEdge(int u, int v, int cap);
bool bfs();
int dfs(int u, int a);
int MF();

//i: 学生, i+n: 床
int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); s=0; t=n<<2;
    edge.clear(); FORR(i,s,t) G[i].clear();
    FORR(i,1,n){
      scanf("%d",&isS[i]);
      //if(isS[i]) addEdge(i+n,i+(n<<1),1); //有床
      if(isS[i]) addEdge(i+n,t,1); //有床
    }
    int cnt=0;  //在校学生中回家人数
    FORR(i,1,n){
      scanf("%d",&isH[i]);
      if(isS[i]){
        if(!isH[i]) addEdge(0,i,1);
        else cnt++;
      }else addEdge(0,i,1);
    }
    int tt;
    FORR(i,1,n){
      addEdge(i,i+n,1); //睡自己的床
      FORR(j,1,n){
        scanf("%d",&tt);
        if(tt) addEdge(i,j+n,1);
      }
    }

    int ans=MF();
    printf("%s\n", ans==n-cnt ? "^_^" : "T_T" );
  }

  return 0;
}

//i: 学生, i+n: 床, i+2n: 床
//没有必要的拆点
/*
int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); s=0; t=n<<2;
    edge.clear(); FORR(i,s,t) G[i].clear();
    FORR(i,1,n){
      scanf("%d",&isS[i]);
      if(isS[i]) addEdge(i+n,i+(n<<1),1); //有床
    }
    int cnt=0;  //在校学生中回家人数
    FORR(i,1,n){
      scanf("%d",&isH[i]);
      if(isS[i]){
        if(!isH[i]) addEdge(0,i,1);
        else cnt++;
      }else addEdge(0,i,1);
    }
    FORR(i,1,n) addEdge(i+(n<<1),t,1);
    int tt;
    FORR(i,1,n){
      addEdge(i,i+n,1); //睡自己的床
      FORR(j,1,n){
        scanf("%d",&tt);
        if(tt) addEdge(i,j+n,1);
      }
    }

    int ans=MF();
    printf("%s\n", ans==n-cnt ? "^_^" : "T_T" );
  }

  return 0;
}
*/

inline void addEdge(int u, int v, int cap){
  edge.push_back((Edge){u,v,cap,0});
  edge.push_back((Edge){v,u,0,0});
  int sz=edge.size();
  G[u].push_back(sz-2);
  G[v].push_back(sz-1);
}
bool bfs(){
  MST(vis,0);
  head=tail=0;
  q[tail++]=s; d[s]=0; vis[s]=1;
  while(head<tail){
    int u=q[head++];
    FOR(i,0,G[u].size()){
      Edge & e=edge[G[u][i]];
      if(!vis[e.v] && e.cap>e.flow){
        d[e.v]=d[u]+1; vis[e.v]=1;
        q[tail++]=e.v;
      }
    }
  }
  return vis[t];
}
int dfs(int u, int a){
  if(a==0 || u==t) return a;
  int flow=0,f;
  for(int & i=cur[u];i<G[u].size();i++){
    Edge & e=edge[G[u][i]];
    if(d[e.v]==d[u]+1 && (f=dfs(e.v,min(a,e.cap-e.flow)))>0){
      e.flow+=f; edge[G[u][i]^1].flow-=f;
      flow+=f; a-=f;
      if(!a) break;
    }
  }
  return flow;
}
int MF(){
  int ans=0;
  while(bfs()){
    MST(cur,0);
    ans+=dfs(s,INF);
  }
  return ans;
}
