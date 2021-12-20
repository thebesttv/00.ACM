#include <iostream>
#include "Chapter6.h"

int main(void){
  int n;
  while(std::cin >> n){
    std::cout << fact(n) << std::endl;
  }

  return 0;
}
