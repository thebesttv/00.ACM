#include <iostream>
#include <vector>

std::vector<int>::iterator find(std::vector<int>::iterator begin,
    std::vector<int>::iterator end, int v){
  while(begin != end){
    if(*begin == v) break;
    ++begin;
  }
  return begin;
}

int main(void){
  srand(time(NULL));
  int n = 10;
  std::vector<int> v(n);
  for(int i=0;i<n;++i) v[i] = rand()%10;

  int x = rand()%10;
  std::vector<int>::iterator it = find(v.begin(), v.end(), x);
  if(it != v.end()){
    std::cout << "found " << x << " at v[" << v.end() - it << "]" << std::endl;
  }else{
    std::cout << "couldn't find " << x << " in v" << std::endl;
  }

  return 0;
}
