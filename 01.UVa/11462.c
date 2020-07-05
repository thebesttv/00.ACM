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
typedef long long LL;
typedef long long unsigned LLU;

int n,cnt[101];

int read(){
  int sum=0,ch=getchar();
  while(!isdigit(ch)) ch=getchar();
  do{ sum = sum*10 + ch-'0'; ch=getchar(); }while(isdigit(ch));
  return sum;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(cnt,0);
    while(n--) cnt[read()]++;
    bool first=1;
    FORR(i,1,100) FOR(j,0,cnt[i]){
      if(first) first=0;
      else putchar(' ');
      printf("%d",i);
    }
    printf("\n");
  }
  return 0;
}
