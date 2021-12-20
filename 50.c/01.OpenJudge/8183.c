/*
描述
根据参数，画出矩形。

输入
输入一行，包括四个参数：前两个参数为整数，依次代表矩形的高和宽（高不少于3行不多于10行，宽不少于5列不多于10列）；第三个参数是一个字符，表示用来画图的矩形符号；第四个参数为1或0，0代表空心，1代表实心。

输出
输出画出的图形。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
	char c;
	int m,n,fill;
	scanf("%d %d %c %d",&m,&n,&c,&fill);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(fill) printf("%c",c);
			else{
				if(i==0 || i==m-1 || j==0 || j==n-1) printf("%c",c);
				else printf(" ");
			}
		}
		printf("\n");
	}

	return 0;
}
