// Tag: 
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
#include<numeric>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

/*
pair<int, int> partition(vector<int> &v, int l, int r, int p){
  vector<int> b(v.begin()+l, v.begin()+r);
  int i = l, j = r;
  for(int x : b)
    if(x < p)
      v[i++] = x;
    else if(x > p)
      v[--j] = x;
  for(int k = i; k < j; k++)
    v[k] = p;
  return pair<int, int>(i, j);
}
*/

pair<int, int> partition(vector<int> &v, int l, int r, int p){
#ifdef DEBUG
  printf("partitioning [%d, %d] p: %d:\n  ",l,r,p);
  for(int i = l; i < r; i++) printf("%d ",v[i]); putchar('\n');
#endif
  int i = l, j = r;
  while(v[i] < p) i++;
  while(v[j-1] > p) --j;

  int k = i;
  while(k < j){
    if(v[k] < p){
      swap(v[i], v[k]);
      while(v[i] < p) i++;
      k = max(k, i);
    }else if(v[k] > p){
      --j;
      swap(v[j], v[k]);
      while(v[j-1] > p) --j;
    }else{
      k++;
    }
  }
#ifdef DEBUG
  printf("partition (%d, %d)\n  ",i,j);
  for(int i = l; i < r; i++) printf("%d ",v[i]); putchar('\n');
#endif
  return pair<int, int>(i, j);
}

void quicksort(vector<int> &v, int l, int r){
  if(r - l < 2) return;
#ifdef DEBUG
  printf("quicksort(%d, %d)\n",l,r);
#endif
  pair<int, int> p = partition(v, l, r, v[l + rand()%(r-l)]);
  quicksort(v, l, p.first);
  quicksort(v, p.second, r);
}

void mergesort(vector<int> &v, int l, int r){
  if(r - l < 2) return;
  int m = (l + r) / 2;
  mergesort(v, l, m);
  mergesort(v, m, r);

  vector<int> b(v.begin() + l, v.begin() + r);
  int i = 0, j = m - l, k = l;
  m -= l, r -= l;
  while(i < m || j < r){
    if(j == r || (i < m && b[i] < b[j])) v[k++] = b[i++];
    else v[k++] = b[j++];
  }
}

int main(void){
  srand(20210209);
  int n; scanf("%d",&n);
  vector<int> v(n);
  for(int i = 0; i < n; i++)
    scanf("%d",&v[i]);

  // quicksort(v, 0, n);
  mergesort(v, 0, n);

  for(int x : v) printf("%d ",x);
  putchar('\n');

  return 0;
}

/*
const int MAX = 1e5 + 20;
int n, a[MAX];

void quicksort(int *a, int l, int r){
#ifdef DEBUG
  printf("quicksort(%d, %d)\n",l,r);
#endif
  if(r - l < 2) return;
  int p = a[l], i = l+1, j = r-1;
  while(i < j){
    while(i < j && a[i] <= p) i++;
    while(i < j && a[j] >= p) j--;
    if(i >= j) break;
    swap(a[i], a[j]);
  }
  if(p > a[i]) swap(a[l], a[i]);
  quicksort(a, l, i);
  quicksort(a, i, r);
}

int main(void){
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
    scanf("%d",&a[i]);
  quicksort(a, 0, n);
  for(int i = 0; i < n; i++)
    printf("%d ",a[i]);
  putchar('\n');

  return 0;
}
*/
