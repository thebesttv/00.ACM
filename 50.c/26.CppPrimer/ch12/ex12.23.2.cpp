#include <iostream>
#include <string>
#include <memory>

char *concat(const std::string &s1, const std::string &s2){
  char *p = new char [s1.size()+s2.size()+1];
  char *t = p;
  for(char c : s1) *t++ = c;
  for(char c : s2) *t++ = c;
  *t = '\0';
  return p;
}

int main(void){
  std::string s1("Hello,");
  std::string s2(" World!");
  char *p = concat(s1,s2);
  std::cout << p << std::endl;
  delete [] p;

  return 0;
}
