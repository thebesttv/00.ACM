#include <iostream>
#include <string>

int main(void){
  std::string s;
  while(std::getline(std::cin, s))
    std::cout << s << std::endl;
  //while(std::cin >> s)
  //  std::cout << s << std::endl;

  return 0;
}
