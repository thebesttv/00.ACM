// Tag: 数位DP
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

const int MAX = 20;
int l,r,v[MAX],f[MAX][MAX];

int dfs(int cur, int last, bool limited){
  if(!cur) return 1;
  int &a = f[cur][last];
  if(!limited && a!=-1) return a;
  int r = limited ? v[cur] : 9, sum = 0;
  FORR(i,last,r)
    sum += dfs(cur-1, i, limited && i==r);
  if(!limited) a = sum;
  return sum;
}

int solve(int x){
  int len = 0;
  while(x) v[++len]=x%10, x/=10;
  MST(f,-1);
  return dfs(len,0,true);
}

int main(void){
  while(scanf("%d%d",&l,&r)==2){
    printf("%d\n",solve(r) - solve(l-1));
  }

  return 0;
}