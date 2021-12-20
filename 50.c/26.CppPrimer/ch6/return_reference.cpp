#include <iostream>
#include <string>

std::string & shorterString(std::string &s1, std::string &s2){
  return s1.size() < s2.size() ? s1 : s2;
}

int main(void){
  std::cout << "change shorter string to \"lalala\"" << std::endl;
  std::string s1, s2;
  std::cin >> s1 >> s2;
  shorterString(s1,s2) = "lalala";
  std::cout << "s1: " + s1 << std::endl;
  std::cout << "s2: " + s2 << std::endl;

  return 0;
}
