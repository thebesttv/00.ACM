// Tag: 数学 iii
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

int a,b,oa,ob,pos[3030];

int main(void){
  while(scanf("%d%d",&a,&b) == 2){
    FORR(i,0,b) pos[i] = -1;
    oa = a, ob = b;
    VR<int> v; int c, r, idx = 0;
    while(true){
      c = a/b, r = a%b;
      v.push_back(c);
      if(pos[r] != -1) break;
      pos[r] = idx++;
      a = r * 10;
    }

    int cnt = v.size() - pos[r] - 1;
    printf("%d/%d = %d.",oa,ob,v[0]);
    FORR(i,1,pos[r]) printf("%d",v[i]);
    putchar('(');
    FOR(i,pos[r]+1,min(51,(int)v.size())) printf("%d",v[i]);
    if(v.size() > 51) printf("...");
    printf(")\n   %d = number of digits in repeating cycle\n\n",cnt);
  }

  return 0;
}
