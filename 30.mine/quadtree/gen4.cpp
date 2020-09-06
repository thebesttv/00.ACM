// Tag: 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;


const int LENGTH = 200;
const int HEIGHT = 2*LENGTH;
const int WIDTH = LENGTH;

enum Color{ white = 0, black = 1 };

double dis(int x1, int y1, int x2, int y2){
  x1 -= x2, y1 -= y2;
  return sqrt(x1*x1 + y1*y1);
}

struct Character{
  int G[HEIGHT+2][WIDTH+2];

  Character() { init(); }
  Character(char c) { draw(c); }
  void init(Color c = white){
    FOR(i,0,HEIGHT) FOR(j,0,WIDTH)
      G[i][j]=c;
  }

  void circle(double px, double py, double pr, int c){
    int x = px * LENGTH, y = py * LENGTH, r = pr * LENGTH;
    FOR(i,0,HEIGHT) FOR(j,0,WIDTH){
      if(dis(i,j,x,y)<=r) G[i][j]=c;
    }
  }
  void rCircle(double px, double py, double pr, int c){
    int x = px * LENGTH, y = py * LENGTH, r = pr * LENGTH;
    FOR(i,0,HEIGHT) FOR(j,0,WIDTH){
      if(dis(i,j,x,y)>r) G[i][j]=c;
    }
  }
  void midCircle(){
    circle(1.0, 0.5, 0.5, black);
    circle(1.0, 0.5, 0.4, white);
  }
  void emptyCircle(double px, double py, double pr){
    circle(px,py,pr,black);
    circle(px,py,pr-0.1,white);
  }

  void rect(double px1, double py1, double px2, double py2, double c){
    int x1 = px1 * LENGTH, y1 = py1 * LENGTH;
    int x2 = px2 * LENGTH, y2 = py2 * LENGTH;
    FORR(i,x1,x2) FORR(j,y1,y2) G[i][j]=c;
  }

  void para(double px1, double py1, double px2, double py2, double width, int c){
    // print to the right
    double x1 = px1 * LENGTH, y1 = py1 * LENGTH;
    double x2 = px2 * LENGTH, y2 = py2 * LENGTH;
    double a1 = y2 - y1, b1 = x1 - x2, c1 = x2*y1 - x1*y2;
    y1 = (py1 + width) * LENGTH, y2 = (py2 + width) * LENGTH;
    double a2 = y2 - y1, b2 = x1 - x2, c2 = x2*y1 - x1*y2;
    FORR(i,x1,x2) FOR(j,0,WIDTH){
      if(a1 * i + b1 * j + c1 < 0
       && a2 * i + b2 * j + c2 > 0)
        G[i][j] = c;
    }
  }

