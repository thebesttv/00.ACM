/*
描述
请统计某个给定范围[L, R]的所有整数中，数字2出现的次数。

比如给定范围[2, 22]，数字2在数2中出现了1次，在数12中出现1次，在数20中出现1次，在数21中出现1次，在数22中出现2次，所以数字2在该范围内一共出现了6次。

输入
输入共 1 行，为两个正整数 L 和 R，之间用一个空格隔开。

输出
输出共 1 行，表示数字 2 出现的次数。
*/

#include<iostream>
#include<cstdio>

int main(){
	int L,R;
	int i,t,n,sum=0;

	scanf("%d%d",&L,&R);
	for(i=L;i<=R;i++){
		t=i;
		while(t>0){
			n=t%10;
			if(n==2) sum++;
			t/=10;
		}
	}
	printf("%d\n",sum);

	return 0;
}
