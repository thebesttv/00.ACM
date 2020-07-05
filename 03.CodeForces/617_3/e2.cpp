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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=2e5 + 20;
int n; char s[MAX];
struct Node{
  int ch, pos;
  bool operator < (const Node &b) const {
    return ch != b.ch ? ch < b.ch : pos < b.pos;
  }
}node[MAX];
int tail = 0;
VR<Node> v[26];
int ans[MAX];

int find(Node t){
  int pMax = -1, r = -1;
  FOR(i,0,tail) if(v[i].back().pos < t.pos
      && v[i].back().pos > pMax){
    pMax = v[i].back().pos;
    r = i;
  }
  return r;
}

int main(void){
  scanf("%d%s",&n,s);
  FOR(i,0,n) node[i]={s[i],i};
  sort(node,node+n);

  v[tail++].push_back(node[0]);
  FOR(i,1,n){
    int t = find(node[i]);
    if(t==-1) v[tail++].push_back(node[i]);
    else v[t].push_back(node[i]);
  }

  FOR(i,0,tail) for(Node t : v[i]){
    ans[t.pos]=i+1;
  }
  printf("%d\n",tail);
  FOR(i,0,n) printf("%d ",ans[i]);
  putchar('\n');
  return 0;
}
