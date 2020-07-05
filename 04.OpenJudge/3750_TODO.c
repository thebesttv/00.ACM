// MDZZ
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

const char warriorName[5][20] = {"dragon", "ninja", "iceman", "lion", "wolf" };
const int redOrder[] = {2,3,4,1,0};
const int blueOrder[] = {3,0,1,2,4};
int warriorElement[5], warriorForce[5];

int n,m,t;
int hour,totTime;

struct Warrior{
  int num, element, force, type;
  int pos;  // 0:n+1
  int flag; // Red:1, Blue:-1

  Warrior(int num, int type, int flag):
    num(num), element(warriorElement[type]), force(warriorForce[type]), type(type), flag(flag) {
      if(flag==1) pos=0;
      else pos=n+1;
    }
  void march(){
    if(pos!=0 && pos!=n+1){
      if(flag==1) city[pos].redW=NULL;
      else city[pos].blueW=NULL;
    }

    pos+=flag;
    if(type==2){  // iceman
      if(w.pos>0 || w.pos<n+1){
        pos+=flag;
        if(element>9) element-=9;
        else element=1;
      }
    }

    if(flag==1) city[pos].redW=this;
    else city[pos].blueW=this;
  }
  bool isDead(){
  }
};

struct City{
  int element, num;
  int flag; // Red:1, Blue:-1
  Warrior *redW,*blueW;
  
  void init(){
    if(num==0) flag=1;
    else if(num==n+1) flag=-1;
    else if(num&1) flag=1;
    else flag=-1;

    redW=blueW=NULL;
  }
  void produceE(){
    element++;
  }
  void reportMarch(){
    if(num==0 || num==n+1){
      if(//
    }else{
      FOR(i,0,2){
        Worrior *p;
        if(i==0) p=redW;
        else p=blueW;
        if(p){
          char *side = (p->flag)==1 ? "red" : "blue";
          printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",hour,side,warriorName[p->type],p->num,num,p->element,p->force);
        }
      }
    }
  }
}city[30];

struct HeadQuarter{
  int element,num,order[5];
  int nextW,flag;
  char name[10];
  VR<Warrior> v;

  void init(){
    element=m; num=0; nextW=0; v.clear();
  }
  void produceW(){
    int ord=order[nextW];
    if(element < warriorElement[ord]) return;
    element-=warriorElement[ord];

    v.push_back(Warrior(++num, ord, flag));
    printf("%03d:00 %s %s %d born\n", hour, name, warriorName[ord], num);

    nextW = (nextW+1)%5;
  }
  void report(){
    printf("%03d:50 %d elements in %s headquarter\n", hour, element, name);
  }
  void march(){
    for(Warrior w : v){
      if((w.flag==1 && w.pos==n+1)
      || (w.flag==-1 && w.pos==0)){
        // stay
      }else{
        w.march();
      }
    }
  }
  void deleteDead(){
  }
}red,blue;

int main(void){
  // init HeadQuarter
  memcpy(red.order,redOrder,SIZ(redOrder));
  red.flag=1; strcpy(red.name,"red");
  memcpy(blue.order,blueOrder,SIZ(blueOrder));
  blue.flag=-1; strcpy(blue.name,"blue");
  // init City num
  FOR(i,0,30) city[i].num=i;

  int T; scanf("%d",&T);
  FORR(kase,1,T){
#ifdef DEBUG
    printf("in kase %d\n",kase);
#endif
    scanf("%d%d%d",&m,&n,&t);
    FOR(i,0,5) scanf("%d",&warriorElement[i]);
    FOR(i,0,5) scanf("%d",&warriorForce[i]);

    red.init(), blue.init();
    FORR(i,0,n+1) city[i].init();

    printf("Case:%d\n",kase);
    hour=0, totTime=0;
    while(true){
#ifdef DEBUG
    printf("  hour %d\n",hour);
#endif
      //00
      red.produceW();
      blue.produceW();
      totTime+=10;
      if(totTime>=t) goto END;

      //10
      red.march(); blue.march();
      FORR(i,1,n) city[i].reportMarch();
      totTime+=10;
      if(totTime>=t) goto END;

      //20
      FORR(i,1,n) city[i].produceE();
      totTime+=10;
      if(totTime>=t) goto END;

      //30
      totTime+=10;
      if(totTime>=t) goto END;

      //40
      totTime+=10;
      if(totTime>=t) goto END;

      //50
      totTime+=10;
      red.report();
      blue.report();
      if(totTime>=t) goto END;

      hour++;
    }
END:
    1+1;
  }

  return 0;
}
