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

const int MAX = 20;
int n,m,x[MAX]; char s[1<<8],t[MAX];

int main(void){
  int kase = 0; char ch;
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) scanf("%s",t), x[i] = t[1]-'1';
    scanf("%s%d",s,&m);
    printf("S-Tree #%d:\n",++kase);
    while(m--){
      int u = 1; scanf("%s",t);
      FOR(i,0,n)
        if(t[x[i]]=='0') u = u<<1;
        else u = u<<1|1;
      putchar(s[u-(1<<n)]);
    }
    printf("\n\n");
  }

  return 0;
}
