#include <iostream>

int main(void){
  int *pi = new int {1024};
  const int *pc = new int {1024};
  std::cout << "pi: " << pi << "\npc: " << pc << std::endl;

  std::cout << "*pc: " << *pc << std::endl;
  int *p = const_cast<int*>(pc);
  *p = 2048;
  std::cout << "*pc: " << *pc << std::endl;

  return 0;
}
