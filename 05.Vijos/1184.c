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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=2020;
const int INF=0x3f3f3f3f;
int n,m,w[MAX];

map<int, int> mp;
VR<string> v;
int get(string &ip){
  int s=0;
  for(char c : ip){
    if(c=='.') s *= 1000;
    else s = s*10 + (c-'0');
  }
  return s;
}
int cnt=0;
int ID(string ip){
  int s = get(ip);
  if(mp.count(s)) return mp[s];
  v.push_back(ip);
  return mp[s] = ++cnt;
}

struct Edge{
  int v,w; Edge *next;
}edge[MAX*MAX];
Edge *head[MAX];
int tail=0;
void addEdge(int u, int v, int w){
  edge[tail] = Edge{v,w,head[u]}; head[u] = edge + tail++;
  edge[tail] = Edge{u,w,head[v]}; head[v] = edge + tail++;
}

struct Node{
  int d,u;
  bool operator < (const Node &b) const {
    return d > b.d;
  }
};

int d[MAX];
void Dij(int s){
  MST(d,0x3f); d[s]=0;
  PQ<Node> q; q.push(Node{0,s});
  while(!q.empty()){
    Node t=q.top(); q.pop();
    int u=t.u;
    if(d[u]!=t.d) continue;
    for(Edge *e=head[u];e;e=e->next){
      if(d[e->v] > t.d + e->w){
        d[e->v] = t.d + e->w;
        q.push(Node{d[e->v],e->v});
      }
    }
  }
}

int main(void){
  ios::sync_with_stdio(false);
  v.push_back("");  // v[0]

  cin >> n;
  string su,sv; int x;
  while(n--){
    cin >> su >> x;
    w[ID(su)] += x;
  }

  cin >> m;
  while(m--){
    cin >> su >> sv;
    int nu=get(su), nv=get(sv);
    if(mp.count(nu) && mp.count(nv)){
      nu = mp[nu], nv = mp[nv];
      addEdge(nu,nv,w[nu]+w[nv]);
    }
  }

  bool unknown=0;
  VR<Node> v;
  FORR(i,1,cnt){
    Dij(i);
    int sum=0;
    FORR(j,1,cnt){
      if(d[j]==INF){
        unknown=1; break;
      }
      sum+=d[j];
    }
    if(unknown) break;
    v.push_back(Node{sum,i});
  }

  sort(ALL(v));
  string ans;
  if(unknown || (v.size()>1 && v[0].d==v[2].d)){
    ans = string("222.240.168.135");
  }else ans = ::v[v[0].u];

  cout << "The ONLY truth is: it is you, " + ans << endl;

  return 0;
}
