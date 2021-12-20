#include <iostream>
#include <vector>
#include <iterator>

int main(void){
  std::istream_iterator<int> it(std::cin), end;
  std::vector<int> v(it, end);


  for(int x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
