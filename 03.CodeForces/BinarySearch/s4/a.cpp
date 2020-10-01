// Tag: 二分 i
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

const int MAX = 1e5 + 20;
int n,d,a[MAX]; double s[MAX],f[MAX];

bool ok(double x){
  double s = 0;
  FORR(i,1,n){
    s += a[i] - x;
    f[i] = min(f[i-1], s);
    if(i >= d && s >= f[i-d]){
#ifdef DEBUG
      printf("ok(%.2lf), i: %d\n",x,i);
#endif
      return true;
    }
  }
#ifdef DEBUG
  printf("ok(%.2lf): bad\n",x);
  printf("f:"); FORR(i,1,n) printf(" %.2lf",f[i]); putchar('\n');
#endif
  return false;
}

void print(double x){
  int last = -1;
  FORR(i,1,n){
    s[i] = s[i-1] + a[i] - x;
    f[i] = min(f[i-1], s[i]);
    if(i >= d && s[i] >= f[i-d]) last = i;
  }
  FORR(j,1,n) if(s[j-1] <= s[last]){
    printf("%d %d\n",j,last);
    break;
  }
}

int main(void){
  n = read(), d = read();
  FORR(i,1,n) a[i] = read();

  double l = -1, r = 101;
  while(r - l > 1e-4){
    double m = (l+r)/2;
    if(ok(m)) l = m;
    else r = m;
  }
#ifdef DEBUG
  printf("%.4lf\n",l);
#endif
  print(l);

  return 0;
}

