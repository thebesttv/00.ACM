/*
背景
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！

描述
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

格式
输入格式
输入只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。

输出格式
输出共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。

样例1
样例输入1
error

样例输出1
Lucky Word
2

样例2
样例输入2
olymipic

样例输出2
No Answer
0

限制
各个测试点1s

输入输出样例1解释
单词error中出现最多的字母r出现了3次，出现次数最少的字母出现了1次，3-1=2，2是质数。

输入输出样例2解释
单词olymipic中出现最多的字母i出现了2次，出现次数最少的字母出现了1次，2-1=1，1不是质数。

来源
NOIp2008 提高组第一题
*/

/*
  得分：100
  解题报告：
    统计字母出现个数，再判断质数即可。注意质数的判断要考虑所有情况。
*/

#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int cnt[26];
char temp[120];

bool isprime(int n){
  if(n<=1) return false;
  if(n==2) return true;
  for(int i=2;i<n;i++) if(n%i==0) return false;
  return true;
}

int main(void){
  scanf("%s",temp);
  int len=strlen(temp);
  for(int i=0;i<len;i++) cnt[temp[i]-'a']++;
  int tMax=0,tMin=len;
  for(int i=0;i<26;i++) if(cnt[i]){
    //if(cnt[i]>tMax) tMax=cnt[i];
    //if(cnt[i]<tMin) tMin=cnt[i];  //<b>不能用else if </b>
    tMax=max(tMax,cnt[i]);
    tMin=min(tMin,cnt[i]);
  }
#ifdef DEBUG
  printf("  tMax: %d, tMin: %d\n",tMax,tMin);
#endif
  if(isprime(tMax-tMin)) printf("Lucky Word\n%d\n",tMax-tMin);
  else printf("No Answer\n%d\n",0);

  return 0;
}
