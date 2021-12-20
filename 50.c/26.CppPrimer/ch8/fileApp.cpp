#include <iostream>
#include <fstream>

int main(void){
  std::ofstream out("file1", std::ios_base::app);
  //std::ofstream out("file1", std::ofstream::app);
  //std::ofstream out("file1", std::ofstream::out | std::ofstream::app);
  out << "Written at time " << time(NULL) << std::endl;
  out.close();

  return 0;
}
