#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include <cstring>

struct PigNode
{
  char PigName[20];
  int  weight;
  PigNode * pNextPig;

  PigNode() { }
  PigNode(const char *s, int w){
    strcpy(PigName, s);
    weight = w;
  }
};

//创建有number头猪的单向链表，返回头指针
// PigNode * CreatePigs(int number);
PigNode * CreatePigs(int n, PigNode *v);

//按照猪的名字排序，返回链表头指针
PigNode * SortPigsByName(PigNode * head);

//按照猪的体重排序，返回链表头指针
PigNode * SortPigsByWeight(PigNode * head);

//插入一头新的猪
PigNode * InsertPig(PigNode * head, PigNode pig);

//杀掉大于等于weight重量的猪，返回杀完后的链表头指针
PigNode * KillPigByWeight(PigNode * head, int weight);

//杀掉指定名字的猪，返回杀完后的链表头指针
PigNode * KillPigByName(PigNode * head, const char *name); 

//杀掉所有的猪
void KillAllPigs(PigNode * head);

//获取链表中猪的个数
int GetPigsNumber(PigNode * head);

//显示链表中所有的猪
void ShowAllPigs(PigNode * head);

#endif
