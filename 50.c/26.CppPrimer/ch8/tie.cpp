#include <iostream>
#include <fstream>

int main(void){
  std::ofstream ofs("tie.txt");

  std::cout << "tie example" << std::endl;

  *std::cin.tie() << "This is inserted into cout." << std::endl;
  auto prevstr = std::cin.tie(&ofs);
  *std::cin.tie() << "This is inserted into the file." << std::endl;
  std::cin.tie(prevstr);

  ofs.close();

  return 0;
}
