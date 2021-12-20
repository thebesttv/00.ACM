#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v;
  for(int i=0;i<5;++i) v.push_back(i);
  std::cout << "original capacity: " << v.capacity() << std::endl;
  v.shrink_to_fit();
  std::cout << "after shrinking: " << v.capacity() << std::endl;

  return 0;
}
