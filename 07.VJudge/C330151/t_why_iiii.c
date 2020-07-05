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

const int MAX=40;
const int INF=0x3f3f3f3f;
int n,c,use[MAX];
struct Node{
  int v,b;
  bool operator < (const Node &b) const {
    return v > b.v;
  }
}node[MAX];

int main(void){
  scanf("%d%d",&n,&c);
  FOR(i,0,n) scanf("%d%d",&node[i].v,&node[i].b);
  sort(node,node+n);
  int ans=0;
  FOR(i,0,n) if(node[i].v>=c){
    ans+=node[i].b; node[i].b=0;
  }else break;

  while(true){
    MST(use,0);
    int left=c,x;
    FOR(i,0,n) if(node[i].b){
      x = min(left/node[i].v, node[i].b);
      use[i] = x;
      left -= x*node[i].v;
      if(left<=0) break;
    }
    if(left>0){
      /*
      ROR(i,n-1,0) if(node[i].b){
        x = ceil(1.0*left/node[i].v);
        x = min(x, node[i].b);
        use[i] += x; if(use[i]>node[i].b) break;
        left -= x*node[i].v;
        if(left<=0) break;
      }
      */
      ROR(i,n-1,0) if(use[i]+1<=node[i].b && node[i].v>=left){
        use[i]++; left=0; break;
      }
    }
    if(left>0) break;
#ifdef DEBUG
    printf("\n");
    FOR(i,0,n) if(use[i])
      printf(" use %d %d\n",node[i].v,use[i]);
#endif
    int tMax=INF;
    FOR(i,0,n) if(use[i]){
      tMax=min(tMax, node[i].b/use[i]);
    }
    ans+=tMax;
    FOR(i,0,n) if(use[i]){
      node[i].b-=use[i]*tMax;
    }
  }
  printf("%d\n",ans);
  return 0;
}

/*
const int MAX=40;
int n,c;
struct Node{
  int v,b;
  Node(int v, int b): v(v), b(b) { }
  bool operator < (const Node &b) const {
    return v > b.v;
  }
};
deque<Node> node;

int main(void){
  scanf("%d%d",&n,&c);
  FOR(i,0,n){
    int v,b; scanf("%d%d",&v,&b);
    node.push_back(Node(v,b));
  }
  sort(node.begin(),node.end());
  int ans=0;
  while(node.front().v>=c){
    ans+=node.front().b;
    node.pop_front();
  }
  while(true){
    while(!node.empty() && node.front().b==0) node.pop_front();
    if(node.empty()) break;
    int t = min(c / node.front().v, node.front().b);
    int left = c - t*node.front().v;
    node.front().b-=t;
    if(left>0){
      ROR(i,node.size()-1,0) if(node[i].b){
        t = min((int)ceil(1.0*left/node[i].v), node[i].b);
        left -= t*node[i].v; node[i].b-=t;
        if(left<=0) break;
      }
    }
    if(left<=0) ans++;
    else break;
  }
  printf("%d\n",ans);
  return 0;
}
*/
