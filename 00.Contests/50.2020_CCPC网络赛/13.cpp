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

const int MAX = 1e5 + 20;
const LL MOD = 998244353;
int n; LL a[MAX],b[MAX],c[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,0,n) scanf("%lld",&a[i]);
    FORR(i,2,n) scanf("%lld",&b[i]);
    FORR(i,2,n) scanf("%lld",&c[i]);
    FORR(i,2,n) FORR(j,0,n){
      a[j] = (c[i] * a[j] %MOD + b[i] * (j+1) %MOD * a[j+1] %MOD) %MOD;
    }
    FORR(i,0,n) printf("%lld ",a[i]); putchar('\n');
  }

  return 0;
}
