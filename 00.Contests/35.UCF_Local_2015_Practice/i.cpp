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

const int MAX = 20;
const int INF = 0x3f3f3f3f;
const int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const char *direction[4] = {"east", "south", "west", "north"};

int n; char s[MAX];
int G1[MAX][MAX],G2[MAX][MAX];
int d1[MAX][MAX],d2[MAX][MAX];
pii s1, s2;
bool vis[MAX][MAX];

void bfs(decltype(G1) G, decltype(d1) d, pii s){
  MST(vis,0);
  queue<pair<pii,int>> q; q.push({s,0});
  vis[s.FI][s.SE] = 1;
  d[s.FI][s.SE] = 0;

  while(!q.empty()){
    auto t = q.front(); q.pop();
    FOR(dir,0,4){
      int tx = t.FI.FI + to[dir][0],
          ty = t.FI.SE + to[dir][1];
      if(tx<1 || tx>n || ty<1 || ty>n
          || G[tx][ty] || vis[tx][ty])
        continue;
      vis[tx][ty] = 1; d[tx][ty] = t.SE + 1;
      q.push({{tx,ty}, t.SE+1});
    }
  }
#ifdef DEBUG
  printf("G:\n");
  FORR(i,1,n){
    FORR(j,1,n) printf("%d ",G[i][j]);
    putchar('\n');
  }
  printf("d:\n");
  FORR(i,1,n){
    FORR(j,1,n) printf("%d ",d[i][j]);
    putchar('\n');
  }
#endif
}

void print(decltype(G1) G, decltype(d1) d, pii s, pii t, const char *pre){
  VR<int> v;
  while(s != t){
    FOR(dir,0,4){
      int tx = t.FI + to[dir][0],
          ty = t.SE + to[dir][1];
      if(tx<1 || tx>n || ty<1 || ty>n) continue;
      if(d[tx][ty] + 1 != d[t.FI][t.SE]) continue;
      v.push_back((dir+2)%4); t = {tx,ty};
      break;
    }
  }
  reverse(ALL(v));
  for(int d : v){
    printf("   %s move %s\n",pre,direction[d]);
  }
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FORR(i,1,n){
      scanf("%s",s+1);
      FORR(j,1,n){
        if(s[j] == 'M'){
          s1 = {i,j};
          G1[i][j] = G2[i][j] = 0;
        }else if(s[j] == 'Z'){
          s2 = {i,j};
          G1[i][j] = G2[i][j] = 0;
        }else{
          int d = s[j] - '0';
          G1[i][j] = (d&1)==0;
          G2[i][j] = (d&2)==0;
        }
      }
    }

    MST(d1,0x3f), MST(d2,0x3f);
    bfs(G1, d1, s1);
    bfs(G2, d2, s2);

    int ans = INF; pii e1, e2;
    FORR(i,1,n) FORR(j,1,n) FOR(dir,0,4){
      int tx = i + to[dir][0],
          ty = j + to[dir][1];
      if(tx < 1 || tx > n || ty < 1 || ty > n)
        continue;
      if(d1[i][j] + d2[tx][ty] < ans){
        ans = d1[i][j] + d2[tx][ty];
        e1 = {i,j}, e2 = {tx,ty};
      }
    }

    printf("Maze #%d:\n",kase);
    print(G1,d1,s1,e1,"Mack");
    print(G2,d2,s2,e2,"Zack");
    printf("   Total number of moves: %d\n",ans);
    putchar('\n');
  }

  return 0;
}
