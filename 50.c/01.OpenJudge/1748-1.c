/*
描述
约瑟夫问题：有ｎ只猴子，按顺时针方向围成一圈选大王（编号从１到ｎ），从第１号开始报数，一直数到ｍ，数到ｍ的猴子退出圈外，剩下的猴子再接着从1开始报数。就这样，直到圈内只剩下一只猴子时，这个猴子就是猴王，编程求输入ｎ，ｍ后，输出最后猴王的编号。

输入
每行是用空格分开的两个整数，第一个是 n, 第二个是 m ( 0 < m,n <=300)。最后一行是：

0 0

输出
对于每行输入数据（最后一行除外)，输出数据也是一行，即最后猴王的编号
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[310],m,n;

int main(void){
	while(scanf("%d%d",&n,&m)==2 && n){
		memset(a,-1,sizeof(a));
		for(int i=1;i<=n;i++) a[i]=i;
		int cou=1,cur=1;
		while(cou<n){
			for(int i=0;i<=m;){
				if(a[cur]!=-1) i++;
				if(i==m){
					a[cur]=-1; i++;
				}
				cur=(cur+1)%(n+1);
			}
			cou++;
		}
		for(int i=1;i<=n;i++) if(a[i]!=-1) printf("%d\n",i);
	}

	return 0;
}
