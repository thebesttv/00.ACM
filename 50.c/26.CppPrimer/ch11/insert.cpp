#include <iostream>
#include <map>
#include <string>

int main(void){
  std::map<std::string, size_t> mp;
  std::string word;
  while(std::cin >> word){
    /*
    auto res = mp.insert({word,1});
    if(!res.second){
      ++ res.first->second;
    }
    */
    ++mp.insert({word,0}).first->second;
  }
  for(const auto &p : mp){
    std::cout << p.first << " occures " << p.second << " time(s)" << std::endl;
  }

  return 0;
}
