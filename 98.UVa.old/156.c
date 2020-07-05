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

int n=0;
char a[1020][24];
bool same[1020];

bool anagram(int i, int j){
  VR<char> v1, v2;
  for(char *p=a[i];*p;p++)
    v1.push_back(tolower(*p));
  for(char *p=a[j];*p;p++)
    v2.push_back(tolower(*p));
  if(v1.size()!=v2.size())
    return 0;
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());
  FOR(i,0,v1.size())
    if(v1[i]!=v2[i]) return 0;
  return 1;
}

int main(void){
  while(scanf("%s",a[n])==1){
    if(a[n][0]=='#') break;
    else n++;
  }
#ifdef DEBUG
  printf("  get %d words\n",n);
#endif

  FOR(i,0,n) FOR(j,i+1,n)
    if(anagram(i,j)){
      same[i]=same[j]=1;
    }

  VR<string> v;
  FOR(i,0,n) if(!same[i])
    v.push_back(string(a[i]));
  sort(v.begin(), v.end());
  for(string i : v)
    cout << i << endl;

  return 0;
}
