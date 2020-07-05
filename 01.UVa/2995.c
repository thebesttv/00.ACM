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

const int MAX=12;
int n;
int a[MAX][MAX][MAX];
int view[6][MAX][MAX];

int get_color(){
  int ch;
  do ch=getchar(); while(!(isalpha(ch) || ch=='.'));
  return ch;
}

void get(int k, int i, int j, int p, int &x, int &y, int &z){
  if(k==0)      x = i, y = j, z = p;
  else if(k==1) x = i, y = p, z = n-1-j;
  else if(k==2) x = i, y = n-1-j, z = n-1-p;
  else if(k==3) x = i, y = n-1-p, z = j;
  else if(k==4) x = p, y = j, z = n-1-i;
  else          x = n-1-p, y = j, z = i;
  
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) FOR(j,0,n) FOR(k,0,n) a[i][j][k]='#';  // init all blocks as full & without color
    FOR(i,0,n) FOR(k,0,6) FOR(j,0,n){
      int ch=get_color();   // get view color
      view[k][i][j]=ch;
      if(ch=='.') FOR(p,0,n){ // if see through, then delete all related blocks
        int x,y,z; get(k,i,j,p,x,y,z);
        a[x][y][z]='.';
      }
    }

    while(1){ // loop, as long as one block was deleated the last time
      bool done=1; int x,y,z;
      FOR(k,0,6) FOR(i,0,n) FOR(j,0,n) if(view[k][i][j]!='.')  // for all non-empty views
        FOR(p,0,n){ //<b> from shallow to deep, break as soon as needed </b>
          get(k,i,j,p,x,y,z);
          int &color = a[x][y][z];
          // 4 possibilities: empty, no color, wrong color, right color
          if(color=='.'){
            continue;
          }else if(color=='#'){
            color = view[k][i][j]; break;
          }else if(color!=view[k][i][j]){
            color='.'; done=0; continue;  // go deeper
          }else break;
        }

      if(done) break;
    }

    int cnt=0;
    FOR(i,0,n) FOR(j,0,n) FOR(k,0,n)
      if(a[i][j][k]!='.') cnt++;
    printf("Maximum weight: %d gram(s)\n",cnt);
  }

  return 0;
}
