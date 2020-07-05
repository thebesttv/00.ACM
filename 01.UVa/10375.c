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

const int MAX=10000;
int p,q,r,s,cnt[MAX];
bool vis[MAX+20];
VR<int> prime;

void add(int n, int d){
  FOR(i,0,prime.size()) if(n%prime[i]==0){
    while(n%prime[i]==0){
      n /= prime[i]; cnt[i]+=d;
    }
    if(n==1) break;
  }
}

void addFrac(int n, int d){
  FORR(i,2,n) add(i,d);
}

int main(void){
  FORR(i,2,MAX) if(!vis[i]){
    prime.push_back(i);
    for(int j=i*i;j<=MAX;j+=i) vis[j]=1;
  }

  while(cin >> p >> q >> r >> s){
    MST(cnt,0);

    addFrac(p,1);
    addFrac(q,-1);
    addFrac(p-q,-1);

    addFrac(r,-1);
    addFrac(s,1);
    addFrac(r-s,1);

    double ans = 1;
    FOR(i,0,prime.size()) if(cnt[i]){
      ans *= pow(prime[i],cnt[i]);
    }
    printf("%.5lf\n",ans);
  }

  return 0;
}
