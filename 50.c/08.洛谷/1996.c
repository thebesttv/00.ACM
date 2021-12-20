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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=120;
int n,m;
bool a[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) a[i]=1;
  int p=-1; //<b> </b>
  FOR(i,0,n){
    int cnt=0;
    while(cnt<m){
      do (p+=1)%=n; while(!a[p]);
      cnt++;
    }
    a[p]=0;
    printf("%d ",p+1);
  }
  printf("\n");

  return 0;
}
