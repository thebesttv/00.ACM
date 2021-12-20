#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=220;
struct Ind{
  char s[120];
  int n;
  bool operator < (const Ind & b) const {
    return strcmp(s,b.s)<0;
  }
};
set<Ind> st;
char t1[120],t2[120];
int check_f[MAX][2],n;
bool g[MAX][2];
vector<int> G[MAX];

int get(char * str){
  Ind t; strcpy(t.s,str);
  set<Ind>::iterator it=st.find(t);
  if(it!=st.end()) return it->n;
  t.n=st.size(); st.insert(t);
  return t.n;
}
int f(int u, bool t){
  int & a=check_f[u][t];
  if(a!=-1) return a;
  if(!G[u].size()) a=t,g[u][t]=1;
  else if(!t){
    a=0;
    FOR(i,0,G[u].size()){
      int v=G[u][i];
      int f0=f(v,0),f1=f(v,1);
      if((f0<f1 && !g[v][1]) || (f0>f1 && !g[v][0]) || f0==f1) g[u][t]=0;
      a+=max(f0,f1);
    }
  }else{
    a=1;  //<b></b>
    FOR(i,0,G[u].size()){
      a+=f(G[u][i],0);
      if(!g[G[u][i]][0]) g[u][t]=0;
    }
  }
  return a;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    st.clear(); FORR(i,0,n) G[i].clear(); MST(check_f,-1);
    FORR(i,0,n) g[i][0]=g[i][1]=1;  //<b></b>
    scanf("%s",t1); get(t1);
    FOR(i,1,n){
      scanf("%s%s",t1,t2); G[get(t2)].push_back(get(t1));
#ifdef DEBUG
      printf("  %s (%d) -> %s (%d)\n",t1,get(t1),t2,get(t2));
#endif
    }
    int f0=f(0,0),f1=f(0,1);
    char str[4]; strcpy(str,"Yes");
    if((f0<f1 && !g[0][1]) || (f0>f1 && !g[0][0]) || f0==f1) strcpy(str,"No");
    printf("%d %s\n",max(f0,f1),str);
  }

  return 0;
}
