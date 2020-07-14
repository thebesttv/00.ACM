// Tag: quadtree 边读入边计算 fun 可出题
// Link: [UVa 297]
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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 40;
int G[MAX][MAX];

void read(int l1, int r1, int l2, int r2){
  int ch; do ch = getchar(); while(!isalpha(ch));
  if(ch == 'e') return;
  if(ch == 'f'){
    FOR(i,l1,r1) FOR(j,l2,r2)
      G[i][j] = 1;
    return;
  }

  int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
  read(l1,m1,m2,r2);
  read(l1,m1,l2,m2);
  read(m1,r1,l2,m2);
  read(m1,r1,m2,r2);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(G,0);
    read(0,32,0,32);
    read(0,32,0,32);
    int cnt = 0;
    FOR(i,0,32) FOR(j,0,32) cnt += G[i][j];
    printf("There are %d black pixels.\n",cnt);
  }

  return 0;
}
