/*
题目描述
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！
这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。

输入输出格式

输入格式：
一行，一个单词，其中只可能出现小写字母，并且长度小于100。
输出格式：
共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出“No Answer”；
第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=110;
char a[MAX];
bool check[MAX];
int app[30];

int main(void){
	check[0]=1; check[1]=1;
	for(int i=4;i<=MAX;i+=2) check[i]=1;
	for(int i=3;i<=11;i++) if(!check[i])
		for(int j=i*i;j<=MAX;j+=i) check[j]=1;
	scanf("%s",a);
	int len=strlen(a),Max=0,Min=100;
	for(int i=0;i<len;i++){
		app[a[i]-'a']++;
	}
	for(int i=0;i<30;i++){
		if(app[i]){
			Max=max(Max,app[i]);
			Min=min(Min,app[i]);
		}
	}
	if(!check[Max-Min]){
		printf("Lucky Word\n%d\n",Max-Min);
	}else{
		printf("No Answer\n0\n");
	}

	return 0;
}
