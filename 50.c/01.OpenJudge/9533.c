/*
描述
程序填空

#include <iostream> 
using namespace std;
class Point { 
  private: 
    int x; 
    int y; 
  public: 
    Point() { };
    // 在此处补充你的代码
}; 
int main() 
{ 
  Point p;
  while(cin >> p) {
    cout << p << endl;
  }
  return 0;
}

输入
多组数据，每组两个整数

输出
对每组数据，输出一行，就是输入的两个整数

样例输入
2 3
4 5

样例输出
2,3
4,5

来源
Guo Wei
*/

#include <iostream> 
using namespace std;
class Point { 
  private: 
    int x; 
    int y; 
  public: 
    Point() { };
    friend istream & operator >> (istream & is, Point & a){
      is >> a.x >> a.y;
      return is;
    }
    friend ostream & operator << (ostream & os, Point & a){
      os << a.x << "," << a.y;
      return os;
    }
}; 
int main() 
{ 
  Point p;
  while(cin >> p) {
    cout << p << endl;
  }
  return 0;
}
