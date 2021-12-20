#include <iostream>

int sum(std::initializer_list<int> li){
  int s=0;
  for(auto p = li.begin(); p != li.end(); ++p)
    s += *p;
  return s;
}

int main(void){
  std::cout << sum({1}) << std::endl;
  std::cout << sum({1,2}) << std::endl;
  std::cout << sum({1,2,3,4}) << std::endl;

  return 0;
}
