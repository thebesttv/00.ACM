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

struct Ind{
  int p, q;
  bool operator < (const Ind &b) const {
    return q < b.q;
  }
};
int n,bud; char type[40], name[40];
VR<Ind> v[1000];
set<int> st; VR<int> qRec;
map<string, int> mp;

int type_cnt=0;
int ID(char *t){
  string s(t);
  if(mp.count(s)) return mp[s];
  else return mp[s]=type_cnt++;
}

bool ok(int m){
  int sum=0;
  FOR(i,0,type_cnt){
    int tMin=0x3f3f3f3f;
    for(Ind t : v[i]) if(t.q>=m){
      tMin=min(tMin,t.p);
    }
    if(tMin==0x3f3f3f3f) return false;
    sum+=tMin;
  }
  return sum<=bud;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,type_cnt) v[i].clear();
    mp.clear(); type_cnt=0;

    scanf("%d%d",&n,&bud);
    int qMax=0, qMin=1000000001,p,q;
    FOR(i,0,n){
      scanf("%s%s%d%d",type,name,&p,&q);
      v[ID(type)].push_back((Ind){p,q});
      if(q<qMin) qMin=q;
      if(q>qMax) qMax=q;
    }

    int l=qMin, r=qMax;
    while(l<r){
      int m=(l+r+1)/2;
      if(ok(m)) l=m;
      else r=m-1;
    }
    printf("%d\n",l);
  }

  return 0;
}

/*
struct Ind{
  int p, q;
  bool operator < (const Ind &b) const {
    return q < b.q;
  }
};
int n,bud; char type[40], name[40];
VR<Ind> v[1000];
set<int> st; VR<int> qRec;
map<string, int> mp;

int type_cnt=0;
int ID(char *t){
  string s(t);
  if(mp.count(s)) return mp[s];
  else return mp[s]=type_cnt++;
}

bool ok(int m){
  int sum=0;
  FOR(i,0,type_cnt){
    VR<Ind>::iterator it = lower_bound(v[i].begin(), v[i].end(), (Ind){0,m});
    if(it==v[i].end()) return false;  // <b> </b>
    int tMin=0x3f3f3f3f;
    while(it!=v[i].end()){
      tMin=min(tMin,(*it).p);
      it++;
    }
    sum+=tMin;
    if(sum>bud) return false;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,type_cnt) v[i].clear();
    mp.clear(); type_cnt=0;
    st.clear(); qRec.clear();

    scanf("%d%d",&n,&bud);
    int qMax=0, qMin=1000000001,p,q;
    FOR(i,0,n){
      scanf("%s%s%d%d",type,name,&p,&q);
      v[ID(type)].push_back((Ind){p,q});
      st.insert(q);
    }
    FOR(i,0,type_cnt){
      sort(v[i].begin(), v[i].end());
      qMin = min(qMin,v[i][0].q);
      qMax = max(qMax,v[i][v[i].size()-1].q);
    }
    for(int i : st) qRec.push_back(i);

    int l=0, r=qRec.size()-1;
    while(l<r){
      int m = (l+r+1)/2;
#ifdef DEBUG
      printf("l: %d, r: %d, m: %d\n",l,r,m);
#endif
      int mq = qRec[m];
      if(ok(mq)) l=m;
      else r=m-1;
    }
    printf("%d\n",qRec[l]);

    //int l=qMin, r=qMax;
    //while(l<r){
    //  int m=(l+r+1)/2;
    //  if(ok(m)) l=m;
    //  else r=m-1;
    //}
    //printf("%d\n",l);
  }

  return 0;
}
*/
