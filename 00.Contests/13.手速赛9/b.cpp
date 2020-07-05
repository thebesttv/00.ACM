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

int r[200];
VR<int> v;

void dfs(int cur, int s, int len){
  if(cur==len){
    if(s==10){
      int sum = 0;
      FOR(i,0,cur)
        sum = sum*10 + r[i];
      v.push_back(sum);
    }
    return;
  }
  if(cur){
    FORR(i,0,9){
      if(i+s<=10){
        r[cur]=i;
        dfs(cur+1,s+i,len);
      }else break;
    }
  }else{
    FORR(i,1,9){
      r[cur]=i;
      dfs(cur+1,s+i,len);
    }
  }
}

int main(void){
  FOR(len,2,100){
    if(v.size() > 10000) break;
    dfs(0,0,len);
  }
  sort(ALL(v));
  int k; scanf("%d",&k);
  printf("%d\n",v[k-1]);

  return 0;
}
