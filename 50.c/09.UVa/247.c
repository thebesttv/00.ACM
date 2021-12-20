/*
  解题报告：
    使用Floyd求传递闭包，然后，对每个G[i][j]，当且仅当G[i][j]=G[j][i]=1时将(i,j)放入新图。
    然后依次输出新图中的每个连通分量即可。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)

const int MAX=30;
char name[MAX][30];
char t1[30],t2[30];
int G[MAX][MAX],G2[MAX][MAX];
bool vis[MAX],first;
int n,m,tail;

int get(char *str){
  for(int i=0;i<tail;i++) if(!strcmp(str,name[i])) return i;
  strcpy(name[tail],str);
  return tail++;
}
void print(int i){
  if(first) first=0;
  else printf(", ");
  printf("%s",name[i]); vis[i]=1;
  FOR(j,0,n) if(!vis[j] && G2[i][j]) print(j);
}

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&m)==2 && n){
    MST(G,0); MST(G2,0); MST(vis,0); tail=0;
    FOR(i,0,m){
      scanf("%s%s",t1,t2);
      int u=get(t1),v=get(t2);
      G[u][v]=1;
    }
    FOR(i,0,n) G[i][i]=1;
    FOR(k,0,n) FOR(i,0,n) FOR(j,0,n)
      G[i][j]=G[i][j] || (G[i][k] && G[k][j]);
    FOR(i,0,n) FOR(j,0,n)
      if(G[i][j] && G[j][i]) G2[i][j]=G2[j][i]=1;

    if(kase) printf("\n");
    printf("Calling circles for data set %d:\n",++kase);
    FOR(i,0,n) if(!vis[i]) {first=1; print(i); printf("\n");}
  }

  return 0;
}
