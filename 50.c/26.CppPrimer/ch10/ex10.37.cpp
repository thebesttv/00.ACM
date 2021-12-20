#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

int main(void){
  std::vector<int> v{0,1,2,3,4,5,6,7,8,9};
  std::reverse_iterator<decltype(v.begin())> r(v.begin()+3);
  std::reverse_iterator<decltype(v.begin())> l(v.begin()+8);
  std::cout << "r points to " << *r << ", l points to " << *l << std::endl;

  std::list<int> li(l,r);
  for(int x : li)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
