/*
题目背景
还记得NOIP2011的寻宝吗？6年之后，小明带着他的妹子小芳，再次走上了寻宝的道路。
然而这次他们寻宝回来之后，小明被困在了一个迷宫中。

题目描述
迷宫是一个n*m的字符矩阵。
小明在这个矩阵的左上角，只能向下和向右走，去和在矩阵右下角的小芳会合。
小明必须将他走过的路径上的，经过的字符收集起来。如果到右下角时他收集到的这些字符连在一起是回文的，那么他就能够走出这个迷宫，否则他就会掉进陷阱出不来。
小明想知道有多少条路径能够让他走出这个迷宫。由于答案可能很大，请对 1000000007 取模。

输入输出格式
输入格式：
第一行两个整数n和m。
接下来n行，每行m个字符表示这个矩阵，全部均为小写字母

输出格式：
输出一行一个整数表示答案

输入输出样例
输入样例#1：
3 4
aaab
baaa
abba

输出样例#1：
3

说明
对于20%的数据，满足n*m≤10
对于另外10%的数据，满足字符都是a
对于70%的数据，满足n,m≤60
对于100%的数据，满足n,m≤500
*/

/*
  得分：0
  解题报告（考后）：
性质
  对于一个r*c的矩阵，共要经过r+c-1个格子，即回文串长度总为r+c-1。从(0,0)到(r-1,c-1)共走r+c-2步，其中r-1步向下，c-1步向右，因此，一共有C(r+c-2,r-1)种走法。推广：从点(a,b)到点(x,y)共走x-a+y-b步。
  首先，令回文串的中间位置，也是矩阵的“中部”为half_way=floor((r+c)/2)-1，从起点(0,0)和终点(r-1,c-1)各进行一次步数为half_way的bfs，分别将矩阵中步数为half_way的格点的二进制第一、第二位标记为1。会产生两种情况。
    第一种：同一行中有两个格点被标记，数字分别为1,2，计作type1
        +----+      +----+
        |0122|      |0012|
        |1221|  ->  |0120|
        |2210|      |1200|
        +----+      +----+
          1           2       图1为bfs的步数记录，图2为最终的标记矩阵

    第二种：同一行中只有一个格点被标记，数组为3，计作type3
        +---+      +---+
        |012|      |003|
        |121|  ->  |030|
        |210|      |300|
        +---+      +---+
          1          2
  结论：当r+c为奇数时，矩阵类型为type1，而当r+c为偶数时，矩阵类型为type3
  证明：1.r+c为奇数，则 floor((r+c)/2)=floor((r+c-1)/2)=(r+c-1)/2，而总长度r+c-1为偶数，因此其一半即为中间偏左或偏右，共两个，即1和2两种
        2.r+c为偶数，则 floor((r+c)/2)=(r+c)/2，总长度r+c-1为奇数，因此其一半即为正中间，只有一个，即3
[1]动规dp 60分
  令 f(x1,y1,x2,y2) 为从起点到(x1,y1)和从终点反行走向到(x2,y2)能形成的回文串的个数，则
    f(x1,y1,x2,y2) = 0, G[x1][y1]!=G[x2][y2]
                     1, x1=0 && y1=0 && x2=r-1 && y2=c-1 && <b> G[x1][y1]==G[x2][y2] </b>
                     f(x1-1,y1,x2+1,y2) + f(x1-1,y1,x2,y2+1) + f(x1,y1-1,x2+1,y2) + f(x1,y1-1,x2,y2+1)
  对全a的情况不用特判
  可以根据x1,y1,x2推出y2，因此可以只用三维记录
[2]滚动数组优化
*/

//滚动数组优化 unsolved

//三维dp，递归
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef unsigned long long LLU;
const int MOD=1000000007;
const int MAX=500;  //程序500M，本地开不了
int r,c;
unsigned int check[MAX][MAX][MAX];
char G[MAX][MAX];

unsigned int f(int x1,int y1, int x2){
  int y2=r+c-2-x2-x1-y1;
  if(x1<0 || x1>=r ||  x2<0 || x2>=r || y1<0 || y1>=c || y2<0 || y2>=c) return 0;
  unsigned int & a = check[x1][y1][x2];
  if(a!=-1) return a;
  if(x1==0 && y1==0 && x2==r-1) a = (G[0][0]==G[r-1][c-1]);
  else if(G[x1][y1]!=G[x2][y2]) a=0;
  else
    a = ((long long)f(x1,y1-1,x2+1) //<b>注意long long要在括号内，否则会先进行三次加法再被转换为long long</b>
                  + f(x1,y1-1,x2)
                  + f(x1-1,y1,x2+1)
                  + f(x1-1,y1,x2))%MOD;
  return a;
}

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&r,&c); int half_len=(r+c)/2-1;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      do G[i][j]=getchar(); while(!isalpha(G[i][j]));
    }
  }
  memset(check,-1,sizeof(check));
  unsigned long long sum=0;
  if((r+c)&1){  //type1
    for(int i=0;i<r;i++){
      int j=(r+c)/2-1-i;
      (sum+=f(i,j,i+1)+f(i,j,i))%=MOD;
    }
  }else{  //type3
    for(int i=0;i<r;i++){
      int j=(r+c)/2-1-i;
      (sum+=f(i,j,i))%=MOD;
    }
  }
  printf("%llu\n",sum);
#ifdef DEBUG
  for(int x1=0;x1<r;x1++) for(int y1=0;y1<c;y1++) for(int x2=0;x2<r;x2++){
    int y2=r+c-2-x2-x1-y1;
    printf("(%d,%d) (%d,%d): %u\n",x1,y1,x2,y2,f(x1,y1,x2));
  }
