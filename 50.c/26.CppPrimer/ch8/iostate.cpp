#include <iostream>

void checkState(std::istream &s){
  std::cout << "start checking state:" << std::endl;
  std::iostream::iostate st = s.rdstate();

  if((st & std::iostream::badbit) == std::iostream::badbit)
    std::cout << "  badbit" << std::endl;
  if((st & std::iostream::failbit) == std::iostream::failbit)
    std::cout << "  failbit" << std::endl;
  if((st & std::iostream::eofbit) == std::iostream::eofbit)
    std::cout << "  eofbit" << std::endl;
  if((st & std::iostream::goodbit) == std::iostream::goodbit)
    std::cout << "  goodbit" << std::endl;
}

int main(void){
  checkState(std::cin);
  int x, sum=0;
  while(std::cin >> x){
    checkState(std::cin);
    sum += x;
  }
  std::cout << "sum: " << sum << std::endl;
  checkState(std::cin);

  return 0;
}
