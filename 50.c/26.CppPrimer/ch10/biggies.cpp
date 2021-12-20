#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

void elimDups(std::vector<std::string> &v){
  std::sort(v.begin(), v.end());
  auto vend = std::unique(v.begin(), v.end());
  v.erase(vend, v.end());
}

bool isGreater(const std::string &s, int sz){
  return s.size() >= sz;
}

void biggies(std::vector<std::string> &v, std::vector<std::string>::size_type sz){
  elimDups(v);
  stable_sort(v.begin(), v.end(),
      [](const std::string &a, const std::string &b){
        return a.size() < b.size();
      } );
  /*
  auto wc = find_if(v.begin(), v.end(),
      [sz](const std::string &s){
        return s.size() >= sz;
      } );
  */
  auto wc = find_if(v.begin(), v.end(),
      std::bind(isGreater, std::placeholders::_1, sz));

  auto cnt = v.end() - wc;
  std::cout << cnt << " word(s) of length " << sz << " or longer,"
            << " they are:" << std::endl;

  std::for_each(wc, v.end(),
      [](std::string &s){
        std::cout << s << " ";
      } );
  std::cout << std::endl;
}

int main(void){
  int sz; std::string s;
  std::vector<std::string> v;
  std::cin >> sz;
  while(std::cin >> s)
    v.push_back(s);
  biggies(v, sz);

  return 0;
}
