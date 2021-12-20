/*
首先考虑表示状态，即当前所有灯的状态和老人的位置。
发现所有被关闭的灯一定是一个区间，而老张只会在这个区间的左边或者右边。
那么就可以用 f[l][r][0/1] 表示：当前第l:r个灯被关闭、老张在第l/r个灯旁时的最小花费，于是一切就很容易了。
~~不知道我原来怎么死也想不出来~~
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

const int MAX=100;
int n,c;
int s[MAX],pos[MAX];
int f[MAX][MAX][2];

int main(void){
  scanf("%d%d",&n,&c);
  FORR(i,1,n) scanf("%d%d",&pos[i],&s[i]), s[i]+=s[i-1];

  MST(f,0x3f); f[c][c][0]=f[c][c][1]=0;
  ROR(l,c,1) FORR(r,c,n){
    int t=f[l][r][0], left = s[l-1] + s[n]-s[r];
    if(l>1) f[l-1][r][0] = min( f[l-1][r][0], t + left*(pos[l]-pos[l-1]) ); //向左走
    if(r<n) f[l][r+1][1] = min( f[l][r+1][1], t + left*(pos[r+1]-pos[l]) ); //向右走

    t=f[l][r][1];
    if(l>1) f[l-1][r][0] = min( f[l-1][r][0], t + left*(pos[r]-pos[l-1]) ); //向左走
    if(r<n) f[l][r+1][1] = min( f[l][r+1][1], t + left*(pos[r+1]-pos[r]) ); //向右走
  }
  printf("%d\n",min(f[1][n][0],f[1][n][1]));

  return 0;
}
