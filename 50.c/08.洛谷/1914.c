/*
题目背景

某蒟蒻迷上了“小书童”，有一天登陆时忘记密码了（他没绑定邮箱or手机），于是便把问题抛给了神犇你。

题目描述

蒟蒻虽然忘记密码，但他还记得密码是由一串字母组成。且密码是由一串字母每个向后移动n为形成。z的下一个字母是a，如此循环。他现在找到了移动前的那串字母及n，请你求出密码。(均为小写)

输入输出格式

输入格式：
第一行：n。第二行：未移动前的一串字母

输出格式：
一行，是此蒟蒻的密码
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
	char a[100];
	int n,len;

	scanf("%d %s",&n,a);
	len=strlen(a);
	for(int i=0;i<len;i++){
		a[i]=(a[i]-'a'+n)%26+'a';
	}
	printf("%s\n",a);

	return 0;
}
