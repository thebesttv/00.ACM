/*
题目描述
给定一篇只含有大小写字母，空格以及 ′.′(不含引号)的长度为 L 的文章。文章被若干个 ′.′ 划分 成若干个句子，句子被若干个空格划分成单词。你需要将文章中每个句子第一个单词的首字母改成大写， 其他一律小写，空格与 ′.′ 需原样输出。注意，可能存在某个句子中没有单词，或者某两个单词之间有多 个空格。

输入输出格式
输入格式：
一行，表示原串。

输出格式：
一行，表示你的回答。

输入输出样例
输入样例#1：
nigeru. wa.haji.

输出样例#1：
Nigeru. Wa.Haji.

输入样例#2：
.. .nI noip WEn   le  .NICE broO..

输出样例#2：
.. .Ni noip wen   le  .Nice broo..

说明
测试点编号　　限制与约束
1,2,3,4,5     L<=10^3
6,7,8,9,10    L<=10^5
*/

/*
  得分：100
  解题报告：
    扫描的同时判断输出即可。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

int main(void){
  int ch; bool first=1;
  while((ch=getchar())!=EOF){
    if(ch=='.') first=1;
    else if(isalpha(ch)){
      if(!first) ch=tolower(ch);
      else {ch=toupper(ch); first=0;}
    }
    putchar(ch);
  }

  return 0;
}
