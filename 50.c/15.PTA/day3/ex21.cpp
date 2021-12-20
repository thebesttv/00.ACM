#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
  int Data; /* 存储结点数据 */
  PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
  int N, i;
  List L, p;

  scanf("%d", &N);
  L = NULL;
  for ( i=0; i<N; i++ ) {
    p = (List)malloc(sizeof(struct Node));
    scanf("%d", &p->Data);
    p->Next = L;  L = p;
  }
  printf("%d\n", FactorialSum(L));

  return 0;
}

int fac(int n){
  if(n<=1) return 1;
  int ans=1;
  for(int i=2;i<=n;i++) ans*=i;
  return ans;
}

int FactorialSum( List L ){
  int sum=0;
  while(L){
    sum += fac(L->Data);
    L = L->Next;
  }
  return sum;
}
