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

const int MAX = 1e3 + 20;
int n,k,t,xl,xr,yl,yr;

bool within(int x, int y){
  return xl <= x && x <= xr && yl <= y && y <= yr;
}

struct Ind{
  pii v[MAX];
  bool pass(){
    FORR(i,1,t) if(within(v[i].FI,v[i].SE))
      return true;
    return false;
  }
  bool stay(){
    bool ok = false; int cnt = 0;
    FORR(i,1,t) if(within(v[i].FI,v[i].SE)){
      ++cnt; if(cnt >= k) return true;
    }else cnt = 0;
    return false;
  }
}ind[40];

int main(void){
  scanf("%d%d%d%d%d%d%d",&n,&k,&t,&xl,&yl,&xr,&yr);
  int cp = 0, cs = 0;
  FORR(i,1,n){
    FORR(j,1,t) scanf("%d%d",&ind[i].v[j].FI,&ind[i].v[j].SE);
    cp += ind[i].pass();
    cs += ind[i].stay();
  }
  printf("%d\n%d\n",cp,cs);
  
  return 0;
}