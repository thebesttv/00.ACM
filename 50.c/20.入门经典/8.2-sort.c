#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=5000000;
int A[MAX],T[MAX],ori[MAX],res[MAX];
clock_t start,stop;

void merge_sort(int * A, int L, int R, int * T);
void quick_sort(int * A, int L, int R);
int get_nth_element(int n, int * A, int L, int R);

int main(void){
  srand(time(NULL));
  int tot; scanf("%d",&tot);
  for(int i=0;i<tot;i++) ori[i]=A[i]=res[i]=(double)rand()/RAND_MAX*10000;
  int n=(double)rand()/RAND_MAX*tot;
  start=clock(); get_nth_element(n,A,0,tot-1); stop=clock();
  printf("time: %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);
}

/*
int main(void){
  srand(time(NULL));
  for(int i=0;i<MAX;i++) ori[i]=A[i]=(double)rand()/RAND_MAX*1000;
  start=clock();
  //merge_sort(A,0,MAX,T);
  quick_sort(A,0,MAX-1);
  stop=clock();
  printf("quick sort: %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);
  memcpy(res,A,sizeof(A)); memcpy(A,ori,sizeof(ori));
  start=clock();
  sort(A,A+MAX);
  stop=clock();
  printf("STL sort: %lf\n",(double)(stop-start)/CLOCKS_PER_SEC);
  if(memcmp(res,A,sizeof(A))) printf("WA\n");

  return 0;
}
*/

void merge_sort(int * A, int L, int R, int * T){  //[L,R)
  if(L+1>=R) return;
  int M=L+(R-L)/2;
  merge_sort(A,L,M,T);
  merge_sort(A,M,R,T);
  int x=L,y=M,tail=L; //<b>注意x和tail的起始位置为L，而非0</b>
  while(x<M || y<R){
    if(y>=R || (x<M && A[x]<=A[y])) T[tail++]=A[x++];
    else T[tail++]=A[y++];
  }
  for(int i=L;i<R;i++) A[i]=T[i];
}

void quick_sort(int * A, int L, int R){ //[L,R]
  if(L>=R) return;
  int i=L,j=R,k=A[L];
  while(i<j){
    while(i<j && A[j]>=k) j--;
    while(i<j && A[i]<=k) i++;
    swap(A[i],A[j]);
  }
  swap(A[L],A[i]);
  quick_sort(A,L,i-1);
  quick_sort(A,i+1,R);
}

int get_nth_element(int n, int * A, int L, int R){
  if(L==R) return A[L];
  int i=L,j=R,k=A[L];
  while(i!=j){
    while(i<j && A[j]>=k) j--;
    while(i<j && A[i]<=k) i++;
    swap(A[i],A[j]);
  }
  swap(A[L],A[i]);
  if(i==n) return A[i];
  else if(i>n) return get_nth_element(n,A,L,i-1);
  else return get_nth_element(n,A,i+1,R);
}
