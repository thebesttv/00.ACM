#include <iostream>
#include <string>

class Person{
  private:
    std::string strName, strAddress;

  public:
    Person() = default;
    Person(std::string sn, std::string sa):
      strName(sn), strAddress(sa) { }
    Person(std::istream &in){
      in >> strName >> strAddress;
    }

    std::string &name(){
      return strName;
    }
    std::string &address(){
      return strAddress;
    }
};

std::istream &read(std::istream &in, Person &p){
  return in >> p.name() >> p.address();
}

std::ostream &print(std::ostream &out, Person &p){
  return out << "name: " << p.name() << ", address: " << p.address();
}
