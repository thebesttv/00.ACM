// Tag: notag
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

int n,ansMin = 0x3f3f3f3f;

bool isPrime(int n){
  int r = sqrt(n+1);
  FORR(i,2,r) if(n%i==0) return false;
  return true;
}

void dfs(int n, int last, int sum){
  if(sum > ansMin) return;
  if(n==1) { ansMin = sum; return; }
  FORR(i,last+1,n) if(n%i==0){
    dfs(n/i, i, sum+i);
  }
}

int main(void){
  scanf("%d",&n);
  if(isPrime(n)){
    printf("%d\n",n+1); return 0;
  }
  dfs(n, 1, 0);
  printf("%d\n",ansMin);

  return 0;
}
