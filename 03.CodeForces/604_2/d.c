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

const int MAX = 1e5 + 20;
int n,a,b,c,d,v[MAX];

bool ok(int s, int a, int b, int c, int d){
  v[0] = s;
  switch(s){
    case 0: --a; break;
    case 1: --b; break;
    case 2: --c; break;
    case 3: --d; break;
  }
  if(a<0 || b<0 || c<0 || d<0) return false;
  FOR(i,0,n){
    if(v[i]==0){
      if(!b) return false;
      v[i+1] = 1, --b;
    }else if(v[i]==1){
      if(a){
        v[i+1] = 0, --a;
      }else if(c){
        v[i+1] = 2, --c;
      }else{
        return false;
      }
    }else if(v[i]==2){
      if(b){
        v[i+1] = 1, --b;
      }else if(d){
        v[i+1] = 3, --d;
      }else{
        return false;
      }
    }else{
      if(!c) return false;
      v[i+1] = 2, --c;
    }
  }
  return true;
}

int main(void){
  scanf("%d%d%d%d",&a,&b,&c,&d);
  n = a + b + c + d - 1;
  bool done = 0;
  FOR(i,0,4) if(ok(i,a,b,c,d)){
    done = 1;
    printf("YES\n");
    FORR(j,0,n) printf("%d ",v[j]);
    putchar('\n'); break;
  }
  if(!done) printf("NO\n");

  return 0;
}
