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

int ori,n,ns,a[102][102],bun;
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void plimba(int x, int y){
  a[x][y]*=-1;  //相当于vis
  if(abs(a[x-1][y])!=ori && (a[x-1][y-1]!=a[x-1][y] || abs(a[x][y-1])!=ori)) ns++;  //上面有边
  if(abs(a[x+1][y])!=ori && (a[x+1][y-1]!=a[x+1][y] || abs(a[x][y-1])!=ori)) ns++;  //左面有边
  if(abs(a[x][y-1])!=ori && (a[x-1][y-1]!=a[x][y-1] || abs(a[x-1][y])!=ori)) ns++;  //
  if(abs(a[x][y+1])!=ori && (a[x-1][y+1]!=a[x][y+1] || abs(a[x-1][y])!=ori)) ns++;

  FOR(i,0,4){
    int x1=x+to[i][0],y1=y+to[i][1];
    if(x1>=1 && x1<=n && y1>=1 && y1<=n && a[x1][y1]==ori)
      plimba(x1,y1);
  }
}

int main(void){
  bun=1;
  scanf("%d",&n);
  a[0][0] = a[n+1][0] = a[0][n+1] = a[n+1][n+1] = -1; //???
  FORR(i,1,n) FORR(j,1,n) scanf("%d",&a[i][j]);
  FORR(i,1,n) FORR(j,1,n) if(a[i][j]>-1){
    ns=0; ori=a[i][j];  //ns???
    plimba(i,j);
    if(ns%2) bun=0; //ns%2??? bun??
  }
  if(bun) printf("YES\n");
  else printf("NO\n");

  return 0;
}
