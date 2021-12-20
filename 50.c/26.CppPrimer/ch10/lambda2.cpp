#include <iostream>
#include <string>

int main(void){
  auto basicLambda = []{ std::cout << "Hello, world!" << std::endl; };
  auto add = [](int a, int b) -> int {
    return a + b;
  };
  auto mul = [](int a, int b) {
    return a * b;
  };
  basicLambda();
  std::cout << "add(3,4): " << add(3,4) << std::endl;
  std::cout << "mul(3,4): " << mul(3,4) << std::endl;

  return 0;
}
