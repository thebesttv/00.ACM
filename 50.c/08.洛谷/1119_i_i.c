/*
题目背景
B地区在地震过后，所有村庄都造成了一定的损毁，而这场地震却没对公路造成什么影响。但是在村庄重建好之前，所有与未重建完成的村庄的公路均无法通车。换句话说，只有连接着两个重建完成的村庄的公路才能通车，只能到达重建完成的村庄。

题目描述
给出B地区的村庄数N，村庄编号从0到N-1，和所有M条公路的长度，公路是双向的。并给出第i个村庄重建完成的时间t[i]，你可以认为是同时开始重建并在第t[i]天重建完成，并且在当天即可通车。若t[i]为0则说明地震未对此地区造成损坏，一开始就可以通车。之后有Q个询问 (x,y,t) ，对于每个询问你要回答在第t天，从村庄x到村庄y的最短路径长度为多少。如果无法找到从x村庄到y村庄的路径，经过若干个已重建完成的村庄，或者村庄x或村庄y在第t天仍未重建完成 ，则需要返回-1。

输入输出格式
输入格式：
输入文件rebuild.in的第一行包含两个正整数N，M，表示了村庄的数目与公路的数量。
第二行包含N个非负整数t[0], t[1], …, t[N – 1]，表示了每个村庄重建完成的时间，数据保证了t[0] ≤ t[1] ≤ … ≤ t[N – 1]。
接下来M行，每行3个非负整数 i,j,w ，w为不超过10000的正整数，表示了有一条连接村庄i与村庄j的道路，长度为w，保证i≠j，且对于任意一对村庄只会存在一条道路。
接下来一行也就是M+3行包含一个正整数Q，表示Q个询问。
接下来Q行，每行3个非负整数 x,y,t ，询问在第t天，从村庄x到村庄y的最短路径长度为多少，数据保证了t是不下降的。

输出格式：
输出文件rebuild.out包含Q行，对每一个询问(x, y, t)输出对应的答案，即在第t天，从村庄x到村庄y的最短路径长度为多少。如果在第t天无法找到从x村庄到y村庄的路径，经过若干个已重建完成的村庄，或者村庄x或村庄y在第t天仍未修复完成，则输出-1。

输入输出样例
输入样例#1：
4 5
1 2 3 4
0 2 1
2 3 1
3 1 2
2 1 4
0 3 5
4
2 0 2
0 1 2
0 1 3
0 1 4

输出样例#1：
-1
-1
5
4

说明
对于30%的数据，有N≤50；
对于30%的数据，有t[i] = 0，其中有20%的数据有t[i] = 0且N＞50；
对于50%的数据，有Q≤100；
对于100%的数据，有N≤200，M≤N*(N-1)/2，Q≤50000，所有输入数据涉及整数均不超过100000。
*/

