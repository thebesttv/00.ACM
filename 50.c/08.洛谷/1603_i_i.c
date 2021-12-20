/*
题目背景
根据斯诺登事件出的一道水题

题目描述
2013年X月X日，俄罗斯办理了斯诺登的护照，于是他混迹于一架开往委内瑞拉的飞机。但是，这件事情太不周密了，因为FBI的间谍早已获悉他的具体位置——但这不是最重要的——最重要的是如果要去委内瑞拉，那么就要经过古巴，而经过古巴的路在美国的掌控之中。丧心病狂的奥巴马迫降斯诺登的飞机，搜查时却发现，斯诺登杳无踪迹。但是，在据说是斯诺登的座位上，发现了一张纸条。纸条由纯英文构成：Obama is a two five zero.（以"."结束输出，只有6个单词+一个句号，句子开头如没有大写亦为合法）这句话虽然有点无厘头，但是警官陈珺骛发现这是一条极其重要的线索。他在斯诺登截获的一台笔记本中找到了一个C++程序，输入这条句子后立马给出了相对应的密码。陈珺鹜高兴得晕了过去，身为警官的你把字条和程序带上了飞机，准备飞往曼哈顿国际机场，但是在飞机上检查的时候发现——程序被粉碎了！飞机抵达华盛顿只剩5分钟，你必须在这5分钟内编写（杜撰）一个程序，免受上司的10000000000%10大板。破译密码的步骤如下：

（1）找出句子中所有用英文表示的数字(≤20)，列举在下：
正规：one two three four five six seven eight nine ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen twenty
非正规：a both another first second third
（2）将这些数字平方后%100，如00,05,11,19,86,99。
（3）把这些两位数按数位排成一行，组成一个新数，如果开头为0，就去0。
（4）找出所有排列方法中最小的一个数，即为密码。

输入输出格式

输入格式：
一个含有6个单词的句子。

输出格式：
一个整型变量（密码）。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[100];
struct Token{	//<b>不能直接对二维数组排序！</b>
	char str[3];

	bool operator < (const Token & b){
		return strcmp(str,b.str)<=0;
	}
}token[20];
char check[21][14]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
int Get(char * p);

int main(void){
	fgets(a,sizeof(a),stdin);
	char * p=strtok(a," ,.\n\r");
	int tail=0;
	while(p!=NULL){
		int t=Get(p);
		#ifdef DEBUG
		printf("  get: %s --> %d\n",p,t);
		#endif
		if(t!=-1){
			t=(t*t)%100;
			token[tail].str[0]=t/10+'0';
			token[tail].str[1]=t%10+'0';
			tail++;
		}
		p=strtok(NULL," ,.\n\r");
	}
	sort(token,token+tail);
	#ifdef DEBUG
	for(int i=0;i<tail;i++) printf("  token[%d]: %s\n",i,token[i].str);
	#endif
	bool first=0;
	for(int i=0;i<tail;i++){
		for(int j=0;j<2;j++){
			if(!first){
				if(token[i].str[j]!='0'){
					first=1;
					printf("%c",token[i].str[j]);
				}
			}else{
				printf("%c",token[i].str[j]);
			}
		}
	}
	if(!first) printf("0");
	printf("\n");

	return 0;
}

int Get(char * p){
	for(int i=0;i<=20;i++){
		if(!strcmp(p,check[i])) return i;
	}
	if(!strcmp(p,"a")) return 1;
	if(!strcmp(p,"both")) return 2;
	if(!strcmp(p,"another")) return 1;
	if(!strcmp(p,"first")) return 1;
	if(!strcmp(p,"second")) return 2;
	if(!strcmp(p,"third")) return 3;

	return -1;
}
