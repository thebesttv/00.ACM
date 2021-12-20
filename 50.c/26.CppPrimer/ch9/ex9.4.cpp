#include <iostream>
#include <vector>

bool find(std::vector<int>::iterator begin,
    std::vector<int>::iterator end, int v){
  while(begin != end){
    if(*begin == v) return true;
    ++begin;
  }
  return false;
}

int main(void){
  srand(time(NULL));
  int n = 10;
  std::vector<int> v(n);
  for(int i=0;i<n;++i) v[i] = rand()%10;

  int x = rand()%10;
  if(find(v.begin(), v.end(), x)){
    std::cout << "found " << x << " in v" << std::endl;
  }else{
    std::cout << "couldn't find " << x << " in v" << std::endl;
  }

  return 0;
}
