#include "SingleLinkedList.h"
#include <cstring>
#include <algorithm>
#include <cstdio>

//创建有number头猪的单向链表，返回头指针
// PigNode * CreatePigs(int number)
// {
//  PigNode * head = nullptr;
//  while(number--){
//    PigNode *p = new PigNode;
//    p->PigName[0]=0;
//    p->weight=0;
//    p->pNextPig=head;
//    head = p;
//  }
//  return head;
// }

PigNode * CreatePigs(int n, PigNode *v)
{
  PigNode * head = nullptr;
  for(int i=n-1;i>=0;--i){
    PigNode *p = new PigNode;
    strcpy(p->PigName,v[i].PigName);
    p->weight=v[i].weight;
    p->pNextPig=head;
    head = p;
  }
  return head;
}

//按照猪的名字排序，返回链表头指针
PigNode * SortPigsByName(PigNode * head)
{
  PigNode * p;
  int cnt = GetPigsNumber(head), tail=0;
  PigNode *v = new PigNode [cnt];
  p = head;
  while(p){
    v[tail++] = *p;
    p = p->pNextPig;
  }
  KillAllPigs(head);

  std::sort(v,v+tail,[](PigNode &a, PigNode &b){
    return strcmp(a.PigName,b.PigName)<0;
  });

  head = CreatePigs(cnt, v);
  delete [] v;
  return head;
}

//按照猪的体重排序，返回链表头指针
PigNode * SortPigsByWeight(PigNode * head)
{
  PigNode * p;
  int cnt = GetPigsNumber(head), tail=0;
  PigNode *v = new PigNode [cnt];
  p = head;
  while(p){
    v[tail++] = *p;
    p = p->pNextPig;
  }
  KillAllPigs(head);

  std::sort(v,v+tail,[](PigNode &a, PigNode &b){
    return a.weight < b.weight;
  });

  head = CreatePigs(cnt, v);
  delete [] v;
  return head;
}

//插入一头新的猪
PigNode * InsertPig(PigNode * head, PigNode pig)
{
  PigNode *p = new PigNode(pig);
  p->pNextPig=head;
  head=p;
  
  return head;
}

//杀掉大于等于weight重量的猪，返回杀完后的链表头指针
PigNode * KillPigByWeight(PigNode * head, int weight)
{
  PigNode *p=head, *res=nullptr;
  while(p){
    if(p->weight<weight){
      PigNode *t = new PigNode(*p);
      t->pNextPig=res;
      res=t;
    }
    p=p->pNextPig;
  }
  KillAllPigs(head);
  
  return res;
}

//杀掉指定名字的猪，返回杀完后的链表头指针
PigNode * KillPigByName(PigNode * head, const char *name)
{
  PigNode *p=head, *res=nullptr;
  while(p){
    if(strcmp(p->PigName, name)){
      PigNode *t = new PigNode(*p);
      t->pNextPig=res;
      res=t;
    }
    p=p->pNextPig;
  }
  KillAllPigs(head);
  
  return res;
}

//杀掉所有的猪
void KillAllPigs(PigNode * head)
{
  while(head){
    PigNode *p = head;
    head = head->pNextPig;
    delete p;
  }
}

//获取链表中猪的个数
int GetPigsNumber(PigNode * head)
{
  int cnt=0;
  while(head){
    ++cnt;
    head=head->pNextPig;
  }
  return cnt;
}

//显示链表中所有的猪
void ShowAllPigs(PigNode * head)
{
  printf("List:\n");
  PigNode *p = head;
  while(p){
    printf("  name: %s, weight: %d\n",p->PigName,p->weight);
    p = p->pNextPig;
  }
}
