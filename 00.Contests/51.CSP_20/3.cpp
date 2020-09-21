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

//#define DEBUG

const int MAXN = 504, MAXM = 5*500 + 4;
int n,m,input[MAXM],output[10000+4][MAXN];
VR<int> topo; VR<int> G[MAXN];
int vis[MAXN];

struct Input{
  int type, x;  // type: 0: given, 1: output from others
  Input(int type, int x) : type(type), x(x) { }
};

int func(){
  char str[20];
  scanf("%s",str);
  if(str[0] == 'A'){  // AND
    return 1;
  }else if(str[0] == 'O'){  // OR
    return 2;
  }else if(str[0] == 'X'){  // XOR
    return 3;
  }else if(str[1] == 'O' && str[2] == 'T'){  // NOT
    return 0;
  }else if(str[1] == 'A'){  // NAND
    return 4;
  }else{  // NOR
    return 5;
  }
  return -1;
}
Input readIn(){
  int ch, s = 0;
  do ch = getchar(); while(!isalpha(ch));
  int type = ch == 'I' ? 0 : 1;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return Input(type, s);
}

struct Node{
  int type; // 0: NOT, 1: AND, 2: OR, 3: XOR, 4: NAND, 5: NOR
  VR<Input> vin; int out;
  
  void print(){
    printf("type: %d, ",type);
    printf("in:");
    for(auto p : vin) printf(" (%d,%d)",p.type,p.x);
    putchar('\n');
  }
  void cal(int *in, int n){
    if(type == 0){
      out = !in[0];
    }else if(type == 1){
      out = 1;
      FOR(i,0,n) if(!in[i]){
        out = 0; break;
      }
    }else if(type == 2){
      out = 0;
      FOR(i,0,n) if(in[i]){
        out = 1; break;
      }
    }else if(type == 3){
      out = 0;
      FOR(i,0,n) out ^= in[i];
    }else if(type == 4){
      out = 1;
      FOR(i,0,n) if(!in[i]){
        out = 0; break;
      }
      out = !out;
    }else{
      out = 0;
      FOR(i,0,n) if(in[i]){
        out = 1; break;
      }
      out = !out;
    }
  }
}node[MAXN];

bool dfs(int u){
  vis[u] = -1;
  for(int v : G[u])
    if(vis[v] < 0) return false;
    else if(!vis[v] && !dfs(v)) return false;
  vis[u] = 1; topo.pb(u);
  return true;
}

bool testLoop(){  // also generate topo order
  topo.clear(); MST(vis,0);
  FORR(i,1,n) if(!vis[i])
    if(!dfs(i)) return true;
  reverse(ALL(topo));
  #ifdef DEBUG
  printf("topo:");
  for(int x : topo) printf(" %d",x); putchar('\n');
  #endif
  return false;
}

void run(){
  int in[20];
  for(int i : topo){
    Node &t = node[i];
    int tail = 0;
    for(auto &p : t.vin)
      if(p.type == 0) in[tail++] = input[p.x];
      else in[tail++] = node[p.x].out;
    t.cal(in, tail);
  }
}

int main(void){
  #ifdef DEBUG
  freopen("in.txt","r",stdin);
  #endif
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&m,&n);
    FORR(i,1,n) G[i].clear();
    
    FORR(i,1,n){
      node[i].vin.clear();
      node[i].type = func();
      int c; scanf("%d",&c);
      while(c--) node[i].vin.pb(readIn());
      #ifdef DEBUG
      node[i].print();
      #endif
      for(auto &p : node[i].vin)
        if(p.type == 1) G[p.x].pb(i);
    }
    
    bool loop = testLoop();

    int s; scanf("%d",&s);
    FORR(i,1,s){  // input
      FORR(j,1,m) scanf("%d",&input[j]);
      run();
      FORR(j,1,n) output[i][j] = node[j].out;
    }
    
    FORR(i,1,s){  // output
      int c,x; scanf("%d",&c);
      VR<int> v;
      while(c--) scanf("%d",&x), v.pb(x);
      if(!loop){
        for(int x : v) printf("%d ",output[i][x]);
        putchar('\n');
      }
    }
    
    if(loop) printf("LOOP\n");
  }
  return 0;
}