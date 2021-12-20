#include <iostream>
#include <forward_list>
#include <string>
#include <sstream>

std::ostream & operator << (std::ostream &os,
    const std::forward_list<std::string> &fli){
  bool first = 1;
  for(std::string x : fli){
    if(first) first = 0;
    else os << " ";
    os << x;
  }
  return os;
}

int main(void){
  std::forward_list<std::string> fli;
  std::string s1, s2, s, line;
  getline(std::cin, line);
  std::cin >> s1 >> s2;

  std::istringstream is(line);
  while(is >> s) fli.push_front(s);
  fli.reverse();

  std::cout << "get: " << fli << std::endl;
  std::cout << "s1: " + s1 << ", s2: " + s2 << std::endl;

  auto prev = fli.before_begin(), curr = fli.begin();
  while(curr != fli.end() && *curr != s1){
    prev = curr++;
  }

  if(curr == fli.end()) fli.insert_after(prev,s2);
  else fli.insert_after(curr,s2);
  std::cout << "res: " << fli << std::endl;

  return 0;
}
