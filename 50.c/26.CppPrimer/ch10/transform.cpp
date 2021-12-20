#include <iostream>
#include <vector>
#include <algorithm>

int main(void){
  std::vector<int> v{1,-1,2,-2,3,-3,4,-4}, v2;
  auto it = std::back_inserter(v2);
  //std::transform(v.begin(), v.end(), it,
  //    [](int i) { return i < 0 ? -i : i; });
  std::transform(v.begin(), v.end(), it,
      [](int i) -> int {
        if (i >= 0) return i;
        else return -i;
      });
  for(int x : v2){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
