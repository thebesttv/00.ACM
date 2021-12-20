#include <iostream>
#include <string>
#include <fstream>

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data{
  private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

  public:
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
      bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &in){
      read(in, *this);
    }

    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data &);
    inline double avg_price() const;

  friend Sales_data add(const Sales_data&, const Sales_data&);
  friend std::ostream &print(std::ostream&, const Sales_data&);
  friend std::istream &read(std::istream&, Sales_data&);
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price() const {
  if(units_sold){
    return revenue / units_sold;
  }else{
    return 0;
  }
}

Sales_data& Sales_data::combine(const Sales_data &r){
  units_sold += r.units_sold;
  revenue += r.revenue;
  return *this;
}

std::istream &read(std::istream &is, Sales_data &item){
  double price = 0;
  is >> item.bookNo >> item.units_sold >> price;
  item.revenue = price * item.units_sold;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item){
  os << "isbn: " + item.isbn() << ", " << "sold: " << item.units_sold
    << ", revenue: " << item.revenue << ", avg: " << item.avg_price();
  return os;
}

Sales_data add(const Sales_data &l, const Sales_data &r){
  Sales_data sum = l;
  sum.combine(r);
  return sum;
}

int main(int argc, char *argv[]){
  std::ifstream input(argv[1]);
  std::ofstream output(argv[2]);

  Sales_data total;
  if(read(input, total)){
    Sales_data trans;
    while(read(input, trans)){
      if(total.isbn() == trans.isbn()){
        total.combine(trans);
      }else{
        print(output, total) << std::endl;
        total = trans;
      }
    }
    print(output, total) << std::endl;
  }else{
    std::cerr << "No data!" << std::endl;
    return -1;
  }
  return 0;
}
