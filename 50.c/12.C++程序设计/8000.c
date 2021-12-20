/*
描述
下面程序的输出是：
3+4i
5+6i
请补足Complex类的成员函数。不能加成员变量。 

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
  private:
    double r,i;
  public:
    void Print() {
      cout << r << "+" << i << "i" << endl;
    }

    // 在此处补充你的代码

};
int main() {
  Complex a;
  a = "3+4i"; a.Print();
  a = "5+6i"; a.Print();
  return 0;
}

输入
无

输出
3+4i
5+6i
*/

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
  private:
    double r,i;
  public:
    void Print() {
      cout << r << "+" << i << "i" << endl;
    }
    Complex & operator = (string s){
      char str[100]; memset(str,0,sizeof(str));
      for(int i_=0;i_<s.length();i_++) str[i_]=s[i_];
      char *p = strtok(str,"+i");
      r=atof(p);
      p=strtok(NULL,"+i");
      i=atof(p);
      return *this;
    }
};
int main() {
  Complex a;
  a = "3+4i"; a.Print();
  a = "5+6i"; a.Print();
  return 0;
}
