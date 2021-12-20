#include <iostream>
#include <string>

int main(void){
  std::string s1, s2;
  std::cin >> s1 >> s2;
  if(s1==s2){
    std::cout << "\"" + s1 + "\" equals \"" + s2 + "\"" << std::endl;
  }else{
    if(s1<s2) std::swap(s1,s2);
    std::cout << "\"" + s1 + "\" is greater than \"" + s2 + "\"" << std::endl;
  }

  return 0;
}
