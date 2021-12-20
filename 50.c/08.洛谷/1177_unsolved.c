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

const int MAX=100020;
int n,a[MAX],t[MAX];

inline int read(){
  int ans=0,ch;
  do ch=getchar(); while(ch<'0' || ch>'9');
  do {ans=ans*10+ch-'0'; ch=getchar();} while(ch>='0' && ch<='9');
  return ans;
}

//void quick_sort(int l, int r){  //[l,r]
//  if(l>=r) return;
//  if(l+1==r){
//    if(a[l]>a[r]) swap(a[l],a[r]);
//    return;
//  }
//  int k=a[l],i=l,j=r; //<b></b>
//  while(i<j){
//    while(i<j && a[j]>=k) j--;
//    while(i<j && a[i]<=k) i++;
//    swap(a[i],a[j]);
//  }
//  swap(a[l],a[i]);
//  quick_sort(l,i-1);
//  quick_sort(i+1,r);
//}

inline void bubble_sort(int l, int r){ //[l,r]
  RORR(i,r,l) FOR(j,l,i)
    if(a[j]>a[j+1])
      swap(a[j],a[j+1]);
}

/*
void quick_sort(int l, int r){  //[l,r]
  int i=l,j=r; //<b> i从l开始 </b>
  int p=l+rand()%(r-l);
  int k=a[p]; swap(a[l],a[p]);
  while(i<j){
    while(i<j && a[j]>=k) j--;
    while(i<j && a[i]<=k) i++;
    swap(a[i],a[j]);
  }
  swap(a[l],a[i]);

  int l1=i-l,l2=r-i;  //左边和右边的长度
  if(l1==2){
    if(a[l]>a[i-1]) swap(a[l],a[i-1]);
  }else if(l1<=4){
    bubble_sort(l,i-1);
  }else if(l1>0) quick_sort(l,i-1);

  if(l2==2){
    if(a[i+1]>a[r]) swap(a[i+1],a[r]);
  }else if(l2<=4){
    bubble_sort(i+1,r);
  }else if(l2>0) quick_sort(i+1,r);
}

void merge_sort(int l, int r){  //[l,r)
  if(l+1>=r) return;
  int m=(l+r)>>1;
  merge_sort(l,m);
  merge_sort(m,r);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && a[p]<a[q])) t[tail++]=a[p++];  //a[p] < a[q]
    else t[tail++]=a[q++];  //a[p] > a[q]
  }
  FOR(i,l,r) a[i]=t[i];
}
*/



void quick_sort(int l, int r){
  if(l>=r) return;
  int k=a[l],i=l,j=r;
  while(i<j){
    while(i<j && a[j]>=k) j--;
    while(i<j && a[i]<=k) i++;
    swap(a[i],a[j]);
  }
  swap(a[l],a[i]);
  quick_sort(l,i-1);
  quick_sort(i+1,r);
}

void merge_sort(int l, int r){  //[l,r)
  if(l+1>=r) return;
  int m=(l+r)>>1;
  merge_sort(l,m);
  merge_sort(m,r);
  int p=l,q=m,tail=l;
  while(p<m || q<r){
    if(q>=r || (p<m && a[p]<a[q])) t[tail++]=a[p++];
    else t[tail++]=a[q++];
  }
  FOR(i,l,r) a[i]=t[i];
}






int main(void){
  n=read();
  int t=0;
  FOR(i,0,n) t^=(a[i]=read());
  srand(t);

  //quick_sort(0,n-1);
  merge_sort(0,n);

  FOR(i,0,n) printf("%d ",a[i]); printf("\n");

  return 0;
}
