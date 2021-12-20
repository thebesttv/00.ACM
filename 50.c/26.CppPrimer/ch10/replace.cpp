#include <iostream>
#include <vector>
#include <algorithm>

std::ostream & operator << (std::ostream &os, std::vector<int> &v){
  bool first = 1;
  for(int x : v){
    if(first) first = 0;
    else os << " ";
    os << x;
  }
  return os;
}

int main(void){
  std::vector<int> v{3,1,4,1,5,9,2,6};
  std::cout << "ori: " << v << std::endl;
  std::replace(v.begin(), v.end(), 1, 1024);
  std::cout << "res: " << v << std::endl;

  return 0;
}
