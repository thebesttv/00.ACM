#include <iostream>
#include <vector>
#include <string>
#include <utility>

int main(void){
  using p_si = std::pair<std::string, int>;
  std::vector<p_si> v;
  std::string s; int x;
  while(std::cin >> s >> x){
    v.push_back({s,x});
  }
  for(const auto &p : v){
    std::cout << "get: <" << p.first << ", " << p.second << ">" << std::endl;
  }

  return 0;
}
