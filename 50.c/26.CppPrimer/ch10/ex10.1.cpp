#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

int main(void){
  int x, val;
  std::cin >> val; std::cin.get();
  std::vector<int> v;
  std::string line;
  getline(std::cin, line);
  std::string::size_type pos = 0, offset = 0;
  while(pos < line.size()){
    //while(!isdigit(line[pos])) ++pos;
    int t = stoi(line.substr(pos), &offset);
    v.push_back(t); pos += offset;
  }
  auto cnt = count(v.begin(), v.end(), val);
  std::cout << "val " << val << " appears " << cnt << " time(s)" << std::endl;

  return 0;
}

/*
int main(void){
  std::vector<int> v;
  int x,val; std::cin >> val;
  while(std::cin >> x)
    v.push_back(x);
  auto cnt = count(v.begin(), v.end(), val);
  std::cout << "val " << val << " appears " << cnt << " time(s)" << std::endl;

  return 0;
}
*/
