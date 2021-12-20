/*
描述
输入一行字符，统计出其中数字字符的个数。

输入
一行字符串，总长度不超过255。

输出
输出为1行，输出字符串里面数字字符的个数。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int sum=0;
	char str[256];

	fgets(str,sizeof(str),stdin);
	for(int i=0;str[i];i++){
		if(isdigit(str[i])) sum++;
	}
	printf("%d\n",sum);

	return 0;
}
