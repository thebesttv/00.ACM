/*
描述
程序填空输出指定结果

#include <iostream> 
using namespace std;
class A 
{ 
  public:
    A() { }
    // 在此处补充你的代码
}; 
class B:public A { 
  public: 
    ~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
  A * pa; 
  pa = new B; 
  delete pa; 
  return 0;
}

输入
无

输出
destructor B
destructor A

来源
Guo Wei
*/

#include <iostream> 
using namespace std;
class A 
{ 
  public:
    A() { }
    ~A() {  cout << "destructor B" << endl; cout << "destructor A" << endl; }
}; 
class B:public A { 
  public: 
    ~B() { cout << "destructor B" << endl; } 
}; 
int main() 
{ 
  A * pa; 
  pa = new B; 
  delete pa; 
  return 0;
}
