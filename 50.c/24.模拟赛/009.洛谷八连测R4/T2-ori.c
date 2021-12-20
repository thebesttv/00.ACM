#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

int n;
VR<int> rec,tmp,v;

void dfs(int cur, VR<int> & v){
  if(cur==(n>>1)){
    FOR(i,0,n)
      if(tmp[i]>rec[i]) {rec=tmp; return;}
      else if(tmp[i]<rec[i]) return;
    return;
  }
  int siz=v.size()-1;
  FOR(i,0,siz){
    tmp[cur<<1]=v[i]; tmp[cur<<1|1]=v[i+1];
    VR<int> tv;
    FOR(j,0,v.size()) if(j!=i && j!=i+1) tv.push_back(v[j]);
    dfs(cur+1,tv);
  }
}

int main(void){
  scanf("%d",&n);
  int t; FOR(i,0,n) {scanf("%d",&t); v.push_back(t);}
  FOR(i,0,n) tmp.push_back(0),rec.push_back(0);
  
  dfs(0,v);

  FOR(i,0,n) printf("%d ",rec[i]); printf("\n");

  return 0;
}
