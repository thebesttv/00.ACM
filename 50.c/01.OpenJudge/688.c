/*
描述
判断两个表达式在数学上是否是等价的。

输入
第一行：N（1<=N<=20），表示测试数据组数。
接下来每组测试数据包括两行，每行包括一个数学表达式，每个表达式的长度不超过80个字符。输入数据没有空行。
一个表达式可能包括：
单个英文字母表示的变量（区分大小写）
数字（只有一位数）
配对的括号
运算符加+、减-、乘*
任意数量的空格或tab（可能出现在表达式中间的任何位置）
注意：表达式保证是语法正确的，且所有运算符的优先级相同，运算次序从左至右。变量的系数和指数保证不超过16位整数。

输出
对每个测试数据，输出一行：等价则输出“YES”，不等价则输出“NO”。

样例输入
3
(a+b-c)*2
(a+a)+(b*2)-(3*c)+c
a*2-(a+c)+((a+c+e)*2)
3*a+c+(2*e)
(a-b)*(a-b)
(a*a)-(2*a*b)-(b*b)

样例输出
YES
YES
NO
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

char a[100],b[100];
char a_[100],b_[100];
int var[120];
struct Stack{
	char exp[100];
	int top;
};


int Convert(char ori[], char dest[]);	//将中缀表达式转换为后缀表达式，并返回变量数
long long Cal(char a[]);	//计算后缀表达式的值

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	srand(time(NULL));
	char temp[10]; fgets(temp,sizeof(temp),stdin);
	int n=atoi(temp);
	for(int i=0;i<n;i++){
		memset(a,0,sizeof(a)); memset(b,0,sizeof(b));
		memset(a_,0,sizeof(a_)); memset(b_,0,sizeof(b_));
		fgets(a,sizeof(a),stdin); fgets(b,sizeof(b),stdin);
		int lena=strlen(a), lenb=strlen(b);
		for(int i=0;i<lena;i++) if(isalpha(a[i])) a[i]=tolower(a[i]);
		for(int i=0;i<lenb;i++) if(isalpha(b[i])) b[i]=tolower(b[i]);
		int vara=Convert(a,a_), varb=Convert(b,b_);
//		if(vara!=varb){printf("NO\n"); continue;}
		bool flag=1;
		for(int k=0;k<10;k++){
			for(int i=0;i<120;i++) var[i]=rand()%10;
			if(Cal(a_)!=Cal(b_)) flag=0;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

int Convert(char ori[], char dest[]){
	Stack temp; memset(&temp,0,sizeof(temp));
	int len=strlen(ori),var=0;
	int tailDest=0;
	bool occ[120]; memset(occ,0,sizeof(occ));
	for(int i=0;i<len;i++){
		if(isalpha(ori[i])){	//变量
			dest[tailDest++]=ori[i];
			if(!occ[ori[i]]){
				occ[ori[i]]=1; var++;
			}
		}else if(isdigit(ori[i])){	//系数
			dest[tailDest++]=ori[i];
		}else if(ori[i]=='+' || ori[i]=='-'){	//加减
			for(int j=temp.top-1;j>=0;j--){
				if(temp.exp[j]!='('){
					dest[tailDest++]=temp.exp[--temp.top];
				}else{
					break;
				}
			}
			temp.exp[temp.top++]=ori[i];
		}else if(ori[i]=='*'){	//乘
			for(int j=temp.top-1;j>=0;j--){
				if(temp.exp[i]=='*'){
					dest[tailDest++]=temp.exp[--temp.top];
				}else{
					break;
				}
			}
			temp.exp[temp.top++]=ori[i];
		}else if(ori[i]=='('){	//左括号直接入栈
			temp.exp[temp.top++]=ori[i];
		}else if(ori[i]==')'){	//右括号，输出到第一个左括号
			for(int j=temp.top-1;j>=0;j--){
				if(temp.exp[j]!='('){
					dest[tailDest++]=temp.exp[--temp.top];
				}else{
					temp.top--; break;
				}
			}
		}

//		#ifdef DEBUG
//		printf("  "); for(int i=0;i<tailDest;i++) printf("%c",dest[i]); printf("\n");
//		printf("    "); for(int i=0;i<temp.top;i++) printf("%c",temp.exp[i]); printf("\n");
//		#endif
	}
	while(temp.top>0) dest[tailDest++]=temp.exp[--temp.top];
	#ifdef DEBUG
	printf("  exp: "); //len=strlen(dest);
	for(int i=0;i<tailDest;i++) printf("%c",dest[i]);
	printf(" , var: %d\n",var);
	#endif
	return var;
}

long long Cal(char a[]){
	int len=strlen(a);
	long long temp[100],top=0;
	for(int i=0;i<len;i++){
		if(isalpha(a[i])){
			temp[top++]=var[a[i]];
		}else if(isdigit(a[i])){
			temp[top++]=a[i]-'0';
		}else if(a[i]=='+' || a[i]=='-' || a[i]=='*'){
			int y=temp[--top], x=temp[--top], res;
			switch(a[i]){
				case '+': res=x+y; break;
				case '-': res=x-y; break;
				case '*': res=x*y; break;
			}
			temp[top++]=res;
		}
//		#ifdef DEBUG
//		printf("  temp: "); for(int i=0;i<top;i++) printf("%d ",temp[i]); printf("\n");
//		#endif
	}
//	#ifdef DEBUG
//	bool book[120]; memset(book,0,sizeof(book));
//	for(int i=0;i<len;i++) if(isalpha(a[i])) book[a[i]]=1;
//	for(int i=0;i<120;i++) if(book[i]) printf("  %c: %d\n",i,var[i]);
//	printf("  result: %d\n",temp[0]);
//	#endif
	return temp[0];
}
