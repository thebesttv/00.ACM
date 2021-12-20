/*
题目背景
宇宙总统竞选

题目描述
地球历公元6036年，全宇宙准备竞选一个最贤能的人当总统，共有n个非凡拔尖的人竞选总统，现在票数已经统计完毕，请你算出谁能够当上总统。

输入输出格式
输入格式：
第一行为一个整数n,代表竞选总统的人数。
接下来有n行，分别为第一个候选人到第n个候选人的票数。

输出格式：
共两行，第一行是一个整数m，为当上总统的人的号数。
第二行是当上总统的人的选票。

输入输出样例
输入样例#1：
5
98765
12365
87954
1022356
985678

输出样例#1：
4
1022356

说明
票数可能会很大，可能会到100位数字。
n<=20 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=140;
struct Ind{
  int n;
  char tot[200];

  Ind() {memset(tot,0,sizeof(tot));}
  bool operator < (const Ind & b) const {
    return strcmp(tot,b.tot)>0;
  }
}ind[24];
char temp[200];

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%s",temp);
    int len=strlen(temp);
    strcpy(ind[i].tot+MAX-len+1,temp);
    for(int j=0;j<MAX-len+1;j++) ind[i].tot[j]='0';
    ind[i].n=i+1;
  }
  sort(ind,ind+n);
  printf("%d\n",ind[0].n);
  int pos=0;
  while(ind[0].tot[pos]=='0') pos++;
  while(ind[0].tot[pos]) putchar(ind[0].tot[pos++]);
  printf("\n");

  return 0;
}
