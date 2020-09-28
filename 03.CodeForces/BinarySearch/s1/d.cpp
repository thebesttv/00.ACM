// Tag: 二分
// 两侧设置哨兵 a[0] = INT_MIN, a[++n] = INT_MAX
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
int n,m,a[MAX];

int cal1(int x){  // min i, st. ai >= x
  int l = 0, r = n;
  while(l < r){
    int m = (l+r)/2;
    if(a[m] >= x) r = m;
    else l = m+1;
  }
  return l;
}

int cal2(int x){  // max i, st. ai <= x
  int l = 0, r = n;
  while(l < r){
    int m = (l+r+1)/2;
    if(a[m] <= x) l = m;
    else r = m-1;
  }
  return l;
}

int count(int l, int r){
  l = cal1(l), r = cal2(r);
  return max(0, r-l+1);
}

int main(void){
  n = read();
  FORR(i,1,n) a[i] = nread();
  sort(a+1,a+1+n);
  a[0] = INT_MIN, a[++n] = INT_MAX;

  m = read();
  while(m--){
    int l = nread(), r = nread();
    printf("%d ", count(l, r));
  }
  putchar('\n');

  return 0;
}

