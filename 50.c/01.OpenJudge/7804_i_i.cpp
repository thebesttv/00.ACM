/*
描述
给定一个只包含小写字母的字符串，请你找到第一个仅出现一次的字符。如果没有，输出no。

输入
一个字符串，长度小于100000。

输出
输出第一个仅出现一次的字符，若没有则输出no。
*/

#include<iostream>
#include<cstdio>
#include<cstring>

#define DEBUG 0

char str[100000];

struct Alp{
	long fpos;
	long n;
}alp[26];

int main(){
	int t;
	long minPos[26],min,len;

	for(int i=0;i<26;i++){
		minPos[i]=-1;
		alp[i].fpos=-1;
		alp[i].n=0;
	}

	scanf("%s",str);
	#if DEBUG
//		printf("str: %s\n",str);
	#endif

	len=strlen(str);
	for(long i=0;i<len;i++){
		t=str[i]-'a';
		#if DEBUG
			printf("t: %d\n",t);
		#endif
		alp[t].n++;
		if(alp[t].fpos==-1){
			alp[t].fpos=i;
		}
	}

	#if DEBUG
		printf("alp:\n");
		for(int i=0;i<26;i++){
			printf("fpos of %c: %ld ,",i+'a',alp[i].fpos);
			printf("n of %c: %ld\n",i+'a',alp[i].n);
		}
	#endif

	for(int i=0;i<26;i++){	//记录所有出现一次的字母位置
		if(alp[i].n==1){
			minPos[i]=alp[i].fpos;
		}
	}

	#if DEBUG
		printf("minPos:\n");
		for(int i=0;i<26;i++){
			printf("%c: %ld\n",i+'a',minPos[i]);
		}
	#endif

	min=100001;
	for(int i=0;i<26;i++){	//比较最小
		if(minPos[i]!=-1 && minPos[i]<min){
			min=minPos[i];
			t=i;
		}
	}

	if(min==100001){
		printf("no\n");
	}else{
		printf("%c\n",t+'a');
	}

	return 0;
}
