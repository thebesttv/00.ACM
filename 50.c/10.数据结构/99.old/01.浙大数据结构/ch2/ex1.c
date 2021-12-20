#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

int main(void){
  return 0;
}

List Merge(List L1, List L2){
  List ans = (struct Node*) malloc(sizeof(struct Node));  // head of result
  ans->Data = 0; ans->Next = NULL;
  PtrToNode p = ans;
  PtrToNode p1 = L1->Next; L1->Next = NULL;
  PtrToNode p2 = L2->Next; L2->Next = NULL;

  while(p1 || p2){
    if(!p2 || (p1 && p1->Data < p2->Data)){ // use p1
      p->Next = p1;
      p1 = p1->Next;
      p = p->Next; p->Next = NULL;
    }else{  // use p2
      p->Next = p2;
      p2 = p2->Next;
      p = p->Next; p->Next = NULL;
    }
  }
  return ans;
}
