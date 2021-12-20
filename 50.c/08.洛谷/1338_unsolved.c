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

const int MAX=100;
int a[MAX],tmp[MAX],t[MAX];
int cnt=0;

/*
void merge_sort(int *a, int l, int r){
  if(l>=r) return;
  int m=(l+r)>>1;
  merge_sort(a,l,m); merge_sort(a,m+1,r);
  int p=l,q=m+1,tail=l;
  while(p<=m && q<=r){
    if(a[p]<=a[q]) t[tail++]=a[p++];
    else {t[tail++]=a[q++]; cnt+=m-p+1;}
  }
  while(p<=m) t[tail++]=a[p++];
  while(q<=r) t[tail++]=a[q++];
  FORR(i,l,r) a[i]=t[i];
}
*/

void merge_sort(int * a, int l, int r){ //[l,r)
  if(l+1>=r) return;
  int m=(l+r)>>1;
  merge_sort(a,l,m);
  merge_sort(a,m,r);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && a[p]<=a[q])) t[tail++]=a[p++];
    else {t[tail++]=a[q++]; cnt+=m-p;}
  }
  FOR(i,l,r) a[i]=t[i];
}

int main(void){
  int n; scanf("%d",&n);
  FOR(i,0,n) a[i]=i+1;
  int kase=0;
  do{
    cnt=0; memcpy(tmp,a,SIZ(a));
    merge_sort(tmp,0,n);
    //printf("No. %4d:",++kase);
    //FOR(i,0,n) printf(" %d",a[i]); printf(": %2d\n",cnt);
    printf("%4d: %d",++kase,cnt);
    if((kase-1)%6==0) putchar('-'); putchar('\n');
  }while(next_permutation(a,a+n));

  return 0;
}
