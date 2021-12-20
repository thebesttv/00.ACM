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
  std::vector<int> v{3,1,4,1,5,9,2,6}, v2;
  std::cout << "ori: " << v << std::endl;
  auto it = std::back_inserter(v2);
  std::replace_copy(v.begin(), v.end(), it, 1, 1024);
  std::cout << "res:\n"
            << "  v:  " << v << std::endl
            << "  v2: " << v2 << std::endl;

  return 0;
}
