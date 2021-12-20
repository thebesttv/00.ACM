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

const int MAXA=1000020;
const int MAXB=1020;
char A[MAXA],B[MAXB];
int lena,lenb;
int f[MAXB],g[MAXB];  //f[i]: 以B[i]结尾的最长公共子序列长度，g[i]: 该状态下子序列在A中的最后一个的位置
//f[i] = max{ f[j] + ((A[g[j]+1):n] has B[i] }
VR<int> v[26];  //v[i]: A中i的每个出现位置（递增）

int Ahas(int pos, int opt){  //返回B[pos:lenb]中opt第一次出现的位置
  opt-='a';
  VR<int>::iterator it;
  it=lower_bound(v[opt].begin(),v[opt].end(),pos);
  if(it==v[opt].end()) return 0;
  else return *it;

  return 0;
}

int main(void){
  scanf("%s%s",A+1,B+1);
  lena=strlen(A+1); lenb=strlen(B+1);
  FORR(i,1,lena) v[A[i]-'a'].push_back(i);  //初始化v

  int ansMax=0;
  int pos=Ahas(1,B[1]); //初始化f[1]
  if(pos) {f[1]=1; g[1]=pos;}
  FORR(i,2,lenb){
    FOR(j,1,i) if(pos=Ahas(g[j]+1,B[i])){
      if(f[i]<f[j]+1){
        f[i]=f[j]+1;
        g[i]=pos;
      }
    }
    ansMax=max(ansMax,f[i]);
  }
#ifdef DEBUG
  FORR(i,1,lenb)
    printf("  f[%d]: { %d, %d }\n",i,f[i],g[i]);
#endif
  printf("%d\n",ansMax);

  return 0;
}
