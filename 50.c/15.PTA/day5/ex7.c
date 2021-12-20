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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

struct List{
  double v; List *next;
};

int main(void){
  int n; scanf("%d",&n);
  List *head = new List, *p = head;
  FOR(i,0,n){
    scanf("%lf",&(p->v));
    if(i<n-1){
      p->next = new List;
      p = p->next;
    }else p->next = NULL;
  }
  double sum = 0, ansMax=0, ansMin=0x3f3f3f3f;
  p = head;
  while(p){
    sum += p->v;
    ansMax = max(ansMax, p->v);
    ansMin = min(ansMin, p->v);
    p = p->next;
  }
  printf("average = %.2lf\nmax = %.2lf\nmin = %.2lf\n",
      1.0*sum/n,ansMax,ansMin);

  return 0;
}
