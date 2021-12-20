#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v;
  for(int i=0;i<20;++i)
    v.push_back(i);
  auto it = v.begin();
  while(it != v.end()){
    if((*it)&1)
      it = v.erase(it);
    else
      ++it;
  }
  for(int x : v)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
