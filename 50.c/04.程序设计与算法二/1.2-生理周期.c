#include<iostream>
#include<cstdio>

int main(){
	int p,e,i,d,n=1;	/*n初始值不能为0，0模任何非0整数都为0*/
	scanf("%d%d%d%d",&p,&e,&i,&d);

	for(;(n-p)%23;n++);	/*求出满足23的n，注意(n-p),(n-e),(n-i)*/
	for(;(n-e)%28;n+=23);	/*注意n加的是23*/
	for(;(n-i)%33;n+=23*28);	/*23,28的最小公倍数23*28*/

	printf("%d\n",n-d);

	return 0;
}
