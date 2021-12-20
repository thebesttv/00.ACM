/*
描述
程序填空，产生指定输出结果

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[8] = {6,5,14,23,2,9,87,10 };
	sort(
// 在此处补充你的代码
);
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	return 0;
}
输入
无
输出
6,87,23,14,9,5,2,10,
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[8] = {6,5,14,23,2,9,87,10 };
	sort(a+1,a+7,greater<int>());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	return 0;
}