/*
  解题报告：
    一开始想到用Floyd，感觉最不济O(n^4+q)应该能过，结果WA了几次就T了。。。
    不过一开始还是学到点东西：
      因为村庄被修好的时间是单调不递减的，那么就可以枚举当前被修好的村庄，在每次枚举中来一个Floyd，再尝试回答问题。
   <b>只有当前被枚举的村庄h的t[h]!=t[h+1]时才可以回答Q.t<t[h+1]的问题。</b>
    等到没有WA，又T了一半的时候，痛定思痛，想到了一个O(n^3+q)的算法。
  歪解：
    想要优化，枚举的n是不能动了，只能优化n^3。
    想到每次枚举后又重新Floyd，是因为新增加的点<b>增加了许多条有效边</b>，所以其他点都要重新进行松弛。
    也就是说，<b>其他点对(i,j)如果能被更新，一定是被更新成 G[i][j] = G[i][h] + G[h][i] 的形式</b>。
    但如果只枚举 G[i][j] = min( G[i][j], G[i][h] + G[h][j] ) 的话，连样例都过不了。
      因为如果要更新，确实是那样的形式，但<b>不能保证 G[i][h] 或 G[h][j] 就是最短的，它们很有可能还没被更新</b>。
    由此，尝试使用Dij做一次以当前枚举村庄h为起点的单源最短路，然后再用O(h^2)枚举(i,j)并更新，更新完后回答问题即可。
    时间复杂度：O(n*(mlongn+n^2)+q)=O(n^3+q)
  正解： O(n^3+q)
    本题中，调用Floyd算法其实就是枚举村庄k再使用k更新其他村庄i,j，那么可以像之前一样，在枚举h的时候用h更新其他点，只不过更新的(i,j)中i,j范围都是[0,n-1]，也可以对每个问题根据其时间看是否有<b>新的</b>村庄k被加入，如果有就更新。
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

//Dij
const int MAX=220;
const int MAXQ=50020;
const int INF=0x3f3f3f3f;
int n,m,t[MAX],nq;
struct Quest{
  int x,y,t;
}Q[MAXQ];
int G[MAX][MAX],d[MAX];
int cur;
struct Node{
  int u,d;
  bool operator < (const Node & b) const {return d>b.d;}
};

void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push((Node){s,0});
  while(!q.empty()){
    Node tn=q.top(); q.pop();
    int u=tn.u;
    if(d[u]!=tn.d) continue;
    FORR(i,0,cur) if(G[u][i]<INF && d[i]>d[u]+G[u][i]){
      d[i]=d[u]+G[u][i];
      q.push((Node){i,d[i]});
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) scanf("%d",&t[i]);
  t[n]=t[n-1]+1;
  MST(G,0x3f); FOR(i,0,n) G[i][i]=0;
  for(int i=0,u,v,w;i<m;i++){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=G[v][u]=w;
  }
  scanf("%d",&nq);
  FOR(i,0,nq) scanf("%d%d%d",&Q[i].x,&Q[i].y,&Q[i].t);

  int pos=0;  //pos of quest
  for(cur=0;cur<n;cur++){ //枚举当前已建成村庄
    Dij(cur);
    FORR(i,0,cur) FORR(j,0,cur)
      G[i][j]=min(G[i][j],d[i]+d[j]);
    if(t[cur]!=t[cur+1]){ //<b> </b>
      int nt=t[cur+1];
      while(pos<nq && Q[pos].t<nt){
        int x=Q[pos].x,y=Q[pos].y;
        int ans=G[x][y];
        if(t[x]>=nt || t[y]>=nt) ans=INF;
        printf("%d\n",ans>=INF ? -1 : ans);
        pos++;
      }
      if(pos==nq) break;
    }
  }
  while(pos<nq){
    int x=Q[pos].x,y=Q[pos].y;
    int ans=G[x][y];
    printf("%d\n",ans>=INF ? -1 : ans);
    pos++;
  }

  return 0;
}

/*
//对每个问题看有没有新的k
const int MAX=220;
const int INF=0x3f3f3f3f;
int n,m,t[MAX],nq;
int G[MAX][MAX];
bool vis[MAX];  //判断村庄i是否被用来更新过

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) scanf("%d",&t[i]);  t[n]=t[n-1]+1;
  MST(G,0x3f); FOR(i,0,n) G[i][i]=0;
  for(int i=0,u,v,w;i<m;i++){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=G[v][u]=w;
  }

  scanf("%d",&nq);
  FOR(ii,0,nq){
    int x,y,day; scanf("%d%d%d",&x,&y,&day);
    FOR(k,0,n) (!vis[k] && t[k]<=day){
      vis[k]=1;
      FOR(i,0,n) if(G[i][k]<INF)
        FOR(j,0,n) if(G[k][j]<INF)
          G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    }
    if(t[x]>day || t[y]>day || G[x][y]>=INF) printf("%d\n",-1);
    else printf("%d\n",G[x][y]);
  }

  return 0;
}
*/


/*
//枚举每个k，看问题
const int MAX=220;
const int MAXQ=50020;
const int INF=0x3f3f3f3f;
int n,m,t[MAX],q;
int G[MAX][MAX];
struct Quest{
  int x,y,t;
}quest[MAXQ];

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) scanf("%d",&t[i]);
  t[n]=t[n-1]+1;
  MST(G,0x3f);
  int u,v,w;
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    G[u][v]=G[v][u]=w;
  }
  FOR(i,0,n) G[i][i]=0;
  scanf("%d",&q);
  FOR(i,0,q) scanf("%d%d%d",&quest[i].x,&quest[i].y,&quest[i].t);

  int pos=0;
  FOR(k,0,n){ //村庄
    int day=t[k];
    FOR(i,0,n) if(G[i][k]<INF) FOR(j,0,n) if(G[k][j]<INF) //<b> i和j的范围都是[0,n-1] </b>
      G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
    if(t[k]!=t[k+1]) while(pos<q && quest[pos].t<t[k+1]){
      int u=quest[pos].x,v=quest[pos].y;
      int ans=G[u][v];
      if(t[u]>=t[k+1] || t[v]>=t[k+1]) ans=INF;
      printf("%d\n",ans==INF ? -1 : ans);
      pos++;
    }
    if(pos==q) break;
  }
  while(pos<q){
    int u=quest[pos].x,v=quest[pos].y;
    int ans=G[u][v];
    printf("%d\n",ans==INF ? -1 : ans);
    pos++;
  }

  return 0;
}
*/
