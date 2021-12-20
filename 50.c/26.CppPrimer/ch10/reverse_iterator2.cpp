#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
  std::vector<int> v{3,1,4,1,5,9,2,6};

  std::sort(v.begin(), v.end());
  std::cout << "sort:";
  for(int x : v) std::cout << " " << x; std::cout << std::endl;

  std::sort(v.rbegin(), v.rend());
  std::cout << "sort reverse:";
  for(int x : v) std::cout << " " << x; std::cout << std::endl;

  return 0;
}
