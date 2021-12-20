#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <class T>
void errorMsg(std::initializer_list<T> li){
  std::cout << "errorMsg " << typeid(T).name() << ":";
  for(const auto &i : li) std::cout << " " << i;
  std::cout << std::endl;
}

int main(void){
  errorMsg({1});
  errorMsg({1,2});
  errorMsg({1,2,3,4,5,6});

  errorMsg({"s1"});
  errorMsg({"s1","s2","s3","s4"});

  return 0;
}
