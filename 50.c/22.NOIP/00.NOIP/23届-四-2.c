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

int n,i,j,x,y,nx,ny;
int a[40][40];

int main(void){
  scanf("%d",&n);
  y=0; x=n-1;
  n=2*n-1;
  FORR(i,1,n*n){
    a[y][x]=i;
    ny=(y-1+n)%n;
    nx=(x+1)%n;
    if((y==0 && x==n-1) || a[ny][nx]!=0) y++;
    else {y=ny; x=nx;}
  }
  FOR(j,0,n) printf("%d ",a[0][j]);
  printf("\n");

  return 0;
}
