/*
描述
求两个不超过200位的非负整数的和。

输入
有两行，每行是一个不超过200位的非负整数，可能有多余的前导0。

输出
一行，即相加后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int LEN=220;

void swap(char & a, char & b){
	char t=a; a=b; b=t;
}

int main(void){
	char a[LEN],b[LEN];
	int lena,lenb;
	scanf("%s%s",a,b);
	lena=strlen(a); lenb=strlen(b);
	int mlen=max(lena,lenb);
//printf("lena: %d, lenb: %d\n",lena,lenb);
	for(int i=0;i<lena/2;i++) swap(a[i],a[lena-i-1]);
	for(int i=0;i<lenb/2;i++) swap(b[i],b[lenb-i-1]);
//printf("%s\n%s\n\n",a,b);
	int t=0;
	for(int i=lena;i<LEN;i++) a[i]='0';
	for(int i=lenb;i<LEN;i++) b[i]='0';
	for(int i=0;i<mlen;i++){
		t=a[i]-'0'+b[i]-'0'+t;
		b[i]=t%10+'0';
		t/=10;
	}
	if(t!=0) b[mlen]=t+'0';
	mlen=strlen(b);
	int first=0;
	for(int i=mlen-1;i>=0;i--){
		if(first){
			putchar(b[i]);
		}else if(b[i]!='0'){
			putchar(b[i]);
			first=1;
		}
	}
	if(!first) putchar('0');
	putchar('\n');

	return 0;
}
