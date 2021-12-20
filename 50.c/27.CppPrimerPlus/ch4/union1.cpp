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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

struct widget{
  char brand[20];
  int type;
  union Id{
    long id_num;
    char id_char[20];
  }id;
  void print(){
    cout << "widget: " << brand;
    if(type==1){
      cout << ", 1: " << id.id_num << endl;
    }else{
      cout << ", 2: " << id.id_char << endl;
    }
  }
};

int main(void){
  widget prize;
  strcpy(prize.brand,"lala A");
  prize.type=1;
  prize.id.id_num=1234567;
  prize.print();

  prize.type=2;
  strcpy(prize.id.id_char,"lalala");
  prize.print();

  return 0;
}

