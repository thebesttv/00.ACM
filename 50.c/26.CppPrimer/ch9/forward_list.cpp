#include <iostream>
#include <forward_list>

int main(void){
  std::forward_list<int> fli = {0,1,2,3,4,5,6,7,8,9};
  auto prev = fli.before_begin();
  auto curr = fli.begin();
  while(curr != fli.end()){
    if(*curr & 1){
      curr = fli.erase_after(prev);
    }else{
      prev = curr; ++curr;
    }
  }
  for(int x : fli)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
