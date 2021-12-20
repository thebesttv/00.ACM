#include <iostream>

int main(void){
  int a[5]={3,1,4,1,5};
  int (&b)[5] = a;
  for(auto i = std::begin(a); i != std::end(a); ++i)
    std::cout << *i << " ";
  std::cout << std::endl;
  for(auto i = std::begin(b); i != std::end(b); ++i)
    std::cout << *i << " ";
  std::cout << std::endl;

  b[0] = 1, b[1] = 2, b[2] = 3, b[3] = 4, b[4] = 5;
  for(auto i : a) printf("%d ",i); putchar('\n');

  return 0;
}
