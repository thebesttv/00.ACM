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

int a[7],s;

int main(void){
  while(true){
    s=0;
    FORR(i,1,6) scanf("%d",&a[i]), s+=a[i];
    if(!s) break;

    int cnt=0;
    // 6
    cnt+=a[6]; a[6]=0;

    // 5
    cnt+=a[5];
    a[1]=max(0,a[1]-11*a[5]);
    a[5]=0;

    // 4
    if(a[4]){
      cnt+=a[4];
      int t = min(a[4]*5, a[2]);
      int left = a[4]*20 - t*4;
      a[2]-=t; a[1]=max(0,a[1]-left);
      a[4]=0;
    }

    // 3
    cnt += a[3]/4; a[3]%=4;
    if(a[3]){
      cnt++; int left=36-a[3]*9;
      if(a[2]){
        int t;
        if(a[3]==1) t=5;
        else if(a[3]==2) t=3;
        else t=1;
        t = min(t,a[2]);
        left-=t*4; a[2]-=t;
      }
      a[1]=max(0,a[1]-left);
    }

    // 2
    cnt += a[2]/9; a[2]%=9;
    if(a[2]){
      cnt++; int left=36-a[2]*4;
      a[1]=max(0,a[1]-left);
    }

    // 1
    cnt += a[1]/36; a[1]%=36;
    if(a[1]) cnt++;

    printf("%d\n",cnt);
  }

  return 0;
}
