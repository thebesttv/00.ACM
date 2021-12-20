#include <iostream>
#include <new>
#include <thread>
#include <chrono>

int main(void){
  const int MAX=1e4;
  try{
    auto p1 = new int [MAX][MAX][MAX];
  }catch(std::bad_alloc &ba){
    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
  }
  auto p2 = new (std::nothrow) int [MAX][MAX][MAX];

  return 0;
}
