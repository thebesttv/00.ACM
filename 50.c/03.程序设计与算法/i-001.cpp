/*
写出下面程序的输出结果:
	unsigned int x = 0xffffffff;
	unsigned int b = x + 2;
	int y = x;
	printf("%x,%d,%x,%d",y,y,b,b);
结果为: ffffffff,-1,1,1
*/

#include<iostream>
#include<cstdio>

int main(){
	unsigned int x=0xffffffff;
	unsigned int b=x+2;
	int y=x;
	printf("%x,%d,%x,%d",y,y,b,b);

	return 0;
}
