#include <iostream>
#include <cassert>

void print(int *p){
  assert(p);
  std::cout << *p << std::endl;
}

int main(void){
  int a = 10;
  int *p1 = &a, *p2 = NULL;
  
  std::cout << "p1: "; print(p1);
  std::cout << "p2: "; print(p2);

  return 0;
}
