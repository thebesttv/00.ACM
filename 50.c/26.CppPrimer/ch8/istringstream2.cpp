#include <iostream>
#include <sstream>

int main(void){
  std::string line;
  getline(std::cin, line);

  std::istringstream ss;
  ss.str(line);

  int x;

  while(ss >> x){
    std::cout << x << std::endl;
  }
  std::cout << "Finished writing the numbers in : "
            << ss.str() << std::endl;

  return 0;
}
