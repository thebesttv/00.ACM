#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=10000;
int A[MAX],S[MAX+10];

int maxSum(int * A, int L, int R){  //O(nlogn)
  if(L+1==R) return A[L];
  int M=L+(R-L)/2;
  int ans=max(maxSum(A,L,M), maxSum(A,M,R));
  int x,y,v;
  x=A[M-1]; v=0;
  for(int i=M-1;i>=L;i--) x=max(x,v+=A[i]);
  y=A[M]; v=0;
  for(int i=M;i<R;i++) y=max(y,v+=A[i]);
  return max(x+y,ans);
}

int maxSum(int * A, int n){ //0(n)
  S[0]=0;
  int Min=0,ans=A[0];
  for(int i=1;i<=n;i++){
    S[i]=S[i-1]+A[i-1];
    ans=max(ans,S[i]-Min);
    Min=min(Min,S[i]);
  }
  return ans;
}

int main(void){
  srand(time(NULL));
  for(int i=0;i<MAX;i++){
    A[i]=(double)rand()/RAND_MAX*1000;
    if(rand()&1) A[i]*=-1;
  }
  S[0]=0; int ans=A[0];
  for(int i=1;i<=MAX;i++) S[i]=S[i-1]+A[i-1];
  for(int i=0;i<MAX;i++) for(int j=i+1;j<MAX;j++) ans=max(ans,S[j]-S[i]);
  int get=maxSum(A,MAX);
  if(ans!=get) printf("WA\n");
  else printf("AC\n");

  return 0;
}

/*
int main(void){
  srand(time(NULL));
  for(int i=0;i<MAX;i++){
    int t=(double)rand()/RAND_MAX*100;
    int minus= rand()&1 ? 1 : -1;
    t*=minus;
    A[i]=t;
  }
  printf("total elements: %d\n",MAX);
  clock_t start=clock();
  int ans=maxSum(A,0,MAX);
  clock_t stop=clock();
  printf("O(nlogn): time: %lf, ans:%d\n",(double)(stop-start)/CLOCKS_PER_SEC,ans);
  start=clock();
  ans=maxSum(A,MAX);
  stop=clock();
  printf("O(n): time: %lf, ans:%d\n",(double)(stop-start)/CLOCKS_PER_SEC,ans);

  return 0;
}
*/
