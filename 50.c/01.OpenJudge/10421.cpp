/*
描述
编写GetDoubleFromString函数，该函数可以不断从字符串中取出正浮点数或整数，无数可取，则返回值小于0

#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
// 在此处补充你的代码
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}

输入
多组数据，每组数据一行

输出
针对每组数据，将其中的数输出来。每行一个数，保留小数点后面6位。输入数据中只会有正数，不用考虑负号。两个数之间有至少一个非数字非小数点的字符。
*/

#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
	static char * p;
	if(str!=NULL) p=str;
	while(*p!=0){
		char * s=NULL, * e=NULL, * flag=NULL;

		while(*p!=0){
			if(*p>='0' && *p<='9') {s=p;break;}
			p++;
		}
		while(*p!=0){
			if(*p=='.') flag=p;
			if((*p<'0' || *p>'9') && *p!='.') {e=p;break;}
			p++;
		}
		if(e==NULL) e=p;
		if(s!=NULL && e!=NULL){
			if(flag==NULL){
				double t=*(s++)-'0';
				while(s!=e){t=t*10+(*s-'0'); s++;}
				return t;
			}else{
				double t=*(s++)-'0',m=1;
				while(s!=flag){t=t*10+(*s-'0'); s++;}
				s++;
				while(s!=e){m/=10; t=t+(*s-'0')*m; s++;}
				return t;
			}
		}
	}
	return -1;
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}
