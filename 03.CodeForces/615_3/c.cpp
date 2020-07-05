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

const int MAX = 1e5 + 20;
int n, tail;
int p[MAX], cnt[MAX];

void div(int n){
  int r = sqrt(n+0.5);
  FORR(i,2,r) if(n%i==0){
    p[tail] = i;
    while(n%i==0) ++cnt[tail], n/=i;
    ++tail;
  }
  if(n>1) p[tail] = n, cnt[tail++] = 1;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,tail) cnt[i] = p[i] = 0;
    tail = 0;
    scanf("%d",&n);
    div(n);
    int a, b;
    if(tail==1){
      if(cnt[0] < 6){
        printf("NO\n"); continue;
      }else{
        a = p[0];
        b = a*a;
      }
    }else if(tail==2){
      if(cnt[0] + cnt[1] < 4){
        printf("NO\n"); continue;
      }else{
        if(cnt[0] > cnt[1]){
          swap(cnt[0], cnt[1]);
          swap(p[0], p[1]);
        }

        if(cnt[0]==1){  // cnt[1] >= 3
          a = p[0];
          b = p[1];
        }else if(cnt[0]==2){  // cnt[1] >= 2
          a = p[0];
          b = p[0] * p[1];
        }else{  // cnt[0] >= 3
          a = p[0];
          b = p[1];
        }
      }
    }else{
      a = p[0], b = p[1];
    }
    printf("YES\n");
    printf("%d %d %d\n",a,b,n/a/b);
  }

  return 0;
}
