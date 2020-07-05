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

int a[7], r[7], ansMin = 0x3f3f3f3f;

bool ok(){
  VR<int> v1, v2;
  FOR(i,0,7)
    if(r[i]==1) v1.push_back(a[i]);
    else if(r[i]==2) v2.push_back(a[i]);

  if(v1.size() && v1.size()<3)
    return false;

  if(v2.size() && v2.size()<3)
    return false;

  if(v1.size()){
    if(v1[0] == v1[1]) FOR(i,1,v1.size()){
      if(v1[i] != v1[0]) return false;
    }else FOR(i,1,v1.size()){
      if(v1[i] != v1[0] + i) return false;
    }
  }

  if(v2.size()){
    if(v2[0] == v2[1]) FOR(i,1,v2.size()){
      if(v2[i] != v2[0]) return false;
    }else FOR(i,1,v2.size()){
      if(v2[i] != v2[0] + i) return false;
    }
  }

  return true;
}

void dfs(int cur){
  if(cur==7){
    if(ok()){
      int t = 0;
      FOR(i,0,7) if(!r[i])
        t += a[i];
      ansMin = min(ansMin, t);
    }
    return;
  }
  FORR(i,0,2){
    r[cur] = i;
    dfs(cur+1);
  }
}

int main(void){
  FOR(i,0,7) scanf("%d",&a[i]);
  sort(a,a+7);

  dfs(0);
  printf("%d\n",ansMin);

  return 0;
}
