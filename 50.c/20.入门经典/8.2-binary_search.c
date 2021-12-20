#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

int bsearch(int v, int * A, int n){
  int L=0,R=n;
  while(L<R){
    int M=L+(R-L)/2;
    if(A[M]==v) return M;
    else if(A[M]>v) R=M;
    else L=M+1;
  }
  return L;
}

int lower_bound(int v, int * A, int n){
  int L=0,R=n;
  while(L<R){
    int M=L+(R-L)/2;
    if(A[M]>=v) R=M;
    else L=M+1;
  }
  return L;
}

int upper_bound(int v, int * A, int n){
  int L=0,R=n;
  while(L<R){
    int M=L+(R-L)/2;
    if(A[M]<=v) L=M+!;
    else R=M;
  }
  return L;
}

int main(void){


  return 0;
}
