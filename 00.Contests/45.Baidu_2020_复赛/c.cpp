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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
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

const int MAX = 1e5 + 20;
int n,l,k,v[MAX];

LL cal(){
  int left = n-l+1, i = 1, j = k;
  LL ans = 0;
  FORR(i,k,n){
    int d;
    if(i % k == 0){
      d = min(left, l-k+1);
    }else{
      d = min(left, 1);
    }
    left -= d;
    ans += 1ll*d*v[i];
  }
  return ans;
}

int main(void){
  int T,x; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&l,&k);
    FORR(i,1,n) scanf("%d",&v[i]);
    LL ansMax, ansMin;

    sort(v+1,v+1+n, greater<int>());
    ansMax = cal();

    reverse(v+1,v+1+n); k = l-k+1;
    ansMin = cal();

    printf("%lld %lld\n",ansMax, ansMin);
  }

  return 0;
}

/*
const int MAX = 1e5 + 20;
int n,l,k,v[MAX];

void cal(VR<int> &ans){
  int d = l-k, head = 0, tail = n;
  queue<pii> v1,v2;
  v1.push_back({tail-d,tail}); tail -= d;
  while(head < tail){
    int t = max(tail - d, head);
    v1.push({t, tail}); tail = t;

    t = min(head + k, tail);
    v2.push({head, t}); head = t;
  }

  VR<int> ans; int op = 0;
  FOR(i,0,siz){
    pii p;
    if(!op){
      if(!v1.empty()) p = v1.front(), v1.pop();
    }else{
      if(!v2.empty()) p = v2.front(), v2.pop();
    }
    FOR(k,p.FI,p.SE) ans.push_back(v[k]);
    op ^= 1;
  }
}

int main(void){
  int T,x; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&l,&k);
    FOR(i,0,n) scanf("%d",&v[i]);

    VR<int> ans;
    sort(v,v+n,greater<int>());
    cal(ans);
    LL ansMax = getMax(ans);

    reverse(v,v+n); ans.clear(); k = l - k + 1;
    cal(ans);
    LL ansMin = getMin(ans);

    printf("%lld ",ansMax);
  }

  return 0;
}
*/
