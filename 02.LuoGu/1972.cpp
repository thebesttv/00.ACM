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

const int MAX = 1e6 + 4;
int n,m,a[MAX],occ[MAX],ans[MAX];
VR<int> Q[MAX], no[MAX];

void read(int &s){
  int ch; s = 0;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s * 10 + ch-'0', ch = getchar();
}

struct ST{
  int v[MAX],n;
  void add(int x, int a){
    while(x <= n){
      v[x] += a, x += x&-x;
    }
  }
  int sum(int x){
    int s = 0;
    while(x) s += v[x], x -= x&-x;
    return s;
  }
}sg;

int main(void){
  read(n);
  FORR(i,1,n) read(a[i]);
  read(m);
  int l,r;
  FOR(i,0,m){
    read(l), read(r);
    Q[r].push_back(l);
    no[r].push_back(i);
  }

  sg.n = 1e6;
  FORR(r,1,int(1e6)){
    int &o = occ[a[r]];
    if(o) sg.add(o, -1);
    sg.add(o=r, 1);
    FOR(i,0,Q[r].size())
      ans[no[r][i]] = sg.sum(r) - sg.sum(Q[r][i]-1);
  }
  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}
