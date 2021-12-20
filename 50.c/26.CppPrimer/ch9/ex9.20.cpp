#include <iostream>
#include <deque>
#include <list>

std::ostream & operator << (std::ostream &os, const std::deque<int> q){
  bool first = 1;
  for(auto x : q){
    if(first) first = 0;
    else os << " ";
    os << x;
  }
  return os;
}
int main(void){
  std::list<int> li;
  std::deque<int> even, odd;
  for(int x; std::cin >> x;){
    li.push_back(x);
  }
  int st = 0;
  for(auto it = li.begin(); it != li.end(); ++it, st^=1){
    if(st) odd.push_back(*it);
    else even.push_back(*it);
  }
  std::cout << "odd:  " << odd << std::endl
            << "even: " << even << std::endl;

  return 0;
}
