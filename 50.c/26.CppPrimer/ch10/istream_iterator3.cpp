#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

int main(void){
  std::vector<int> v{3,1,4,1,5,9,2,6};
  std::ostream_iterator<int> it(std::cout, " ");
  std::copy(v.begin(), v.end(), it);
  std::cout << std::endl;

  return 0;
}
