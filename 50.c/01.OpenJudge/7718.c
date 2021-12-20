/*
描述
有一个分数序列 q1/p1,q2/p2,q3/p3,q4/p4,q5/p5,.... ,其中qi+1= qi+ pi, pi+1=qi, p1= 1, q1= 2。比如这个序列前6项分别是2/1,3/2,5/3,8/5,13/8,21/13。求这个分数序列的前n项之和。

输入
输入有一行，包含一个正整数n(n <= 30)。

输出
输出有一行，包含一个浮点数，表示分数序列前n项的和，精确到小数点后4位。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
	double p=1,q=1,sum=0,t;	//p0=1,q0=1;
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		t=q;
		q=p+q;
		p=t;
		sum+=q/p;
	}
	printf("%.4lf\n",sum);

/*
	double p=1,q=2,sum=0,t;
	int n;
	scanf("%d",&n);

	sum+=q/p;
	for(int i=1;i<n;i++){
		t=q;
		q=p+q;
		p=t;
		sum+=q/p;
	}
	printf("%.4lf\n",sum);
*/
	return 0;
}
