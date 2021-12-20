#include<list>
using namespace std;

const int MAX=100;
struct Edge{
  int v,w;
};
list<Edge> edge[MAX];

void addEdge(int u, int v, int w){
  edge[u].push_back((Edge){v,w}); //巧用类型转换
}

int main(void){


  return 0;
}
