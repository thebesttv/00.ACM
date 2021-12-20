#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v{0,1,2,3,4,5,6,7};
  for(auto it = v.rbegin(); it != v.rend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
