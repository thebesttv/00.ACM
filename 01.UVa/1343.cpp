// Tag: bfs IDA* 暴力 i
#include<iostream>
#include<cassert>
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

int v[8][7] = {
  { 0, 2, 6,11,15,20,22}, // A
  { 1, 3, 8,12,17,21,23}, // B
  {10, 9, 8, 7, 6, 5, 4}, // C
  {19,18,17,16,15,14,13}  // D
};
int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2};
int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};
int a[24],maxd,r[120];

bool ok(){
  FOR(i,1,8) if(a[center[i]] != a[center[0]])
    return false;
  return true;
}

int diff(int tgt){
  int c = 0;
  FOR(i,0,8) if(a[center[i]] != tgt) ++c;
  return c;
}

int h(){
  return min(diff(1), min(diff(2), diff(3)));
}

void move(int d){
  int tmp = a[v[d][0]];
  FOR(i,0,6) a[v[d][i]] = a[v[d][i+1]];
  a[v[d][6]] = tmp;
}

bool dfs(int cur){
  if(cur == maxd) return ok();
  if(cur + h() > maxd) return false;  // 每次移动最多增加一个匹配
  FOR(d,0,8){
    r[cur] = d; move(d);
    if(dfs(cur+1)) return true;
    move(rev[d]);
  }
  return false;
}

int main(void){
  FOR(i,4,8) FOR(j,0,7) v[i][j] = v[rev[i]][6-j];
  while(scanf("%d",&a[0])==1 && a[0]){
    FOR(i,1,24) scanf("%d",&a[i]);
    if(ok()){
      printf("No moves needed\n%d\n",a[center[0]]);
      continue;
    }

    for(maxd=1;;maxd++) if(dfs(0)){
      FOR(i,0,maxd) putchar(r[i]+'A'); putchar('\n');
      printf("%d\n",a[center[0]]); break;
    }
  }

  return 0;
}

/*
const int MAX = 735471 + 20;
int a[24],to[MAX][8],id[1<<24],v[MAX];

bool ok(int st){
  const int RES = 0x399c0;
  return st == id[RES];
}

struct Node{
  int st; string s;
  Node(int st, string s): st(st), s(s) { }
};

void print(int st){
  st = v[st];
  int G[7][7]; MST(G,-1);
  pii pos[24] = {{0,2},{0,4},{1,2},{1,4},{2,0},{2,1},{2,2},{2,3},{2,4},{2,5},{2,6},{3,2},{3,4},{4,0},{4,1},{4,2},{4,3},{4,4},{4,5},{4,6},{5,2},{5,4},{6,2},{6,4}};
  FOR(i,0,24) G[pos[i].FI][pos[i].SE] = (st>>i)&1;
  FOR(i,0,7){
    FOR(j,0,7)
      if(G[i][j]==-1) printf("  ");
      else printf("%d ",G[i][j]);
    putchar('\n');
  }
}

int move(int st, int mask, int d){  // d=0: left, d=1: right
  int tail = 0, x = 0;
  FOR(i,0,24) if(mask&(1<<i)){
    if(st&(1<<i)) x |= 1<<tail;
    tail++;
  }
  if(!d) x = (0x7f&(x<<1)) | (x>>6);
  else x = (x>>1) | ((x&1)<<6);

  tail = 0;
  FOR(i,0,24) if(mask&(1<<i))
    if(x&(1<<(tail++))) st |= 1<<i;
    else st &= ~(1<<i);
  return st;
}

int move(int st, int d){
  switch(d){
    case 0: return move(st, 0x508845, 1); // A
    case 5: return move(st, 0x508845, 0); // F

    case 1: return move(st, 0xa2110a, 1); // B
    case 4: return move(st, 0xa2110a, 0); // E

    case 2: return move(st, 0x7f0, 0);    // C
    case 7: return move(st, 0x7f0, 1);    // H

    case 3: return move(st, 0xfe000, 0);  // D
    case 6: return move(st, 0xfe000, 1);  // G
  }
  return 0;
}

int vis[MAX];
string solve(int st, int tgt){
  queue<Node> q; q.push(Node(st,""));
  vis[st] = tgt;
  while(!q.empty()){
    Node t = q.front(); q.pop();
#ifdef DEBUG
    printf("node %s\n",t.s.c_str());
    print(t.st);
#endif
    if(ok(t.st)) return t.s;
    FOR(d,0,8) if(vis[to[t.st][d]] != tgt){ // move
#ifdef DEBUG
      printf("dir %c\n",char(d+'A'));
      print(to[t.st][d]);
#endif
      Node x(to[t.st][d], t.s + char('A'+d));
      q.push(x); vis[x.st] = tgt;
    }
  }
  return "Z";
}

int dfstail;
void dfs(int cur, int st, int left){
  if(cur == 24){
    id[st] = dfstail, v[dfstail++] = st;
    return;
  }
  if(left) dfs(cur+1, st|(1<<cur), left-1);
  if(24-cur > left) dfs(cur+1, st, left);
}

int main(void){
  dfs(0,0,8);
  FOR(i,0,dfstail) FOR(d,0,8){
    to[i][d] = id[move(v[i], d)];
  }
#ifdef DEBUG
  printf("total state: %d\n",dfstail);
  printf("pp done\n");
#endif

  while(scanf("%d",&a[0])==1 && a[0]){
    MST(vis,0);
    FOR(i,1,24) scanf("%d",&a[i]);
    string ans("Z"); int r = -1;
    FORR(tgt,1,3){
#ifdef DEBUG
      printf("target %d\n",tgt);
#endif
      int st = 0;
      FOR(i,0,24) if(a[i]==tgt) st |= 1<<i;
      string s = solve(id[st], tgt);

      if(s == "Z") continue;
      if(ans == "Z" || s.size() < ans.size() 
          || (s.size() == ans.size() && s < ans)){
        ans = s; r = tgt;
      }
    }
    if(ans.size()==0) printf("No moves needed\n");
    else printf("%s\n",ans.c_str());
    printf("%d\n",r);
  }

  return 0;
}
*/
