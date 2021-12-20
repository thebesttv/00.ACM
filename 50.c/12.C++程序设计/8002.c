/*
描述
写一个二维数组类 Array2,使得下面程序的输出符合输出要求：
程序：

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {

  // 在此处补充你的代码

};

int main() {
  Array2 a(3,4);
  int i,j;
  for(  i = 0;i < 3; ++i )
    for(  j = 0; j < 4; j ++ )
      a[i][j] = i * 4 + j;
  for(  i = 0;i < 3; ++i ) {
    for(  j = 0; j < 4; j ++ ) {
      cout << a(i,j) << ",";
    }
    cout << endl;
  }
  cout << "next" << endl;
  Array2 b;     b = a;
  for(  i = 0;i < 3; ++i ) {
    for(  j = 0; j < 4; j ++ ) {
      cout << b[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}

输入
无

输出
0,1,2,3,
4,5,6,7,
8,9,10,11,
next
0,1,2,3,
4,5,6,7,
8,9,10,11,
*/

#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
  private:
    int a[100][100];
    int r,c;
  public:
    Array2(): r(0), c(0) {}
    Array2(int r_, int c_): r(r_), c(c_) {}
    int * operator [] (const int i){
      return a[i];
    }
    int operator () (int i,int j) {return a[i][j];}
    Array2 & operator = (Array2 & b){
      for(int i=0;i<b.r;i++) for(int j=0;j<b.c;j++)
        a[i][j] = b.a[i][j];
      return *this;
    }
};

int main() {
  Array2 a(3,4);
  int i,j;
  for(  i = 0;i < 3; ++i )
    for(  j = 0; j < 4; j ++ )
      a[i][j] = i * 4 + j;
  for(  i = 0;i < 3; ++i ) {
    for(  j = 0; j < 4; j ++ ) {
      cout << a(i,j) << ",";
    }
    cout << endl;
  }
  cout << "next" << endl;
  Array2 b;     b = a;
  for(  i = 0;i < 3; ++i ) {
    for(  j = 0; j < 4; j ++ ) {
      cout << b[i][j] << ",";
    }
    cout << endl;
  }
  return 0;
}
