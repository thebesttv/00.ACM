#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=100;
int A[MAX];
bool B[MAX];
int cnt=0;

void print_subset(int n, int *A, int cur);
void print_subset(int n, bool *A, int cur);
void print_subset(int n, int s);

int main(void){
  int n; scanf("%d",&n);
//[1]
//print_subset(n,A,0);
//[2]
//print_subset(n,B,0);
//[3]
  for(int i=0;i<(1<<n);i++)
    print_subset(n,i);

  return 0;
}

/*
//[1]增量构造法
void print_subset(int n, int *A, int cur){
  printf("%d:",++cnt);
  for(int i=0;i<cur;i++) printf(" %d",A[i]);
  printf("\n");

  int s = cur ? A[cur-1]+1 : 0;
  for(int i=s;i<n;i++){
    A[cur]=i;
    print_subset(n,A,cur+1);
  }
}
*/

/*
//[2]位向量法
//解答树节点约为增量构造法的两倍
void print_subset(int n, int *B, int cur){
  if(cur==n){
    printf("%d:",++cnt);
    for(int i=0;i<n;i++) if(B[i])
      printf(" %d",i);
    printf("\n");
  }else{
    B[cur]=0;
    print_subset(n,B,cur+1);
    B[cur]=1;
    print_subset(n,B,cur+1);
  }
}
*/

//[3]二进制法（位向量法的简易版）
inline bool getBit(int a, int n){
  return (a>>n)&1;
}
void print_subset(int n, int s){
  printf("%d:",++cnt);
  for(int i=0;i<n;i++) if(getBit(s,i))
    printf(" %d",i);
  printf("\n");
}
