// Tag: 
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

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 5e4 + 20;
const double E = 2.718281828;
int n,c,to[MAX];
struct Node{
  int type, f1, f2;
  VR<double> v;
}node[MAX];
VR<int> G[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    int t; scanf("%d",&t);
    node[i].type = t;
    if(t == 0){
      double x; scanf("%lf",&x);
#ifdef DEBUG
      printf("  %.2lf\n",x);
#endif
      node[i].v.pb(x);
      node[i].f1 = ++c;
    }else if(t <= 3){
      scanf("%d%d",&node[i].f1,&node[i].f2);
      ++node[i].f1, ++node[i].f2;
#ifdef DEBUG
      printf("  %d, %d\n",node[i].f1,node[i].f2);
#endif
      G[node[i].f1].pb(i);
      G[node[i].f2].pb(i);
      to[i] += 2;
    }else{
      scanf("%d",&node[i].f1);
      ++node[i].f1;
#ifdef DEBUG
      printf("  %d\n",node[i].f1);
#endif
      G[node[i].f1].pb(i);
      ++to[i];
    }
  }

  queue<int> q;
  FORR(i,1,n){
    node[i].v.resize(c+1);
    if(!to[i]){
      node[i].v[node[i].f1] = 1;
      q.push(i);
    }
  }

  int last = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
#ifdef DEBUG
    printf("  %d\n",u);
#endif
    last = u; Node &t = node[u];
    if(node[u].type == 1){        // +
      FORR(i,0,c) t.v[i] = node[t.f1].v[i] + node[t.f2].v[i];
    }else if(node[u].type == 2){  // -
      FORR(i,0,c) t.v[i] = node[t.f1].v[i] - node[t.f2].v[i];
    }else if(node[u].type == 3){  // *
      t.v[0] = node[t.f1].v[0] * node[t.f2].v[0];
      FORR(i,1,c) t.v[i] = node[t.f1].v[i] * node[t.f2].v[0]
                         + node[t.f1].v[0] * node[t.f2].v[i];
    }else if(node[u].type == 4){  // e^x
      t.v[0] = pow(E, node[t.f1].v[0]);
      FORR(i,1,c) t.v[i] = node[t.f1].v[i] * pow(E, node[t.f1].v[0]);
    }else if(node[u].type == 5){  // ln(x)
      t.v[0] = log(node[t.f1].v[0]);
      FORR(i,1,c) t.v[i] = node[t.f1].v[i] / node[t.f1].v[0];
    }else if(node[u].type == 6){  // sin(x)
      t.v[0] = sin(node[t.f1].v[0]);
      FORR(i,1,c) t.v[i] = node[t.f1].v[i] * cos(node[t.f1].v[0]);
    }

    for(int v : G[u]) if((--to[v]) == 0){
      q.push(v);
    }
  }
  printf("%.3lf\n",node[last].v[0]);
  FORR(i,1,c){
    if(i > 1) putchar(' ');
    printf("%.3lf",node[last].v[i]);
  }
  putchar('\n');

  return 0;
}

