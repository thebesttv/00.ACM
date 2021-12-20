/*
描述
2008年北京奥运会，A国的运动员参与了n天的决赛项目(1≤n≤17)。现在要统计一下A国所获得的金、银、铜牌数目及总奖牌数。

输入
输入n＋1行，第1行是A国参与决赛项目的天数n，其后n行，每一行是该国某一天获得的金、银、铜牌数目，以一个空格分开。

输出
输出1行，包括4个整数，为A国所获得的金、银、铜牌总数及总奖牌数，以一个空格分开。
*/

#include<iostream>
#include<cstdio>

int main(){
	int n,tempg,temps,tempc;
	int g=0,s=0,c=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&tempg,&temps,&tempc);
		g+=tempg;
		s+=temps;
		c+=tempc;
	}
	printf("%d %d %d %d\n",g,s,c,g+s+c);

	return 0;
}
