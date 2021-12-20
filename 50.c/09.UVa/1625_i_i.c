/*
  解题报告：
    使用DP即可，但具体实现需仔细斟酌。
    令f[i][j]为选取A[1:i],B[1:j]所构成的最优解，则：
      f[i][j] = min{ f[i-1][j]+g(i-1,j), f[i][j-1]+g(i,j-1) }
    其中g(i,j)为A[1:i],B[1:j]的序列构造后，其中“已开始但还未结束”的颜色的个数。
    g(i,j)的求解：
      令sA[ch],eA[ch]分别表示ch在A中的出现和结束位置，sB[ch],eB[ch]类似。
      初始化时，<b>令sA[i]=INF,eA[i]=-1 </b>
      然后在每次查询g(i,j)时，枚举ch='A':'Z'，
        若 i>=eA[ch] && j>=eB[ch]，则剩余序列中一定没有ch，ch已经结束
        若 i>=sA[ch] || j>=sB[ch]，则ch在当前序列中已存在，且在剩余序列中还存在，ch以开始但未结束
        否则，ch未开始
      然后即可求解。
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=5020;
const int INF=0x3f3f3f3f;
char A[MAX],B[MAX];
int f[MAX][MAX];
int sA[256],sB[256],eA[256],eB[256];
int lena,lenb;

void init(){
  MST(sA,0x3f); MST(sB,0x3f); //<b></b>
  MST(eA,-1); MST(eB,-1);
  FORR(i,1,lena){
    if(sA[A[i]]==INF) sA[A[i]]=i;
    eA[A[i]]=i;
  }
  FORR(i,1,lenb){
    if(sB[B[i]]==INF) sB[B[i]]=i;
    eB[B[i]]=i;
  }
#ifdef DEBUG
  FORR(ch,'A','Z') if(sA[ch]!=INF || sB[ch]!=INF)
    printf("  ch %c, A[%d:%d], B[%d:%d]\n",ch,sA[ch],eA[ch],sB[ch],eB[ch]);
#endif
}
int g(int i, int j){
  int cnt=0;
  FORR(ch,'A','Z'){
    if(i>=eA[ch] && j>=eB[ch]) continue;
    if(i>=sA[ch] || j>=sB[ch]) cnt++;
  }
#ifdef DEBUG  
  printf("  g(%d,%d): ",i,j);
  FORR(k,1,i) printf("%c",A[k]); FORR(k,1,j) printf("%c",B[k]);
  printf(", left: "); FORR(k,i+1,lena) cout<<A[k]; FORR(k,j+1,lenb) cout<<B[k];
  printf(", %d\n",cnt);
#endif
  return cnt;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s%s",A+1,B+1);
    lena=strlen(A+1),lenb=strlen(B+1);
    init();

    FORR(i,0,lena) FORR(j,0,lenb){  //<b>要考虑i,j等于0的情况</b>
      if(i && j)
        f[i][j] = min( f[i-1][j] + g(i-1,j), f[i][j-1] + g(i,j-1) );
      else if(i)
        f[i][j] = f[i-1][j] + g(i-1,j);
      else if(j)
        f[i][j] = f[i][j-1] + g(i,j-1);
    }
    printf("%d\n",f[lena][lenb]);
  }

  return 0;
}
