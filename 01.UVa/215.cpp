// Tag: 模拟 拓扑
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

const int MAX = 220;
int n,m,in[MAX];
VR<int> G[MAX];

int idx(int i, int j){
  return 10*(i-'A') + j-'0';
}

struct Node{
  char exp[80];
  int v; VR<int> add,sub;
  bool done;

  void eval(int no){
    v = 0; done = 0; add.clear(); sub.clear();
    int sign = '+', i = 0;
    while(exp[i]){
      if(exp[i] == '+' || exp[i] == '-') sign = exp[i], i++;
      else if(isalpha(exp[i])){
        int k = idx(exp[i], exp[i+1]); i+=2;
        if(sign == '+') add.push_back(k);
        else sub.push_back(k);
        G[k].push_back(no); ++in[no];
      }else if(isdigit(exp[i])){
        int sum = 0;
        while(isdigit(exp[i])) sum = sum * 10 + exp[i]-'0', ++i;
        v += sign == '+' ? sum : -sum;
      }else ++i;
    }
#ifdef DEBUG
    /*
    printf("node %c%c:\n  sum: %d\n  add:", char((no/10)+'A'), char((no%10)+'0'), v);
    for(int x : add) printf(" %c%c",char((x/10)+'A'), char((x%10)+'0'));
    printf("\n  sub:");
    for(int x : sub) printf(" %c%c",char((x/10)+'A'), char((x%10)+'0'));
    putchar('\n');
    */
#endif
  }
}node[MAX];

void bfs(int u){
  queue<int> q; q.push(u);
  node[u].done = true;
  while(!q.empty()){
    u = q.front(); q.pop();
#ifdef DEBUG
    printf("  node %c%c with v: %d\n",char((u/10)+'A'), char((u%10)+'0'), node[u].v);
#endif
    for(int v : G[u]) if((--in[v]) == 0){
      for(int x : node[v].add)
        node[v].v += node[x].v;
      for(int x : node[v].sub)
        node[v].v -= node[x].v;
#ifdef DEBUG
    printf("    node %c%c with v: %d\n",char((v/10)+'A'), char((v%10)+'0'), node[v].v);
#endif
      q.push(v); node[v].done = true;
    }
  }
}

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    MST(in,-1); getchar();
    FOR(i,0,MAX) G[i].clear();
    FOR(i,0,n) FOR(j,0,m)
      in[idx(i+'A', j+'0')]=0;

    FOR(i,0,n) FOR(j,0,m){
      int k = idx(i+'A', j+'0');
      FGETS(node[k].exp);
      node[k].eval(k);
    }

    FOR(i,0,n) FOR(j,0,m){
      int k = idx(i+'A', j+'0');
      if(!node[k].done && in[k] == 0){
        bfs(k);
      }
    }

    VR<int> bad;
    FOR(i,0,n) FOR(j,0,m){
      int k = idx(i+'A', j+'0');
      if(!node[k].done) bad.push_back(k);
    }

    if(!bad.empty()){
      for(int x : bad)
        printf("%c%c: %s",char((x/10)+'A'), char((x%10)+'0'), node[x].exp);
      putchar('\n');
      continue;
    }

    putchar(' ');
    FOR(i,0,m) printf(" %5d",i); putchar('\n');
    FOR(i,0,n){
      printf("%c",i+'A');
      FOR(j,0,m) printf(" %5d",node[i*10+j].v);
      putchar('\n');
    }
    putchar('\n');
  }

  return 0;
}
