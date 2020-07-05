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

const int MAX = 520;
int n, m;
LL r[MAX],c[MAX];
LL v[MAX][MAX];

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}
LL lcm(LL a, LL b){
  return a/gcd(a,b)*b;
}

bool bad(){
  FORR(i,1,n){
    LL t = v[i][1];
    FORR(j,2,m) t = gcd(t,v[i][j]);
    if(t != r[i]) return 1;
  }
  FORR(j,1,m){
    LL t = v[1][j];
    FORR(i,2,n) t = gcd(t, v[i][j]);
    if(t != c[j]) return 1;
  }
  return 0;
}

int main(void){
  scanf("%d%d",&n,&m);
  if(n==m && n==1){
    printf("0\n"); return 0;
  }

  if(m==1){
    c[1] = 1;
    FORR(i,1,n) r[i] = 1+i;
  }else{
    r[1] = 1;
    FORR(j,1,m) c[j] = j+1;
    FORR(i,2,n) r[i] = m+i;
  }

  FORR(i,1,n) FORR(j,1,m){
    //v[i][j] = lcm(r[i],c[j]);
    v[i][j] = r[i]*c[j];
  }

  if(bad()){
    printf("0\n");
  }else{
    FORR(i,1,n){
      FORR(j,1,m){
        if(j>1) cout << ' ';
        //printf("%lld",v[i][j]);
        cout << v[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
