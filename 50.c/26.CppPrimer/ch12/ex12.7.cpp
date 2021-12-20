#include <iostream>
#include <vector>
#include <memory>

typedef std::shared_ptr<std::vector<int>> Ptr;

Ptr getVector(){
  return std::make_shared<std::vector<int>>();
}
void get(Ptr p){
  int x;
  while(std::cin >> x)
    p->push_back(x);
}
void print(Ptr p){
  for(int x : *p){
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(void){
  auto p = getVector();
  get(p);
  print(p);

  return 0;
}
