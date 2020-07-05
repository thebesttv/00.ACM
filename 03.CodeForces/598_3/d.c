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

const int MAX=1e6+20;
LL n,k; char s[MAX];
VR<int> zero;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    zero.clear();
    scanf("%lld%lld",&n,&k);
    scanf("%s",s);
    FOR(i,0,n) if(s[i]=='0')
      zero.push_back(i);

    LL l=0,r=0;
    auto it = zero.begin();
    while(l<n){
      while(l<n && s[l]!='1') l++;
      it = upper_bound(it, zero.end(),l);
      if(it == zero.end()) break;
      r = *it++;
      int t = min(LL(r)-l, k);
      swap(s[r-t],s[r]); k-=t;
      if(!k) break; ++l;
    }
    printf("%s\n",s);
  }

  return 0;
}

/*
const int MAX=1e6+20;
int n,k; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int l=0,r=0;
    while(r<n){
      while(r<n && s[r]!='0') r++;
      if(r>=n) break;
      while(l<r && s[l]!='1') l++;
      int t = min(r-l, k);
      swap(s[r],s[r-t]);
      k -= t; if(!k) break;
    }
    printf("%s\n",s);
  }

  return 0;
}
*/

/*
const int MAX=1e6+20;
int n,k; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    int l = 0;
    FOR(i,0,n) if(s[i]=='0'){
      int t = max(l, i-k);
      swap(s[t], s[i]);
      k -= (i-t); l = t+1;
      if(!k) break;
    }
    printf("%s\n",s);
  }

  return 0;
}
*/
