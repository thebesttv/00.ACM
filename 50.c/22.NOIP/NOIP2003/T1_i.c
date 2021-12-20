/*
描述
神经网络就是一张有向图，图中的节点称为神经元，而且两个神经元之间至多有一条边相连，下图是一个神经元的例子：

  X1 --\
        \ +---------+ /--- Y1
  X2 ---- | C1 | U1 |
        / +---------+ \--- Y2
  X3 --/

        神经元（编号为1）
图中，X1—X3是信息输入渠道，Y1－Y2是信息输出渠道，C1表示神经元目前的状态，Ui是阈值，可视为神经元的一个内在参数。
神经元按一定的顺序排列，构成整个神经网络。在兰兰的模型之中，神经网络中的神经元分为几层；称为输入层、输出层，和若干个中间层。每层神经元只向下一层的神经元输出信息，只从上一层神经元接受信息。下图是一个简单的三层神经网络的例子。

     --3--
    /     \
  1-       --6
    \     /
     --4--
    /     \
  2-       --7
    \     /
     --5--

兰兰规定，Ci服从公式：（其中n是网络中所有神经元的数目）

Ci = sum{Wji * Cj | <j,i>连通} - Ui

公式中的Wji（可能为负值）表示连接j号神经元和 i号神经元的边的权值。当 Ci大于0时，该神经元处于兴奋状态，否则就处于平静状态。当神经元处于兴奋状态时，下一秒它会向其他神经元传送信号，信号的强度为Ci。
如此，在输入层神经元被激发之后，整个网络系统就在信息传输的推动下进行运作。现在，给定一个神经网络，及当前输入层神经元的状态（Ci），要求你的程序运算出最后网络输出层的状态。

格式
输入格式
输入第一行是两个整数n（1≤n≤200）和p。接下来n行，每行两个整数，第i＋1行是神经元i最初状态和其阈值（Ui），非输入层的神经元开始时状态必然为0。再下面P行，每行由两个整数i，j及一个整数Wij，表示连接神经元i、j的边权值为Wij。

输出格式
输出包含若干行，每行有两个整数，分别对应一个神经元的编号，及其最后的状态，两个整数间以空格分隔。仅输出最后兴奋的输出层神经元状态，并且按照编号由小到大顺序输出！
若输出层的神经元最后状态均为 0，则输出 NULL。

样例
样例输入1
5 6
1 0
1 0
0 1
0 1
0 1
1 3 1
1 4 1
1 5 1
2 3 1
2 4 1
2 5 1

样例输出1
3 1
4 1
5 1

限制
每个测试点1s

来源
NOIP2003第一题
*/

