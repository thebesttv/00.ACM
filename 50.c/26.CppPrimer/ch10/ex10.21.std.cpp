#include <iostream>
#include <algorithm>

int main(void){
  int i = 5;
  auto f = [i] () mutable -> bool {
    if(i > 0){
      --i; return false;
    }else{
      return true;
    }
  };
  for(int j=0; j<6; ++j)
    std::cout << f() << std::endl;
}
