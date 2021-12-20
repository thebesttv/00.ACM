#include <iostream>
#include <vector>
#include <list>
#include <string>

int main(void){
  std::list<const char *> li {"word1", "word 2", "w o r d threeeee" };
  std::vector<std::string> v(li.begin(), li.end());
  for(auto &s : v){
    std::cout << s << std::endl;
  }

  return 0;
}
