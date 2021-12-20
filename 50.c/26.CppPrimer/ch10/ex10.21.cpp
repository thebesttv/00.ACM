#include <iostream>

int main(void){
  int i = 2;
  auto f = [&i]() -> bool {
    if(!i) return false;
    --i; return true;
  };
  bool st;

  st = f();
  std::cout << "st: " << st << ", i: " << i << std::endl;

  st = f();
  std::cout << "st: " << st << ", i: " << i << std::endl;

  st = f();
  std::cout << "st: " << st << ", i: " << i << std::endl;

  st = f();
  std::cout << "st: " << st << ", i: " << i << std::endl;

  return 0;
}
