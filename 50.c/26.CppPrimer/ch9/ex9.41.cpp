#include <iostream>
#include <vector>
#include <string>

int main(void){
  std::vector<char> v;
  for(char ch; std::cin.get(ch);){
    v.push_back(ch);
  }
  std::string s(v.data(), v.size());
  //std::string s(v.begin(), v.end());
  std::cout << "get: " << s << std::endl;

  return 0;
}
