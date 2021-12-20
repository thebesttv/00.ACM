/*
题目描述

写一个程序从输入文件中去读取四行大写字母（全都是大写的，每行不超过72个字符），然后用柱状图输出每个字符在输入文件中出现的次数。严格地按照输出样例来安排你的输出格式。

输入输出格式

输入格式：
四行字符，由大写字母组成，每行不超过72个字符

输出格式：
由若干行组成，前几行由空格和星号组成，最后一行则是由空格和字母组成的。在任何一行末尾不要打印不需要的多余空格。不要打印任何空行。

样例输出：
                            *
                            *
        *                   *
        *                   *     *   *
        *                   *     *   *
*       *     *             *     *   *
*       *     * *     * *   *     * * *
*       *   * * *     * *   * *   * * * *
*     * * * * * *     * * * * *   * * * *     * *
* * * * * * * * * * * * * * * * * * * * * * * * * *
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define DEBUG 0

char a[100];
int t[26];

void Count(char a[]);
int Max(int a[]);

int main(void){
	int max,end=0;
//freopen("testdata.in","r",stdin);

	for(int i=0;i<26;i++) t[i]=0;
	for(int i=0;i<4;i++){
		fgets(a,sizeof(a),stdin);
		Count(a);
	}

	#if DEBUG
		for(int i=0;i<26;i++){
			printf("%c: %d\t",i+'A',t[i]);
			if((i+1)%6==0) printf("\n");
		}
		printf("\n");
	#endif

	//打印柱状图
	max=Max(t);	//寻找最大值，确定柱状图高度
	#if DEBUG
		printf("max: %d\n",max);
	#endif
	for(int i=max;i>=1;i--){	//由高到低打印
		for(int j=25;j>=0;j--){	//寻找最后一个出现次数>=当前高度的字母
			if(t[j]>=i){
				end=j;
				break;
			}
		}
		for(int j=0;j<=end;j++){
			if(t[j]>=i) printf("*");	//注意：是“>=”
			else printf(" ");
			if(j!=end) printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<26;i++){
		printf("%c",i+'A');
		if(i!=25) printf(" ");
	}
	printf("\n");

	return 0;
}

void Count(char a[]){
	int len=strlen(a);	//<b>strlen不-1</b>
	for(int i=0;i<len;i++){
		if(isupper(a[i]))	t[a[i]-'A']++;
		else if(islower(a[i]))	t[a[i]-'a']++;
	}
}

int Max(int a[]){
	int max=0;
	for(int i=1;i<26;i++){
		if(a[i]>a[max]) max=i;
	}
	return a[max];
}
