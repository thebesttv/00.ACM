#include <iostream>
#include <memory>

int main(void){
  int a = 1024;
  auto p1 = std::make_shared<int>(a);
  std::cout << "p1 is " << (p1.unique() ? "unique" : "not unique") << std::endl;
  auto p2 = p1;
  std::cout << "p1 is " << (p1.unique() ? "unique" : "not unique") << std::endl;
  std::cout << "p2 is " << (p2.unique() ? "unique" : "not unique") << std::endl;

  return 0;
}
