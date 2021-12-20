#include <iostream>
#include <list>
#include <string>

int main(void){
  std::list<std::string> q;
  std::string word;
  while(std::cin >> word){
    q.push_back(word);
  }
  //for(std::deque<std::string>::iterator it;
  for(auto it = q.begin(); it != q.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;

  return 0;
}
