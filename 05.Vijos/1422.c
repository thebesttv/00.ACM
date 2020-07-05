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

const int MAX=100020;
int n,maxL; bool vis[MAX];
queue<string> q;

struct Edge{
  int u,v,w;
  bool operator < (const Edge &e) const {
    return w<e.w;
  }
};
VR<Edge> edge;
void addEdge(int u, int v, int w){
  edge.push_back(Edge{u,v,w});
}

int ID(const string &);

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  scanf("%d",&n);
  string vs[10];
  FOR(i,0,n){
    string s; cin >> s;
    maxL=max(maxL,(int)s.size());
    vis[ID(s)]=1; q.push(s);
    vs[i]=s;
  }
  FOR(i,1,n) addEdge(ID(vs[i-1]),ID(vs[i]),0);

  while(!q.empty()){
    string s=q.front(); q.pop();
    int siz=s.size(),v;

    FOR(i,0,siz) FOR(j,i+1,siz){
      if(s[i]==s[j]) continue;
      string t=s;
      swap(t[i],t[j]); v=ID(t);
      if(!vis[v]) { q.push(t); vis[v]=1; }
    }

    if(siz==2 && s[0]==s[1]){
      string t; t+=s[0]; v=ID(t);
      if(!vis[v]) { q.push(t); vis[v]=1; }
    }else if(siz>2) FOR(i,0,siz){
      int a = s[i]-'0';
      int b = s[ i==0 ? siz-1 : i-1 ]-'0';
      int c = s[ i==siz-1 ? 0 : i+1 ]-'0';
      if(a>=b && a<=c){
        string t=s;
        t.erase(t.begin()+i); v = ID(t);
        if(!vis[v]) { q.push(t); vis[v]=1; }
      }
    }

    if(siz<maxL){
      FOR(i,0,siz){
        int b = s[ i==0 ? siz-1 : i-1 ]-'0';
        int c = s[i]-'0';

        FORR(a,b,c){
          string t=s; t.insert(t.begin()+i,a+'0');
          v = ID(t);
          if(!vis[v]) { q.push(t); vis[v]=1; }
        }
      }
      int b = s[siz-1]-'0';
      int c = s[0]-'0';
      FORR(a,b,c){
        string t=s; t+=a+'0';
        v = ID(t);
        if(!vis[v]) { q.push(t); vis[v]=1; }
      }
    }
  }

  FOR(i,0,MAX) if(vis[i]){
    string s=to_string(i);
    int siz=s.size();
    int u=ID(s),v;

    FOR(i,0,siz) FOR(j,i+1,siz){
      if(s[i]==s[j]) continue;
      string t=s;
      swap(t[i],t[j]); v=ID(t);
      int a = s[i]-'0', b = s[j]-'0';
      addEdge(u,v, ((a&b)+(a^b))*2);
    }

    if(siz==2 && s[0]==s[1]){
      int a=s[0]-'0';
      string t; t+=s[0]; v=ID(t);
      addEdge(u,v,(a + (a&a) + (a^a)));
    }else if(siz>2) FOR(i,0,siz){
      int a = s[i]-'0';
      int b = s[ i==0 ? siz-1 : i-1 ]-'0';
      int c = s[ i==siz-1 ? 0 : i+1 ]-'0';
      if(a>=b && a<=c){
        string t=s; t.erase(t.begin()+i);
        v = ID(t);
        addEdge(u,v, ( a + (b&c) + (b^c) ));
      }
    }

    if(siz<maxL){
      FOR(i,0,siz){
        int b = s[ i==0 ? siz-1 : i-1 ]-'0';
        int c = s[i]-'0';

        FORR(a,b,c){
          string t=s; t.insert(t.begin()+i,a+'0');
          v = ID(t);
          addEdge(u,v, a + (b&c) + (b^c));
        }
      }
      int b = s[siz-1]-'0';
      int c = s[0]-'0';
      FORR(a,b,c){
        string t=s; t+=a+'0';
        v = ID(t);
        addEdge(u,v, a + (b&c) + (b^c));
      }
    }
  }

  MST(p,-1);
  sort(ALL(edge));
  LL ans=0;
  for(Edge e : edge){
    int x=fa(e.u), y=fa(e.v);
    if(x!=y){
      ans+=e.w; p[x]=y;
    }
  }
  printf("%lld\n",ans);

  return 0;
}

int ID(const string &s){
  int sum=0;
  for(char c : s) sum = sum*10 + c-'0';
  return sum;
}
