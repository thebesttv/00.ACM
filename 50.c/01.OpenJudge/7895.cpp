/*
描述
给定一个字符，用它构造一个对角线长5个字符，倾斜放置的菱形。

输入
输入只有一行， 包含一个字符。

输出
该字符构成的菱形。
*/

#include<iostream>
#include<cstdio>

int main(){
	char c;
	scanf("%c",&c);
	printf("  %c\n %c%c%c\n%c%c%c%c%c\n %c%c%c\n  %c\n",c,c,c,c,c,c,c,c,c,c,c,c,c);

	return 0;
}
