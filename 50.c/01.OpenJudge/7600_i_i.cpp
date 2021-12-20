/*
描述
输入1行句子（不多于200个单词，每个单词长度不超过100），只包含字母、空格和逗号。单词由至少一个连续的字母构成，空格和逗号都是单词间的间隔。

试输出第1个最长的单词和第1个最短单词。 

输入
一行句子。

输出
两行输出：
第1行，第一个最长的单词。
第2行，第一个最短的单词。
*/

#include<iostream>
#include<cstdio>
#include<cstring>

char str[200*100+200];

int main(){
	char ch;
	long len;
	int max=0,min=100,count,i=0,j;
	char maxL[100],minL[100],tmp[100];

	fgets(str,sizeof(str),stdin);
	len=strlen(str);
	ch=str[0];
	while(i<len){
		ch=str[i++];
		if(isalpha(ch)){
			count=0;
			while(i<len){
				tmp[count++]=ch;
				ch=str[i++];
				if(!isalpha(ch)) break;
			}
			if(count>max){
				max=count;
//				strcpy(maxL,tmp);
				for(j=0;j<count;j++) maxL[j]=tmp[j];
				maxL[j]='\0';	//标明结束位置
			}if(count<min){
				min=count;
//				strcpy(minL,tmp);
				for(j=0;j<count;j++) minL[j]=tmp[j];
				minL[j]='\0';	//标明结束位置
			}
		}
	}
	printf("%s\n%s\n",maxL,minL);

	return 0;
}
