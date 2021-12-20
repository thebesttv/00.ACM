#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v;
  for(int i=0;i<5;++i) v.push_back(i);
  std::cout << "capacity: " << v.capacity() << std::endl;
  v.reserve(15);
  std::cout << "capacity: " << v.capacity() << std::endl;

  return 0;
}
