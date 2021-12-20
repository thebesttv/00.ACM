/*
描述
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：
add x 把x加入集合
del x 把集合中所有与x相等的元素删除
ask x 对集合中元素x的情况询问
对每种操作，我们要求进行如下输出。
add 输出操作后集合中x的个数
del 输出操作前集合中x的个数
ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。

输入
第一行是一个整数n，表示命令数。0<=n<=100000。
后面n行命令，如Description中所述。

输出
共n行，每行按要求输出。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>	//使用multiset或set时要包含头文件set
#include<cstring>
using namespace std;

#define DEBUG 0

multiset<int> st,st2;
multiset<int>::iterator p;

void Add(int x);
void Del(int x);
void Ask(int x);
void Print(int x);

#if DEBUG
void PrintAll(){
//	multiset<int>::iterator p;
	printf("    ");
	for(p=st.begin();p!=st.end();p++) printf("%d,",*p);
	printf("\n");
}
#endif

int main(){
	int n,x;
	char ord[10];
//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s %d",ord,&x);
		switch(ord[1]){
			case 'd': Add(x); break;
			case 'e': Del(x); break;
			case 's': Ask(x); break;
		}
	}

	return 0;
}

void Add(int x){
	st.insert(x);
	st2.insert(x);
	Print(x);
#if DEBUG
PrintAll();
#endif
}

void Del(int x){	//要使用st.erase(st.lower_bound(x),st.upper_bound(x));删除
	Print(x);
//	multiset<int>::iterator p;
//	for(p=st.begin();p!=st.end();p++) if(*p==x) st.erase(p);
	st.erase(st.lower_bound(x),st.upper_bound(x));
#if DEBUG
PrintAll();
#endif
}

void Ask(int x){
	if(st2.find(x)==st2.end()) printf("0 ");
	else printf("1 ");
	Print(x);
#if DEBUG
PrintAll();
#endif
}

void Print(int x){
//	multiset<int>::iterator p;
	int cou=0;
	for(p=st.begin();p!=st.end();p++) if(*p==x) cou++;
	printf("%d\n",cou);
}
