#include <iostream>

int main(void){
  int n;
  while(std::cin >> n) switch(n){
    case true:
      std::cout << "true" << std::endl;
      break;
    case false:
      std::cout << "false" << std::endl;
      break;
  }

  return 0;
}
