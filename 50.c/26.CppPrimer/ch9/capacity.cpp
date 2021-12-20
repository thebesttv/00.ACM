#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v;
  for(int i=0;i<100;++i){
    v.push_back(i);
    std::cout << v.size() << "\t" << v.capacity() << "\t" << &v[0] << std::endl;
  }
}
