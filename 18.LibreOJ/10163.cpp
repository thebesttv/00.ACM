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

const int MAX = 50;
int l,r,k,b,v[MAX],f[MAX][MAX];

int dfs(int cur, int cnt, bool limited){
  if(!cur) return cnt == k;
  int &a = f[cur][cnt];
  if(!limited && a!=-1) return a;
  int r = limited ? min(v[cur],1) : 1, sum = 0;
  FORR(i,0,r){
    sum += dfs(cur-1, cnt+i, limited && i==v[cur]);
  }
  if(!limited) a = sum;
  return sum;
}

int solve(int x){
  int len = 0;
  while(x) v[++len] = x%b, x/=b;
  MST(f,-1);
  return dfs(len,0,true);
}

int main(void){
  scanf("%d%d%d%d",&l,&r,&k,&b);
  printf("%d\n",solve(r) - solve(l-1));

  return 0;
}
