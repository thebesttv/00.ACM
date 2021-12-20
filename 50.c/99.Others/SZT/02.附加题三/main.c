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
typedef long long LL;
typedef long long unsigned LLU;

const int L=26;
int G[L][L];

void init(){
  FOR(i,0,L) FOR(j,0,L)
    G[i][j] = (i+j)%L;
#ifdef DEBUG
  FOR(i,0,L){
    FOR(j,0,L) printf("%c ",G[i][j]+'A');
    putchar('\n');
  }
#endif
}

void print(VR<int> v, bool lower){
  for(int i : v){
    putchar( i + (lower?'a':'A') );
  }
  putchar('\n');
}

void enc(const VR<int> &s, const VR<int> &k, VR<int> &ans){
  FOR(i,0,s.size())
    ans.push_back(G[s[i]][k[i]]);
}

void dec(const VR<int> &s, const VR<int> &k, VR<int> &ans){
  FOR(j,0,k.size()) FOR(i,0,L)
    if(G[i][k[j]]==s[j]) ans.push_back(i);
}

int main(void){
  init();
  string ts,tk;
  cin >> ts >> tk;
  VR<int> s,orik,k;
  FOR(i,0,ts.size()) s.push_back(ts[i]-'a');
  FOR(i,0,tk.size()) orik.push_back(tk[i]-'a');
  FOR(i,0,s.size()) k.push_back(orik[i%orik.size()]);

  print(s,1); print(orik,1); print(k,1);
  VR<int> v; enc(s,k,v);
  print(v,0);

  VR<int> ans; dec(v,k,ans);
  print(ans,1);

  return 0;
}
