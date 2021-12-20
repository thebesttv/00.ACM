#include <iostream>
#include <string>

int main(void){
  std::string s, ans;
  bool first = 1;
  while(std::cin >> s){
    if(first) first = 0;
    else ans += " ";
    ans += s;
  }
  std::cout << ans << std::endl;

  return 0;
}
