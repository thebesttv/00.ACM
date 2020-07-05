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

int n;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    VR<int> v;
    v.push_back(n/10000*10000);
    v.push_back(n%10000/1000*1000);
    v.push_back(n%1000/100*100);
    v.push_back(n%100/10*10);
    v.push_back(n%10);
    int cnt = 0;
    for(int x : v) if(x) ++cnt;
    printf("%d\n",cnt);
    for(int x : v) if(x) printf("%d ",x);
    putchar('\n');
  }

  return 0;
}
