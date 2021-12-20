/*
题目描述
一般的文本编辑器都有查找单词的功能，该功能可以快速定位特定单词在文章中的位置，有的还能统计出特定单词在文章中出现的次数。
现在，请你编程实现这一功能，具体要求是：给定一个单词，请你输出它在给定的文章中出现的次数和第一次出现的位置。注意：匹配单词时，不区分大小写，但要求完全匹配，即给定单词必须与文章中的某一独立单词在不区分大小写的情况下完全相同（参见样例1 ），如果给定单词仅是文章中某一单词的一部分则不算匹配（参见样例2 ）。

输入输出格式
输入格式：
第1行为一个字符串，其中只含字母，表示给定单词；
第2行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

输出格式：
只有一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 0 开始）；如果单词在文章中没有出现，则直接输出一个整数-1。

说明
数据范围
1≤单词长度≤10。
1≤文章长度≤1,000,000。
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char ori[1000000+4];
char des[10+4];
int cou=0,flag=0,first;
char * p;

int main(void){
  fgets(des,sizeof(des),stdin); des[strlen(des)-1]=0; strtok(des," ");
  fgets(ori,sizeof(ori),stdin);
  for(int i=0;des[i]!=0;i++) des[i]=tolower(des[i]);
  for(int i=0;ori[i]!=0;i++) ori[i]=tolower(ori[i]);

  p=strtok(ori," \n\r");
  while(p!=NULL){
    if(strcmp(p,des)==0){
      if(flag==0) first=p-ori;
      cou++; flag=1;
    }
    p=strtok(NULL," \n\r");
  }
  if(cou==0) printf("-1\n");
  else printf("%d %d\n",cou,first);

  return 0;
}

/* first edition
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define DEBUG 0

char a[1000010];
char ori[20];
long app[100000];

int main(void){
  long len,count=0;
  int state,lenori,j;

  fgets(ori,sizeof(ori),stdin);
  fgets(a,sizeof(a),stdin);
  len=strlen(a)-1;
  lenori=strlen(ori)-1;
  #if DEBUG
    for(long i=0;i<len;i++) printf("%ld",i%10);
    printf("\nlength of a: %ld\nlength of ori: %d\n",len,lenori);
  #endif
  for(long i=0;i<len;i++) a[i]=tolower(a[i]);
  if(ori[lenori-1]==' ') lenori--;
  for(int i=0;i<lenori;i++) ori[i]=tolower(ori[i]);
  if(isalpha(a[0])) state=1;  //开头不一定为字母
  for(long i=0;i<len;i++){
    if(state==1){
      #if DEBUG
        printf("in: %ld, state==1\n",i);
      #endif
      for(j=0;j<lenori;j++){
        if(a[i+j]!=ori[j]){
          state=0;
        #if DEBUG
          printf("a[%ld+%d]:%c != ori[%d]: %c, state: 0\n",i,j,a[i+j],j,ori[j]);
        #endif
          break;
        }
      }
      i+=j;
      #if DEBUG
        printf("corrient i: %ld\n",i);
      #endif
      if(isalpha(a[i])){
        state=0;
        #if DEBUG
          printf("a[%ld]:%c != ' ', state: 0\n",i,a[i]);
        #endif
      }
      else{
        app[count++]=i-lenori;
        #if DEBUG
          printf("find match\n");
          printf("app[%ld]:%ld\n",count-1,app[count-1]);
        #endif
      }
    }
    if(a[i]==' ' && isalpha(a[i+1])){
      state=1;
      #if DEBUG
        printf("find world in a[%ld]: %c\n",i+1,a[i+1]);
      #endif
    }
    if(isalpha(a[i]) && a[i+1]==' ') state=0;
  }
  if(count!=0) printf("%ld %ld\n",count,app[0]);
  else printf("-1\n");

  return 0;
}
*/
