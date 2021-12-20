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
typedef long long LL;
typedef long long unsigned LLU;

int n;
VR<int> v1,v2;
set<int> ans;

bool find(int x, VR<int> &v){
  for(int y : v) if(x==y) return 1;
  return 0;
}

int main(void){
  scanf("%d",&n); v1.resize(n);
  FOR(i,0,n) scanf("%d",&v1[i]);
  scanf("%d",&n); v2.resize(n);
  FOR(i,0,n) scanf("%d",&v2[i]);

  bool first=1;
  for(int x : v1){
    if(!find(x, v2)){
      if(ans.find(x)==ans.end()){
        if(first) first=0;
        else putchar(' ');
        printf("%d",x);
        ans.insert(x);
      }
    }
  }

  for(int x : v2){
    if(!find(x, v1)){
      if(ans.find(x)==ans.end()){
        if(first) first=0;
        else putchar(' ');
        printf("%d",x);
        ans.insert(x);
      }
    }
  }

  return 0;
}

/*
set<int> s1, s2, si, su;
int n, t;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) { scanf("%d",&t); s1.insert(t); }
  scanf("%d",&n);
  FOR(i,0,n) { scanf("%d",&t); s2.insert(t); }

  set_intersection(ALL(s1),ALL(s2),INS(si));
  set_union(ALL(s1),ALL(s2),INS(su));

  bool first=1;
  for(auto i : su){
    if(si.find(i)==si.end()){
      if(first) first=0;
      else putchar(' ');
      printf("%d",i);
    }
  }
  putchar('\n');

  return 0;
}
*/
