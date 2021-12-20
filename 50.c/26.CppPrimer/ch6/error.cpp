#include <iostream>

void printErr(){
  std::cout << "Error: " << __FILE__
            << ": in function " << __func__
            << " at time " << __LINE__ << std::endl
            << "Compiled on " << __DATE__
            << " at " << __TIME__ << std::endl;
}

int main(void){
  printErr();

  return 0;
}
