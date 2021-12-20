#include <iostream>
#include <stdexcept>

std::istream &f(std::istream &in){
  int v;
  while(in >> v, !in.eof()){
    if(in.bad()){
      throw std::runtime_error("IO流错误");
    }
    if(in.fail()){
      std::cerr << "wrong input, try again" << std::endl;
      in.clear();
      in.ignore(1024, '\n');
      // std::istrea::ignore:
      // istream &ignore(streamsize n = 1, int delim = EOF);
      // Extracts characters from the input sequence and discards them, until
      //   either n characters have been extracted, or one compares equal to delim.
      //   Note that delim is extracted stream and discarded.
      continue;
    }
    std::cout << "get: " << v << std::endl;
  }
  in.clear();
  return in;
}

int main(void){
  f(std::cin);
  return 0;
}
