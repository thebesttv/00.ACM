#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=100020;
struct Node{
  int l,r;
  int n,ln,rn;
  bool operator < (const Node & b) const {return l!=b.l ? l<b.l : r<b.r;}
}rec[MAX<<1];
PQ<Node> q;
int n,tail,a[MAX];
bool ill[MAX<<1];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,1,n){
    Node t; t.l=a[i-1]; t.r=a[i];
    t.n=tail++; t.ln=t.n-1; t.rn=t.n+1;
    if(i==1) t.ln=-1; else if(i==n-1) t.rn=-1;
    rec[t.n]=t; q.push(t);
  }

  bool first=1; int cnt=0;
  while(!q.empty()){
    Node t=q.top(); q.pop();
    if(ill[t.n]) continue;
    if(!first) printf(" %d %d",t.l,t.r);
    else {printf("%d %d",t.l,t.r); first=0;}
    //cnt+=2; if(cnt==n) break;

    int n=t.n;
    ill[n]=1;
#ifdef DEBUG
    printf(" ***l: %d, r: %d, n: %d, ln: %d, rn: %d ***\n",rec[n].l,rec[n].r,n,rec[n].ln,rec[n].rn);
#endif
    /*
    t.n=tail++;
    ill[rec[n].ln]=1; ill[rec[n].rn]=1;
    t.l=rec[rec[n].ln].l; t.r=rec[rec[n].rn].r;
    t.ln=rec[rec[n].ln].ln;
    t.rn=rec[rec[n].rn].rn;
    rec[t.ln].rn=t.n; rec[t.rn].ln=t.n;
    rec[t.n]=t; q.push(t);
    */

    if(rec[n].ln==-1 || rec[n].rn==-1) t.n=-1;
    else t.n=tail++;

    if(rec[n].ln!=-1){
      ill[rec[n].ln]=1;
      t.l=rec[rec[n].ln].l;
      t.ln=rec[rec[n].ln].ln;
      if(t.ln!=-1){
        rec[t.ln].rn=t.n;
      }
    }
    if(rec[n].rn!=-1){
      ill[rec[n].rn]=1;
      t.r=rec[rec[n].rn].r;
      t.rn=rec[rec[n].rn].rn;
      if(t.rn!=-1){
        rec[t.rn].ln=t.n;
      }
    }
    if(t.n!=-1){
      rec[t.n]=t; q.push(t);
#ifdef DEBUG
    printf("create ***l: %d, r: %d, n: %d, ln: %d, rn: %d ***\n",t.l,t.r,t.n,t.ln,t.rn);
#endif
    }

    /*
    t.n=tail++;

    bool ok=1;
    if(rec[n].ln!=-1){
      ill[rec[n].ln]=1;
      t.l=rec[rec[n].ln].l;
      t.ln=rec[rec[n].ln].ln;
      if(t.ln!=-1){
        rec[t.ln].rn=t.n;
        printf("  rec[%d].rn changed to %d\n",t.ln,t.n);
      }
    }else ok=0;
    if(rec[n].rn!=-1){
      ill[rec[n].rn]=1;
      t.r=rec[rec[n].rn].r;
      t.rn=rec[rec[n].rn].rn;
      if(t.rn!=-1){
        rec[t.rn].ln=t.n;
        printf("  rec[%d].ln changed to %d\n",t.rn,t.n);
      }
    }else ok=0;
    if(ok){
      rec[t.n]=t; q.push(t);
#ifdef DEBUG
    printf("create ***l: %d, r: %d, n: %d, ln: %d, rn: %d ***\n",t.l,t.r,t.n,t.ln,t.rn);
#endif
    }
    */
  }
  putchar('\n');
#ifdef DEBUG
  printf("  tot element: %d\n",tail);
#endif

  return 0;
}
