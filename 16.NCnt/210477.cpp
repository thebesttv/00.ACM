// Tag: 概率DP
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

const int MAX = 120;
int n,a[MAX]; double f[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  f[n] = a[n];
  ROR(i,n-1,1){
    int cnt = 0; double sum = 0;
    FORR(j,1,6) if(i+j<=n)
      sum += f[i+j], ++cnt;
    f[i] = sum/cnt + a[i];
  }
  printf("%.10lf\n",f[1]);

  return 0;
}
