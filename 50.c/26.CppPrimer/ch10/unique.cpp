#include <iostream>
#include <vector>
#include <algorithm>

void elimDups(std::vector<int> &v){
  std::sort(v.begin(), v.end());
  auto it = std::unique(v.begin(), v.end());
  v.erase(it, v.end());
}

int main(void){
  int x;
  std::vector<int> v;
  while(std::cin >> x) v.push_back(x);
  elimDups(v);
  for(int x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
