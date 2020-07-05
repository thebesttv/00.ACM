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

const int MAX = 300020, MAX_NODE = 4000 * 100 + 20;
const int MOD = 20071027;
int n, f[MAX];
char s[MAX], word[104];

int tail = 1;
int to[MAX_NODE][26];
bool val[MAX_NODE];

void init(){
  tail = 1;
  MST(to[0], 0);
}

void insert(char *s){
  int u = 0, c;
  int n = strlen(s);
  ROR(i,n-1,0){
    c = s[i] - 'a';
    if(!to[u][c]){
      MST(to[tail], 0);
      val[tail] = 0;
      to[u][c] = tail++;
    }
    u = to[u][c];
  }
  val[u] = 1;
}

int main(void){
  int kase = 0;
  while(scanf("%s", s+1)==1){
    init();
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%s", word);
      insert(word);
    }
    n = strlen(s+1);
    f[0] = 1;
    FORR(i,1,n){
      int &a = f[i], u = 0, c;
      a = 0;
      ROR(j,i,1){
        c = s[j] - 'a';
        if(!to[u][c]) break;
        u = to[u][c];
        if(val[u]){
          a = (a + f[j-1]) % MOD;
        }
      }
    }
#ifdef DEBUG
    FORR(i,1,n) printf("  f[%d]: %d\n",i,f[i]);
#endif
    printf("Case %d: %d\n", ++kase, f[n]);
  }

  return 0;
}

/*
const int MAX = 300020, MAX_NODE = 4000 * 100 + 20;
const int MOD = 20071027;
int n, f[MAX];
char s[MAX], word[104];

int tail = 1;
int to[MAX_NODE][26];
bool val[MAX_NODE];

void init(){
  tail = 1;
  MST(to[0], 0);
}

void insert(char *s){
  int u = 0, c;
  while(*s){
    c = *s++ - 'a';
    if(!to[u][c]){
      MST(to[tail], 0);
      val[tail] = 0;
      to[u][c] = tail++;
    }
    u = to[u][c];
  }
  val[u] = 1;
}

int main(void){
  int kase = 0;
  while(scanf("%s", s+1)==1){
    init();
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%s", word);
      insert(word);
    }
    n = strlen(s+1);
    f[n+1] = 1;
    ROR(i,n,1){
      int &a = f[i], u = 0, c;
      a = 0;
      FORR(j,i,n){
        c = s[j] - 'a';
        if(!to[u][c]) break;
        u = to[u][c];
        if(val[u]){
          a = (a + f[j+1]) % MOD;
        }
      }
    }
#ifdef DEBUG
    FORR(i,1,n) printf("  f[%d]: %d\n",i,f[i]);
#endif
    printf("Case %d: %d\n", ++kase, f[1]);
  }

  return 0;
}
*/