/*
  得分：20
  解题报告：
    使用bfs，确定每个神经元的层次，并对其指向的神经元更新，同时维护一个maxDepth。
    最后将每个深度为maxDepth的神经元输出。
  问题：
    1.代码过长，多冗余。
    2.步骤繁琐。
    3.不能正确估计时间复杂度，因此过多使用vector，Node中from, to只要用int记录数量就能解决，却使用vector。

  正解：
    源自网络，非常精简的代码。
    Node中使用(int)from, to记录入边和出边的数量，由此判断一个节点是否被更新结束、是否为输入层或输出层。并且在bfs中使用一个节点对它所指向的节点进行更新，值得学习。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAX=220;
const int INF=0x7fffffff;
struct Node{
  int c,u;
  int from,to;
}node[MAX];
int G[MAX][MAX],n;

int main(void){
  for(int i=0;i<MAX;i++) for(int j=0;j<MAX;j++) G[i][j]=INF;  //可能有权值为0的边
  int p; scanf("%d%d",&n,&p);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&node[i].c,&node[i].u);
    if(!node[i].c) node[i].c-=node[i].u;  //先减去u，防止之后判断某个节点是否加完
  }
  for(int i=0;i<p;i++){
    int u,v,w; scanf("%d%d%d",&u,&v,&w);
    G[u][v]=w; node[u].to++; node[v].from++;  //记录入边和出边个数
  }

  queue<int> q;
  for(int i=1;i<=n;i++) if(!node[i].from && node[i].c) q.push(i);
  while(!q.empty()){
    int t=q.front(); q.pop();
    //if(node[t].c<=0) continue;  //<1>
    for(int i=1;i<=n;i++) if(G[t][i]!=INF){ //对于每个节点，更新它所指向的节点，而不是逆其道而行
      node[i].c+=G[t][i]*node[t].c;
      node[i].from--; //<b>node[t].to不自减，为之后输出判断服务</b>
      if(!node[i].from && node[i].c>0) q.push(i); //第二个条件可方便<1>处不用判断（上方注释处）
    }
  }
  bool flag=0;
  for(int i=1;i<=n;i++) if(!node[i].to && node[i].c>0){
    flag=1; printf("%d %d\n",i,node[i].c);
  }
  if(!flag) printf("NULL\n");

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX=220;
struct Node{
  int c,u;
  int depth,num;
  vector<int> from,to;
}node[MAX];
int q[MAX];
bool vis[MAX];
int G[MAX][MAX],n,p;
int maxDepth=0;

int main(void){
  scanf("%d%d",&n,&p);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&node[i].c,&node[i].u); node[i].num=i;
  }
  int u,v,w;
  for(int i=0;i<p;i++){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=w;
    node[u].to.push_back(v); node[v].from.push_back(u);
  }

  //bfs
  int head=0,tail=0;
  for(int i=1;i<=n;i++) if(node[i].c) {q[tail++]=i; vis[i]=1;}
  while(head<tail){
    int t=q[head++];
    if(node[t].c<=0) continue;
    int u,v;
    for(int i=node[t].to.size()-1;i>=0;i--){ //node[t]指向的神经元
      v=node[t].to[i];
      if(vis[v]) continue;
      else vis[v]=1;
      int sum=-node[v].u;
      for(int j=node[v].from.size()-1;j>=0;j--){  //指向v的神经元
        u=node[v].from[j];  //<b> u在if之前</b>
        if(node[u].c>0){  //<b>只有兴奋(c>0)的神经元才能传递信息</b>
          sum+=G[u][v]*node[u].c;
        }
      }
      node[v].c=sum; node[v].depth=node[t].depth+1;
      maxDepth=max(maxDepth,node[v].depth);
      q[tail++]=v;
    }
  }
  bool flag=0;
  for(int i=1;i<=n;i++) if(node[i].depth==maxDepth && node[i].c>0){ //如果用之前的pos会RE
    flag=1; printf("%d %d\n",i,node[i].c);
  }
  if(!flag) printf("NULL\n");
  return 0;
}
*/

/*
//已AC
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX=220;
struct Node{
  int c,u;
  int depth,num;
  vector<int> from,to;
}node[MAX];
int q[MAX];
bool vis[MAX];
int G[MAX][MAX],n,p;
int maxDepth=0;
vector<int> input,output;

int main(void){
  scanf("%d%d",&n,&p);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&node[i].c,&node[i].u); node[i].num=i;
    if(node[i].c) input.push_back(i);
  }
  int u,v,w;
  for(int i=0;i<p;i++){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=w;
    node[u].to.push_back(v); node[v].from.push_back(u);
  }
#ifdef DEBUG
  printf("  input:");
  for(int i=input.size()-1;i>=0;i--) printf(" %d",input[i]); printf("\n");
#endif

  //bfs
  int head=0,tail=0;
  for(int i=input.size()-1;i>=0;i--) {q[tail++]=input[i]; vis[input[i]]=1;}
  while(head<tail){
    int t=q[head++]; Node temp=node[t];
    if(temp.c<=0) continue;
    int u,v,w;
    for(int i=temp.to.size()-1;i>=0;i--){ //temp指向的神经元
      v=temp.to[i];
      if(vis[v]) continue;
      else vis[v]=1;
      int sum=-node[v].u;
      for(int j=node[v].from.size()-1;j>=0;j--){  //指向v的神经元
        u=node[v].from[j];
        if(node[u].c>0) sum+=G[u][v]*node[u].c;
      }
      node[v].c=sum; node[v].depth=temp.depth+1;
      maxDepth=max(maxDepth,node[v].depth);
      q[tail++]=v;
    }
  }

  bool flag=0;
  int pos=tail;
  while(pos-1>=0 && node[q[pos-1]].depth==maxDepth) pos--;
  while(pos<tail){
    if(node[q[pos]].c>0){
      flag=1;
      output.push_back(q[pos]);
    }
    pos++;
  }
  if(!flag) printf("NULL\n");
  else{
    sort(output.begin(),output.end(),greater<int>());
    for(int i=output.size()-1;i>=0;i--){
      int num=output[i];
      printf("%d %d\n",num,node[num].c);
    }
  }

  return 0;
}
*/
