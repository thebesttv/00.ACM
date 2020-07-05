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

const int MAX = 60;
int n,m,G[MAX][MAX];
bool r[MAX],c[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(r,0), MST(c,0);
    scanf("%d%d",&n,&m);
    FORR(i,1,n) FORR(j,1,m){
      scanf("%d",&G[i][j]);
      if(G[i][j]) r[i]=c[j]=1;
    }
    int cr = 0, cc = 0;
    FORR(i,1,n) if(!r[i]) ++cr;
    FORR(i,1,m) if(!c[i]) ++cc;

    printf("%s\n", min(cr,cc) & 1 ? "Ashish" : "Vivek" );
  }

  return 0;
}

/*
const int MAX = 60;
int n,m,G[MAX][MAX];
bool r[MAX],c[MAX];

bool place(){
  FORR(i,1,n) if(!r[i]) FORR(j,1,m) if(!c[j]){
    r[i] = c[j] = 1; return true;
  }
  return false;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(r,0), MST(c,0);
    scanf("%d%d",&n,&m);
    FORR(i,1,n) FORR(j,1,m){
      scanf("%d",&G[i][j]);
      if(G[i][j]) r[i]=c[j]=1;
    }

    int player = 0;
    while(true){
      if(!place()){
        printf("%s\n", player==0 ? "Vivek" : "Ashish");
        break;
      }
      player ^= 1;
    }
  }

  return 0;
}
*/
