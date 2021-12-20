#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

std::ostream &print(std::ostream &os, const std::string &s, char c){
  return os << s << c;
}

int main(void){
  auto g = std::bind(print, std::ref(std::cout), std::placeholders::_1, ' ');
  std::vector<std::string> v{"fdsfen", "fwe", "efew", "ef"};
  std::for_each(v.begin(), v.end(), g);
  std::cout << std::endl;

  return 0;
}
