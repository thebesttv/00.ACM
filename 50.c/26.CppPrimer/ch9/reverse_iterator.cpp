#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v;
  for(int i=0;i<10;++i) v.push_back(i);
  std::vector<int>::reverse_iterator it = v.rbegin();
  while(it != v.rend()){
    std::cout << *it++ << std::endl;
  }

  return 0;
}
