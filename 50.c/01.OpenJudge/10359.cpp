/*
描述
下面程序输出结果是 Tesla Tes 请填空
#include <iostream>
using namespace std;
void Print(const char * p1, const char * p2) 
{  
	for(
// 在此处补充你的代码
) 	
		cout << * p1;
}
int main()  
{
	const char * s = "Tesla123";
	Print(s,s+5);
	cout << endl;
	Print(s,s+3);
	cout << endl;
	
	return 0;
}

输入
无

输出
Tesla
Tes
*/

#include <iostream>
using namespace std;
void Print(const char * p1, const char * p2) 
{  
	for(;p1<p2;p1++) 	
		cout << * p1;
}
int main()  
{
	const char * s = "Tesla123";
	Print(s,s+5);
	cout << endl;
	Print(s,s+3);
	cout << endl;
	
	return 0;
}
