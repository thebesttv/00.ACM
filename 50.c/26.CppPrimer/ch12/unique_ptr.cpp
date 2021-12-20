#include <iostream>
#include <memory>

int main(void){
  std::unique_ptr<int> p1(new int{1024});
  std::unique_ptr<int> p2(p1.release());
  std::cout << "*p2: " << *p2 << std::endl;
  std::unique_ptr<int> p3(new int{4096});
  p2.reset(p3.release());
  std::cout << "*p2: " << *p2 << std::endl;
  auto p = p2.release();
  delete p;

  return 0;
}
