#include <iostream>

void go(){
  int x = 1024;
  auto f = [x](int a) -> int {
    return a + x;
  };
  std::cout << "f(10): " << f(10) << std::endl;
}

int main(void){
  go();
  return 0;
}
