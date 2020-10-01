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

const int MAX = 1020;
int n,m,a[MAX],t[MAX],z[MAX],y[MAX];

LL cal(LL t, LL z, LL y, LL x){
  LL k = x / (t * z + y);
  LL sum = k * z; x -= k * (t * z + y);
  sum += min(x / t, z);
  return sum;
}

bool ok(LL x){
  LL sum = 0;
  FORR(i,1,n) sum += cal(t[i],z[i],y[i],x);
  return sum >= m;
}

int main(void){
  m = read(), n = read();
  FORR(i,1,n) t[i] = read(), z[i] = read(), y[i] = read();

  int l = 0, r = INT_MAX;
  while(l < r){
    int m = l + (r-l)/2;
    if(ok(m)) r = m;
    else l = m+1;
  }

  FORR(i,1,n) a[i] = cal(t[i],z[i],y[i],l);

  printf("%d\n",l);
  FORR(i,1,n){
    int d = min(m, a[i]);
    m -= d; printf("%d ",d);
  }
  putchar('\n');

  return 0;
}

