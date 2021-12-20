/*
num[i]: 对于 S[1:i] ，既为它的前缀，又为它的后缀，且前缀与后缀不重叠的子串个数。
因为“前缀与后缀不重叠”这个条件不容易判断，那么就先忽略。
令 f[i] 表示对于 S[1:i] ，即为它的前缀，又为它的后缀的子串个数（包括前缀和后缀都为自身的情况），则有
　f[i] = f[P[i]] + 1，其中 P[i] 即为 KMP 中的 next[i]
　原因：
　　求 f 实质上就是遍历 S[1:i] 中的所有子串 S[1:j] ，若 S[1:j] = S[i-j+1:i] ，则算入 f 中。
　　首先，最大的子串，即自身 S[1:i]=S[1:i] 的情况要算进去；
　　然后要计算的第二大的子串就是 P[i] 所表示的 S[1:P[i]] = S[i-P[i]+1:i]，而之后的所有其他子串都是在 S[1:P[i]] 之内的，那么就可以用 f[P[i]] 递推得出。

再令 g[i] = num[i] ，则 g[i] 可以由 f 算出。
g[i] 类似与 f[i] ，只不过在子串 S[1:j] 上加了一个限制 j <= i/2 。
那么在求解时，先令 j = P[i] ，然后一直令 j = P[j] ，直到 j 满足限制条件，那么 g[i] 就等于 f[j] 了。

``` cpp
FORR(i,1,lenb){
  int j=P[i];
  while(j>(i>>1)) j=P[j]; //[1]
  g[i]=f[j];
}
```

但如果这样计算，当 S="aaaaa..." 时，[1] 处的代码就会变成 $O(n)$ 的，整体的复杂度就被卡到了 $O(n^2)$ ，因此要想办法优化。

可以看出，对于 g[i] 的求解实际上就是找出最大的 j ，使得 S[1:j] = S[i-j+1:i] 并且 j <= i/2 。而这样的过程与 KMP 中 next 数组的计算十分接近，只不过还是多了一个 j <= i/2 的条件。
那么就类似 next 数组求解时，将 S 与自身配对求解 g 。

``` cpp
int j=0;
FORR(i,1,lenb){
  while(j && B[i]!=B[j+1]) j=P[j];  //[1]
  if(B[i]==B[j+1]) j++;             //[2]
  while(j>(i>>1)) j=P[j];           //[3]
  g[i]=f[j];
}
```

而这样做的复杂度是线性的。
因为只有 [2] 处 j 可能增加，而在 [1]、[3] 处 j 都是减小的。又因为 j 最多只增加了 n 次，那么最多也只能减小 n 次，那么复杂度就是线性的了。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1000020;
const int MOD=1000000007;
int P[MAX],f[MAX];
char S[MAX]; int n;

void getP(){
  int j=0; P[1]=0;
  FORR(i,2,n){
    while(j && S[i]!=S[j+1]) j=P[j];
    if(S[i]==S[j+1]) j++;
    P[i]=j;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",S+1); n=strlen(S+1);
    getP();

    FORR(i,1,n) f[i]=f[P[i]]+1;

    int j=0; LL ans=1;
    FORR(i,1,n){
      while(j && S[j+1]!=S[i]) j=P[j];
      if(S[j+1]==S[i]) j++;
      while(j>(i>>1)) j=P[j];
      ans = ans*(f[j]+1)%MOD;
    }

    printf("%lld\n",ans);
  }

  return 0;
}

/*
const int MAX=1000020;
const int MOD=1000000007;
int n,P[MAX],f[MAX],g[MAX];
char B[MAX]; int lenb;

void getP(){
  int j=0; P[1]=0;
  FORR(i,2,lenb){
    while(j && B[i]!=B[j+1]) j=P[j];
    if(B[i]==B[j+1]) j++;
    P[i]=j;
  }
}

int main(void){
  scanf("%d",&n);
  while(n--){
    //MST(f,0);
    scanf("%s",B+1); lenb=strlen(B+1);
    getP();

    //f[i]: 在 B[1:i] 中，前缀与后缀相等的个数（包括自身与自身相等）
    FORR(i,1,lenb){
      f[i]=f[P[i]]+1;
    }

    FORR(i,1,lenb){ //计算 g[i]
      int j=P[i];
      while(j>(i>>1)) j=P[j]; //对于 "aaaa..." ，被卡成 O(n^2) ...
      g[i]=f[j];
    }

    LL ans=1; FORR(i,1,lenb) ans = ans*(g[i]+1)%MOD;

#ifdef DEBUG
    printf("B: %s\n",B+1);
    printf("P:"); FORR(i,1,lenb) printf(" %d",P[i]); printf("\n");
    printf("f:"); FORR(i,1,lenb) printf(" %d",f[i]); printf("\n");
    printf("g:"); FORR(i,1,lenb) printf(" %d",g[i]); printf("\n");
#endif
    printf("%lld\n",ans);
  }

  return 0;
}
*/