  void printLine(int i){
    FOR(j,0,WIDTH){
      printf("%d ",G[i][j]);
    }
  }
  void a(){
    midCircle();
    rect(1.0,0.9,1.5,1.0,black);
  }
  void b(){
    midCircle();
    rect(0.0,0.0,1.5,0.1,black);
  }
  void c(){
    midCircle();
    rect(0.75,0.5,1.25,1.0,white);
  }
  void d(){
    midCircle();
    rect(0.0,0.9,1.5,1.0,black);
  }
  void e(){
    midCircle();
    rect(1.,0.5,1.3,1.0,white);
    rect(0.95,0,1.05,1,black);
    rCircle(1.0, 0.5, 0.5,white);
  }
  void f(){
    emptyCircle(0.5,0.7,0.3);
    rect(0.0,0.75,1.5,1.0,white);
    rect(0.5,0.0,1.5,1.0,white);
    rect(0.5,0.4,1.5,0.5,black);
    rect(0.6,0.15,0.7,0.75,black);
  }
  void g(){
    circle(1.5, 0.5, 0.5, black);
    circle(1.5, 0.5, 0.4, white);
    rect(1.0,0.0,2.0,0.5, white);
    rect(1.0,0.5,1.5,1.0, white);
    rect(1.9,0.2,2.0,0.5, black);
    a();
  }
  void h(){
    midCircle();
    rect(1.0,0.0,2.0,1.0,white);
    rect(0.0,0.0,1.5,0.1,black);
    rect(1.0,0.9,1.5,1.0,black);
  }
  void i(){
    rect(0.5,0.45,1.5,0.55,black);
    circle(0.3,0.5,0.05,black);
  }
  void j(){
    circle(1.5,0.05,0.5,black);
    circle(1.5,0.05,0.4,white);
    rect(1.0,0.0,1.5,0.45,white);
    i();
  }
  void k(){
    rect(0.0,0.3,1.5,0.4,black);
    para(0.5,0.7,0.95,0.3,0.1,black);
    para(0.95,0.3,1.5,0.8,0.1,black);
  }
  void l(){
    rect(0.0,0.45,1.5,0.55,black);
  }
  void m(){
    circle(0.775,0.275,0.275,black);
    circle(0.775,0.275,0.175,white);
    circle(0.775,0.725,0.275,black);
    circle(0.775,0.725,0.175,white);
    rect(0.775,0.0,1.5,1.0,white);
    rect(0.775,0.0,1.5,0.1,black);
    rect(0.775,0.45,1.5,0.55,black);
    rect(0.775,0.9,1.5,1.0,black);
  }
  void n(){
    midCircle();
    rect(1.0,0.0,1.5,1.0,white);
    rect(1.0,0.0,1.5,0.1,black);
    rect(1.0,0.9,1.5,1.0,black);
  }
  void o(){
    midCircle();
  }
  void p(){
    midCircle();
    rect(1.0,0.0,2.0,0.1,black);
  }
  void q(){
    midCircle();
    rect(1.0,0.9,2.0,1.0,black);
  }
  void r(){
    circle(1.0,0.75,0.5,black);
    circle(1.0,0.75,0.4,white);
    rect(0.0,0.75,2.0,1.0,white);
    rect(1.0,0.0,2.0,1.0,white);
    rect(.55,0.25,1.5,0.35,black);
  }
  void s(){
    decltype(G) G2;
    emptyCircle(0.7,0.5,0.3);
    rect(0.7,0.51,1.0,1.0,white);
    memcpy(G2,G,sizeof(G));

    emptyCircle(1.2,0.5,0.3);
    rect(0.0,0.0,1.2,0.49,white);
    FOR(i,0,WIDTH) FOR(j,0,HEIGHT){
      G[i][j] = G2[i][j] || G[i][j];
    }
  }
  void t(){
    emptyCircle(1.2,0.7,0.3);
    rect(0.5,0.0,1.2,1.0,white);
    rect(0.3,0.4,1.2,0.5,black);
    rect(0.6,0.15,0.7,0.75,black);
  }
  void u(){
    n();
    reverse(G,G+HEIGHT);
  }
  void v(){
    para(0.5,0.0,1.5,0.45,0.1,black);
    para(0.5,0.9,1.5,0.45,0.1,black);
  }
  void w(){
    para(0.5,0.0,1.5,0.225,0.1,black);
    para(0.5,0.45,1.5,0.225,0.1,black);
    para(0.5,0.45,1.5,0.675,0.1,black);
    para(0.5,0.9,1.5,0.675,0.1,black);
  }
  void x(){
    para(0.5,0.0,1.5,0.88,0.12,black);
    para(0.5,0.88,1.5,0.0,0.12,black);
  }
  void y(){
    g();
    rect(0.0,0.0,1.0,1.0,white);
    rect(0.5,0.0,1.0,0.1,black);
    rect(0.5,0.9,1.0,1.0,black);
  }
  void z(){
    rect(0.5,0.0,0.6,1.0,black);
    rect(1.4,0.0,1.5,1.0,black);
    para(0.6,0.88,1.4,0.0,0.12,black);
  }
  void draw(char ch){
    init();
    switch(ch){
      case 'a': case 'A': a(); break;
      case 'b': case 'B': b(); break;
      case 'c': case 'C': c(); break;
      case 'd': case 'D': d(); break;
      case 'e': case 'E': e(); break;
      case 'f': case 'F': f(); break;
      case 'g': case 'G': g(); break;
      case 'h': case 'H': h(); break;
      case 'i': case 'I': i(); break;
      case 'j': case 'J': j(); break;
      case 'k': case 'K': k(); break;
      case 'l': case 'L': l(); break;
      case 'm': case 'M': m(); break;
      case 'n': case 'N': n(); break;
      case 'o': case 'O': o(); break;
      case 'p': case 'P': p(); break;
      case 'q': case 'Q': q(); break;
      case 'r': case 'R': r(); break;
      case 's': case 'S': s(); break;
      case 't': case 'T': t(); break;
      case 'u': case 'U': u(); break;
      case 'v': case 'V': v(); break;
      case 'w': case 'W': w(); break;
      case 'x': case 'X': x(); break;
      case 'y': case 'Y': y(); break;
      case 'z': case 'Z': z(); break;
      default: ;
    }
  }
};

VR<pii> vec;

struct Canvas{
  const int PADDING = LENGTH;
  const int GAP = LENGTH * 0.1;
  VR<Character> v;

  Canvas();
  Canvas(string s){
    for(char c : s) v.push_back(Character(c));
  }

  void print(){
    int h = PADDING * 2 + HEIGHT;
    int w = PADDING * 2 + v.size()*(GAP+WIDTH) - GAP;
    int x = 0, y = 0;

    FOR(i,0,HEIGHT){
      ++x; y = 0;
      FOR(j,0,PADDING) ++y;

      FOR(j,0,v.size()){
        if(j) FOR(k,0,GAP) ++y;
        FOR(k,0,WIDTH){
          if(v[j].G[i][k]){
            vec.push_back({y,-x});
          }
          ++y;
        }
      }
    }
  }
  void push_back(Character &c){
    v.push_back(c);
  }
};

const int RNG = 2e3;

double _get() { return 1.0 * rand() / RAND_MAX; }
int get(int x = RNG){
  x = _get() * x;
  if(_get() > 0.5) x = -x;
  return x;
}

int main(void){
  srand(1206817542);
  string s("uryyb, TE PE");
  for(auto &c : s){
    if(isupper(c))      c = (c-'A'+13)%26+'A';
    else if(islower(c)) c = (c-'a'+13)%26+'a';
  }
  Canvas cv(s);
  cv.print();
  int n = 1e5;
  printf("%d\n",n);
  for(auto p : vec){
    printf("add %d %d\n",p.FI,p.SE); --n;
  }
  while(n--){
    int x1 = get(), y1 = get();
    int x2 = get(), y2 = get();
    if(x1 > x2) swap(x1,x2);
    if(y1 > y2) swap(y1,y2);
    printf("query %d %d %d %d\n",x1,y1,x2,y2);
  }
}
