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

const int to[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};
int n, len;
struct Node{
  int G[6][6], step;
  pii car[11][3];
  LL hash;
  void cal(){
    hash = 0;
    FOR(i,0,6) FOR(j,0,6){
      hash = hash*6 + G[i][j];
    }
  }
}ori;
map<LL, bool> vis;

bool ok(const Node &p){
  FOR(i,0,3) if(p.car[1][i].FI == 2 && p.car[1][i].SE == 5)
    return true;
  return false;
}

bool ok(const Node &t, int i, int d){
  int x, y;
#ifdef DEBUG
  if(t.hash ==-8965512715436420974){
    printf("  trying to move %d, %d\n",i,d);
  }
#endif
  FOR(j,0,3){
    const pii &p = t.car[i][j];
    if(p.FI==-1) continue;
    x = p.FI + to[d][0],
    y = p.SE + to[d][1];
    if(x<0 || x>5 || y<0 || y>5) return false;
    if(t.G[x][y] && t.G[x][y] != i) return false;
  }
  return true;
}

void move(Node &t, int i, int d){
  int x, y;
  if(d==0 || d==3){
    ROR(j,2,0){
      pii &p = t.car[i][j];
      if(p.FI==-1) continue;
      x = p.FI + to[d][0],
      y = p.SE + to[d][1];
      swap(t.G[x][y], t.G[p.FI][p.SE]);
      p = {x,y};
    }
  }else{
    FOR(j,0,3){
      pii &p = t.car[i][j];
      if(p.FI==-1) continue;
      x = p.FI + to[d][0],
      y = p.SE + to[d][1];
      swap(t.G[x][y], t.G[p.FI][p.SE]);
      p = {x,y};
    }
  }

  ++t.step;
  t.cal();
}

void print(const Node &t){
  printf("step: %d, hash: %lld\n",t.step,t.hash);
  FOR(i,0,6){
    FOR(j,0,6){
      printf("%d ",t.G[i][j]);
    }
    putchar('\n');
  }
}

bool isVert(pii *v){
  return v[0].SE == v[1].SE;
}

int main(void){
  VR<pii> pos[11];
  FOR(i,0,6) FOR(j,0,6){
    int x; scanf("%d",&x);
    ori.G[i][j] = x; n = max(n, x);
    if(x) pos[x].push_back({i,j});
  }
  FORR(i,1,n){
    FOR(j,0,pos[i].size())
      ori.car[i][j] = pos[i][j];
    if(pos[i].size()==2)
      ori.car[i][2] = {-1,-1};
  }

  if(isVert(ori.car[1]) || ori.car[1][0].FI != 2){
    printf("-1\n"); return 0;
  }

  len = pos[1].size();

  ori.cal(); vis[ori.hash] = 1;
  queue<Node> q; q.push(ori);
  int ans = -1;
  while(!q.empty()){
    Node t = q.front(); q.pop();
#ifdef DEBUG
    print(t);
#endif
    if(ok(t)){
      ans = t.step + len;
      break;
    }

    if(t.step + len >= 10) continue;

    /*
    FORR(i,1,n) FOR(d,0,4) if(ok(t,i,d)){
      Node tt = t; move(tt,i,d);
      if(vis[tt.hash]) continue;
      q.push(tt); vis[tt.hash] = 1;
    }
    */
    FORR(i,1,n) if(isVert(t.car[i])){
      int d = 1;
      if(ok(t,i,d)){
        Node tt = t; move(tt,i,d);
        if(!vis[tt.hash]){
          q.push(tt); vis[tt.hash] = 1;
        }
      }

      d = 3;
      if(ok(t,i,d)){
        Node tt = t; move(tt,i,d);
        if(!vis[tt.hash]){
          q.push(tt); vis[tt.hash] = 1;
        }
      }
    }else{
      int d = 0;
      if(ok(t,i,d)){
        Node tt = t; move(tt,i,d);
        if(!vis[tt.hash]){
          q.push(tt); vis[tt.hash] = 1;
        }
      }

      d = 2;
      if(ok(t,i,d)){
        Node tt = t; move(tt,i,d);
        if(!vis[tt.hash]){
          q.push(tt); vis[tt.hash] = 1;
        }
      }
    }
  }
  printf("%d\n",ans);

  return 0;
}
