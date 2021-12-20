#include <iostream>
#include <vector>
#include <stdexcept>

void access(std::vector<int> &v, int i){
  try{
    v.at(i);
  }catch(std::out_of_range &oor){
    std::cerr << "out of range error: " << oor.what() << std::endl;
  }
}

int main(void){
  std::vector<int> v{0,1,2,3};
  for(int i=0;i<10;++i){
    access(v,i);
  }

  return 0;
}
