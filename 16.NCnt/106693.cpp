// Tag: 概率DP
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

const int MAX = 1020;
int n,m; double f[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  ROR(i,n,0) ROR(j,m,0) if(i!=n || j!=m)
    f[i][j] = (f[i+1][j] * (n-i) / n * j / m + f[i][j+1] * i / n * (m-j) / m + f[i+1][j+1] * (n-i) / n * (m-j) / m + 1) / (1 - 1.0 * i/n * j/m);
  printf("%.4f\n",f[0][0]); // 啥鬼题目，%lf不行，改成%f就行 @_@

  return 0;
}
