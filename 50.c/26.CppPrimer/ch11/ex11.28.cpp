#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

int main(void){
  std::map<std::string, std::vector<int>> mp;
  std::map<std::string, std::vector<int>>::iterator it;
  std::pair<const std::string, std::vector<int>> p;
  it = std::find(mp.begin(), mp.end(), p);

  return 0;
}
