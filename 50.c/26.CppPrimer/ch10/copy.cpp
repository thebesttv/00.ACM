#include <iostream>
#include <vector>
#include <algorithm>

// back inserter iterator
int main(void){
  int a[] = {123,2,32,32,3,13,213,43,432,2};
  std::vector<int> v;
  auto it = std::back_inserter(v);
  std::copy(std::begin(a), std::end(a), it);
  for(int x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}

/*
// normal iterator
int main(void){
  int a[] = {123,2,32,32,3,13,213,43,432,2};
  std::vector<int> v( sizeof(a) / sizeof(*a) );
  std::copy(std::begin(a), std::end(a), v.begin());
  for(int x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
*/
