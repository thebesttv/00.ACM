#include <iostream>
#include <vector>

int main(void){
  std::vector<int> v;
  int x; auto it = v.begin();
  while(std::cin >> x){
    //it = v.insert(it, x);
    v.insert(it, x);

    std::cout << "v:";
    for(int x : v){
      std::cout << " " << x;
    }
    std::cout << std::endl;
  }

  return 0;
}
