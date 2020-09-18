// Tag: 逆序对 i
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

const int MAX = 1e5 + 20;
int n, a[MAX];

struct ST{
  int a[MAX];
  void add(int x, int v){
    while(x <= n)
      a[x] += v, x += x&-x;
  }
  int sum(int x){
    int s = 0;
    while(x) s += a[x], x -= x&-x;
    return s;
  }
  int sum(int l, int r){
    return sum(r) - sum(l-1);
  }
}sg;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    printf("%d ",sg.sum(a[i]+1, n));
    sg.add(a[i], 1);
  }
  putchar('\n');

  return 0;
}
