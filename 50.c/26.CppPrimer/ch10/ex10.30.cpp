#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main(void){
  std::istream_iterator<int> inIt(std::cin), eof;
  std::ostream_iterator<int> outIt(std::cout, " ");
  std::vector<int> v(inIt, eof);
  std::sort(v.begin(), v.end());
  std::unique_copy(v.begin(), v.end(), outIt);
  std::cout << std::endl;

  return 0;
}
