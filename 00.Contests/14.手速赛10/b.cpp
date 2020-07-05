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

const int MAX = 2e5, MAX_=MAX+20;
int n,k,s[MAX_];
VR<int> v[MAX_];

void cal(int n){
  int cnt = 0;
  while(n){
    v[n].push_back(cnt);
    n>>=1, ++cnt;
  }
  v[0].push_back(cnt);
}

int main(void){
  scanf("%d%d",&n,&k);
  int a;
  FOR(i,0,n){
    scanf("%d",&a);
    cal(a);
  }

  int ansMin = 0x3f3f3f3f;
  FORR(i,0,MAX) if(v[i].size()>=k){
    sort(ALL(v[i]));
    int sum = 0;
    FOR(j,0,k) sum += v[i][j];
    ansMin = min(ansMin, sum);
  }
  printf("%d\n",ansMin);

  return 0;
}
