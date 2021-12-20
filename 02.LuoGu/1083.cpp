// Tag: 差分 二分
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

const int MAX = 1e6 + 20;
int n,m,d[MAX],s[MAX],t[MAX],r[MAX];
LL v[MAX];

bool ok(int x){ // whether the xth order is ok
  FORR(i,1,n) v[i] = r[i] - r[i-1];

  FORR(i,1,x) v[s[i]] -= d[i], v[t[i]+1] += d[i];
  LL del = 0;
  FORR(i,1,n) if((del += v[i]) < 0)
    return false;
  return true;
}

int main(void){
  n = read(), m = read();
  FORR(i,1,n) r[i] = read();
  FORR(i,1,m) d[i] = read(), s[i] = read(), t[i] = read();

  if(ok(m)){
    printf("0\n"); return 0;
  }
  int l = 0, r = m - 1;
  while(l < r){
    int m = (l+r+1)/2;
    if(ok(m)) l = m;
    else r = m-1;
  }
  printf("-1\n%d\n",l+1);

  return 0;
}

