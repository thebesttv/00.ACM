/*
描述
研究表明，这种传染病的传播具有两种很特殊的性质；

第一是它的传播途径是树型的，一个人X只可能被某个特定的人Y感染，只要Y不得病，或者是XY之间的传播途径被切断，则X就不会得病。
第二是这种疾病的传播有周期性，在一个疾病传播周期之内，传染病将只会感染一代患者，而不会再传播给下一代。

这些性质大大减轻了蓬莱国疾病防控的压力，并且他们已经得到了国内部分易感人群
的潜在传播途径图（一棵树）。但是，麻烦还没有结束。由于蓬莱国疾控中心人手不够，同时也缺乏强大的技术，以致他们在一个疾病传播周期内，只能设法切断一条传播途径，而没有被控制的传播途径就会引起更多的易感人群被感染（也就是与当前已经被感染的人有传播途径相连，且连接途径没有被切断的人群）。当不可能有健康人被感染时，疾病就中止传播。所以，蓬莱国疾控中心要制定出一个切断传播途径的顺序，以使尽量少的人被感染。你的程序要针对给定的树，找出合适的切断顺序。

格式
输入格式
输入格式的第一行是两个整数n（1≤n≤300）和p。接下来p行，每一行有两个整数i和j，表示节点i和j间有边相连（意即，第i人和第j人之间有传播途径相连）。其中节点1是已经被感染的患者。

输出格式
只有一行，输出总共被感染的人数。

样例1
样例输入1
7 6
1 2
1 3
2 4
2 5
3 6
3 7

样例输出1
3

限制
每个测试点1s

来源
NOIP2003第四题
*/

