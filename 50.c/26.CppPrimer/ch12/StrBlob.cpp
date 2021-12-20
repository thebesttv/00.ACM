#include <iostream>
#include "StrBlob.h"

int main(void){
  StrBlob b1;
  StrBlob b2 = {"a", "an", "the" };
  std::cout << "b2.size(): " << b2.size() << std::endl;

  b1 = b2;
  b1.push_back("pi");
  b2.push_back("lalala");
  std::cout << "b1.size(): " << b1.size() << std::endl;
  std::cout << "b2.size(): " << b2.size() << std::endl;

  return 0;
}
