#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=100;
int P[MAX],A[MAX];
int cnt=0;

void print_permutation(int n, int *A, int cur);

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&P[i]);
/*
//[1]递归枚举
  sort(P,P+n);
  print_permutation(n,A,0);
*/
//[2]调用 STL 中的 next_permutation （在 algorithm 头文件中），需要事先先排序
  sort(P,P+n);
  do{
    printf("%d:",++cnt);
    for(int i=0;i<n;i++) printf(" %d",P[i]);
    printf("\n");
  }while(next_permutation(P,P+n));

  return 0;
}

/*
//不能重复
void print_permutation(int n, int *A, int cur){
  if(cur==n){
    printf("%d:",++cnt);
    for(int i=0;i<n;i++) printf(" %d",A[i]);
    printf("\n");
  }else for(int i=0;i<n;i++){
    bool ok=1;
    for(int j=0;j<cur;j++) if(A[j]==P[i]) ok=0;
    if(ok){
      A[cur]=P[i];
      print_permutation(n,A,cur+1);
    }
  }
}
*/

//可以有重复元素的全排列
//若 P[3]={1,1,1} ，只输出一个 1 1 1
void print_permutation(int n, int *A, int cur){
  if(cur==n){
    printf("%d:",++cnt);
    for(int i=0;i<n;i++) printf(" %d",A[i]);
    printf("\n");
  }else for(int i=0;i<n;i++) if(!i || P[i]!=P[i-1]){  //<b>if条件使得 P[i] 不重不漏地取遍所有 P 中的值</b>
    int c1=0,c2=0;
    for(int j=0;j<cur;j++) if(A[j]==P[i]) c1++;
    for(int j=0;j<n;j++) if(P[j]==P[i]) c2++;
    if(c1<c2){
      A[cur]=P[i];
      print_permutation(n,A,cur+1);
    }
  }
}
