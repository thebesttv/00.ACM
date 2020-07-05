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

const int MAX = 20;
int n,k; char G[MAX][MAX];

int main(void){
  int kase = 0;
  while(scanf("%d",&n)==1 && n){
    FORR(i,1,n) FORR(j,1,n)
      cin >> G[i][j];
      // do G[i][j] = getchar(); while(!isalpha(G[i][j]));

    printf("Input matrix #%d:\n",++kase);
    FORR(i,1,n){
      printf("%c",G[i][1]);
      FORR(j,2,n){
        printf(" %c",G[i][j]);
      }
      putchar('\n');
    }

    scanf("%d",&k);
    while(k--){
      int x; scanf("%d",&x);
      printf("Symmetric diagonals %d:\n",x);
      bool first = 1;
      FORR(i,1,n){
        if(i+x-1>n) break;
        if(first) first = 0;
        else putchar(' ');
        printf("%c",G[i][i+x-1]);
      }
      putchar('\n');

      if(x!=1){
        first = 1;
        FORR(i,1,n) if(i+x-1<=n){
          if(first) first = 0;
          else putchar(' ');
          printf("%c",G[i+x-1][i]);
        }
        putchar('\n');
      }
    }
    putchar('\n');
  }
  
  return 0;
}
