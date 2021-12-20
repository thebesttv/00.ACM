/*
描述
fish在无数次oi竞赛的狱炼之后，悟出一个真理，往往越容易的题目，陷阱越深。由此，fish创作了这道题目。 
fish首先给出两个短串A=’4567’ (4个字符)， B=’123’(3个字符)。反复进行如下的操作得到一个长串C。 
（１）C=B+A (例如：A=’4567’ ,B=’123’ C=B+A=’1234567’) 
（２）A=B B=C (上述例子 A=’123’ B=’1234567’) 
请你编程找出这个长串的第n个字符。 

输入
第一行包含一个整数 n (1<=n<=10^9)

输出
仅一行，包含一个字符，表示这个长串的第n个字符。
*/

#include<iostream>
#include<cstdio>
using namespace std;

char a[]="1234567123";

int main(void){
	int n; scanf("%d",&n);
	printf("%c\n",a[(n-1)%10]);

	return 0;
}
