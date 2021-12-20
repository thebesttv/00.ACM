/*
题目描述
2020年，人类在火星上建立了一个庞大的基地群，总共有n个基地。起初为了节约材料，人类只修建了n-1条道路来连接这些基地，并且每两个基地都能够通过道路到达，所以所有的基地形成了一个巨大的树状结构。如果基地A到基地B至少要经过d条道路的话，我们称基地A到基地B的距离为d。
由于火星上非常干燥，经常引发火灾，人类决定在火星上修建若干个消防局。消防局只能修建在基地里，每个消防局有能力扑灭与它距离不超过2的基地的火灾。
你的任务是计算至少要修建多少个消防局才能够确保火星上所有的基地在发生火灾时，消防队有能力及时扑灭火灾。

输入输出格式
输入格式：
输入文件名为input.txt。
输入文件的第一行为n （n<=1000），表示火星上基地的数目。接下来的n-1行每行有一个正整数，其中文件第i行的正整数为a[i]，表示从编号为i的基地到编号为a[i]的基地之间有一条道路，为了更加简洁的描述树状结构的基地群，有a[i]<i。

输出格式：
输出文件名为output.txt
输出文件仅有一个正整数，表示至少要设立多少个消防局才有能力及时扑灭任何基地发生的火灾。

输入输出样例
输入样例#1：
6
1
2
3
4
5

输出样例#1：
2
*/