#endif

  return 0;
}

/*
//四维dp，递归
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef unsigned long long LLU;
const int MOD=1000000007;
int r,c;
LLU check[70][70][70][70];
char G[70][70];

LLU f(int x1,int y1, int x2, int y2){
  if(x1<0 || x1>=r ||  x2<0 || x2>=r || y1<0 || y1>=c || y2<0 || y2>=c) return 0;
  LLU & a = check[x1][y1][x2][y2];
  if(a!=-1) return a;
  if(x1==0 && y1==0 && x2==r-1 && y2==c-1) a = (G[0][0]==G[r-1][c-1]);
  else if(G[x1][y1]!=G[x2][y2]) a=0;
  else
    a = (f(x1,y1-1,x2+1,y2)
       + f(x1,y1-1,x2,y2+1)
       + f(x1-1,y1,x2+1,y2)
       + f(x1-1,y1,x2,y2+1))%MOD;
  return a;
}

int main(void){
#ifdef LOCAL
  //freopen("in","r",stdin);
  freopen("out.ori","w",stdout);
#endif
  scanf("%d%d",&r,&c); int half_len=(r+c)/2-1;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      do G[i][j]=getchar(); while(!isalpha(G[i][j]));
    }
  }
  memset(check,-1,sizeof(check));
  LLU sum=0;
  if((r+c)&1){  //type1
    for(int i=0;i<r;i++){
      int j=(r+c)/2-1-i;
      (sum+=f(i,j,i+1,j)+f(i,j,i,j+1))%=MOD;
    }
  }else{  //type3
    for(int i=0;i<r;i++){
      int j=(r+c)/2-1-i;
      (sum+=f(i,j,i,j))%=MOD;
    }
  }
  printf("%llu\n",sum);
#ifdef DEBUG
  for(int x1=0;x1<r;x1++) for(int y1=0;y1<c;y1++) for(int x2=0;x2<r;x2++){
    int y2=r+c-2-x2-x1-y1;
    printf("(%d,%d) (%d,%d): %llu\n",x1,y1,x2,y2,f(x1,y1,x2,y2));
  }
#endif

  return 0;
}
*/


/*
  得分：0
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const unsigned long long MOD=1000000007;
int r,c,half_len,type;
unsigned long long cnt=0;
char G[70][70],str[100];
bool vis[70][70];
bool count[100][256];
bool all_a=1;
struct Node{
  int x,y;
  int step;

  Node() { }
  Node(int x_, int y_, int step_): x(x_), y(y_), step(step_) { }
};
queue<Node> q;

void bfs();
void available_dfs(int x, int y, int cur);
void count_dfs(int x, int y, int cur);

int main(void){
  scanf("%d%d",&r,&c); half_len=(r+c)/2-1;
  if((r+c)&1) type=1;
  else type=3;
  for(int i=0;i<r;i++){
    getchar();
    for(int j=0;j<c;j++){
      G[i][j]=getchar();
      G[i][j]!='a' ? all_a=0 : 0 ;
    }
  }
  if(all_a){
    //
    //
  }else{
    bfs();
    str[0]=G[0][0];
    available_dfs(0,0,0);
  }
  printf("%lld\n",cnt%MOD);

  return 0;
}

void bfs(){
  q.push(Node(r-1,c-1,0));
  count[0][G[r-1][c-1]]=1;
  while(!q.empty()){
    Node temp=q.front(); q.pop();
    if(temp.step>=half_len) break;
    int tx,ty;
    if(temp.x>0){ //上
      tx=temp.x-1; ty=temp.y;
      count[temp.step+1][G[tx][ty]]=1;
      q.push(Node(tx,ty,temp.step+1));
    }
    if(temp.y>0){ //左
      tx=temp.x; ty=temp.y-1;
      count[temp.step+1][G[tx][ty]]=1;
      q.push(Node(tx,ty,temp.step+1));
    }
  }
#ifdef DEBUG
  for(int i=0;i<=half_len;i++){
    printf("  step: %d, have:",i);
    for(int j=0;j<255;j++) if(count[i][j]) printf(" %c",j); printf("\n");
  }
#endif
}
void available_dfs(int x, int y, int cur){
#ifdef DEBUG
  printf("  in a_dfs (%d,%d): %c, cur: %d, str: %s\n",x,y,G[x][y],cur,str);
#endif
  if(cur==half_len){
    if(type==1){
      if(x<r-1) count_dfs(x+1,y,cur);
      if(y<c-1) count_dfs(x,y+1,cur);
    }else count_dfs(x,y,cur);
    return;
  }
  if(!count[cur][G[x][y]]) return;
  //右
  if(y<c-1){
    str[cur+1]=G[x][y+1];
    available_dfs(x,y+1,cur+1);
  }

  //下
  if(x<r-1){
    str[cur+1]=G[x+1][y];
    available_dfs(x+1,y,cur+1);
  }
}
void count_dfs(int x, int y, int cur){
#ifdef DEBUG
  printf("    in c_dfs (%d,%d):%c, cur: %d\n",x,y,G[x][y],cur);
#endif
  if(G[x][y]!=str[cur]) return;
  if(cur==0){
    cnt++;
    return;
  }
  
  if(y<c-1){
    count_dfs(x,y+1,cur-1);
  }
  if(x<r-1){
    count_dfs(x+1,y,cur-1);
  }
}
*/
