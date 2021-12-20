#include <iostream>

int main(void){
  while(int ch = std::cin.get()){
    if(ch==EOF) break;
    std::cout.put(ch);
  }
  std::cout << std::endl;

  return 0;
}
