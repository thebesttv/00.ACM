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

const int MAX = 4e5 + 20;
int n, p[MAX], c[MAX]; char s[MAX];
struct Node{
  int idx, a, b;
  bool operator < (const Node &c) const {
    return a != c.a ? a < c.a : b < c.b;
  }
  bool operator == (const Node &c) const {
    return a == c.a && b == c.b;
  }
}node[MAX], node2[MAX];

int cnt[MAX], pos[MAX];
void radix_sort(){
  MST(cnt, 0);
  FOR(i,0,n) ++cnt[node[i].b];
  pos[0] = 0;
  FOR(i,1,n) pos[i] = pos[i-1] + cnt[i-1];
  FOR(i,0,n) node2[pos[node[i].b]++] = node[i];

  MST(cnt, 0);
  FOR(i,0,n) ++cnt[node2[i].a];
  pos[0] = 0;
  FOR(i,1,n) pos[i] = pos[i-1] + cnt[i-1];
  FOR(i,0,n) node[pos[node2[i].a]++] = node2[i];
}

int main(void){
  scanf("%s",s); n = strlen(s);
  s[n++] = '$'; s[n] = 0;

  FOR(i,0,n) node[i] = {i, s[i], 0};
  sort(node, node+n);
  p[0] = node[0].idx; c[p[0]] = 0;
  FOR(i,1,n){
    p[i] = node[i].idx;
    if(node[i] == node[i-1])
      c[p[i]] = c[p[i-1]];
    else
      c[p[i]] = c[p[i-1]] + 1;
  }

  for(int k=0; (1<<k) < n; ++k){
    FOR(i,0,n) node[i] = {i, c[i], c[(i + (1<<k))%n]};
    radix_sort();
    p[0] = node[0].idx; c[p[0]] = 0;
    FOR(i,1,n){
      p[i] = node[i].idx;
      if(node[i] == node[i-1])
        c[p[i]] = c[p[i-1]];
      else
        c[p[i]] = c[p[i-1]] + 1;
    }
  }

  FOR(i,0,n) printf("%d ",p[i]); putchar('\n');

  return 0;
}
