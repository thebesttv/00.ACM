/*
描述
“红楼飞雪，一时英杰……”耳边传来了那熟悉的歌声。而这，只怕是我最后一次听到这个声音了。
想当年，我们曾经怀着豪情壮志，许下心愿，走过静园，走过一体，走过未名湖畔的每个角落。
想当年，我们也曾慷慨高歌，瞻仰民主与科学，瞻仰博雅塔顶，那百年之前的遗韵。
没错，我爱北大，我爱这个校园。
然而，从当我们穿上学位服的那一刻起，这个校园，就再也不属于我。它只属于往事，属于我的回忆。
没错，这，是我在北大的最后一日。此时，此景，此生，此世，将刻骨难忘。
再也没有了图书馆自习的各种纷纭，再也没有了运动场上的挥汗如雨，有的，只是心中永远的不舍，与牵挂。
夜，已深。人，却不愿离去。天边有一颗流星划过，是那般静，宁谧。
忍不住不回头，我的眼边，有泪光，划过。
这时候，突然有一位路人甲从你身旁出现，问你：从XX到XX怎么走？
索性，就让我再爱你一次。因为，北大永远在你心中。北大的地图，永远在你的心中。
轻手挥扬，不带走一分云彩。

输入
输入分为三个部分。
第一个部分有P+1行，第一行为一个整数P，之后的P行表示北大的地点。地点长度不超过20个字符。
第二个部分有Q+1行，第一行为一个整数Q，之后的Q行每行分别为两个字符串与一个整数，表示这两点有直线的道路，并显示二者之间的矩离（单位为米）。
第三个部分有R+1行，第一行为一个整数R，之后的R行每行为两个字符串，表示需要求的路线。
p<=30,Q<=50,R<=20

输出
输出有R行，分别表示每个路线最短的走法。其中两个点之间，用->(矩离)->相隔。

样例输入
6
XueYiShiTang
CanYinZhongXin
XueWuShiTang
XueYiXiaoBaiFang
BaiNianJiangTang
GongHangQuKuanJi
6
XueYiShiTang CanYinZhongXin 80
XueWuShiTang CanYinZhongXin 40
XueYiShiTang XueYiXiaoBaiFang 35
XueYiXiaoBaiFang XueWuShiTang 85
CanYinZhongXin GongHangQuKuanJi 60
GongHangQuKuanJi BaiNianJiangTang 35
2
XueYiXiaoBaiFang BaiNianJiangTang
GongHangQuKuanJi GongHangQuKuanJi

样例输出
XueYiXiaoBaiFang->(35)->XueYiShiTang->(80)->CanYinZhongXin->(60)->GongHangQuKuanJi->(35)->BaiNianJiangTang
GongHangQuKuanJi

输入数据会有重边，要选择较小的权值
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int INF=0x3f3f3f3f;
const int MAX=40;
struct Node{
  char name[30];
}ind[MAX];
int w[MAX][MAX],n;
char str1[30],str2[30];
int d[MAX],f[MAX],d_save[MAX][MAX],f_save[MAX][MAX];
bool vis[MAX];

int getNum(char * str){
  for(int i=0;i<n;i++) if(!strcmp(str,ind[i].name)) return i;
}
void Dijkstra(int u);
void print(int u, int v);

int main(void){
  memset(w,0x3f,sizeof(w)); for(int i=0;i<MAX;i++) w[i][i]=0;
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%s",ind[i].name);
  int t; scanf("%d",&t);
  for(int i=0;i<t;i++){
    scanf("%s%s",str1,str2);
    int x=getNum(str1), y=getNum(str2);
    int d; scanf("%d",&d);
    w[y][x]=w[x][y]=min(w[x][y],d);
  }
  for(int i=0;i<n;i++){
    Dijkstra(i);
    memcpy(d_save[i],d,sizeof(d)); memcpy(f_save[i],f,sizeof(f));
  }
#ifdef DEBUG
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) printf("%3d",w[i][j]<INF ? w[i][j] : 0);
    printf("\n");
  }
  printf("Dijkstra:\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) printf("%4d",d_save[i][j]<INF ? d_save[i][j] : -1);
    printf("\n");
  }
  printf("father:\n");
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++) printf("%4d",f_save[i][j]);
    printf("\n");
  }
#endif
  scanf("%d",&t);
  for(int i=0;i<t;i++){
    scanf("%s%s",str1,str2);
    int x=getNum(str1),y=getNum(str2);
    print(x,y);
  }

  return 0;
}

void Dijkstra(int u){
  memset(vis,0,sizeof(vis)); memset(f,-1,sizeof(f));
  memset(d,0x3f,sizeof(d)); d[u]=0;
  for(int i=0;i<n;i++){
    int x,m=INF;
    for(int y=0;y<n;y++) if(!vis[y] && d[y]<=m) m=d[x=y];
    vis[x]=1;
    for(int y=0;y<n;y++) if(w[x][y] && d[y]>d[x]+w[x][y]){
      d[y]=d[x]+w[x][y];
      f[y]=x;
    }
  }
}
void print(int u, int v){
  stack<int> st;
  int *d=d_save[u],*f=f_save[u];
  int n=v;
  while(v!=-1){
    st.push(v);
    v=f[v];
  }
  while(!st.empty()){
    int t=st.top();
    printf("%s",ind[t].name); st.pop();
    if(st.empty()) break;
    printf("->(%d)->",w[t][st.top()]);
  }
  printf("\n");
}
