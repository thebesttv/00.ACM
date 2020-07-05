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

const int MAX = 20;
int n;
int ord[128], ord2[20];

struct Card{
  int c, n;
  bool operator < (const Card &b) const {
    return n!=b.n ? n < b.n : c < b.c;
  }
};

bool isShun(const Card *v){
  if(v[1].n == v[0].n+1 && v[1].n+1 == v[2].n)
    return true;
  return v[1].n==12 && v[2].n==13 && v[0].n==1;
}

int type(const Card *v){
  if(v[0].n == v[1].n && v[1].n == v[2].n)
    return 1;

  bool isS = isShun(v);
  bool colorSame = (v[0].c == v[1].c && v[1].c == v[2].c);
  if(isS && colorSame){
    return 2;
  }else if(isS && !colorSame){
    return 4;
  }else if(!isS && colorSame){
    return 3;
  }

  if(v[0].n == v[1].n || v[1].n == v[2].n || v[0].n == v[2].n){
    return 5;
  }
  return 6;
}


int cmp(const Card *v1, const Card *v2, int type){
  if(type==1){
    return ord2[v1[0].n] - ord2[v2[0].n];
  }else if(type==2 || type==4){
    if(v1[1].n==12 && v2[1].n==12){
      return ord2[v1[0].n] - ord2[v2[0].n];
    }
    return v1[1].n - v2[1].n;
  }else if(type==5){
    int com1, com2, odd1, odd2;
    if(v1[0].n==v1[1].n){
      com1 = v1[0].n; odd1 = v1[2].n;
    }else if(v1[1].n==v1[2].n){
      com1 = v1[1].n;
      odd1 = v1[0].n;
    }else{  // 0 2
      com1 = v1[0].n;
      odd1 = v1[1].n;
    }

    if(v2[0].n==v2[1].n){
      com2 = v2[0].n;
      odd2 = v2[2].n;
    }else if(v2[1].n==v2[2].n){
      com2 = v2[1].n;
      odd2 = v2[0].n;
    }else{
      com2 = v2[0].n;
      odd2 = v2[1].n;
    }

    if(com1 == com2){
      return ord2[odd1] - ord2[odd2];
    }else{
      return ord2[com1] - ord2[com2];
    }
  }else{
    int vv1[3], vv2[3];
    FOR(i,1,3){
      vv1[i] = v1[i].n==1 ? 14 : v1[i].n;
      vv2[i] = v2[i].n==1 ? 14 : v2[i].n;
    }

    sort(vv1,vv1+3,greater<int>());
    sort(vv2,vv2+3,greater<int>());
    FOR(i,0,3) if(vv1[i] != vv2[i])
      return vv1[i]-vv2[i];
    return 0;
  }
  return 0;
}

struct Node{
  int no; Card v[3];
  void cal(){
    sort(v, v+3);
  }
  bool operator < (const Node &b) const {
    int t1 = type(v), t2 = type(b.v);
    if(t1 == t2){
      int c = cmp(v, b.v, t1);
      return c==0 ? no < b.no : c > 0;
    }else{
      return t1 < t2;
    }
  }
}node[MAX];

int main(void){
  ord['A'] = 1, ord['J'] = 11, ord['Q']=12, ord['K'] = 13;
  FORR(i,2,13) ord2[i] = i;
  ord2[1] = 14;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n){
      FOR(j,0,3){
        int a; char s[4];
        scanf("%d%s", &a, s);

        node[i].v[j].c = a;
        if(strlen(s)==1){
          if(isdigit(s[0]))
            node[i].v[j].n = s[0]-'0';
          else
            node[i].v[j].n = ord[s[0]];
        }else{
          node[i].v[j].n = 10;
        }
      }
      node[i].no = i+1;
      node[i].cal();
    }
    sort(node, node+n);
    printf("%d\n",node[0].no);
  }

  return 0;
}
