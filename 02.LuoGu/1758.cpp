// Tag: ii 转化 DP
// sum { ai^2 } 转化为两台管道同时取珠，取得相同结果的方案数
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 504;
const int MOD = 1024523;
int n,m,a[MAX],b[MAX],f[MAX][MAX];

void read(int *a, int n){
  int ch;
  ROR(i,n,1){
    do ch = getchar(); while(ch!='A' && ch!='B');
    a[i] = ch == 'A';
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  read(a,n), read(b,m);

  f[0][0] = 1;
  FORR(k,1,n+m){
    int r = min(n,k), l = max(0,k-m);
    if(l > r) continue;
    ROR(i,r,l) ROR(j,r,l){
      int &x = f[i][j], t = x; x = 0;
      if(i && j && a[i] == a[j]) x += f[i-1][j-1];
      if(k>i && j && b[k-i] == a[j]) x += f[i][j-1];
      if(k>j && i && a[i] == b[k-j]) x += f[i-1][j];
      if(k>i && k>j && b[k-i] == b[k-j]) x += t;
      x %= MOD;
#ifdef DEBUG
      if(x) printf("f[%d][%d][%d]: %d\n",i,j,k,x);
#endif
    }
  }
  printf("%d\n",f[n][n]);

  return 0;
}

/*
const int MAX = 504;
const int MOD = 1024523;
int n,m,a[MAX],b[MAX],f[MAX][MAX][1004];

void read(int *a, int n){
  int ch;
  ROR(i,n,1){
    do ch = getchar(); while(ch!='A' && ch!='B');
    a[i] = ch == 'A';
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  read(a,n), read(b,m);

  f[0][0][0] = 1;
  FORR(k,1,n+m){
    FORR(i,0,n) FORR(j,0,n){
      if(i+m < k || j+m < k || i > k || j > k) continue;
      int &x = f[i][j][k]; x = 0;
      if(i && j && a[i] == a[j]) x += f[i-1][j-1][k-1];
      if(k>i && j && b[k-i] == a[j]) x += f[i][j-1][k-1];
      if(k>j && i && a[i] == b[k-j]) x += f[i-1][j][k-1];
      if(k>i && k>j && b[k-i] == b[k-j]) x += f[i][j][k-1];
      x %= MOD;
#ifdef DEBUG
      if(x) printf("f[%d][%d][%d]: %d\n",i,j,k,x);
#endif
    }
  }
  printf("%d\n",f[n][n][n+m]);

  return 0;
}
*/
