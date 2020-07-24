// Tag: 
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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e6 + 20;
int n,m,nxt[MAX]; char s[MAX],t[MAX];

void build(){
  int j = 0; nxt[0] = nxt[1] = 0;
  FOR(i,1,m){
    while(j && t[i] != t[j]) j = nxt[j];
    if(t[i] == t[j]) nxt[i+1] = ++j;
    else nxt[i+1] = 0;
  }
}

void kmp(){
  int j = 0;
  FOR(i,0,n){
    while(j && s[i] != t[j]) j = nxt[j];
    if(s[i] == t[j]) ++j;
    if(j == m) printf("%d\n",i-j+2), j=nxt[j];
  }
}

int main(void){
  scanf("%s%s",s,t);
  n = strlen(s), m = strlen(t);
  build(); kmp();
  FORR(i,1,m) printf("%d ",nxt[i]); putchar('\n');

  return 0;
}
