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

int n;
char s[20]; LL d;

LL get(){
  LL sum = 0;
  FOR(i,0,n) sum = sum*10 + s[i]-'0';
  return sum;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s%lld",s,&d);
    n = strlen(s);
    sort(s,s+n);
    int cnt = 0;
    do{
      LL a = get();
      if(a%d==0) ++cnt;
    }while(next_permutation(s,s+n));
    printf("%d\n",cnt);
  }

  return 0;
}
