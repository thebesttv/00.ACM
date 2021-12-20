/*
题目描述
给定一个数，请将该数各个位上数字反转得到一个新数。
这次与NOIp2011普及组第一题不同的是：这个数可以是小数，分数，百分数，整数。整数反转是将所有数位对调；小数反转是把整数部分的数反转，再将小数部分的数反转，不交换整数部分与小数部分；分数反转是把分母的数反转，再把分子的数反转，不交换分子与分母；百分数的分子一定是整数，百分数只改变数字部分。整数新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零；小数新数的末尾不为0（除非小数部分除了0没有别的数，那么只保留1个0）；分数不约分，分子和分母都不是小数（约分滴童鞋抱歉了，不能过哦。输入数据保证分母不为0），本次没有负数。

输入输出格式

输入格式：
一个数s

输出格式：
一个数，即s的反转数

说明
所有数据：25%s是整数，不大于20位
25%s是小数，整数部分和小数部分均不大于10位
25%s是分数，分子和分母均不大于10位
25%s是百分数，分子不大于19位
（20个数据）
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char a[50];
int len;

void Reverse(int left, int right);
void Sort(int left, int right);

int main(void){
	int i;

	scanf("%s",a);
	len=strlen(a);
	for(i=0;i<len;i++){
		if(isdigit(a[i])==0){
			break;
		}
	}
	Reverse(0,i-1);
	Sort(i+1,len-1);

	Sort(0,i-1);
	Reverse(i+1,len-1);

	for(int i=0;i<len;i++){
		printf("%c",a[i]);
	}
	printf("\n");

	return 0;
}

void Reverse(int left, int right){
	if(left>=right) return;
	double mid=(double)(left+right)/2;
	char temp;
	for(int i=left;i<=mid;i++){
		temp=a[i];
		a[i]=a[(int)(2*mid-i)];
		a[(int)(2*mid-i)]=temp;
	}
}

void Sort(int left, int right){
	if(left>=right) return;
	int i,state=0;
	for(i=left;i<=right;i++){
		if(a[i]=='0') state=1;
		if(a[i]!='0') break;
	}
	if(state==1){
		for(int j=i;j<len;j++){
			a[left+j-i]=a[j];
		}
		len-=(i-left);
		if(i==right+1){
			len++;
			a[left]='0';
		}
	}
}
