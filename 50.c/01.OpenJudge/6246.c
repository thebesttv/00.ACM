/*
描述
编写程序，读入一行英文(只包含字母和空格，单词间以单个空格分隔)，将所有单词的顺序倒排并输出，依然以单个空格分隔。

输入
输入为一个字符串（字符串长度至多为100）。

输出
输出为按要求排序后的字符串。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

char a[100][104];
int tail=0;

int main(void){
	while(scanf("%s",a[tail])==1) tail++;
	for(int i=tail-1;i>=0;i--){
		if(i!=tail-1) putchar(' ');
		printf("%s",a[i]);
	}
	putchar('\n');

	return 0;
}

/*
char a[110],temp[110];

void swap(char & a, char & b){
	char t=a; a=b; b=t; 
}
void Print(char * p);

int main(void){
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len/2;i++) swap(a[i],a[len-1-i]);
printf("%s\n",a);
	char * p=strtok(a," ");
	int first=false;
	while(p!=NULL){
		if(first) putchar(' ');
		Print(p);
		p=strtok(NULL," ");
		first=true;
	}
	putchar('\n');

	return 0;
}

void Print(char * p){
	memset(temp,0,sizeof(temp));
	char * t=p;
	while(*t!=0) t++;
	t--;
	for(char * i=t;i!=p-1;i--) putchar(*i);
}
*/
