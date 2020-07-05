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

const int MAX = 1e7, MAX_ = MAX+20;
const int MAXN = 5e5 + 20;
int n,a,d1[MAXN],d2[MAXN];
int prime[MAX], d[MAX];
bool vis[MAX];

void init(){
  int tail = 0; d[1] = 1;
  FORR(i,2,MAX){
    if(!vis[i]){
      prime[tail++] = i;
      d[i] = i;
    }
    FOR(j,0,tail){
      int t = prime[j] * i;
      if(t > MAX) break;
      vis[t] = 1;
      d[t] = prime[j];
      if(i % prime[j] == 0) break;
    }
  }
}

int v[120];
void cal(int n, int idx){
  int tail = 0, s = 1;
#ifdef DEBUG
  printf("%d:",n);
#endif
  while(n != 1){
    if(!tail || v[tail-1] != d[n])
      v[tail++] = d[n], s *= d[n];
    n /= d[n];
  }
#ifdef DEBUG
  FOR(i,0,tail) printf(" %d",v[i]); putchar('\n');
#endif
  if(tail == 1){
    d1[idx] = d2[idx] = -1;
  }else{
    d1[idx] = v[0], d2[idx] = s / v[0];
  }
}

int main(void){
  init();
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a), cal(a,i);
  FORR(i,1,n) printf("%d ",d1[i]); putchar('\n');
  FORR(i,1,n) printf("%d ",d2[i]); putchar('\n');

  return 0;
}
