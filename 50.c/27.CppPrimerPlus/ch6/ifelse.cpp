#include <iostream>
int main(void){
  char ch;
  std::cout << "Type, and I shall repead.\n";
  std::cin.get(ch);
  while (ch != '.'){
    if (ch == '\n')
      std::cout << ch;
    else
      //std::cout << ch+1;  // 1 is int, ch + 1 -> int
      std::cout << ++ch;
    std::cin.get(ch);
  }
  std::cout << "\nPlease excuse the slight confusion.\n";
  return 0;
}
