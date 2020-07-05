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

int a,b,c,d;
int v[] = {4 , 8, 15, 16, 23, 42};

bool ok(){
  if(v[0] * v[1] != a
  || v[0] * v[2] != b
  || v[0] * v[3] != c
  || v[0] * v[4] != d
  ) return false;
  return true;
}

int main(void){
  printf("? 1 2\n"); fflush(stdout);
  scanf("%d",&a);
  printf("? 1 3\n"); fflush(stdout);
  scanf("%d",&b);
  printf("? 1 4\n"); fflush(stdout);
  scanf("%d",&c);
  printf("? 1 5\n"); fflush(stdout);
  scanf("%d",&d);

  do{
    if(ok()){
      printf("!");
      FOR(i,0,6) printf(" %d",v[i]);
      putchar('\n'); fflush(stdout);
      break;
    }
  }while(next_permutation(v,v+6));
  return 0;
}
