#include <iostream>
#include <string>
#include <memory>

int main(void){
  int n = 20;
  std::allocator<std::string> a;
  std::string * const p = a.allocate(n);
  std::string s, *q = p;
  while(std::cin >> s && q != p+n){
    a.construct(q++, s);
  }
  const size_t size = q - p;

  for(size_t i = 0; i < size; ++i){
    std::cout << p[i] << std::endl;
  }

  // for(size_t i = 0; i < size; ++i){
  //   a.destroy(p + i);
  // }
  while(q != p){
    a.destroy(--q);
  }
  a.deallocate(p, n);

  return 0;
}
