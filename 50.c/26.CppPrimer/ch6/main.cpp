#include <iostream>

int main(int argc, char *argv[]){
  // argv: array of pointers to the first index of a C-style string
  std::cout << "argc: " << argc << std::endl;
  for(int i=0;i<argc;++i)
    std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
}
