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

const int MAX = 1020;
char s[MAX]; int cnt[128];

int main(void){
  scanf("%s",s);
  int n = strlen(s);
  FOR(i,0,n) ++cnt[s[i]];

  bool allEven=1, allOdd=1;
  FORR(i,'a','z') if(cnt[i])
    if(cnt[i]&1) allEven=0;
    else         allOdd=0;

  if(allEven)
    printf("0\n");
  else if(allOdd)
    printf("1\n");
  else
    printf("2\n");


  return 0;
}
