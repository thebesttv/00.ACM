#include <iostream>
#include <stdexcept>

std::istream &get(std::istream &in){
  std::cout << "enter function get()" << std::endl;
  if(in.fail()){
    std::cout << "stream already failed!" << std::endl;
  }else{
    std::cout << "stream good, start reading:" << std::endl;
    int v;
    while(in >> v, !in.eof()){
      if(in.bad()){
        throw std::runtime_error("hit badbit");
      }
      if(in.fail()){
        std::cerr << "wrong input, try again" << std::endl;
        in.clear(); in.ignore(10024,'\n');
        continue;
      }
      std::cout << "get: " << v << std::endl;
    }
    std::cout << "hit end of file" << std::endl;
  }
  in.clear();
  std::cout << "reset stream state" << std::endl;
  return in;
}

int main(void){
  get(std::cin);

  return 0;
}
