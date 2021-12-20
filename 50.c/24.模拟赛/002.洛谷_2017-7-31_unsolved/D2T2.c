/*
题目描述
YJC决定对入侵C国的W国军队发动毁灭性打击。将C国看成一个平面直角坐标系，W国一共有n^2个人进入了C国境内，在每一个(x,y)(1≤x,y≤n)上都有恰好一个W国人。YJC决定使用m颗核导弹，每一颗核导弹将杀死某个圆内所有的W国人，恰好在圆上也会被杀死。现在YJC想知道，在这一轮核打击之后，还有多少个W国人在C国境内。

输入输出格式
输入格式：
第一行包含两个整数n和m，意思如题所示。
接下来m行每行三个整数x,y和r，表示以(x,y)为圆心，r为半径的圆圆内和圆上的W国人被全部杀死。

输出格式：
一行，包含一个整数，表示幸存的W国人个数。

输入输出样例
输入样例#1：
3 2
2 2 1
1 1 2

输出样例#1：
1

说明
第一枚导弹杀死了(1,2)、(2,1)、(2,2)、(2,3)、(3,2)上的W国人，第二枚导弹杀死了(1,1)、(1,2)、(1,3)、(2,1)、(2,2)、(3,1)上的W国人，只剩下(3,3)上的W国人没有被杀死。
对于50%的数据，满足n,m≤50。
对于100%的数据，满足1≤x,y≤n≤5000，0≤r≤n，1≤m≤5000。
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int G[5020][5020];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int k=0;k<m;k++){
    int x,y,r; scanf("%d%d%d",&x,&y,&r);
    int r2=r*r;
    bool tag_start=0,tag_end=0;
    for(int i=-r;i<=r;i++){
      int j=floor(sqrt(r2-i*i));
      if(x+i<1 || x+i>n) continue;
      G[x+i][(y-j<1 ? 1 : y-j)]++; G[x+i][(y+j>n ? n+1 : y+j+1)]--;
    }
  }
#ifdef DEBUG
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++) printf("%3d",G[i][j]);
    printf("\n");
  }
#endif
  int cnt=0;
  for(int i=1;i<=n;i++){
    int delta=0;
    for(int j=1;j<=n;j++){
      delta+=G[i][j];
      //cnt = delta==0 ? cnt+1 : cnt;
      (!delta) ? cnt++ : 0 ;
    }
  }
  printf("%d\n",cnt);

  return 0;
}































































/*
  得分：50
  解题报告：
  暴力枚举，配了一个无用的优化。 O(n^2+m^2)
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

bool G[5020][5020];
struct Node{
  int x,y,r;

  bool operator < (const Node & b) const {
    return r>b.r;
  }
}ori[5000];
int n;

inline bool inside(int x, int y){
  return x>=0 && x<n && y>=0 && y<n;
}
inline float dis(int x1, int y1, int x2, int y2){
  return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  int m; scanf("%d%d",&n,&m);
  for(register int i=0;i<m;i++){
    scanf("%d%d%d",&ori[i].x,&ori[i].y,&ori[i].r);
    ori[i].x--; ori[i].y--;
  }
  sort(ori,ori+m);
  register int x,y,r,r2;
  for(register int i=20;i<m;i++){ //若炸弹i在前20的炸弹范围内，则直接删去（无用）
    x=ori[i].x,y=ori[i].y,r=ori[i].r;
    for(register int j=0;j<20;j++) if(ori[j].r - dis(x,y,ori[j].x,ori[j].y) >=r) {ori[i].r=-1; break;}
  }

  memset(G,1,sizeof(G));
  for(register int k=0;k<m;k++) if(ori[k].r!=-1){
    x=ori[k].x, y=ori[k].y, r=ori[k].r, r2=ori[k].r*ori[k].r;
    for(register int i=-r;i<=r;i++) for(register int j=-r;j<=r;j++) if(i*i+j*j<=r2 && inside(x+i,y+j))
      G[x+i][y+j]=0;
  }
  register int cnt=0;
  for(register int i=0;i<n;i++) for(register int j=0;j<n;j++) if(G[i][j]) cnt++;
  printf("%d\n",cnt);

  return 0;
}
*/
