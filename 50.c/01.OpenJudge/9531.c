/*
描述
程序填空

#include <iostream> 
using namespace std;
class MyInt 
{ 
  int nVal; 
  public: 
  MyInt( int n) { nVal = n ;}
  // 在此处补充你的代码
}; 
int Inc(int n) {
  return n + 1;
}
int main () { 
  int n;
  while(cin >>n) {
    MyInt objInt(n); 
    objInt-2-1-3; 
    cout << Inc(objInt);
    cout <<","; 
    objInt-2-1; 
    cout << Inc(objInt) << endl;
  }
  return 0;
}

输入
多组数据，每组一行，整数n

输出
对每组数据，输出一行，包括两个整数， n-5和n - 8

样例输入
20
30

样例输出
15,12
25,22

来源
Guo Wei
*/

#include <iostream> 
using namespace std;
class MyInt 
{ 
  int nVal; 
  public: 
  MyInt( int n) { nVal = n ;}
  operator int (void) {return nVal;}
  MyInt & operator - (int n){
    this->nVal-=n;
    return *this;
  }
}; 
int Inc(int n) {
  return n + 1;
}
int main () { 
  int n;
  while(cin >>n) {
    MyInt objInt(n); 
    objInt-2-1-3; 
    cout << Inc(objInt);
    cout <<","; 
    objInt-2-1; 
    cout << Inc(objInt) << endl;
  }
  return 0;
}
