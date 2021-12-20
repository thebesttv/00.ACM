#include <iostream>
#include <vector>

struct Node{
  int a,b,c;
  Node(int a, int b, int c): a(a), b(b), c(c) { }
};

std::ostream & operator << (std::ostream &os, const Node &b){
  return os << b.a << " " << b.b << " " << b.c;
}

int main(void){
  std::vector<Node> v;
  v.emplace_back(1,2,3);
  v.emplace_back(3,4,5);

  for(const auto &x : v){
    std::cout << x << std::endl;
  }

  return 0;
}

/*
int main(void){
  std::vector<int> v;
  v.emplace_back(10);
  v.emplace_back(20);

  for(auto x : v){
    std::cout << x << " ";
  }
  std::cout << std::endl;

  return 0;
}
*/
