#include <iostream>
#include <vector>

std::vector<int>* getVector(){
  auto p ( new std::vector<int> );
  return p;
}
void get(std::vector<int>* p){
  int x;
  while(std::cin >> x)
    p->push_back(x);
}
void print(std::vector<int> *p){
  for(int x : *p){
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main(void){
  auto p = getVector();
  get(p);
  print(p);
  delete p;

  return 0;
}
