#include <iostream>
#include <set>
#include <iterator>

int main(void){
  std::set<int> st;
  auto it = std::inserter(st,st.end());
  int x;
  while(std::cin >> x)
    *it++ = x;
  for(int x : st)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
