#include <iostream>

void fun(){
  static int cnt = 0;
  std::cout << cnt++ << std::endl;
}
int main(void){
  for(int i=0;i<10;++i) fun();

  return 0;
}
