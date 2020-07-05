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

const int LEN=30;
int len,a[LEN];
int n,b;

void cal(int i){
  len=0;
  while(i){
    a[len++] = i%b;
    i/=b;
  }
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&b);
    int ans=0;
    FORR(i,1,n){
      cal(i);
      FOR(j,0,len) ans+=a[j];
    }
    printf("Case #%d: %d\n",kase,ans);
  }

  return 0;
}

/*
const int LEN=30;
int len; char a[LEN];
int n,b;

void add(){
  FOR(i,0,len){
    a[i]++;
    if(a[i]==b) a[i+1]++;
    else break;
  }
  if(a[len]) len++;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&b);
    len=1; MST(a,0);
    int ans=0;
    FOR(i,0,n){
      add();
      FOR(j,0,len) ans+=a[j];
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
