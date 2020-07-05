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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100020;
int n,m; VR<int> G[MAX];
int in[MAX];
set<int> A,B,C;

bool ok(){
  if(G[1].size()<2) return 0;
  queue<int> q; // 在 q 中的节点都为已确定位置的
  in[1]=1; in[G[1][0]]=2;
  q.push(1); q.push(G[1][0]);

  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : G[u]){
      if(in[v]){
        if(in[u]==in[v]) return false;
        if(in[v]==1){
          if(A.find(v)!=A.end()) return false;
        }else if(in[v]==2){
          if(B.find(v)!=B.end()) return false;
        }else{
          if(C.find(v)!=C.end()) return false;
        }
      }else{
        if(in[u]==1){
          A.insert(v);
          if(B.find(v)!=B.end()){
            in[v]=3; q.push(v);
          }else if(C.find(v)!=C.end()){
            in[v]=2; q.push(v);
          }
        }else if(in[u]==2){
          B.insert(v);
          if(A.find(v)!=A.end()){
            in[v]=3; q.push(v);
          }else if(C.find(v)!=C.end()){
            in[v]=1; q.push(v);
          }
        }else{
          C.insert(v);
          if(A.find(v)!=A.end()){
            in[v]=2; q.push(v);
          }else if(B.find(v)!=B.end()){
            in[v]=1; q.push(v);
          }
        }
      }
    }
  }

  int cnt[4]={0};
  FORR(i,1,n) cnt[in[i]]++;
  if(n!=cnt[1]+cnt[2]+cnt[3]) return false;
  FORR(i,1,n){
    if(G[i].size() != n - cnt[in[i]]) return false;
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  if(m==0) { printf("-1\n"); return 0;}

  int su,sv; scanf("%d%d",&su,&sv);
  G[su].push_back(sv);
  G[sv].push_back(su);
  FOR(i,1,m){
    int u,v; scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  if(!ok()) printf("-1\n");
  else{
    printf("%d",in[1]);
    FORR(i,2,n) printf(" %d",in[i]);
    putchar('\n');
  }

  return 0;
}
