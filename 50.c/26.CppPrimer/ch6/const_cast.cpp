#include <iostream>
#include <string>

const std::string &shorterString(const std::string &s1, const std::string &s2){
  return s1.size() <= s2.size() ? s1 : s2;
}

std::string &shorterString(std::string &s1, std::string &s2){
  auto &r = shorterString(const_cast<const std::string &>(s1),
                          const_cast<const std::string &>(s2));
  return const_cast<std::string &>(r);
}

int main(void){
  std::string s1, s2; std::cin >> s1 >> s2;
  shorterString(s1, s2) = "lalala";
  std::cout << s1 << std::endl << s2 << std::endl;

  return 0;
}
