#include <iostream>
#include <map>

int main(void){
  std::map<int, int> mp { {1, 1024},
                          {2, 2048},
                          {3, 4096},
                          {4, 8192} };
  for(const auto &w : mp)
    std::cout << w.first << " -> " << w.second << std::endl;

  return 0;
}
