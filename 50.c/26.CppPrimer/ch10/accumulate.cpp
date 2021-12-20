#include <iostream>
#include <numeric>
#include <vector>
#include <string>

int main(void){
  std::vector<std::string> v{"a","b","c","d"};
  std::string s = std::accumulate(v.begin(), v.end(), std::string(""));
  std::cout << s << std::endl;

  return 0;
}
