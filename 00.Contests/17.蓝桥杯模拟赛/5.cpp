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

const int MAX = 1020;
int n,a[MAX],lMin[MAX],rMax[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  lMin[1] = a[1];
  FORR(i,2,n) lMin[i] = min(lMin[i-1], a[i]);
  rMax[n] = a[n];
  ROR(i,n-1,1) rMax[i] = max(rMax[i+1], a[i]);
  int cnt = 0;
  FOR(i,2,n) if(lMin[i-1] < a[i] && a[i] < rMax[i+1])
    ++cnt;
  printf("%d\n",cnt);

  return 0;
}
