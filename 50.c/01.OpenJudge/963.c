/*
描述
一个字符串的前缀是从第一个字符开始的连续若干个字符，例如"abaab"共有5个前缀，分别是a, ab, aba, abaa,  abaab。
我们希望知道一个N位字符串S的前缀是否具有循环节。换言之，对于每一个从头开始的长度为 i （i 大于1）的前缀，是否由重复出现的子串A组成，即 AAA...A （A重复出现K次,K 大于 1）。如果存在，请找出最短的循环节对应的K值（也就是这个前缀串的所有可能重复节中，最大的K值）。

输入
输入包括多组测试数据。每组测试数据包括两行。
第一行包括字符串S的长度N（2 <= N <= 1 000 000）。
第二行包括字符串S。
输入数据以只包括一个0的行作为结尾。

输出
对于每组测试数据，第一行输出 "Test case #“ 和测试数据的编号。
接下来的每一行，输出前缀长度i和重复测数K，中间用一个空格隔开。前缀长度需要升序排列。
在每组测试数据的最后输出一个空行。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=1000010;
struct Node{
	int i;
	int k;

	bool operator < (const Node & b) const {
		return i<b.i;
	}
}temp,v[MAX/2];
char a[MAX];
int ans[MAX];
int len,kase=0,tail=0;

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	while(scanf("%d",&len)==1 && len){
		memset(a,0,sizeof(a)); memset(ans,0,sizeof(ans)); memset(v,0,sizeof(v));
		tail=0;
		getchar();
		for(int i=0;i<len;i++) a[i]=getchar();
		getchar();
		#ifdef DEBUG
		printf("%s\n",a);
		#endif
		int mLen=len/2;

		for(int i=1;i<=mLen;i++){	//枚举子串
			if(a[i-1]!=a[i*2-1] || (i>1 && a[i-2]!=a[i*2-2])) continue;
			bool flag=1; int j;
			for(j=0;j<len;j++)
				if(a[j]!=a[j%i]){
					if(j<i*2) flag=0;
					break;
				}
			if(len-j<i) mLen=i;	//确定全局最小子串
			if(flag){
				v[tail].i=i;	//子串长度
				v[tail++].k=j/i;	//子串最大重复次数
			}
		}
		#ifdef DEBUG
		for(int i=0;i<tail;i++) if(v[i].i && v[i].k) printf("  %d %d\n",v[i].i,v[i].k);
		#endif
		for(int i=0;i<tail;i++){
			for(int k=2;k<=v[i].k;k++){
				temp.k=k;
				temp.i=v[i].i*k;	//前缀长度
				if(ans[temp.i]==0) ans[temp.i]=temp.k;	//隐式满足 对于i，第一个被加入的k最大？
			}
		}
		kase++;
		if(kase!=1) printf("\n");
		printf("Test case #%d\n",kase);
		for(int i=0;i<MAX;i++){
			if(ans[i]) printf("%d %d\n",i,ans[i]);
		}
	}

	return 0;
}
