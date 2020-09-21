// Tag: 
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

const int MAX = 70;
int n,k[MAX][MAX],a[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); int sum = 0;
    FORR(i,1,n) FORR(j,1,n) scanf("%d",&a[i][j]);
    FORR(i,1,3) FORR(j,1,3) scanf("%d",&k[i][j]), sum += k[i][j];
    if(sum != k[1][1]){
      MST(a,0);
    }
    FORR(i,1,n){
      printf("%d",a[i][1]);
      FORR(j,2,n) printf(" %d",a[i][j]);
      putchar('\n');
    }
  }

  return 0;
}
