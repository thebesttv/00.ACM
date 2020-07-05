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

const int MAX = 1020;
int n,m,k;
int cntCh = 0;
LL vpow[MAX];
bool has[8];
struct Node{
  LL c[8];
  void cal(char *s){
    FOR(i,0,m){
      c[s[i]-'a'] += vpow[i];
      has[s[i]-'a']=1;
    }
  }

  LL f(int *r){
    LL sum = 0;
    FOR(i,0,8) sum += c[i] * r[i];
    return sum;
  }
}node[MAX];
char s[MAX];

int ansMax = 0;
int r[8]; LL val[MAX];

int cal(){
  FOR(i,0,n){
    val[i] = node[i].f(r);
  }
  sort(val,val+n);
#ifdef DEBUG
  FOR(i,0,n) printf("  hash: %d\n",val[i]);
#endif

  VR<int> v;
  int i = 0;
  while(i<n){
    int j = i+1;
    while(j<n && val[j]==val[i]) ++j;
    if(j-i>1) v.push_back(j-i);
    i = j;
  }

  int ans = 0;
  for(int x : v) ans += x * (x-1) / 2;
  return ans;
}

void dfs(int cur, int cnt){
  // 等价类数目不足
  if(cnt + 8 - cur < cntCh - k) return;

  if(cur==8){
#ifdef DEBUG
    printf("dfs:");
    FOR(i,0,8) if(has[i]) printf(" %d",r[i]);
    printf("\n");
#endif
    if(cnt == cntCh - k)
      ansMax = max(ansMax, cal());
    return;
  }
  if(!has[cur]){
    dfs(cur+1,cnt);
    return;
  }

  FORR(i,1,cnt){
    r[cur] = i;
    dfs(cur+1,cnt);
  }
  if(cnt < cntCh-k){
    r[cur] = cnt+1;
    dfs(cur+1,cnt+1);
  }
}

int main(void){
  vpow[0] = 1;
  FORR(i,1,1000) vpow[i] = 13 * vpow[i-1];

  scanf("%d%d%d",&n,&m,&k);
  FOR(i,0,n){
    scanf("%s",s); node[i].cal(s);
  }

  FOR(i,0,8) if(has[i]) ++cntCh;
#ifdef DEBUG
  printf("has: ");
  FOR(i,0,8) if(has[i]) printf("%c",i+'a');
  printf("\n");
#endif
  if(k >= cntCh-1){
    printf("%d\n", n*(n-1)/2);
    return 0;
  }

  dfs(0,0);

  printf("%d\n",ansMax);

  return 0;
}

/*
int r[8];
set<int> st;
void dfs(int cur, int cnt){
  if(cur==8){
    int sum = 0;
    FOR(i,0,8) sum = sum * 8 + r[i];
    st.insert(sum);
    FOR(i,0,cur) printf("%d ",r[i]);
    printf("\n");
    return;
  }

  FORR(i,1,cnt){
    r[cur] = i;
    dfs(cur+1,cnt);
  }
  r[cur] = cnt+1;
  dfs(cur+1,cnt+1);
}

int main(void){
  dfs(0,0);
  printf("%d\n",(int)st.size());

  return 0;
}
*/
