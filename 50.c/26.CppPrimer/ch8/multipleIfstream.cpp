#include <iostream>
#include <fstream>
#include <string>

void print(std::ifstream &in){
  std::string line;
  while(getline(in,line))
    std::cout << line << "\n";
}

int main(int argc, char *argv[]){
  for(auto p = argv + 1; p != argv + argc; ++p){
    std::ifstream input(*p); // *p: pointer to char
    if(input){
      std::cout << "in file \"" << *p << "\":\n";
      print(input);
      std::cout << std::endl;
    }else{
      std::cerr << "couldn't open \"" << *p << "\"" << std::endl;
    }
  }
  return 0;
}
