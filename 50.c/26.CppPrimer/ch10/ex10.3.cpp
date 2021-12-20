#include <iostream>
#include <cstdlib>
#include <vector>
#include <numeric>

int main(void){
  srand(time(NULL));
  std::vector<int> v;
  for(int i=0;i<10;++i)
    v.push_back(rand()%1024);
  int sum = std::accumulate(v.begin(), v.end(), 0);
  std::cout << sum << std::endl;

  return 0;
}
