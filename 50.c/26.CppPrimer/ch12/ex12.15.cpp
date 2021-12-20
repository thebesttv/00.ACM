#include <memory>

struct Destionation{
  int a;
};
struct Connection{
  int a;
};

Connection connect(Destionation *);
void disconnect(Connection);

void end_connection(Connection *p){
  disconnect(*p);
}

void f(Destionation &d){
  Connection c = connect(&d);
  std::shared_ptr<Connection> p(&c,
      [](Connection *p) -> void {
        disconnect(*p);
      });
}
