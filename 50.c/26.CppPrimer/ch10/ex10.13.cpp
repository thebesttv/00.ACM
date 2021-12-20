#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool pred(const std::string &s){
  return s.size()>=5;
}

int main(void){
  std::string s;
  std::vector<std::string> v;
  while(std::cin >> s)
    v.push_back(s);
  auto pend = partition(v.begin(), v.end(), pred);
  for(auto it = v.begin(); it != pend; ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
