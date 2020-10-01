// Tag: notag 
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
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 120;
int nb,ns,nc,pb,ps,pc,cb,cs,cc;
int n; LL m; char s[MAX];

bool ok(LL x){
  LL tb = x * cb,
     ts = x * cs,
     tc = x * cc;
  LL tot = max(0ll, tb - nb) * pb
         + max(0ll, ts - ns) * ps
         + max(0ll, tc - nc) * pc;
  return tot <= m;
}

int main(void){
  scanf("%s",s); n = strlen(s);
  FOR(i,0,n) switch(s[i]){
    case 'B': ++cb; break;
    case 'C': ++cc; break;
    case 'S': ++cs; break;
  }
  scanf("%d%d%d",&nb,&ns,&nc);
  scanf("%d%d%d",&pb,&ps,&pc);
  scanf("%lld",&m);

  LL l = 0, r = 2e12;
  while(l<r){
    LL m = (l+r+1)/2;
    if(ok(m)) l = m;
    else r = m-1;
  }
  printf("%lld\n",l);

  return 0;
}

