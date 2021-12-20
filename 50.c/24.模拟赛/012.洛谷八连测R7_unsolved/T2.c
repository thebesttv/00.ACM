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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1000000;
int n,a[MAX];

int main(void){
  //freopen("in2.txt","r",stdin);
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  LL cnt=0;
  FORR(i,1,n) FORR(j,i+1,n) if(a[i]>a[j]) cnt+=(n+1-j)*i;
  //每个 (i,j) 对答案的贡献为 (n+1-j)*i

  printf("%lld\n",cnt);

  return 0;
}

/*
int cnt[200][200];

int main(void){
  int n; scanf("%d",&n);
  FORR(l,1,n) FORR(r,l+1,n){
    FORR(i,l,r) FORR(j,i+1,r) cnt[i][j]++;
  }
  FORR(i,1,n) FORR(j,i+1,n)
    //printf("  cnt[%d][%d]: %d\n",i,j,cnt[i][j]);
    if(cnt[i][j] != (n-j+1)*i) printf(" wrong\n");

  return 0;
}
*/

/*
const int MAX=1000000;
int n,a[MAX],t[MAX];
LL cnt;

void merge_sort(int l, int r){  //[l,r)
  if(l+1>=r) return;
  int m=(l+r)>>1;
  merge_sort(l,m);
  merge_sort(m,r);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && a[p]<=a[q])) t[tail++]=a[p++]; //a[p]<=a[q]
    else {t[tail++]=a[q++]; cnt+=m-p;} //a[p]>a[q]
  }
  //while(p<m && q<r){
  //  if(a[p]<=a[q]) t[tail++]=a[p++];
  //  else {t[tail++]=a[q]; cnt+=m-p; q++;}
  //}
  while(p<m) t[tail++]=a[p++];
  while(q<r) t[tail++]=a[q++];
  FORR(i,l,r) a[i]=t[i];
}

int main(void){
  freopen("in2.txt","r",stdin);
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  int c=0;
  FORR(i,1,n) FORR(j,i+1,n) if(a[i]>a[j]) c++; printf("%d\n",c);

  merge_sort(1,n+1);

  //每个 (i,j) 对答案的贡献为 (n+1-j)*i

  printf("%lld\n",cnt);

  return 0;
}
*/
