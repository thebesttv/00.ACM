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

const int MAX=200020;
int n; char s[2][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    scanf("%s%s",s[0],s[1]);
    int x=0, y=0;
    while(y<n){
      if(s[x][y]>='3'){
        if(s[x^1][y]<='2') break;
        x^=1;
      }
      y++;
    }
    printf("%s\n", x==1 && y==n ? "YES" : "NO" );
  }

  return 0;
}

/*
const int MAX=200020;
int n; char s[3][MAX];

bool ok(){
  int x,y,f, nx=1, ny=1, nf=0;

  while(true){
    x=nx, y=ny, f=nf;
    //printf("(%d,%d) %d\n",x,y,f);
    if(x==1 && y==n+1) return 0;
    if(x==2 && y==n){
      if(f==0) return s[x][y]<='2';
      if(f==1) return s[x][y]>='3';
      return 0;
    }

    if(f==0){
      if(s[x][y]<='2'){
        nx=x, ny=y+1, nf=0;
      }else{
        if(x==1) nx=2, ny=y, nf=1;
        else     nx=1, ny=y, nf=3;
      }
    }else if(f==1){
      if(s[x][y]<='2') return 0;
      nx=2, ny=y+1, nf=0;
    }else if(f==3){
      if(s[x][y]<='2') return 0;
      nx=1, ny=y+1, nf=0;
    }else return 0;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    scanf("%s%s",s[1]+1,s[2]+1);

    printf("%s\n", ok() ? "YES" : "NO" );
  }

  return 0;
}
*/
