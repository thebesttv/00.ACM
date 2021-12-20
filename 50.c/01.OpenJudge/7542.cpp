/*
描述
监护室每小时测量一次病人的血压，若收缩压在90 - 140之间并且舒张压在60 - 90之间（包含端点值）则称之为正常，现给出某病人若干次测量的血压值，计算病人保持正常血压的最长小时数。

输入
第一行为一个正整数n，n < 100
其后有n行，每行2个正整数，分别为一次测量的收缩压和舒张压，中间以一个空格分隔。

输出
输出仅一行，血压连续正常的最长小时数。
*/

#include<iostream>
#include<cstdio>

int main(){
	int a,b,n;
	int hour=0,max=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		if(a>=90 && a<=140 && b>=60 && b<=90){
			hour++;
			if(hour>max) max=hour;
		}else{
			hour=0;
		}
	}
	printf("%d\n",max);

	return 0;
}
