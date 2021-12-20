#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &v){
  std::sort(v.begin(), v.end());
  auto it = std::unique(v.begin(), v.end());
  v.erase(it, v.end());
}

bool isShorter(const std::string &s1, const std::string &s2){
  return s1.size() < s2.size();
}

int main(void){
  std::string x;
  std::vector<std::string> v;
  while(std::cin >> x) v.push_back(x);

  elimDups(v);

  std::stable_sort(v.begin(), v.end(), isShorter);

  for(const auto &x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
