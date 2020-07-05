// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes#Segmented_sieve

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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX_SEG = 10;
int n; int vis[MAX_SEG + 20];
VR<int> prime;

int col = 0;
void segmented_sieve(int l, int d){
  ++col;
  int r = l + d, end = sqrt(r+0.5);
  for(int p : prime){
    if(p > end) break;
    LL k = ceil(1.0 * l / p);
    for(LL j = k * p; j < r; j += p)
      vis[j - l] = col;
  }

  FOR(i,0,d) if(vis[i] != col){
    int p = i+l, k = ceil(1.0 * l / p);
    prime.push_back(p);
  }
}

void sieve(int n){
  int l = 2, r = min(MAX_SEG, n+1), d = r-l+1;
  FOR(i,2,r) if(!vis[i]){
    prime.push_back(i);
    for(int j = 2*i; j < r; j += i)
      vis[j] = 1;
  }

  l = r; col = 1;
  while(l <= n){
    int d = min(MAX_SEG, n - l + 1);
    segmented_sieve(l,d);
    l += d;
  }
}

int main(void){
  scanf("%d",&n);
  sieve(n);
  for(int p : prime)
    printf("%d ",p);
  putchar('\n');

  return 0;
}

/*
const int MAX_SEG = 100000;
int n; int vis[MAX_SEG + 20];
VR<int> prime;

int col = 0;
void segmented_sieve(int l, int d){
  ++col;
  int r = l + d;
  for(int p : prime){
    int k = max(ceil(1.0 * l / p), 2.0);
    for(int j = k * p; j < r; j += p)
      vis[j - l] = col;
  }

  FOR(i,0,d) if(vis[i] != col){
    int p = i+l, k = max(ceil(1.0 * l / p), 2.0);
    prime.push_back(p);
    for(int j = k * p; j < r; j += p)
      vis[j - l] = col;
  }
}

void sieve(int n){
  int l = 2;
  while(l <= n){
    int d = min(MAX_SEG, n - l + 1);
    segmented_sieve(l,d);
    l += d;
  }
}

int main(void){
  scanf("%d",&n);
  sieve(n);
  for(int p : prime)
    printf("%d ",p);
  putchar('\n');

  return 0;
}
*/
