/*
描述
在一个学生信息处理程序中，要求实现一个代表学生的类，并且所有成员变量都应该是私有的。
（注：评测系统无法自动判断变量是否私有。我们会在结束之后统一对作业进行检查，请同学们严格按照题目要求完成，否则可能会影响作业成绩。）

输入
姓名，年龄，学号，第一学年平均成绩，第二学年平均成绩，第三学年平均成绩，第四学年平均成绩。
其中姓名、学号为字符串，不含空格和逗号；年龄为正整数；成绩为非负整数。
各部分内容之间均用单个英文逗号","隔开，无多余空格。

输出
一行，按顺序输出：姓名，年龄，学号，四年平均成绩（向下取整）。
各部分内容之间均用单个英文逗号","隔开，无多余空格。
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

class Student{
private:
	char name[20];
	int age,no;
	int score;
public:
	Student(char *name_, int age_, int no_, int score_){
		strcpy(name,name_); age=age_; no=no_; score=score_;
	}
	void print(){
		printf("%s,%d,%d,%d\n",name,age,no,score);
	}
};
char temp[100];

int main(void){
	fgets(temp,sizeof(temp),stdin);
	char *p=strtok(temp,",\n\r");
	char name[20]; strcpy(name,p);
	p=strtok(NULL,",\n\r"); int age=atoi(p);
	p=strtok(NULL,",\n\r"); int no=atoi(p);
	int score=0;
	for(int i=0;i<4;i++) score+=atoi(p=strtok(NULL,",\n\r"));
	score/=4;
	Student ind(name,age,no,score);
	ind.print();

	return 0;
}