/*
  得分：20
  解题报告：
    一开始想到两种贪心：每次选子树最大的节点、每次选度最大的节点，但发现都不可行。
    后来想到使用类似上一题的记忆化搜索，引入check[340]，写出代码。
    但考虑到1号节点不一定为根节点，将边都改为无向边。（当然也可以重构代码，通过无向图生成根为1号节点的树）
    后来右发现之前代码错误，可能导致一层有多个节点被切断，又将check和bfs增加一维。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<list>
using namespace std;

const int MAX=320;
list<int> li[MAX];
bool vis[MAX];
int depth[MAX],maxDepth;
int ansMin=1<<30,n,p;

void build();
void dfs(int cur, vector<int> & v, int ans);  //当前层为cur，当前层被感染的人组成v，根节点到当前层被感染的人数为ans

int main(void){
  scanf("%d%d",&n,&p);
  for(int i=0;i<p;i++){
    int x,y; scanf("%d%d",&x,&y);
    li[x].push_back(y); li[y].push_back(x);
  }
  build();
  vector<int> v; v.push_back(1);
  dfs(0,v,1);
  printf("%d\n",ansMin);

  return 0;
}

void build(){
  queue<int> q; q.push(1); vis[1]=1;
  while(!q.empty()){
    int t=q.front(); q.pop();
    list<int>::iterator it;
    for(it=li[t].begin();it!=li[t].end();it++) if(!vis[*it]){
      q.push(*it); vis[*it]=1; depth[*it]=depth[t]+1;
      depth[*it]>maxDepth ? maxDepth=depth[*it] : 0 ;
    }
  }
}
void dfs(int cur, vector<int> & v, int ans){
  if(ans>ansMin) return;
  if(cur==maxDepth) {ansMin=ans; return;} //如果传播到了最后一层，更新ansMin并返回

  int siz=v.size();
  list<int>::iterator it; for(int i=0;i<siz;i++){
    for(it=li[v[i]].begin();it!=li[v[i]].end();it++)
    if(depth[*it]==depth[v[i]]+1) v.push_back(*it); //<b>因按照无向图存储，所以必须判断(*it)层数，否则可能加入其父节点而非子节点</b>
  int newSiz=v.size();
  if(newSiz==siz) {ansMin=min(ansMin,ans); return;} //<b>如果当前无法继续扩展，更新ansMin并返回</b>
  else for(int i=siz;i<newSiz;i++){
    vector<int> tv;
    for(int j=siz;j<newSiz;j++) if(i!=j) tv.push_back(v[j]);
    int add=tv.size();
    dfs(cur+1,tv,ans+add);
  }
}

/*
//得分：80, TLE
//原因：搜索时未剪枝
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<list>
using namespace std;

const int MAX=320;
bool vis[MAX];
list<int> li[MAX];
int depth[MAX],n;
bool mark[MAX];

void build();
int bfs(vector<int> & q);

int main(void){
  int p; scanf("%d%d",&n,&p);
  for(int i=0;i<p;i++){
    int u,v; scanf("%d%d",&u,&v);
    li[u].push_back(v); li[v].push_back(u);
  }
  build();
#ifdef DEBUG
  printf("  depth:"); for(int i=1;i<=n;i++) printf(" %d",depth[i]); printf("\n");
#endif
  vector<int> v; v.push_back(1);
  int ans=bfs(v)+1;
  printf("%d\n",ans);

  return 0;
}

void build(){
  queue<int> q; q.push(1); vis[1]=1;
  while(!q.empty()){
    int t=q.front(); q.pop();
    list<int>::iterator it;
    for(it=li[t].begin();it!=li[t].end();it++) if(!vis[*it]){
      vis[*it]=1; q.push(*it); depth[*it]=depth[t]+1;
    }
  }
}
int bfs(vector<int> & v){
#ifdef DEBUG
  printf("  bfs:"); for(int i=v.size()-1;i>=0;i--) printf(" %d",v[i]); printf("\n");
#endif
  int ans;
  if(!v.size()) ans=0;
  else{
    ans=1<<30;
    int siz=v.size();
    list<int>::iterator it;
    for(int i=0;i<siz;i++) for(it=li[v[i]].begin();it!=li[v[i]].end();it++)
      if(depth[*it]==depth[v[i]]+1) v.push_back(*it);
    int newSiz=v.size();
    if(siz==newSiz) ans=0;
    else for(int cut=siz;cut<newSiz;cut++){
      vector<int> tv;
      for(int j=siz;j<newSiz;j++) if(cut!=j) tv.push_back(v[j]);
      int sum=tv.size()+bfs(tv);
      ans=min(ans,sum);
    }
  }
  return ans;
}
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

struct Node{
  vector<int> to;
}node[320];
int n;
bool vis[320];
int check[320][2];

int bfs(int root, bool isok);

int main(void){
  memset(check,-1,sizeof(check));
  int m; scanf("%d%d",&n,&m);
  if(m==0) printf("1\n");
  else{
    int u,v;
    for(int i=0;i<m;i++){
      scanf("%d%d",&u,&v);
      node[u].to.push_back(v);
      node[v].to.push_back(u);
    }
    vis[1]=1;
    int ansMin=bfs(1,1)+1;
    printf("%d\n",ansMin);
  }
  return 0;
}

int bfs(int root, bool isok){
#ifdef DEBUG
  printf("  bfs(%d)\n",root);
#endif
  int & a=check[root][isok];
  vector<int> & v=node[root].to;
  if(a!=-1) return a;
  if(v.size()==1) return a=0;
  a=1<<30;
  int siz=v.size();
  vector<int> tv;
  if(isok){
    for(int i=0;i<siz;i++) if(!vis[v[i]]){
      vis[v[i]]=1;
      tv.clear();
      for(int j=0;j<siz;j++) if(j!=i && !vis[v[j]]) tv.push_back(v[j]),vis[v[j]]=1;
      for(int ava=tv.size()-1;ava>=0;ava--){
        int sum=tv.size();
        for(int j=tv.size()-1;j>=0;j--){
          if(j==ava) sum+=bfs(tv[j],1);
          else sum+=bfs(tv[j],0);
        }
        a=min(a,sum);
      }
      for(int j=tv.size()-1;j>=0;j--) vis[v[j]]=0;
      vis[v[i]]=0;
    }
  }else{
    for(int i=v.size()-1;i>=0;i--){
      int sum=v.size();
      for(int j=v.size()-1;j>=0;j--){
        if(j==i) sum+=bfs(v[j],1);
        else sum+=bfs(v[j],0);
      }
      a=min(a,sum);
    }
  }
  return a;
}
*/
