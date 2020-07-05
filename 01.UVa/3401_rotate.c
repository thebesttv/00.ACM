/*
 思想：对一个立方体，使它的6个面都到达顶面一次，且每次一个面到达时，下部旋转四次，同时记录立方体姿态并输出
   a[i]=j: 立方体第 i 面在 j 方向
   因为一开始面和方向是一致的，因此 a[i]=j 等价于 i 方向变换到了 j 方向，直接输出立方体姿态即可
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

int a[6]={0,1,2,3,4,5}; // a[i]=j: 第 i 面在 j 方向，可以完整地表示立方体的姿态
const int v_up[]={2,1,5,0,4,3};   // v_up[i]=j: i方向的面变成了j方向
const int v_left[]={1,5,2,3,0,4};

void up(){
  int t[6]; memcpy(t,a,SIZ(a));
  FOR(i,0,6) a[i] = v_up[ t[i] ];
}
void left(){
  int t[6]; memcpy(t,a,SIZ(a));
  FOR(i,0,6) a[i] = v_left[ t[i] ];
}
void print(){
  putchar('{');
  FOR(i,0,6){
    if(i) putchar(',');
    printf("%d",a[i]);
  }
  printf("},");
#ifdef DEBUG
  FOR(i,0,6) if(a[i]==3-1)
    printf("  %d is on top\n",i+1);
#endif
}

int main(void){
  printf("const int rot[24][6] = {\n");
  FOR(i,0,6){
    if(i==1) { up(); }
    if(i==2) { up(); }
    if(i==3) { up(); }
    if(i==4) { left(); up(); }
    if(i==5) { up(); up(); }

    printf("  ");
    FOR(j,0,4){
      print(); left();
    }
    printf("\n");
  }
  printf("};\n");

  return 0;
}
