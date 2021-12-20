/*
描述
读入两个整数，输出两个整数 ，直到碰到-1

#include <iostream>
using namespace std;
class MyCin
{
  // 在此处补充你的代码
};
int main()
{
  MyCin m;
  int n1,n2;
  while( m >> n1 >> n2) 
    cout  << n1 << " " << n2 << endl;
  return 0;
}

输入
多组数据，每组一行，是两个整数

输出
对每组数据，原样输出 
当碰到输入中出现-1 时，程序结束 
输入中保证会有 -1

样例输入
12 44
344 555
-1
2 3
样例输出
12 44
344 555
来源
Guo Wei
*/

#include <iostream>
using namespace std;
class MyCin
{
  public:
    bool ok;
    MyCin(bool ok_=1): ok(ok_) { }
    operator int () {return ok;}
    MyCin operator >> (int & n){
      if(!ok) return *this;
      cin >> n;
      if(n!=-1) return MyCin(1);
      else return MyCin(0);
    }
};
int main()
{
  MyCin m;
  int n1,n2;
  while( m >> n1 >> n2) 
    cout  << n1 << " " << n2 << endl;
  return 0;
}
