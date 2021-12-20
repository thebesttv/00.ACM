#include <iostream>
#include <string>

std::string s[10];

//typedef std::string (&arrayS)[10];
//arrayS str();

typedef std::string (arrayS)[10];
arrayS &str();

//using arrayS2 = std::string (&)[10];
//arrayS2 str();

using arrayS2 = std::string[10];
arrayS2 &str();

auto str() -> std::string (&)[10];

std::string (&str())[10]{
  return s;
}

int main(void){
  for(int i=0;i<10;++i){
    s[i].resize(10,'a'+i);
  }

  for(int i=0;i<10;++i)
    std::cout << str()[i] << std::endl;

  return 0;
}

