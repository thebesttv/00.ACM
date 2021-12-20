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

bool valid(const std::string &s){
  for(const char c : s)
    if(!isdigit(c)) return 0;
  return 1;
}
std::string format(const std::string &s){
  std::string res("$" + s + "$");
  return res;
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
  
  std::ostringstream os;
  for(const auto &entry : people){
    std::ostringstream out, badNum;
    for(const auto &num : entry.phones){
      if(!valid(num)){
        badNum << " " << num;
      }else{
        out << " " << format(num);
      }
    }
    if(badNum.str().empty()){
      os << entry.name << out.str() << std::endl;
    }else{
      std::cerr << "input error: " << entry.name
                << " invalid number:" << badNum.str() << std::endl;
    }
  }
  std::cout << os.str();

  return 0;
}
