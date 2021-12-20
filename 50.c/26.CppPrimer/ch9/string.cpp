#include <iostream>
#include <string>

int main(void){
  std::string s("C++ Primer");
  s.append(" 4th Ed.");
  std::cout << s << std::endl;
  s.replace(s.find("4th"),3,"5th");
  std::cout << s << std::endl;
  s.replace(s.find("5th"),3,"Fifth");
  std::cout << s << std::endl;

  return 0;
}
