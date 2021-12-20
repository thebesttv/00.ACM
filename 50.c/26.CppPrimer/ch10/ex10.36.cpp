#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
  std::vector<int> v{1,2,0,23,4,32,4,23,3,0,3,1,4};
  auto it = std::find(v.rbegin(), v.rend(), 0);
  auto pos = it.base() - v.begin() - 1;
  std::cout << "find " << v[pos] << " at position " << pos << std::endl;

  return 0;
}
