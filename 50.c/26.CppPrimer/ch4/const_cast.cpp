#include <iostream>

int main(void){
  int i = 1024;
  std::cout << i << std::endl;
  const int &rci = i;
  const_cast<int&>(rci) = 4;
  std::cout << i << std::endl;

  //std::cin >> i;
  //const int j = i;
  const int j = 4321;
  std::cout << j << std::endl;
  int *p = const_cast<int*>(&j);
  *p = 1234;
  std::cout << j << std::endl;  // undefined behavior

  return 0;
}
