#include <iostream>

void g(){
  std::cout << "call g()" << std::endl;
}
void f(){
  std::cout << "call f()" << std::endl;
  return g();
}
int main(void){
  f();

  return 0;
}