/*
  解题报告：
    昏昏沉沉地写了一个DP，然而并没有成功，然后去看了看题解，发现竟然可以贪心。。。
  贪心：
    因为最深的节点一定要被选到，那么可以从最深的节点开始选择。
    而从底部往上看每一个节点，如果要使其覆盖，那么选择它的第二级父节点一定不会更差，证明略。
    那么就可以先进行一遍bfs求出每个节点到根节点的距离，然后从距离最远的节点开始，每次选择其第二级父节点并且将被覆盖的所有点都打上标记，最后即为答案。
  树形DP：
    然后看了看别人的DP，找到了一个我之前没想到的枚举方法，感觉我的DP还是可以抢救一下的 XD
    令 f(u,d) 表示当前在节点u，u上方离它最近的消防局距离为d，那么就有五种状态：
      f(u,0): 即选择u，那么u的子节点可以选也可以不选
        f(u,0) = sum{ min(f(v,0),f(v,1) | v为u的子节点 }
      f(u,1): u的节点可以选也可以不选
        f(u,1) = sum{ min(f(v,0),f(v,2) | v为u的子节点 }
      f(u,2): u的节点依旧是可以选也可以不选
                但如果选了，那么其他没有选择的子节点离最近的消防局距离就是2，而非3
                如果不选，那么距离都是3
        s1 = sum{ f(v,3) }
        s2 = sum{ f{v,0) + f(v',2) | v属于选则的集合S，v'属于不选的集合S' }
        f(u,2) = min(s1,s2)
      f(u,3): 依旧要注意选还是不选的情况，但还要注意u是否为叶节点的情况，u如果是叶节点，那么该情况非法，返回INF
        s1 = sum{ f(v,4) }
        s2 = sum{ f{v,0) + f(v',2) | v属于选则的集合S，v'属于不选的集合S' }
        f(u,3) = min(s1,s2)
      f(u,4): 如果它的子节点都不选，那么u的父节点将变为非法，因此至少要选择一个
        f(u,4) = sum{ f(v,0) + f(v',2) | v属于选则的集合S，v'属于不选的集合S' }
    有了转移方程，但实现后三种的枚举集合还是不容易。
    其实对于后三种的枚举，可以先确定一个一定选择的节点，然后其他节点就变成可选可不选，就可以用min看选和不选哪个好了。
      FOR(i,0,G[u].size()){
        int sum=f(G[u][i],0); //选
        FOR(j,0,G[u].size()) if(j!=i)
          sum+=min(f(G[u][j],0),f(G[u][j],2));  //选和不选都可以
        a=min(a,sum);
      }
    当然DP还有至少两种不同的状态方程，暂时就不看了。
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

const int MAX=1020;
const int INF=0x3f3f3f3f;
VR<int> G[MAX];
int n,check[MAX][5];

//f(i,d): 在点i，i上方离它最近的消防局距离为d

int f(int u, int d);

int main(void){
  scanf("%d",&n);
  for(int i=2,p;i<=n;i++){
    scanf("%d",&p);
    G[p].push_back(i);
  }
  MST(check,-1);
  printf("%d\n",min(f(1,0),min(f(1,3),f(1,4))));

  return 0;
}

int f(int u, int d){
  int & a=check[u][d];
  if(a!=-1) return a;
  if(!G[u].size()){ //leaf
    if(d==0) a=1;
    else if(d>=3) a=INF;
    else a=0;
  }else{
    a=0;
    if(d==0){ //选i
      a=1;
      FOR(i,0,G[u].size()) a+=min(f(G[u][i],0),f(G[u][i],1));
    }else if(d==1){
      FOR(i,0,G[u].size()) a+=min(f(G[u][i],0),f(G[u][i],2));
    }else if(d==2){
      int s1=0;
      FOR(i,0,G[u].size()){ //子节点一个都不选
        int t=f(G[u][i],3);
        if(t==INF) {s1=INF; break;}
        else s1+=t;
      }

      //子节点至少选一个
      int s2=INF;
      FOR(i,0,G[u].size()){ //选i
        int sum=f(G[u][i],0);
        FOR(j,0,G[u].size()) if(j!=i){
          int t=min(f(G[u][j],0),f(G[u][j],2));
          if(t==INF) {sum=INF; break;}
          else sum+=t;
        }
        s2=min(s2,sum);
      }
      a=min(s1,s2);
    }else if(d==3){
      int s1=0;
      FOR(i,0,G[u].size()){ //子节点一个都不选
        int t=f(G[u][i],4);
        if(t==INF) {s1=INF; break;}
        else s1+=t;
      }

      int s2=INF;
      FOR(i,0,G[u].size()){
        int sum=f(G[u][i],0);
        FOR(j,0,G[u].size()) if(j!=i){
          int t=min(f(G[u][j],0),f(G[u][j],2));
          if(t==INF) {sum=INF; break;}
          else sum+=t;
        }
        s2=min(s2,sum);
      }
      a=min(s1,s2);
    }else if(d==4){
      a=INF;
      FOR(i,0,G[u].size()){
        int sum=f(G[u][i],0);
        FOR(j,0,G[u].size()) if(j!=i){
          int t=min(f(G[u][j],0),f(G[u][j],2));
          if(t==INF) {sum=INF; break;}
          else sum+=t;
        }
        a=min(a,sum);
      }
    }
  }
  return a;
}

/*
//贪心
const int MAX=1020;
int n,p[MAX],cnt;
VR<int> G[MAX];
bool vis[MAX];
struct Node{
  int u,dis;
  bool operator < (const Node & b) const{
    return dis>b.dis;
  }
}node[MAX];

void del(int u, int left){
  if(!left) return;
  FOR(i,0,G[u].size()){
    int v=G[u][i];
    vis[v]=1; del(v,left-1);
  }
}

int main(void){
  scanf("%d",&n);
  MST(p,-1);
  for(int v=2,u;v<=n;v++){
    scanf("%d",&u);
    p[v]=u; G[u].push_back(v);
  }
 
  queue<int> q;
  q.push(1); node[1].dis=0; node[1].u=1; vis[1]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    FOR(i,0,G[u].size()){
      int v=G[u][i];
      if(vis[v]) continue;
      node[v].dis=node[u].dis+1; node[v].u=v;
      q.push(v); vis[v]=1;
    }
  }
  sort(node+1,node+1+n);

  MST(vis,0);
  FORR(i,1,n) if(!vis[node[i].u]){
    int u=node[i].u;
    cnt++; vis[u]=1;
    if(p[u]!=-1){
      int p1=p[u]; vis[p1]=1; del(p1,1);
      //printf("  in %d, enter p1: %d\n",u,p1);
      if(p[p1]!=-1){
        int p2=p[p1]; vis[p2]=1; del(p2,2);
        //printf("  in %d, enter p2: %d\n",u,p2);
        if(p[p2]!=-1){
          int p3=p[p2]; vis[p3]=1; del(p3,1);
          //printf("  in %d, enter p3: %d\n",u,p3);
          if(p[p3]!=-1){
            int p4=p[p3]; vis[p4]=1;
            //printf("  in %d, enter p4: %d\n",u,p4);
          }
        }
      }
    }
  }
  printf("%d\n",cnt);

  return 0;
}
*/
