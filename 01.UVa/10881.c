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

const int MAX=10020;
struct Ind{
  int x, dir, no; // dir=1: right, -1: left

  bool operator < (const Ind &b) const {
    return x<b.x;
  }
}a[MAX],b[MAX],c[MAX];
int T,n,l,t;
bool turning[MAX];
char ts[10];

int main(void){
  scanf("%d",&T);
  FORR(kase,1,T){
    MST(turning, 0);
    scanf("%d%d%d",&l,&t,&n);

    int x,dir;
    FOR(i,0,n){
      scanf("%d%s",&x,ts);
      dir = ts[0]=='R' ? 1 : -1;
      a[i] = (Ind){x,dir,i};
      b[i] = (Ind){ x + dir*t, dir, 0 };
    }

    sort(a,a+n); sort(b,b+n);
    FOR(i,0,n){
      c[ a[i].no ] = (Ind){ b[i].x, b[i].dir, 0 };
      b[i].no = a[i].no;
    }

    FOR(i,1,n) if(b[i].x == b[i-1].x)
      turning[ b[i].no ] = turning[ b[i-1].no ] = 1;

    printf("Case #%d:\n",kase);
    FOR(i,0,n){
      if(c[i].x<0 || c[i].x>l)
        printf("Fell off\n");
      else if(turning[i])
        printf("%d Turning\n",c[i].x);
      else printf("%d %c\n", c[i].x, c[i].dir==1 ? 'R' : 'L' );
    }
    printf("\n");
  }

  return 0;
}
