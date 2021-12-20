#include <iostream>
#include <memory>
#include <string>

int main(void){
  std::shared_ptr<int> p1 = std::make_shared<int>();
  std::shared_ptr<int> p2 = std::make_shared<int>(1024);
  auto p3 = std::make_shared<std::string>(10,'2');
  std::cout << "*p1: " << *p1 << std::endl;
  std::cout << "*p2: " << *p2 << std::endl;
  std::cout << "*p3: " << *p3 << std::endl;

  return 0;
}
