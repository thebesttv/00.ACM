// Tag: 二分
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

bool find(int x){
  /*
  int l = 1, r = n;
  while(l <= r){
    int m = (l+r)/2;
    if(a[m] == x) return true;
    if(a[m] < x) l = m+1;
    else r = m-1;
  }
  */
  int l = 1, r = n + 1;
  while(l < r){
    int m = (l+r)/2;
    if(a[m] < x) l = m+1;
    else r = m;
  }
  return a[l] == x;
}

int main(void){
  n = read(), m = read();
  FORR(i,1,n) a[i] = nread();
  while(m--){
    printf("%s\n", find(nread()) ? "YES" : "NO");
  }

  return 0;
}
