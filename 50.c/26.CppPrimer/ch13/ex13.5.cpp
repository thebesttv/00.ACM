#include <string>

class HasPtr{
public:
  HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
  HasPtr(HasPtr &a): i(a.i) {
    ps = new std::string(*a.ps);
  }
  HasPtr & operator = (const HasPtr &a) {
    delete ps;
    ps = new std::string(*a.ps);
    i = a.i;
    return *this;
  }

private:
  std::string *ps;
  int i;
};

int main(void){
  return 0;
}
