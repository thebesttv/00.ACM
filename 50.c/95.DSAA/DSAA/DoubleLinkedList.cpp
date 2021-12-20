#include "DoubleLinkedList.h"
#include <cstring>
#include <algorithm>
#include <cstdio>

//创建有number头猪的双向链表，返回头指针
// DPigNode * CreatePigs(int number)
// {
//  DPigNode * head = nullptr;
//  while(number--){
//    DPigNode *p = new DPigNode;
//    p->PigName[0]=0;
//    p->weight=0;
//    p->pPrePig=nullptr;
//    p->pNextPig=head;
//    if(head)
//      head->pPrePig=p;
//    head=p;
//  }
//  return head;
// }

DPigNode * CreatePigs(int n, DPigNode *v)
{
  DPigNode * head = nullptr;
  for(int i=n-1;i>=0;--i){
    DPigNode *p = new DPigNode;
    strcpy(p->PigName, v[i].PigName);
    p->weight=v[i].weight;
    p->pPrePig=nullptr;
    p->pNextPig=head;
    if(head)
      head->pPrePig=p;
    head=p;
  }
  return head;
}

//按照猪的名字排序，返回链表头指针
DPigNode * SortPigsByName(DPigNode * head)
{
  DPigNode *p;
  int cnt = GetPigsNumber(head), tail=0;
  DPigNode *v = new DPigNode [cnt];
  p = head;
  while(p){
    v[tail++] = *p;
    p = p->pNextPig;
  }
  KillAllPigs(head);
  
  std::sort(v,v+tail,[](DPigNode &a, DPigNode &b){
    return strcmp(a.PigName,b.PigName)<0;
  });
  
  head = CreatePigs(cnt, v);
  delete [] v;
  return head;
}

//按照猪的体重排序，返回链表头指针
DPigNode * SortPigsByWeight(DPigNode * head)
{
  DPigNode *p;
  int cnt = GetPigsNumber(head), tail=0;
  DPigNode *v = new DPigNode [cnt];
  p = head;
  while(p){
    v[tail++] = *p;
    p = p->pNextPig;
  }
  KillAllPigs(head);
  
  std::sort(v,v+tail,[](DPigNode &a, DPigNode &b){
    return a.weight < b.weight;
  });
  
  
  head = CreatePigs(cnt, v);
  delete [] v;
  return head;
}

//插入一头新的猪
DPigNode * InsertPig(DPigNode * head, DPigNode pig)
{
  DPigNode *p = new DPigNode(pig);
  p->pNextPig=head;
  p->pPrePig = nullptr;
  if(head)
    head->pPrePig=p;
  
  return p;
}

//杀掉大于等于weight重量的猪，返回杀完后的链表头指针
DPigNode * KillPigByWeight(DPigNode * head, int weight)
{
  DPigNode *p=head, *res=nullptr;
  while(p){
    if(p->weight<weight){
      DPigNode *t = new DPigNode(*p);
      t->pNextPig=res;
      t->pPrePig=nullptr;
      if(res)
        res->pPrePig=t;
      res=t;
    }
    p=p->pNextPig;
  }
  KillAllPigs(head);
  
  return res;
}

//杀掉指定名字的猪，返回杀完后的链表头指针
DPigNode * KillPigByName(DPigNode *head, const char *name)
{
  DPigNode *p=head, *res=nullptr;
  while(p){
    if(strcmp(p->PigName, name)){
      DPigNode *t = new DPigNode(*p);
      t->pNextPig=res;
      t->pPrePig=nullptr;
      if(res)
        res->pPrePig=t;
      res=t;
    }
    p=p->pNextPig;
  }
  KillAllPigs(head);
  
  return res;
}

//杀掉所有的猪
void KillAllPigs(DPigNode * head)
{
  while(head){
    DPigNode *p = head;
    head=head->pNextPig;
    delete p;
  }
}

//获取链表中猪的个数
int GetPigsNumber(DPigNode * head)
{
  int cnt=0;
  while(head){
    ++cnt;
    head=head->pNextPig;
  }
  return cnt;
}

//显示链表中所有的猪
void ShowAllPigs(DPigNode * head)
{
  printf("Double List:\n");
  DPigNode *p = head;
  while(p){
    printf("  name: %s, weight: %d",p->PigName,p->weight);
    if(p->pPrePig) printf(", pre: %s",p->pPrePig->PigName);
    if(p->pNextPig) printf(", next: %s",p->pNextPig->PigName);
    putchar('\n');
    p = p->pNextPig;
  }
}
