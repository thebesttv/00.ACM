/*
描述
下面程序片段的输出结果是 Hello ,请填空

#include <iostream>
using namespace std;
int main() {
	char s[] = "Hello";  
	char * p;
	for(
// 在此处补充你的代码
)
		cout << * p ;
	return 0;
}

输入
无

输出
Hello
*/

#include <iostream>
using namespace std;
int main() {
	char s[] = "Hello";  
	char * p;
	for(p=s;*p!='\0';p++)
		cout << * p ;
	return 0;
}
