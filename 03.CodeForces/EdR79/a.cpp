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

int v[3];

bool ok(int a, int b, int c){
  if(a-1 > b + c) return false;
  return true;
}

int main(void){
  int T; cin >> T;
  while(T--){
    cin >> v[0] >> v[1] >> v[2];
    sort(v,v+3);
    printf("%s\n", ok(v[2],v[1],v[0]) ? "Yes" : "No");
  }


  return 0;
}

/*
int v[3];

bool ok(int a, int b, int c){
  int t = min(a, min(b,c));
  a -= t, b -= t, c -= t;
  return a==b || a-1==b;
}

int main(void){
  int T; cin >> T;
  while(T--){
    cin >> v[0] >> v[1] >> v[2];
    sort(v,v+3,greater<int>());
    int a = v[0], b = v[1], c = v[2];
    printf("%s\n",ok(a,b,c) ? "Yes" : "No");
  }

  return 0;
}
*/
