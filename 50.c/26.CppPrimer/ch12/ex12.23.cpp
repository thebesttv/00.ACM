#include <iostream>
#include <cstring>
#include <memory>

char *concat(const char *s1, const char *s2){
  int len1 = strlen(s1), len2 = strlen(s2);
  char *p = new char [len1+len2+1];
  char *t = p;
  while(*s1) *t++ = *s1++;
  while(*s2) *t++ = *s2++;
  *t = '\0';
  return p;
}

int main(void){
  const char *s1 = "Hello,";
  const char *s2 = " World!";
  char *p = concat(s1,s2);
  std::cout << p << std::endl;
  delete [] p;

  return 0;
}
