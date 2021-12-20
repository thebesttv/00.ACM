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

const int MAX = 80020;
int n,m,s[MAX]; LL MOD,qMin,qMax,v[MAX];

void add(int l, int r, int x){
  v[l] += x, v[r+1] -= x;
}
int query(int l, int r){
  LL d = 0; int cnt = 0;
  FOR(i,1,l) d += v[i];
  FORR(i,l,r){
    d += v[i];
    LL x = d * i %MOD;
    if(qMin <= x && x <= qMax) ++cnt;
  }
  return cnt;
}

void gen(){
  LL d = 0;
  FORR(i,1,n){
    d += v[i]; v[i] = d;
    LL x = d * i %MOD;
    if(qMin <= x && x <= qMax) s[i] = 1;
  }
  FORR(i,1,n) s[i] += s[i-1];
}

int main(void){
  scanf("%d%d%lld%lld%lld",&n,&m,&MOD,&qMin,&qMax);
  while(m--){
    int op, l, r;
    do op = getchar(); while(op!='A' && op!='Q');
    l = read(), r = read();
    if(op == 'A') add(l,r,nread());
    else printf("%d\n",query(l,r));
  }

  gen();
  m = read();
  while(m--){
    int l = read(), r = read();
    printf("%d\n",s[r]-s[l-1]);
  }

  return 0;
}

