#include <iostream>
#include <string>

int main(void){
  std::string s;
  std::cin >> s;
  for(auto &c : s) c = 'X';
  std::cout << s << std::endl;

  return 0;
}
