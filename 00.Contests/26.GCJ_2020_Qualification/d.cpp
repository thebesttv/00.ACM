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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n; char s[MAX];
bool toFlip, toReverse;

struct Node { int l, r, v; };
VR<Node> even, odd;

void flip(){
  FORR(i,1,n)
    if(s[i]=='0') s[i]='1';
    else if(s[i]=='1') s[i]='0';
}

int ask(int x){
  printf("%d\n",x); fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

void test10(){
#ifdef DEBUG
  printf("  test 10 from %d\n",s);
#endif
  FORR(i,1,5){
    int l = i, r = n-i+1;
    bool a = ask(l), b = ask(r);
    if(a==b)
      even.push_back({l,r,int(a)});
    else
      odd.push_back({l,r,int(a)});
  }
}

void detectEven(){
#ifdef DEBUG
  printf("  detect even\n");
#endif
  bool a = ask(even[0].l) == even[0].v;
  if(!a) toFlip = 1, even[0].v = !even[0].v;
  else toFlip = 0;
}

void detectOdd(){
#ifdef DEBUG
  printf("  detect odd\n");
#endif
  bool b = ask(odd[0].l) == odd[0].v;

  if(!b) odd[0].v = !odd[0].v;

  if((!b && !toFlip) || (b && toFlip))
    toReverse = 1;
  else
    toReverse = 0;
}

void apply(){
  if(toFlip) flip();
  if(toReverse) reverse(s+1,s+1+n);
  toFlip = toReverse = 0;
}

int main(void){
  int T; scanf("%d%d",&T,&n);
  while(T--){
    even.clear(); odd.clear(); MST(s,0);

    test10(); // 0

    int p = 1;  // sym
    bool done = 0;
    FOR(kase,1,15){
      // first even then odd
      if(even.size()) detectEven();
      else ask(1);  // useless
      if(odd.size()) detectOdd();
      else ask(1);  // useless
#ifdef DEBUG
      printf("to flip: %d, to reverse: %d\n",toFlip,toReverse);
#endif
      apply();

      FOR(i,0,4){ // 4 times
        int a = ask(p), b = ask(n-p+1);
        s[p] = '0' + a;
        s[n-p+1] = '0' + b;

        if(a==b) even.push_back({p,n-p+1,a});
        else odd.push_back({p,n-p+1,a});

        if(p==n/2){
          done = 1; break;
        }
        ++p;
      }
      if(done) break;
    }

    printf("%s\n", s+1); fflush(stdout);
    char res[10]; scanf("%s",res);
    if(res[0]=='N') exit(1);  // wrong
  }

  return 0;
}

/*
const int MAX = 120;
int n; char s[MAX];
bool isFlipped, isReversed, toFlip, toReverse; // state & operation

struct Node{
  int l, r; bool ori;
};
VR<Node> even, odd;

bool ask(int n){
  printf("%d\n",n); fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

void test10(int s){
#ifdef DEBUG
  printf("  test 10 from %d\n",s);
#endif
  FOR(i,0,5){
    int l = s+i, r = n-l+1;
    bool a = ask(l), b = ask(r);
    if(a==b)
      even.push_back({l,r,a});
    else
      odd.push_back({l,r,a});
  }
}

void detectEven(){
#ifdef DEBUG
  printf("  detect even\n");
#endif
  bool a = ask(even[0].l) == even[0].ori;
#ifdef DEBUG
  printf("    a: %d\n",a);
#endif
  if(!a) toFlip = 1;
}

void detectOdd(){
#ifdef DEBUG
  printf("  detect odd\n");
#endif
  // bool b = ask(odd[0].l) == odd[0].ori;
  bool b = ask(isReversed ? n - odd[0].l + 1 : odd[0].l) == odd[0].ori;
#ifdef DEBUG
  printf("    b: %d\n",b);
#endif
  if((!b && !toFlip) || (b && toFlip))
    toReverse = 1;
}

void apply(){
  if(toFlip) isFlipped = !isFlipped;
  if(toReverse) isReversed = !isReversed;
}

int main(void){
  int T; scanf("%d%d",&T,&n);
  while(T--){
    MST(s,0); isFlipped = isReversed = toFlip = toReverse = 0;

    test10(1); // 0
    if(n>10) test10(11); // 1

    int p = 1;
    bool done = 0;
    FOR(kase,2,15){
      int cnt = 0; toFlip = toReverse = 0; // operation
      // first even then odd
      if(even.size()) detectEven(), ++cnt;
      if(odd.size()) detectOdd(), ++cnt;
#ifdef DEBUG
      printf("to flip: %d, to reverse: %d\n",toFlip,toReverse);
#endif
      apply();
#ifdef DEBUG
      printf("is flipped: %d, is reversed: %d\n",isFlipped,isReversed);
#endif

      FOR(i,cnt,10){
        bool a = ask(isReversed ? n-p+1 : p);
        s[p] = '0' + (isFlipped ? !a : a);
        if(p > n/2){
          if(s[p] == s[n-p+1])
            even.push_back({n-p+1,p,s[n-p+1]=='1'});
          else
            odd.push_back({n-p+1,p,s[n-p+1]=='1'});
        }
        if(p==n){
          done = 1; break;
        }
        ++p;
      }
      if(done) break;
    }

    printf("%s\n", s+1); fflush(stdout);
    char res[10]; scanf("%s",res);
    if(res[0]=='N') exit(1);  // wrong
  }

  return 0;
}
*/

/*
const int MAX = 120;
int n; char s[MAX];
bool isFlipped, isReversed, either;
bool vis[MAX];

struct Node{
  int l, r; bool ori;
};
VR<Node> even, odd;

bool ask(int n){
  printf("%d\n",n); fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

void test10(int s){
  FOR(i,0,5){
    int l = s+i, r = n-l+1;
    bool a = ask(l), b = ask(r);
    if(a==b)
      even.push_back({l,r,a});
    else
      odd.push_back({l,r,a});
  }
}

void detectBoth(){
  bool a = ask(even[0].l) == even[0].ori,
       b = ask(odd[0].l) = odd[0].ori;
  if(a){
    if(b){  // 4: nothing
      // isFlipped = 0, isReversed = 0;
      0;
    }else{  // 2: toReverse
      // isFlipped = 0, isReversed = 1;
      isReversed = !isReversed;
    }
  }else{
    if(b){  // 3: both
      // isFlipped = 1, isReversed = 1;
      isFlipped = !isFlipped;
      isReversed = !isReversed;
    }else{  // 1: toFlip
      // isFlipped = 1, isReversed = 0;
      isFlipped = !isFlipped;
    }
  }
}

void detectEven(){
  bool a = ask(even[0].l) == even[0].ori;
  // if(a) isFlipped = 0;
  // else  isFlipped = 1;
  if(!a) isFlipped = !isFlipped;
}

void detectOdd(){
  bool b = ask(odd[0].l) = odd[0].ori;
  // if(b) either = 0;
  // else  either = 1;
  if(!b) either = !either;
}

int main(void){
  int T; scanf("%d%d",&T,&n);
  while(T--){
    MST(vis,0); MST(s,0); filpped = isReversed = either = 0;
    test10(1); // 0
    test10(n==10 ? 1 : 11); // 1
    int p = 1;
    FOR(kase,2,15){
      if(even.size() && odd.size()){
        detectBoth();
        FOR(i,2,10){
          bool a = ask(isReversed ? n-p+1 : p);
          s[p] = isFlipped ? !a : a;
          p = p==n ? 1 : p+1;
        }
      }else if(even.size()){  // only even
        detectEven();
        FOR(i,1,10){
          if(p <= n/2){
            bool a = ask(p);
            s[p] = isFlipped ? !a : a;
          }else{
            bool a = ask(p);
            if(isFlipped) a = !a;
            if(s[n-p+1] != a){
              odd.push_back({n-p+1,p,s[n-p+1]});
              isReversed = 0;
            }
            s[p] = a;
          }
          p = p==n ? 1 : p+1;
        }
      }else{  // only odd
        detectOdd();
        FOR(i,1,10){
          if(p <= n/2){
            bool a = ask(p);
            s[p] = isFlipped ? !a : a;
          }else{
            bool a = ask(p);
            if(isFlipped) a = !a;
            if(s[n-p+1] != a){
              odd.push_back({n-p+1,p,s[n-p+1]});
              isReversed = 0;
            }
            s[p] = a;
          }
          p = p==n ? 1 : p+1;
        }
      }
    }
    printf("%s\n", s+1); fflush(stdout);
    char res[10]; scanf("%s",res);
    if(res[0]=='N') exit(1);  // wrong
  }

  return 0;
}
*/
