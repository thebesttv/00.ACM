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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 2e5 + 20;
int n, f[MAX], notKnow[MAX], notGiven[MAX];
bool given[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&f[i]);
    if(f[i]) given[f[i]] = 1;
  }

  VR<int> v;
  FORR(i,1,n) if(!given[i] && !f[i]){
    v.push_back(i);
  }

  if(v.size()==1){
    FORR(i,1,n) if(!given[i] && i!=v[0]){
      f[v[0]] = i; given[i] = 1; break;
    }
  }else if(v.size()>1){
    int sz = v.size();
    FOR(i,0,sz){
      f[v[i]] = v[(i+1)%sz];
      given[v[i]] = 1;
    }
  }

  int j = 1;
  FORR(i,1,n) if(f[i]==0){
    while(j<=n && given[j]) ++j;
    f[i] = j, given[j] = 1; ++j;
  }

  FORR(i,1,n) printf("%d ", f[i]); putchar('\n');

  return 0;
}
