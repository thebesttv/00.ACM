#include <iostream>
#include <string>

int main(void){
  std::string s, oldVal, newVal;
  getline(std::cin, s);
  std::cin >> oldVal >> newVal;

  auto it = s.begin();
  while(it != s.end()){
    if(s.compare(it-s.begin(), oldVal.size(), oldVal)==0){
      it = s.erase(it, it + oldVal.size());
      //s.insert(it - s.begin(),newVal);
      it = s.insert(it, newVal.begin(), newVal.end());
      it += newVal.size();
    }else{
      ++it;
    }
    //std::cout << std::string(it, s.end()) << std::endl;
  }
  std::cout << s << std::endl;

  return 0;
}
