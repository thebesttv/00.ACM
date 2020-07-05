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

const LL MAX = 2e9;
LL n;
char s1[20], s2[20];
int l1, l2;

int cal(LL t){
  sprintf(s2,"%lld",t);
  l2 = strlen(s2);

  int ans = 0, p=0;
  FOR(i,0,l2){
    while(p<l1 && s1[p]!=s2[i]){
      ++p;
    }
    if(p<l1 && s1[p]==s2[i])
      ++p;
    else
      return -1;
  }
  return l1-l2;
}

int main(void){
  scanf("%lld",&n);
  sprintf(s1,"%lld",n);
  l1 = strlen(s1);

  int ansMin = 100;
  for(LL i = 1;i*i<=n;++i){
    int t = cal(i*i);
    if(t!=-1) ansMin = min(ansMin, t);
  }
  printf("%d\n",ansMin==100 ? -1 : ansMin);

  return 0;
}
