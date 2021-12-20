#include <iostream>
#include <string>

int main(void){
  std::string s;
  //int x;
  double x;
  std::cin >> x;
  s = std::to_string(x);
  std::cout << "s: " << s << std::endl;
  return 0;
}
