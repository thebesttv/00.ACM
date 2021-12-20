#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main(void){
  std::multimap<std::string, std::string> mp;
  int n, m; std::string a, b;
  std::cin >> n >> m;
  while(n--){
    std::cin >> a >> b;
    mp.insert({a,b});
  }
  while(m--){
    std::cin >> a;
    auto w = mp.equal_range(a);
    mp.erase(w.first, w.second);
  }
  for(const auto &p : mp){
    std::cout << p.first << " " << p.second << std::endl;
  }

  return 0;
}
