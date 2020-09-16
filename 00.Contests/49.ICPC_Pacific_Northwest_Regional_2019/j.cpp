// Tag: TODO
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

typedef long double LD;
const int MAX = 1e5 + 20;
const LD PI = 3.14159265358979323846;
int n;

LD dis(LD x, LD y){
  x = fabs(x - y); return min(x, 2*PI - x);
}

struct Node{
  LD t,s,a;
  void read() { scanf("%Lf%Lf%Lf",&t,&s,&a); }
  LD cal(LD x){
    return max(0.L, t - s * dis(a,x));
  }
}node[MAX];

LD cal(LD x){
  LD sum = 0;
  FORR(i,1,n) sum += node[i].cal(x);
  return sum;
}

LD solve(LD l, LD r){
  while(r - l >= 1e-10){
    LD m1 = l + (r-l)/3, x1 = cal(m1);
    LD m2 = r - (r-l)/3, x2 = cal(m2);
    if(x1 > x2) r = m2;
    else l = m1;
  }
  return cal(l);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) node[i].read();
  int tail = 0; LD tMax = 0, r = -1;
  int rng = 1000;
  for(LD x = 0; x < PI*2; x += 0.005){
    LD res = cal(x);
#ifdef DEBUG
    printf("%Lf\n",res);
#endif
    if(tMax < res) tMax = res, r = x;
  }
  printf("%.10Lf\n",solve(r - 0.01, r + 0.01));

  return 0;
}
