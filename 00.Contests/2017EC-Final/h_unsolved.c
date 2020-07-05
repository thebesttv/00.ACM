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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1e6 + 20;
int n,x,y;
struct Node{
  int type,cnt;
};
VR<Node> v;

int type(int ch){
  if(ch=='?') return 0;
  if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
    return 1;
  else
    return -1;
}

bool hasDislike(){
  if(v[0].type==0){
    if(v[0].cnt >= x || v[0].cnt >=y) return true;
    if(v[1].type==1){
      if(v[0].cnt + v[1].cnt >= x) return true;
    }else{  // -1
      if(v[0].cnt + v[1].cnt >= y) return true;
    }
  }

  if(v[n-1].type==0){
    if(v[n-1].cnt >= x || v[n-1].cnt >=y) return true;
    if(v[n-2].type==1){
      if(v[n-1].cnt + v[n-2].cnt >= x) return true;
    }else{  // -1
      if(v[n-1].cnt + v[n-2].cnt >= y) return true;
    }
  }

  FOR(i,1,n-1) if(v[i].type==0){
    if(v[i].cnt >=x || v[i].cnt >=y) return true;

    if(v[i-1].type==1 && v[i+1].type==1){
      if(v[i-1].cnt + v[i].cnt + v[i+1].cnt >= x)
        return true;
    }else if(v[i-1].type==-1 && v[i+1].type==-1){
      if(v[i-1].cnt + v[i].cnt + v[i+1].cnt >= y)
        return true;
    }else if(v[i-1].type==1){ // 1 -1
      if(v[i-1].cnt + v[i].cnt >= x
      || v[i+1].cnt + v[i].cnt >= y)
        return true;
    }else{  // -1 1
      if(v[i-1].cnt + v[i].cnt >= y
      || v[i+1].cnt + v[i].cnt >= x)
        return true;
    }
  }
  return false;
}

bool hasLike(){
  FOR(i,1,n-1) if(v[i].type==0){
    if(v[i-1].type==1 && v[i+1].type==1){
      if((v[i].cnt&1)==0){  // even
        if(v[i-1].cnt + 1 == x
        && v[i+1].cnt + 1 == x)
          return false;
      }
    }else if(v[i-1].type==-1 && v[i+1].type==-1){
      if((v[i].cnt&1)==0){
        if(v[i-1].cnt + 1 == y
        && v[i+1].cnt + 1 == y)
          return false;
      }
    }else if(v[i-1].type==1){ // 1 -1
      if(v[i].cnt&1){ // odd
        if(v[i-1].cnt + 1 == x
        && v[i+1].cnt + 1 == y)
          return false;
      }
    }else{  // -1 1
      if(v[i].cnt&1){ // odd
        if(v[i-1].cnt + 1 == y
        && v[i+1].cnt + 1 == x)
          return false;
      }
    }
  }

  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    v.clear(); int ch;
    do ch=getchar(); while(!isalpha(ch) && ch!='?');
    Node cur{type(ch),1};
    while(ch=getchar()){
      if(ch==' ') break;
      int t = type(ch);
      if(t==cur.type){
        ++cur.cnt;
      }else{
        v.push_back(cur);
        cur = Node{t,1};
      }
    }
    v.push_back(cur);
    n = v.size();
#ifdef DEBUG
    printf("\n");
    for(auto x : v) printf("  type: %2d, cnt: %d\n",x.type,x.cnt);
#endif
    scanf("%d%d",&x,&y);

    bool bad = 0;
    for(auto &t : v) if((t.type==1 && t.cnt==x) ||
                        (t.type==-1 && t.cnt==y)){
      bad = 1; break;
    }
    if(bad){
      printf("Case #%d: DISLIKE\n",kase); continue;
    }

    bool a = hasLike(), b = hasDislike();
#ifdef DEBUG
    printf("  x: %d, y: %d, hasLike: %d, hasDislike: %d\n",x,y,a,b);
#endif
    const char *ans = nullptr;
    if(a && b) ans = "SURPRISE";
    else if(a) ans = "LIKE";
    else       ans = "DISLIKE";
    printf("Case #%d: %s\n",kase,ans);
  }

  return 0;
}

/*
bool hasDislike(){
  if(v[0].type==0){
    if(v[1].type==1){
      if(v[0].cnt>=y) return true;
      if(v[0].cnt + v[1].cnt >= x) return true;
    }else{  // -1
      if(v[0].cnt>=x) return true;
      if(v[0].cnt + v[1].cnt >= y) return true;
    }
  }

  if(v[n-1].type==0){
    if(v[n-2].type==1){
      if(v[n-1].cnt>=y) return true;
      if(v[n-1].cnt + v[n-2].cnt >= x) return true;
    }else{  // -1
      if(v[n-1].cnt>=x) return true;
      if(v[n-1].cnt + v[n-2].cnt >= y) return true;
    }
  }

  FOR(i,1,n-1) if(v[i].type==0){
    if(v[i-1].type==1 && v[i+1].type==1){
      if(v[i].cnt >= y) return true;
      if(v[i-1].cnt + (v[i].cnt-1) >= x 
      || v[i+1].cnt + (v[i].cnt-1) >= x
      || v[i-1].cnt + v[i].cnt + v[i+1].cnt == x)
        return true;
      if(v[i].cnt-2>=x) return true;
    }else if(v[i-1].type==-1 && v[i+1].type==-1){
      if(v[i].cnt >= x) return true;
      if(v[i-1].cnt + (v[i].cnt-1) >= y 
      || v[i+1].cnt + (v[i].cnt-1) >= y
      || v[i-1].cnt + v[i].cnt + v[i+1].cnt == y)
        return true;
      if(v[i].cnt-2>=y) return true;
    }else if(v[i-1].type==1){ // 1 -1
      if(v[i-1].cnt + v[i].cnt >= x
      || v[i+1].cnt + v[i].cnt >= y)
        return true;
      if(v[i].cnt-1>=x || v[i].cnt-1>=y)
        return true;
    }else{  // -1 1
      if(v[i-1].cnt + v[i].cnt >= y
      || v[i+1].cnt + v[i].cnt >= x)
        return true;
      if(v[i].cnt-1>=x || v[i].cnt-1>=y)
        return true;
    }
  }
  return false;
}

bool hasLike(){
  FOR(i,1,n-1) if(v[i].type==0){
    if(v[i-1].type==1 && v[i+1].type==1){
      if((v[i].cnt&1)==0){  // even
        if(v[i-1].cnt + 1 == x
        && v[i+1].cnt + 1 == x)
          return false;
      }
    }else if(v[i-1].type==-1 && v[i+1].type==-1){
      if((v[i].cnt&1)==0){
        if(v[i-1].cnt + 1 == y
        && v[i+1].cnt + 1 == y)
          return false;
      }
    }else if(v[i-1].type==1){ // 1 -1
      if(v[i].cnt&1){ // odd
        if(v[i-1].cnt + 1 == x
        && v[i+1].cnt + 1 == y)
          return false;
      }
    }else{  // -1 1
      if(v[i].cnt&1){ // odd
        if(v[i-1].cnt + 1 == y
        && v[i+1].cnt + 1 == x)
          return false;
      }
    }
  }

  return true;
}
*/
