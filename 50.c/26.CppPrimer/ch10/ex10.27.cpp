#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <algorithm>

int main(void){
  std::vector<int> v;
  std::list<int> li;
  int x;

  while(std::cin >> x)
    v.push_back(x);
  std::sort(v.begin(), v.end());
  std::unique_copy(v.begin(), v.end(), std::back_inserter(li));
  for(int x : li){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
