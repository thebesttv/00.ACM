#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void errorMsg(std::initializer_list<int> li){
  std::cout << "errorMsg:";
  for(auto i : li) std::cout << " " << i;
  std::cout << std::endl;
}
void errorMsg(std::initializer_list<std::string> li){
  std::cout << "errorMsg:";
  for(auto i : li) std::cout << " " << i;
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
