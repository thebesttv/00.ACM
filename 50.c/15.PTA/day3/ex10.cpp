#include <stdio.h>

#define MAXN 10
typedef float ElementType;

/*
ElementType Median( ElementType A[], int N ){
  for(int i=1;i<N;i++)
    for(int j=1;j<=N-i;j++)
      if(A[j]<A[j-1]){
        ElementType t=A[j];
        A[j]=A[j-1];
        A[j-1]=t;
      }
  return A[N/2];
}
*/

ElementType Median( ElementType A[], int N );

int main (){
  ElementType A[MAXN];
  int N, i;

  scanf("%d", &N);
  for ( i=0; i<N; i++ )
    scanf("%f", &A[i]);
  printf("%.2f\n", Median(A, N));

  return 0;
}

#include<stdlib.h>
int cmp(const void *a, const void *b){
  return *(ElementType*)a < *(ElementType*)b ? 0 : 1;
}

ElementType Median( ElementType A[], int N ){
  qsort(A,N,sizeof(ElementType),cmp);
  return A[N/2];
}
