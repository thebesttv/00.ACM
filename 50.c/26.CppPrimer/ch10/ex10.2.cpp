#include <iostream>
#include <list>
#include <algorithm>

int main(void){
  std::list<int> li;
  int x,v; std::cin >> v;
  while(std::cin >> x)
    li.push_back(x);
  auto cnt = count(li.begin(), li.end(), v);
  std::cout << "val " << v << " appears " << cnt << " time(s)" << std::endl;

  return 0;
}
