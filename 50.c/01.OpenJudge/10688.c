/*
描述
程序填空，产生指定输出结果

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
	int x;
	int y;
};
// 在此处补充你的代码
int main()
{
	int a[8] = {6,5,55,23,3,9,87,10 };
	sort(a,a+8,Rule1());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	cout << endl;
	Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0} } ;
	sort(ps,ps+8,Rule2());
	for(int i = 0;i < 8; ++i)
		cout << "(" << ps[i].x << "," << ps[i].y << ")"; 
	return 0;
}

输入
无

输出
10,23,3,55,5,6,87,9,
(-1,0)(0,-1)(0,1)(1,0)(1,-1)(1,1)(-2,0)(2,0)

整数按照个位数从小到大排。个位数相同，则大的排前面 

点按照离原点从近到远排。距离相同，则按x坐标从小到大排。x坐标也相同，则按y坐标从小到大排
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Point{
	int x;
	int y;
};

struct Rule1{
	bool operator()(const int & a, const int & b){
		if(a%10<b%10) return true;
		else if(a%10>b%10) return false;
		else return a>b;
	}
};

struct Rule2{
	bool operator()(const Point & a, const Point & b){
		int lena=a.x*a.x+a.y*a.y;
		int lenb=b.x*b.x+b.y*b.y;
		if(lena<lenb) return true;
		else if(lena>lenb) return false;
		else if(a.x!=b.x) return a.x<b.x;
		else return a.y<b.y;
	}
};

int main()
{
	int a[8] = {6,5,55,23,3,9,87,10 };
	sort(a,a+8,Rule1());
	for(int i = 0;i < 8; ++i)
		cout << a[i] << "," ; 
	cout << endl;
	Point ps[8] = {{1,0},{0,1},{0,-1},{-1,0},{1,-1},{1,1},{2,0},{-2,0} } ;
	sort(ps,ps+8,Rule2());
	for(int i = 0;i < 8; ++i)
		cout << "(" << ps[i].x << "," << ps[i].y << ")"; 
	return 0;
}
