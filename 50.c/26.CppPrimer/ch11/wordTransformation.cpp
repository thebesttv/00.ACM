#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

std::map<std::string, std::string> buildMap(std::ifstream &in){
  std::string a, b;
  std::map<std::string, std::string> mp;
  //while(in >> a && in >> b){
  while(in >> a && getline(in,b)){
    if(b.size()>1) mp.insert({a,b.substr(1)});
  }
  return mp;
}

std::string transform(const std::string s, std::map<std::string, std::string> &mp){
  if(mp.find(s) != mp.end()) return mp[s];
  else return s;
}

void wordTransform(std::ifstream &map_file, std::ifstream &in){
  auto trans_map = buildMap(map_file);
  std::string line;
  while(getline(in, line)){
    std::istringstream ss(line);
    std::string word;
    bool first = 1;
    while(ss >> word){
      if(first) first = 0;
      else std::cout << " ";
      std::cout << transform(word, trans_map);
    }
    std::cout << std::endl;
  }
}

int main(int argc, char *argv[]){
  std::ifstream map_file(argv[1]);
  std::ifstream in(argv[2]);
  wordTransform(map_file, in);
  return 0;
}
