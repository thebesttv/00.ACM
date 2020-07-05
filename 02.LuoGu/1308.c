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

const int MAX_LEN=1000020;
char des[20], ori[MAX_LEN];

int main(void){
  FGETS(des); FGETS(ori);
  strtok(des," \n\r");
  for(char *p=des;*p;p++) *p=tolower(*p);
  for(char *p=ori;*p;p++)
    if(isalpha(*p))  *p=tolower(*p);

  char *p=strtok(ori," \n\r");
  int cnt=0, pos=-1;
  while(p){
    if(strcmp(des,p)==0){
      cnt++;
      if(pos==-1) pos=p-ori;
    }
    p=strtok(NULL," \n\r");
  }
  if(pos==-1) printf("-1\n");
  else printf("%d %d\n",cnt,pos);

  return 0;
}

/*
const int MAX_LEN=1000020;
int wlen,slen;
char w[20], s[MAX_LEN];

bool same(int pos){
  FOR(i,0,wlen){
    if(pos+i>=slen) return false;
    if(w[i]!=tolower(s[pos+i])) return false;
  }
  return !isalpha(s[pos+wlen]);
}

int main(void){
  FGETS(w); char *p=w;
  while(isalpha(*p)){
    *p = tolower(*p); p++;
  }
  *p = '\0'; wlen=strlen(w);

  int cnt=0, pos=-1;
  fgets(s+1,SIZ(s),stdin); s[0]=' ';
  slen=strlen(s); s[slen-1]=0; slen--;  // delete '\n'
  FOR(i,1,slen) if(s[i]!=' ' && s[i-1]==' '){  // start of a new word
    if(same(i)){
      cnt++;
      if(pos==-1) pos=i-1;
    }
  }
  if(pos==-1) printf("-1\n");
  else printf("%d %d\n",cnt,pos);

  return 0;
}
*/
