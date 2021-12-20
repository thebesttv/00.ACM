#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(void){
  std::string fileName("ex8.10.in");
  std::ifstream ifs(fileName);
  if(!ifs){
    std::cerr << "couldn't open data file " << fileName << std::endl;
    return -1;
  }

  std::string line, word;
  std::vector<std::string> v;
  while(getline(ifs, line)){
    v.push_back(line);
  }
  ifs.close();

  int lineNum = 0;
  std::istringstream is;
  for(const auto &line : v){
    is.str(line); is.clear();
    std::cout << "Line #" << ++lineNum << ":";
    while(is >> word){
      std::cout << " " + word;
    }
    std::cout << std::endl;
  }

  return 0;
}
