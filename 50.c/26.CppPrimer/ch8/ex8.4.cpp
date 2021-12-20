#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char **argv){
  std::ifstream in(argv[1]);
  if(!in){
    std::cerr << "unable to open file\n";
    return -1;
  }
  std::vector<std::string> v;
  std::string line;
  while(getline(in,line)){
    v.push_back(line);
    //std::cout << "Line " << ++lineNum << ": " << line << std::endl;
  }
  in.close();

  int lineNum=0;
  auto it = v.begin();
  while(it != v.end()){
    std::cout << "Line " << ++lineNum << ": " << *it++ << std::endl;
  }

  return 0;
}
