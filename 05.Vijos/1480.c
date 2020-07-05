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

const int MAX=65538, MAXN=260;
int len; char s[MAX];
int f[MAX]; // f[i]: 长度为 i ，走到0，最小的矩阵个数

int main(void){
  int ch=getchar();
  while(ch!='\n' && ch!='\r' && ch!=-1){  // 密文不一定为 alnum
    s[len++]=ch; ch=getchar();
  }
  
  MST(f,0x3f); f[0]=0;
  FORR(i,1,len) ROR(j,sqrt(i),1){
    f[i] = min(f[i], f[i-j*j] + 1 );
  }

  int p=len,l=0;
  while(p){
    ROR(k,sqrt(p),1) if(f[p]==f[p-k*k]+1){
      // 从 s[l] 开始，边长为 k
      // printf("%d ",i); p-=i*i; break;

      FOR(i,0,k) FOR(j,0,k)
        putchar(s[ l + i + j*k ]);
      l+=k*k, p-=k*k; break;
    }
  }
  printf("\n");

  return 0;
}
