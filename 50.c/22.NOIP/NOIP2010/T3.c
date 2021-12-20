/*
描述
小晨的电脑上安装了一个机器翻译软件，他经常用这个软件来翻译英语文章。
这个翻译软件的原理很简单，它只是从头到尾，依次将每个英文单词用对应的中文含义来替换。对于每个英文单词，软件会先在内存中查找这个单词的中文含义，如果内存中有，软件就会用它进行翻译；如果内存中没有，软件就会在外存中的词典内查找，查出单词的中文含义然后翻译，并将这个单词和译义放入内存，以备后续的查找和翻译。
假设内存中有M个单元，每单元能存放一个单词和译义。每当软件将一个新单词存入内存前，如果当前内存中已存入的单词数不超过M-1，软件会将新单词存入一个未使用的内存单元；若内存中已存入M个单词，软件会清空最早进入内存的那个单词，腾出单元来，存放新单词。
假设一篇英语文章的长度为N个单词。给定这篇待译文章，翻译软件需要去外存查找多少次词典？假设在翻译开始前，内存中没有任何单词。

格式
输入格式
输入文件共2行。每行中两个数之间用一个空格隔开。
第一行为两个正整数M和N，代表内存容量和文章的长度。
第二行为N个非负整数，按照文章的顺序，每个数（大小不超过1000）代表一个英文单词。文章中两个单词是同一个单词，当且仅当它们对应的非负整数相同。

输出格式
包含一个整数，为软件需要查词典的次数。

样例1
样例输入1
3 7
1 2 1 5 4 4 1

样例输出1
5

限制
每个测试点1s

提示
对于10%的数据有M=1，N≤5。
对于100%的数据有0<=M<=100，0<=N<=1000。

样例解释
整个查字典过程如下：每行表示一个单词的翻译，冒号前为本次翻译后的内存状况：
空：内存初始状态为空。
  1. 1：查找单词1并调入内存。
  2. 1 2：查找单词2并调入内存。
  3. 1 2：在内存中找到单词1。
  4. 1 2 5：查找单词5并调入内存。
  5. 2 5 4：查找单词4并调入内存替代单词1。
  6. 2 5 4：在内存中找到单词4。
  7. 5 4 1：查找单词1并调入内存替代单词2。
共计查了5次词典。

来源
noip2010提高组复赛
*/

/*
  得分：100
  解题报告：
    使用队列模拟即可。
*/

#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

deque<int> mem;
deque<int>::iterator it;

bool isIn(int n){
  for(it=mem.begin();it!=mem.end();it++) if((*it)==n) return true;
  return false;
}

int main(void){
  int m,n; scanf("%d%d",&m,&n);
  int cnt=0,a;
  for(int i=0;i<n;i++){
    scanf("%d",&a);
    if(!isIn(a)){
      cnt++;
      if(mem.size()==m) mem.pop_front();
      mem.push_back(a);
    }
  }
  printf("%d\n",cnt);

  return 0;
}
