#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

int main(void){
  std::istream_iterator<std::string> inIt(std::cin), eof;
  std::vector<std::string> v(inIt, eof);
  std::ostream_iterator<std::string> outIt(std::cout, " ");
  std::copy(v.begin(), v.end(), outIt);
  *outIt++ = "\n";
}
