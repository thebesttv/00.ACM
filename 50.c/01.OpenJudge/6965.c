/*
描述
给出一个图的结构，输出其拓扑排序序列，要求在同等条件下，编号小的顶点在前。

输入
若干行整数，第一行有2个数，分别为顶点数v和弧数a，接下来有a行，每一行有2个数，分别是该条弧所关联的两个顶点编号。
v<=100, a<=500

输出
若干个空格隔开的顶点构成的序列(用小写字母)。

样例输入
6 8
1 2
1 3
1 4
3 2
3 5
4 5
6 4
6 5

样例输出
v1 v3 v2 v6 v4 v5
*/

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

const int MAX=120;
bool G[MAX][MAX];
int topo[MAX],tail=0,n;
int indegree[MAX];
bool vis[MAX];  //<b>记录已被访问的节点，它们的indegree已为0，不能再被计算</b>
vector<int> out[MAX];
vector<int>::iterator it;

void topo_sort();

int main(void){
  int m; scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
    int x,y; scanf("%d%d",&x,&y);
    G[x][y]=1;
  }
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(G[i][j]){
    out[i].push_back(j);
    indegree[j]++;
  }
  topo_sort();
  for(int i=0;i<n;i++)
    if(i) printf(" v%d",topo[i]);
    else printf("v%d",topo[i]);
  printf("\n");

  return 0;
}

void topo_sort(){
  for(int i=0;i<n;i++){
    int u;
    for(u=1;u<=n;u++) if(!vis[u] && !indegree[u]) break;
    vis[u]=1;
    while(!out[u].empty()){
      //it=out[u].end(); it--;
      it=out[u].end()-1;
      indegree[*it]--;
      out[u].erase(it);
    }
    topo[tail++]=u;
  }
}

/*
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=120;
bool G[MAX][MAX];
int topo[MAX],t,c[MAX],n;

bool dfs(int u){
  c[u]=-1;
  for(int v=n;v>0;v--) if(G[u][v])
    if(c[v]<0) return false;
    else if(!c[v] && !dfs(v)) return false;
  c[u]=1; topo[--t]=u;
  return true;
}
bool topo_sort(){
  t=n;
  for(int u=n;u>0;u--) if(!c[u])
    if(!dfs(u)) return false;
  return true;
}

int main(void){
  int m; scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
    int x,y; scanf("%d%d",&x,&y);
    if(x!=y) G[x][y]=1;
  }
  if(!topo_sort()) printf("wrong\n");
  for(int i=0;i<n;i++){
    if(i) printf(" ");
    printf("v%d",topo[i]);
  }
  printf("\n");

  return 0;
}
*/
