#include<bits/stdc++.h>
using namespace std;

const int MAX = 1020;
const int INF=0x3f3f3f3f;
int n, a[MAX][MAX];

int main(void){
  int tx, ty;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j){
      scanf("%d",&a[i][j]);
      if(a[i][j] == -1){
        tx = i, ty = j;
        a[i][j] = INF;
      }
    }
  for(int i=0;i<n;++i){
    int tMin = INF;
    for(int j=0;j<n;++j)
      tMin = min(tMin, a[i][j]);
    for(int j=0;j<n;++j)
      a[i][j] -=tMin;
  }
  for(int j=0;j<n;++j){
    int tMin = INF;
    for(int i=0;i<n;++i)
      tMin = min(tMin, a[i][j]);
    for(int i=0;i<n;++i)
      a[i][j] -= tMin;
  }
  int ans = INF -a[tx][ty];
  printf("%d\n",ans);

  return 0;
}
