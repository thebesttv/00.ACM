/*
描述
蒜头君有一只坐骑，人马。
一天，蒜头君骑着他的坐骑走上了一片 n*m 的大荒野，一开始时，蒜头君在 (1,1) 点，他要前往 (n,m) 点，蒜头君的人马每次可以向右或向下移动一格。然而这片荒野并不平静，除了起点和终点外每个点都有一只怪物会袭击蒜头君。
然而蒜头君的人马强大无比，它会先对怪物造成等同于它攻击力的伤害，然后蒜头君才会受到怪物的攻击，伤害等同于怪物的攻击力。然后人马再攻击怪物，怪物再攻击蒜头君，直至怪物死去，假设每个怪物具有相同的体力。
此外，蒜头君的人马还有一个强大无比的技能，使用该技能会使蒜头君接下来 k 次移动，每一次移动后增加等同于移动到的格子的怪物的攻击力，k 次移动后，人马攻击力恢复至初始攻击力。人马必须在当前一个技能释放完后才可以释放下一个技能，且一共可释放技能的次数有限，那么试问蒜头君从起点到终点最少受到多少点伤害。
注：蒜头君的体力是无限的。

输入格式
第一行六个正整数 n,m,t,k,h,atk，表示地图长度、宽度、人马技能可使用次数、人马技能持续移动次数、每只怪物的体力和人马的初始攻击力。保证 n+m−1≥t*k。
接下来 n 行，每行 m 个整数，表示每个点的怪物的攻击力。保证 (1,1) 点、(n,m) 点为 0，其他点为正整数。

输出格式
输出一个整数，表示蒜头君受到的最小伤害。

数据规模
对于 30% 的测试数据，满足 1≤n,m≤10, 1≤t≤3, 1≤k≤3
对于 60% 的测试数据，满足 1≤n,m≤100, 1≤t≤10, 1≤k≤5
对于 100% 的测试数据，满足 1≤n,m≤500, 1≤t≤10, 1≤k≤5, 1≤atk≤h≤100, 1≤怪物攻击力≤100。
样例输入
4 3 2 1 7 4
0 2 4
3 5 1
2 3 2
5 4 0

样例输出
3
*/

/*
  得分：0
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int ansMin=1<<30;
int G[520][520];
int r,c,tot,k,life,ori_atk;

void dfs(int x, int y, int harm, int atk, int left){
#ifdef DEBUG
  printf("  dfs(%d,%d), harm: %d, atk: %d, left: %d\n",x,y,harm,atk,left);
#endif
  if(harm>=ansMin) return;
  if(x==r-1 && y==c-1) {ansMin=harm; return;}
  if(left) {atk+=G[x][y]; left--;}
  else atk=ori_atk;
  int ind_atk=ceil((double)life/atk);
  harm += (ind_atk ? ind_atk-1 : 0)*G[x][y];
  //右
  register int tx=x,ty=y+1;
  if(x>=0 && x<r && y>=0 && y<c){
    if(!left && tot){
      tot--;
      dfs(tx,ty,harm,atk,k);
      tot++;
    }
    dfs(tx,ty,harm,atk,(left ? left-1 : 0));
  }

  //下
  tx=x+1,ty=y;
  if(x>=0 && x<r && y>=0 && y<c){
    if(!left && tot){
      tot--;
      dfs(tx,ty,harm,atk,k);
      tot++;
    }
    dfs(tx,ty,harm,atk,(left ? left-1 : 0));
  }
}

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d%d%d%d",&r,&c,&tot,&k,&life,&ori_atk);
  if(ori_atk==life) printf("0\n");  //可能没用
  else{
    for(register int i=0;i<r;++i) for(register int j=0;j<c;++j) scanf("%d",&G[i][j]);
    dfs(0,0,0,ori_atk,0);
    printf("%d\n",ansMin);
  }
  return 0;
}
