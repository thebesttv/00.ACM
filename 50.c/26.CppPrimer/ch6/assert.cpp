#include <iostream>
#include <cassert>

int main(void){
  std::cout << "Before assert" << std::endl;
  int *p = NULL;
  assert(p);
  std::cout << "After assert" << std::endl;

  return 0;
}
