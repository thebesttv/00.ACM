#include <string>
#include <vector>

int main(void){
  int *pi1 = new int(1024);
  int *pi2 = new int{1024};
  auto ps1 = new std::string(10,'2');
  auto ps2 = new std::string{"lalala"};
  auto pv = new std::vector<int>{0,1,2,3,4};
  auto p1 = new auto(std::string("lalala"));
  auto p2 = new auto(std::vector<int>{1,2});

  return 0;
}
