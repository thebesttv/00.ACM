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

const int MAX = 520;
int n,a[MAX][MAX]; bool G[MAX][MAX];
char s[MAX];

bool findMatch(int i, int j){
  int s = 0;
  FOR(k,i+1,j) if(G[k][j]){
    s += a[i][k];
  }
  return s%10 == a[i][j];
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%s",s+1);
    FORR(j,1,n) a[i][j] = s[j]-'0';
  }

  ROR(i,n,1){
    FORR(j,i+1,n) if(!findMatch(i,j)){
#ifdef DEBUG
      printf("  fail match (%d, %d)\n",i,j);
#endif
      G[i][j] = 1;
    }
  }

  FORR(i,1,n){
    FORR(j,1,n) putchar(G[i][j]+'0');
    putchar('\n');
  }

  return 0;
}
