#include <iostream>
#include <fstream>

int main(void){
  std::ofstream out("file1");
  //std::ofstream out("file1", std::ofstream::trunc);
  //std::ofstream out("file1", std::ofstream::out | std::ofstream::trunc);
  out << "Written at time " << time(NULL) << std::endl;
  out.close();

  return 0;
}
