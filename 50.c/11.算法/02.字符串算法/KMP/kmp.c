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
char A[MAX],B[MAX];
int lena,lenb,P[MAX];

/*
void KMP(){
  int j=0;
  FOR(i,0,lena){
    while(j && A[i]!=B[j]) j=P[j];
    if(A[i]==B[j]) j++;
    if(j==lenb) printf("%d\n",i-lenb+1);
  }
}
//P[i]: 在串 S[0:i-1] 中，最长的相同前缀后缀长度
void getP(){
  int j=0; P[0]=P[1]=0;
  FOR(i,1,lenb){
    while(j && B[i]!=B[j]) j=P[j];
    if(B[i]==B[j]) j++;
    P[i+1]=j;
  }
}
*/


void KMP(){
  int j=0;
  FOR(i,0,lena){
    while(j && A[i]!=B[j]) j=P[j];
    if(A[i]==B[j]) j++;
    if(j==lenb) printf("%d\n",i-lenb+1), j=P[j];
  }
}
void getP(){
  int j=0; P[0]=P[1]=0;
  FOR(i,1,lenb){
    while(j && B[i]!=B[j]) j=P[j];
    if(B[i]==B[j]) j++;
    P[i+1]=j;
  }
}

int main(void){
  scanf("%s%s",A,B);
  lena=strlen(A), lenb=strlen(B);
  getP();
#ifdef DEBUG
  printf("P:"); FORR(i,0,lenb) printf(" %d",P[i]); printf("\n");
#endif
  KMP();

  return 0;
}








































/*
const int MAX=1000020;
char A[MAX],B[MAX];
int lena,lenb,P[MAX];

void getP(){
  int j=0; P[1]=0;
  FORR(i,2,lenb){
    while(j && B[i]!=B[j+1]) j=P[j];
    if(B[i]==B[j+1]) j++;
    P[i]=j;
  }
}
void KMP(){
  int j=0;
  FORR(i,1,lena){
    while(j && A[i]!=B[j+1]) j=P[j];
    if(A[i]==B[j+1]) j++;
    if(j==lenb) printf("%d\n",i-lenb+1), j=P[j];
  }
}

int main(void){
  scanf("%s%s",A+1,B+1);
  lena=strlen(A+1); lenb=strlen(B+1);
  getP(); KMP();
  FORR(i,1,lenb) printf("%d ",P[i]); putchar('\n');

  return 0;
}
*/
