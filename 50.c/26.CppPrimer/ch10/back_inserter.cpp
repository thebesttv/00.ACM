#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(void){
  std::vector<int> v;
  auto it = std::back_inserter(v);
  std::fill_n(it, 10, 1024);
  for(int x : v)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
