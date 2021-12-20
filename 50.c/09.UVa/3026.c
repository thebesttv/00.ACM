/*
解题报告：
  若 P[i]!=0 && i%(i-P[i])=0 则循环节长度为 i-P[i]，循环次数 k=i/(i-P[i])，否则 k=1 。
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
int n,P[MAX];
char B[MAX];

void getP(){
  int j=0; P[1]=0;
  FORR(i,2,n){
    while(j && B[i]!=B[j+1]) j=P[j];
    if(B[i]==B[j+1]) j++;
    P[i]=j;
  }
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    scanf("%s",B+1);
    getP();
    printf("Test case #%d\n",++kase);
    FORR(i,1,n) if(P[i] && i%(i-P[i])==0)
      printf("%d %d\n",i,i/(i-P[i]));
    printf("\n");
  }

  return 0;
}
