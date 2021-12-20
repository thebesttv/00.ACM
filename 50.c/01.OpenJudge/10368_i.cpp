/*
描述
程序填空使得输出指定结果

#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(
// 在此处补充你的代码
p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}

输入
无

输出
10
20
30
*/

#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	x = 10;
	y = 20;
	z = 30;
	
	int * a[3]  = { &x, &y,&z};
	for(int ** p=a; p < a + 3; ++p) 
			cout<< * (*p) << endl;
	return 0;
	
}
