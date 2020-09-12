// Tag: notag
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

int n,m,a,b,c;
struct Node{
  int x,y,t;
};
VR<Node> v;

LL f(const Node &p){
  return 1ll * a * p.x + 1ll * b * p.y + c;
}
bool same(const VR<int> &v){
  if(v.empty()) return false;
  FOR(i,1,v.size()) if(v[i] != v[0])
    return false;
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n){
    int x,y,ch;
    scanf("%d%d",&x,&y);
    do ch=getchar(); while(ch!='A' && ch!='B');
    v.pb(Node{x,y,ch=='B'});
  }

  while(m--){
    VR<int> vp, vn;
    scanf("%d%d%d",&c,&a,&b);
    for(Node &p : v)
      if(f(p) > 0) vp.pb(p.t);
      else vn.pb(p.t);
    printf("%s\n", same(vp) && same(vn) ? "Yes" : "No");
  }

  return 0;
}
