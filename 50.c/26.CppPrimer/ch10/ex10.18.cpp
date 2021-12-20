#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void elimDups(std::vector<std::string> &v){
  std::sort(v.begin(), v.end());
  auto vend = std::unique(v.begin(), v.end());
  v.erase(vend, v.end());
}

void biggies(std::vector<std::string> &v,
    std::vector<std::string>::size_type sz){
  elimDups(v);
  auto it = partition(v.begin(), v.end(),
      [sz](const std::string &s){
        return s.size() >= sz;
      } );
  auto cnt = it - v.begin();
  auto make_plural = [](const std::string &s, int cnt) -> std::string {
    if(cnt>1) return s + "s";
    else return s;
  };
  std::cout << cnt << " " << make_plural("word",cnt) << " of length "
            << sz << " or longer" << std::endl;
  std::for_each(v.begin(), it,
      [](const std::string &s){
        std::cout << s << " ";
      });
  std::cout << std::endl;
}

int main(void){
  int sz; std::string s;
  std::vector<std::string> v;
  std::cin >> sz;
  while(std::cin >> s)
    v.push_back(s);
  biggies(v,sz);

  return 0;
}
