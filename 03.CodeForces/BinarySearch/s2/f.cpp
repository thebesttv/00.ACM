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

const int MAX = 200020;
int n, m, a[MAX]; char s[MAX], s2[MAX], t[MAX];

bool ok(int r){
  memcpy(s2,s,sizeof(s));
  FORR(i,1,r) s2[a[i]] = 0;
  int j = 1;
  FORR(i,1,m){
    while(j<=n && s2[j] != t[i]) ++j;
    if(j > n) return false;
    ++j;
  }
  return true;
}

int main(void){
  scanf("%s%s",s+1,t+1);
  n = strlen(s+1), m = strlen(t+1);
  FORR(i,1,n) a[i] = read();

  int l = 0, r = n;
  while(l < r){
    int m = (l+r+1)/2;
    if(ok(m)) l = m;
    else r = m-1;
  }
  printf("%d\n",l);

  return 0;
}

