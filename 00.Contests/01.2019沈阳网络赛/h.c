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

const int MAX=100020;
int n;
struct Ind{
  char name[20];
  int card[5],cnt[14];
  int rk;

  bool operator < (const Ind &b) const {
    if(rk!=b.rk) return rk>b.rk;
    else return strcmp(name,b.name)<0;
  }
}ind[MAX];

void getCard(char *s, int *card, int *cnt){
  char *p=s; int tail=0,t;
  while(*p){
    switch(*p){
      case 'A': t=1; break;
      case '1': t=10; p++; break;
      case 'J': t=11; break;
      case 'Q': t=12; break;
      case 'K': t=13; break;
      default: t=(*p)-'0';
    }
    card[tail++]=t; p++;
  }
  sort(card,card+5);
  FOR(i,0,5) cnt[card[i]]++;
#ifdef DEBUG
  printf("get:");
  FOR(i,0,5) printf(" %d",card[i]);
  printf("\n");
#endif
}
bool checkCnt(int *cnt, int s){
  FORR(i,1,13) if(cnt[i]==s) return true;
  return false;
}

int getRank(int *c, int *cnt){
  if(c[0]==1 && c[1]==10 && c[2]==11 && c[3]==12 && c[4]==13)
    return 100000000;

  if(c[1]==c[0]+1 && c[2]==c[0]+2 && c[3]==c[0]+3 && c[4]==c[0]+4)
    return 9000000 + c[4];

  if(checkCnt(cnt,4)){
    int t=8000000 + c[2]*100;
    FORR(i,1,13) if(cnt[i]==1){
      t+=i; break;
    }
    return t;
  }

  if(checkCnt(cnt,3)){
    if(checkCnt(cnt,2)){
      int t=7000000 + c[2]*10000;
      FORR(i,1,13) if(cnt[i]==2) t+=i;
      return t;
    }
    int t=6000000 + c[2]*100;
    FORR(i,1,13) if(cnt[i]==1) t+=i;
    return t;
  }

  int pair=0, rec[2];
  FORR(i,1,13) if(cnt[i]==2){
    rec[pair++]=i;
  }

  if(pair==2){
    int t=5000000 + rec[1]*10000 + rec[0]*100;
    FORR(i,1,13) if(cnt[i]==1){
      t+=i; break;
    }
    return t;
  }else if(pair==1){
    int t=4000000 + rec[0]*100;
    FORR(i,1,13) if(cnt[i]==1){
      t+=i;
    }
    return t;
  }
  int s=0; FOR(i,0,5) s+=c[i];
  return s;
}

int main(void){
  while(scanf("%d",&n)==1){
    MST(ind,0); char s[20];
    FOR(i,0,n){
      scanf("%s%s",ind[i].name,s);
      getCard(s,ind[i].card,ind[i].cnt);
      ind[i].rk = getRank(ind[i].card,ind[i].cnt);
    }
#ifdef DEBUG
    FOR(i,0,n) printf("ind %s: %d\n",ind[i].name,ind[i].rk);
#endif
    sort(ind,ind+n);
    FOR(i,0,n) printf("%s\n",ind[i].name);
  }

  return 0;
}
