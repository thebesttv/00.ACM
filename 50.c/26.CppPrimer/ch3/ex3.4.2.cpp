#include <iostream>
#include <string>
#include <typeinfo> // for typeid

int main(void){
  std::string s1, s2;
  std::cin >> s1 >> s2;
  auto len1 = s1.size();
  auto len2 = s2.size();
  std::cout << "len1 & len2 have type " << typeid(len1).name() << std::endl;
  if(len1==len2){
    std::cout << "\"" + s1 + "\" and \"" + s2 + "\""
              << " have the same length" << std::endl;
  }else{
    if(len1<len2) std::swap(s1,s2);
    std::cout << "\"" + s1 + "\" is longer" << std::endl;
  }

  return 0;
}
