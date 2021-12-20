#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo{
  std::string name;
  std::vector<std::string> phones;
};

std::ostream & operator << (std::ostream &out, const PersonInfo &p) {
  std::cout << p.name << ": ";
  bool first = 1;
  for(const auto &s : p.phones){
    if(first) first = 0;
    else out << ", ";
    out << s;
  }
  return out;
}

int main(void){
  std::string line, word;
  std::vector<PersonInfo> people;

  while(getline(std::cin, line)){
    PersonInfo t;
    std::istringstream ss(line);
    ss >> t.name;
    while(ss >> word){
      t.phones.push_back(word);
    }
    people.push_back(t);
  }
  
  for(int i=0;i<people.size();++i){
    std::cout << "Person #" << i << ":\n"
              << people[i] << std::endl;
  }

  return 0;
}
