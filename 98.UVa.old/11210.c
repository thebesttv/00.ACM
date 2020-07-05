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

int cnt[34];
char name[34][6] = {
  "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
  "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
  "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
  "DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI" };

inline int ID(char *s){
  FOR(i,0,34) if(!strcmp(s,name[i]))
    return i;
  return -1;
}

bool dfs(int remaining, int jiang, int ke, int shun){
  if(!remaining) return true;
  if(remaining==14){  // find 1 jiang
    FOR(i,0,34) if(cnt[i]>=2){
      cnt[i]-=2;
      bool st = dfs(12,1,0,0);
      cnt[i]+=2;
      if(st) return true;
    }
  }else{  // find 1 ke or shun
    // ke
    FOR(i,0,34) if(cnt[i]>=3){
      cnt[i]-=3;
      bool st = dfs(remaining-3,jiang,ke+1,shun);
      cnt[i]+=3;
      if(st) return true;
    }
    // shun
    FOR(i,0,27) if(i%9<=6)
      if(cnt[i] && cnt[i+1] && cnt[i+2]){
        cnt[i]-=1, cnt[i+1]-=1, cnt[i+2]-=1;
        bool st = dfs(remaining-3,jiang,ke,shun+1);
        cnt[i]+=1, cnt[i+1]+=1, cnt[i+2]+=1;
        if(st) return true;
      }
  }
  return false;
}

int main(void){
  int kase=0; char t[6];
  while(scanf("%s",t)==1 && t[0]!='0'){
    MST(cnt,0); cnt[ID(t)]++;
    FOR(i,1,13){
      scanf("%s",t); cnt[ID(t)]++;
    }

    bool hasAns=0;
    printf("Case %d:",++kase);
    FOR(i,0,34) if(cnt[i]<=3){
      cnt[i]++;
      if(dfs(14,0,0,0)){
        hasAns=1; printf(" %s",name[i]);
      }
      cnt[i]--;
    }
    if(hasAns) printf("\n");
    else printf(" Not ready\n");
  }

  return 0;
}

/*
int cnt[34], ans[34];
const char name[34][6] = {
  "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
  "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
  "1W", "2W", "3W", "4W", "5W", "6W", "7W", "8W", "9W",
  "DONG", "NAN", "XI", "BEI", "ZHONG", "FA", "BAI" };

int ID(char s){
  FOR(i,0,34) if(!strcmp(s,name[i]))
    return i;
}

void dfs(int remaining, int jiang, int ke, int shun, int missing){  //不考虑每种排只有四张的限制
  if(!remaining){ ans[missing]=1; return; }
  if(remaining==13){  //first, find 1 jiang
    FOR(i,0,34)
      if(cnt[i]==1){
        cnt[i]--;
        dfs(12,1,0,0,i);
        cnt[i]++;
      }else if(cnt[i]>=2){
        cnt[i]-=2;
        dfs(11,1,0,0,-1);
        cnt[i]+=2;
      }
  }else{  // find ke & shun
    if(missing==-1){
      //ke
      FOR(i,0,34)
        if(cnt[i]==2){
          cnt[i]-=2;
          dfs(remaining-2,jiang,ke+1,shun,i);
          cnt[i]+=2;
        }else if(cnt[i]>=3){
          cnt[i]-=3;
          dfs(remaining-3,jiang,ke+1,shun,-1);
          cnt[i]+=3;
        }
      //shun T
      FORR(i,0,6)
        if(!cnt[i]){
        }//
    }else{
    }
  }
}

int main(void){
  int kase=0; char t[6];
  while(scanf("%s",&t)==1 && t[0]!='0'){
    MST(cnt,0), MST(ans,0);
    cnt[ID(t)]++;
    FOR(i,1,13){
      scanf("%s",t); cnt[ID(t)]++;
    }

    dfs(13,0,0,0,-1);

    bool hasAns=0;
    printf("Case %d:",++kase);
    FOR(i,0,34) if(ans[i] && ans[i]+cnt[i]<=4){ // 限制：不大于四张
      hasAns=1; printf(" %s",name[i]);
    }
    if(hasAns) printf("\n");
    else printf(" Not ready\n");
  }


  return 0;
}
*/
