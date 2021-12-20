/*
描述
转眼毕业了，曾经朝夕相处的同学们不得不都各奔东西，大家都去了不同的城市开始新的生活。在各自城市居住了一段时间后，他们都感到了一些厌倦，想去看看其他人的生活究竟如何，于是他们都选择到另一个同学所在城市去旅游，并且希望旅游的城市各不相同，他们想知道有多少种不同的方案，可是数量实在太多了，他们无法计算出来，你能帮助他们吗。

输入
一个正整数n(n<200)，表示人数。

输出
一个数，表示有多少不同的方案。
*/

//ans=((-1)^2)*(n-2)! + ((-1)^3)*(n-3)! + ((-1)^4)*(n-4)! + ... + ((-1)^n)*(n-n)!
//网络: ans[n]=(ans[n-1]+ans[n-2])*(n-1)

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int save[1000],n,sum=0;
bool book[1000];

void dfs(int step){
	if(step==n+1){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(save[i]==i) flag=0;
		}
		if(flag) sum++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!book[i]){
			book[i]=1;
			save[step]=i;
			dfs(step+1);
			book[i]=0;
		}
	}
}

int main(void){
	for(n=2;n<=10;n++){
		sum=0;
		memset(save,0,sizeof(save)); memset(book,0,sizeof(book));
		dfs(1);
		printf("%d: %d\n",n,sum);
	}

	return 0;
}
