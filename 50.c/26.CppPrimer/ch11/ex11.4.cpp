#include <iostream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

int main(void){
  std::set<std::string> exclude {"the", "but", "and", "or", "an", "a"};
  std::map<std::string, size_t> mp;
  std::string token;
  while(std::cin >> token){
    //std::for_each(word.begin(), word.end(),
    //    [](char &c) { c = tolower(c); } );  // hhhh
    std::string word;
    std::for_each(token.begin(), token.end(),
        [&word](const char c){
          if(isalpha(c))
            word.push_back(tolower(c));
        });
    if(exclude.find(word) == exclude.end()){
      ++mp[word];
    }
  }
  for(const auto &w : mp){
    std::cout << w.first << " occures " << w.second
              << std::string(" time") + ((w.second > 1) ? "s" : "") << std::endl;
  }

  return 0;
}
