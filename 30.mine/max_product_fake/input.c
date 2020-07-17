// Tag: 
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

int main(int argc, char *argv[]){
  srand(time(NULL));
  int n,m; double possi;
  sscanf(argv[1],"%d",&n);
  sscanf(argv[2],"%d",&m);
  sscanf(argv[3],"%lf",&possi);
  printf("%d %d\n",n,m);
  FOR(i,0,n){
    if(1.0 * rand() / RAND_MAX < possi)
      printf("0 ");
    else{
      int x = 1.0 * rand() / RAND_MAX * int(1e2);
      if(1.0 * rand() / RAND_MAX > 0.7) x = -x;
      printf("%d ",x);
    }
  }
  putchar('\n');

  printf("%d %d\n",1,n); m--;
  while(m--){
    int l = rand()%n + 1,
        r = rand()%n + 1;
    if(l > r) swap(l,r);
    printf("%d %d\n",l,r);
  }

  return 0;
}
