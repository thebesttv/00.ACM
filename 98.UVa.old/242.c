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

const int MAXN=20, MAX=100*10+20;
int s,n,x[MAXN],f[MAX];
struct Set{
  VR<int> v;
  bool operator < (const Set &b) const {
    if(v.size()!=b.v.size())
      return v.size() < b.v.size();
    ROR(i,v.size()-1,0) if(v[i]!=b.v[i])
      return v[i]<b.v[i];
    return 0;
  }
}st[MAXN];

int cal(VR<int> &v){
  MST(f,0x3f); f[0]=0;
  int i=0;
  while(f[i]<=s){
    if(f[i]<s) for(int x : v)
      f[i+x]=min(f[i+x],f[i]+1);
    i++;
  }
  return i-1;
}

int main(void){
  while(scanf("%d",&s)==1 && s){
    scanf("%d",&n);
    FOR(i,0,n){
      int m,t; scanf("%d",&m);
      VR<int> &v=st[i].v; v.resize(m);
      FOR(j,0,m) scanf("%d",&v[j]);
    }
    sort(st,st+n);

    int ansMax=0,ansR=0;
    FOR(i,0,n){
      int t=cal(st[i].v);
      if(t>ansMax){
        ansMax=t; ansR=i;
      }
    }

    printf("max coverage =%4d :",ansMax);
    for(int i : st[ansR].v) printf("%3d",i);
    putchar('\n');
  }
  return 0;
}

/*
const int MAXN=20, MAX=100*10+20;
int s,n,x[MAXN];
bool f[MAX][MAXN];
struct Set{
  VR<int> v;
  bool operator < (const Set &b) const {
    if(v.size()!=b.v.size())
      return v.size() < b.v.size();
    ROR(i,v.size()-1,0) if(v[i]!=b.v[i])
      return v[i]<b.v[i];
    return 0;
  }
}st[MAXN];

int cal(VR<int> &v){
  MST(f,0); f[0][0]=1;
  int i=0;
  while(true){
    bool ok=0;
    FORR(j,0,s) ok|=f[i][j];
    if(!ok) break;
    FOR(j,bool(i),s) if(f[i][j]){
      for(int x : v) f[i+x][j+1]=1;
    }
    i++;
  }
  i--;
  return i;
}

int main(void){
  while(scanf("%d",&s)==1 && s){
    scanf("%d",&n);
    FORR(i,1,n){
      VR<int> &v=st[i].v; v.clear();
      int m,t; scanf("%d",&m);
      FOR(j,0,m) scanf("%d",&t), v.push_back(t);
    }
    sort(st+1,st+1+n);
    int ansMax=0; Set *ansSt=NULL;
    FORR(i,1,n){
      int t = cal(st[i].v);
      if(t>ansMax){
        ansMax=t, ansSt=st+i;
      }
    }
    printf("max coverage =%4d :",ansMax);
    for(int i : ansSt->v) printf("%3d",i);
    putchar('\n');
  }
  return 0;
}
*/
