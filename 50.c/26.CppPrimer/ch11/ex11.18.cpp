#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <sstream>
#include <utility>
#include <algorithm>

int main(void){
  std::set<std::string> exclude {"the", "but", "and", "or", "an", "a"};
  std::map<std::string, std::list<int>> mp;
  std::string token, line;

  int lineNum = 0;
  while(getline(std::cin, line)){
    ++lineNum;
    std::istringstream in(line);
    while(in >> token){
      std::string word;
      std::for_each(token.begin(), token.end(),
          [&word](const char c){
          if(isalpha(c))
          word.push_back(tolower(c));
          });

      if(exclude.find(word) == exclude.end()){
        mp[word].push_back(lineNum);
      }
    }
  }

  auto it = mp.cbegin();
  //std::map<std::string, std::list<int>>::const_iterator it = mp.cbegin();
  while(it != mp.cend()){
    std::cout << it->first << " occures at";
    for(int x : it->second){
      std::cout << " " << x;
    }
    std::cout << std::endl;
    ++it;
  }

  return 0;
}
