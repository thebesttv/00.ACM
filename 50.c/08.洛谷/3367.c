/*
题目描述
如题，现在有一个并查集，你需要完成合并和查询操作。

输入输出格式
输入格式：
第一行包含两个整数N、M，表示共有N个元素和M个操作。
接下来M行，每行包含三个整数Zi、Xi、Yi
当Zi=1时，将Xi与Yi所在的集合合并
当Zi=2时，输出Xi与Yi是否在同一集合内，是的话输出Y；否则话输出N

输出格式：
如上，对于每一个Zi=2的操作，都有一行输出，每行包含一个大写字母，为Y或者N

输入输出样例
输入样例#1：
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4

输出样例#1：
N
Y
N
Y

说明
时空限制：1000ms,128M
数据规模：
对于30%的数据，N<=10，M<=20；
对于70%的数据，N<=100，M<=1000；
对于100%的数据，N<=10000，M<=200000。
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10020;
int n,m,p[MAX];

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void merge(int x, int y){
  int px=find(x),py=find(y);
  if(px==py) return;
  if(p[px]<p[py]){  //|p[px]|>|p[py]|
    p[px]+=p[py];
    p[py]=px;
  }else{
    p[py]+=p[px];
    p[px]=py;
  }
}

int main(void){
  MST(p,-1);
  scanf("%d%d",&n,&m);
  int x,y,z;
  FOR(i,0,m){
    scanf("%d%d%d",&z,&x,&y);
    if(z==1) merge(x,y);
    else printf("%c\n", find(x)==find(y) ? 'Y' : 'N');
  }

  return 0;
}

/*
int p[10000+10];

int getParent(int n){
  if(p[n]<0) return n;
  else return p[n]=getParent(p[n]);
}
void merge(int a, int b){
  int pa=getParent(a),pb=getParent(b);
  if(pa==pb) return;
  int tot=p[pa]+p[pb];
  if(p[pa]<p[pb]){  // -p[pa] > -p[pb]
    p[pb]=pa;
    p[pa]=tot;
  }else{
    p[pa]=pb;
    p[pb]=tot;
  }
}

int main(void){
  memset(p,-1,sizeof(p));
  int n,m; scanf("%d%d",&n,&m);
  int a,b,type;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&type,&a,&b);
    if(type==1){
      merge(a,b);
    }else{
      if(getParent(a)!=getParent(b)) printf("N\n");
      else printf("Y\n");
    }
  }

  return 0;
}
*/
