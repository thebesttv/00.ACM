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

const int MAX = 2020;
int n,p,a[MAX];

bool ok(int x){
  int j = 0;
  FORR(i,1,n){
    while(j<n && a[j+1] <= x+i-1) ++j;
    int s = j + 1 - i;
    if(s <= 0 || s%p==0)
      return false;
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&p);
  FORR(i,1,n) scanf("%d",&a[i]);
  sort(a+1,a+1+n);

  VR<int> ans;
  FORR(x,1,2000) if(ok(x)){
    ans.push_back(x);
  }
  printf("%d\n",(int)ans.size());
  for(int x : ans) printf("%d ",x); putchar('\n');

  return 0;
}
