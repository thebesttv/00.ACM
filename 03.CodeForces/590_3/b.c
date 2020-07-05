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

const int MAX=200020;
int n,k,q[MAX],head,tail;
map<int,bool> mp;

int main(void){
  scanf("%d%d",&n,&k);
  int id;
  FOR(i,0,n){
    scanf("%d",&id);
    if(mp.count(id) && mp[id]) continue;  // already have id
    if(tail - head < k){  // not full
      q[tail++] = id; mp[id]=1;
    }else{
      mp[q[head++]]=0; q[tail++]=id; mp[id]=1;
    }
  }
  printf("%d\n",tail-head);
  printf("%d",q[tail-1]);
  if(tail-head>=2) ROR(k,tail-2,head)
    printf(" %d",q[k]);
  putchar('\n');

  return 0;
}
