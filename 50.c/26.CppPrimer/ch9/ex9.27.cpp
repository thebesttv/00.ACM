#include <iostream>
#include <forward_list>

std::ostream & operator << (std::ostream &os,
    const std::forward_list<int> &fli){
  bool first = 1;
  for(int x : fli){
    if(first) first = 0;
    else os << " ";
    os << x;
  }
  return os;
}

int main(void){
  std::forward_list<int> fli;
  for(int x; std::cin >> x;){
    fli.push_front(x);
  }
  std::cout << "get: " << fli << std::endl;

  auto prev = fli.before_begin(), curr = fli.begin();
  while(curr != fli.end()){
    if(*curr & 1){
      curr = fli.erase_after(prev);
    }else{
      prev = curr++;
    }
  }

  std::cout << "after: " << fli << std::endl;

  return 0;
}
