#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

int main(void){
  std::istream_iterator<int> it(std::cin), eof;
  std::cout << std::accumulate(it, eof, 0) << std::endl;

  return 0;
}
