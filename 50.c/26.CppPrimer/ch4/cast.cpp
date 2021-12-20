#include <iostream>

int main(void){
  int i = 3, j = 5;
  std::cout << static_cast<double>(i) / j << std::endl;
  double x = 3.1415, y = 5.9900;
  std::cout << static_cast<int>(x) / static_cast<int>(y) << std::endl;
  //void *p = static_cast<void*>(&x);
  void *p = &x;
  std::cout << *static_cast<double*>(p) << std::endl;

  return 0;
}
