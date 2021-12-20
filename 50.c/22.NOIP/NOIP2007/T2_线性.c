/*
看到八中OJ上面吧NOIP原题的n=300扩大到了n=500000，就研究了一下O(n)的算法。

首先要确定的是如果有好几条直径的话，任意一个上面都会有一个核。 证明的话可以这么想：先考虑有两条直径的情况，因为这是一棵树，所以两个直径肯定有重合的部分，如果核在重合的部分就不用说了。如果在其他地方呢，那么是不可能的= =！为什么呢？先把两条直径简化成>--<的形状，那么重合的部分的一侧的两条链是对称的。如果核在<上，那其偏心距肯定在>--上。这么看来的话肯定不如核在中间部分优。

怎么找到一条直径呢，最简单的办法就是先任选一个点开始BFS/DFS，找到一个最远的点，这个点一定是直径的一个端点。再从这个点开始找一个最远的点就是另一个端点。这个算法的正确性很显然（参照树和直径的性质）。

我们把直径上的每一个点都作为一个根，把与其相连的非直径点作为节点构建外向树。求每一个直径上的点的到外向树的点的最大距离。

假设我们考虑链上的某个部分，那么偏心距的来源只可能是从直径的两端或者是刚才求过的外向树最大距离。

而且我们还能发现有包含关系的两部分，较长的部分的偏心距一定不会更大。

综上我们使用单调队列来维护这个最小的偏心距。整个算法的复杂度为O(n)

我本来因为懒选择了DFS，结果发现递归爆栈了。于是咬牙自己第一次写了人工栈，写的挺烂的。。。
*/

#include<cstdio>
#include<cstring>
  struct edge{
    int point;
    int data;
    edge *next;
  };  
struct vertex{
  edge *link;
  vertex(){
    link=NULL;
  }   
};  
struct queue{
  int data;
  int pos;
};  
int max,n,s,a,b,c,dist[500010],relax[500010],F[500010],stack[500010],stack2[500010],top;
edge *doing[500010];
vertex g[500010];
queue D[500010];
bool mark[500010];
void insert(int from,int to,int value){
  edge *temp=new edge;
  (*temp).data=value;
  (*temp).next=g[from].link;
  (*temp).point=to;
  g[from].link=temp;
}   
void search(int h){
  mark[h]=true;
  stack[++top]=h;
  stack2[top]=0;
  doing[top]=g[h].link;
  while (top){
    if (doing[top]==NULL) {if (stack2[top]>max) max=stack2[top];top--;}
    else
      if (!mark[(*doing[top]).point]){
        mark[(*doing[top]).point]=true;
        stack[top+1]=(*doing[top]).point;
        stack2[top+1]=stack2[top]+(*doing[top]).data;
        doing[top+1]=g[(*doing[top]).point].link;
        doing[top]=(*doing[top]).next;
        top++;
      }else doing[top]=(*doing[top]).next;   
  }  
}     
void dfs(int h){
  mark[h]=true;
  doing[++top]=g[h].link;
  stack[top]=h;
  while (top)
    if (doing[top]==NULL) top--;
    else
      if (!mark[(*doing[top]).point]){
        mark[(*doing[top]).point]=true;
        relax[(*doing[top]).point]=stack[top];
        dist[(*doing[top]).point]=dist[stack[top]]+(*doing[top]).data;
        stack[top+1]=(*doing[top]).point;
        doing[top+1]=g[(*doing[top]).point].link;
        doing[top]=(*doing[top]).next;
        top++;
      } else doing[top]=(*doing[top]).next;
}          
int main(){
  scanf("%d%d",&n,&s);
  for (int i=1;i<n;i++){
    scanf("%d%d%d",&a,&b,&c);
    insert(a,b,c);
    insert(b,a,c);
  }
  dfs(1);
  int st,ed;
  for (int i=1;i<=n;i++)
    if (dist[i]>max) {max=dist[i];ed=i;}
  memset(mark,0,sizeof(mark));
  memset(dist,0,sizeof(dist));
  dfs(ed);max=0;
  for (int i=1;i<=n;i++)
    if (dist[i]>max) {max=dist[i];st=i;}
  memset(mark,0,sizeof(mark));    
  mark[st]=true;F[1]=st;  
  int num=1,now=st;
  do{
    now=relax[now];
    mark[now]=true;
    F[++num]=now;
  }while (now!=ed);
  int low=1,L=0,R=-1,ans=(1<<31)-1; 
  for (int i=1;i<=num;i++){
    while (dist[F[low]]-dist[F[i]]>s) low++;
    max=0;search(F[i]);
    while (L<=R&&max>=D[R].data) R--;
    D[++R].pos=i;
    D[R].data=max;
    while (D[L].pos<low) L++;
    max=D[L].data;
    if (dist[F[i]]>max) max=dist[F[i]];
    if (dist[st]-dist[F[low]]>max) max=dist[st]-dist[F[low]];
    if (max<ans) ans=max;    
  }
  printf("%d\n",ans);
  return 0;
}
