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

int n,vis[10];

bool ok(int n, int m){
  if(n < 1000 || m < 1000 || n > 99999 || m > 99999) return false;
  MST(vis,0);
  if(n < 10000) ++vis[0]; while(n) ++vis[n%10], n/=10;
  if(m < 10000) ++vis[0]; while(m) ++vis[m%10], m/=10;
  FOR(i,0,10) if(vis[i]!=1) return false;
  return true;
}

int main(void){
  bool first = 1;
  while(scanf("%d",&n)==1 && n){
    if(first) first = 0;
    else putchar('\n');
    bool done = 0;
    FORR(i,0,99999) if(i%n ==0 && ok(i, i/n))
      printf("%05d / %05d = %d\n",i,i/n,n), done = 1;
    if(!done) printf("There are no solutions for %d.\n",n);
  }

  return 0;
}
