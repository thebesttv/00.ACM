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

const int MAX=5020;
int n; bool vis[MAX];

struct Node{
  int x,y;
  Node() { }
  Node(int x, int y): x(x), y(y) { }
  bool operator < (const Node &b) const {
    return x!=b.x ? x<b.x : y<b.y;
  }
}node[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0);
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d%d",&node[i].x,&node[i].y);
    sort(node+1,node+1+n);
    int cnt=0;
    FORR(i,1,n) if(!vis[i]){
      cnt++; int x=node[i].x,y=node[i].y;
      FORR(j,i+1,n) if(!vis[j] && node[j].x>=x && node[j].y>=y){
        vis[j]=1; x=node[j].x, y=node[j].y;
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}

/*
const int MAX=5020;
int n; bool G[MAX][MAX];

struct Node{
  int x,y;
  Node() { }
  Node(int x, int y): x(x), y(y) { }
  bool operator < (const Node &b) const {
    return x!=b.x ? x<b.x : y<b.y;
  }
}node[MAX];

struct Node2{
  int n, len;
  Node2(int n, int len): n(n), len(len) { }
  bool operator < (const Node &b) const {
    return len < b.len;
  }
};
VR<Node2> v;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d%d",&node[i].x,&node[i].y);
    sort(node+1,node+1+n);
    FORR(i,1,n) FORR(j,i+1,n)
      if(node[i].y <= node[j].y) G[i][j]=1;
    FORR(i,1,n){
      //
    }
  }

  return 0;
}
*/
