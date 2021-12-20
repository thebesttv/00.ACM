#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxm=60;
struct node{
  int x,y;
}g[maxm],yx[maxm];
struct Node{
  int s,x,y,step;
};
int n,map[maxm][maxm],b[maxm][maxm],cnt,tot,ans;
bool vis[1<<14][maxm][maxm],mp[1<<14][maxm][maxm];  //mp[S]: 状态为S的地图，mp[S][x][y]为1表示在攻击范围内，为0表示不在攻击范围（棋子本身不算在攻击范围内
char s[maxm];
int gx,gy,qx,qy;

void hqs(int s,int x,int y) //骑士
{
  mp[s][x-1][y+2]=mp[s][x+1][y+2]=mp[s][x+2][y-1]=mp[s][x+2][y+1]=1;
  if(x-2>0) mp[s][x-2][y-1]=mp[s][x-2][y+1]=1;
  if(y-2>0) mp[s][x-1][y-2]=mp[s][x+1][y-2]=1;
}
void king(int s,int x,int y)  //国王
{
  mp[s][x-1][y-1]=mp[s][x-1][y]=mp[s][x-1][y+1]=1;
  mp[s][x][y-1]=mp[s][x][y+1]=1;
  mp[s][x+1][y-1]=mp[s][x+1][y]=mp[s][x+1][y+1]=1;
}
bool ok(int s,int x,int y)//当前的位置可不可行
{
  if(x<1||x>n||y<1||y>n) return 0;
  if(map[x][y]<=1) return 1;
  if(map[x][y]==2||map[x][y]==7) return 0;
  if(s&(1<<b[x][y]-1)) return 0;
}
void cb(int s,int x,int y)  //城堡
{
  for(int i=x-1;i>=1;i--)
  {
    mp[s][i][y]=1;
    if(!ok(s,i,y)) break;
  }
  for(int i=x+1;i<=n;i--)
  {
    mp[s][i][y]=1;
    if(!ok(s,i,y)) break;
  }
  for(int i=y-1;i>=1;i--)
  {
    mp[s][x][i]=1;
    if(!ok(s,x,i)) break;
  }
  for(int i=y+1;i<=n;i--)
  {
    mp[s][x][i]=1;
    if(!ok(s,x,i)) break;
  }
}
void zj(int s,int x,int y)  //主教
{
  for(int i=1;i<min(x,y);i++)       if(ok(s,x-i,y-i)) mp[s][x-i][y-i]=1; else{mp[s][x-i][y-i]=1;break;}
  for(int i=1;i<=min(n-x,n-y);i++)  if(ok(s,x+i,y+i)) mp[s][x+i][y+i]=1; else{mp[s][x+i][y+i]=1;break;}
  for(int i=1;i<=min(x,n-y);i++)    if(ok(s,x-i,y+i)) mp[s][x-i][y+i]=1; else{mp[s][x-i][y+i]=1;break;}
  for(int i=1;i<=min(n-x,y);i++)    if(ok(s,x+i,y-i)) mp[s][x+i][y-i]=1; else{mp[s][x+i][y-i]=1;break;}
}
void wh(int s,int x,int y)  //皇后
{
  zj(s,x,y);
  cb(s,x,y);
}
void sb(int s,int x,int y)  //士兵
{
  mp[s][x+1][y-1]=mp[s][x+1][y+1]=1;
}
queue <Node> dl;
void tz(int s,int x,int y,int step) //bfs的一部分
{
  if(x<1 || x>n || y<1 || y>n) return;
  if(mp[s][x][y]  //如果被攻击
      || vis[s][x][y]) return;
  vis[s][x][y]=1;
  if(map[x][y]==2)  //吃国王
  {
    ans=step;
    return;
  }
  if(map[x][y]>=3&&map[x][y]<=6)
    if(s&(1<<(b[x][y]-1))) s^=(1<<(b[x][y]-1));//吃了
  vis[s][x][y]=1;
  dl.push((Node){s,x,y,step});
}
void get_ans()
{
  while(!dl.empty()) dl.pop();
  dl.push((Node){(1<<tot)-1,qx,qy,0});
  vis[(1<<tot)-1][qx][qy]=1;
  while(!dl.empty())  //bfs
  {
    Node d=dl.front(); dl.pop();
    tz(d.s,d.x-2,d.y-1,d.step+1);
    tz(d.s,d.x-2,d.y+1,d.step+1);
    tz(d.s,d.x-1,d.y-2,d.step+1);
    tz(d.s,d.x-1,d.y+2,d.step+1);
    tz(d.s,d.x+1,d.y-2,d.step+1);
    tz(d.s,d.x+1,d.y+2,d.step+1);
    tz(d.s,d.x+2,d.y-1,d.step+1);
    tz(d.s,d.x+2,d.y+1,d.step+1);
    if(ans) break;
  }
  if(ans) printf("%d\n",ans);
  else printf("-1"); 
}
int main()
{
  while(scanf("%d",&n)==1)
  {
    memset(map,0,sizeof(map)); memset(vis,0,sizeof(vis));
    memset(b,0,sizeof(b)); memset(mp,0,sizeof(mp));
    cnt=0,tot=0; ans=0;
    for(int i=1;i<=n;i++) //读入
    {
      scanf("%s",(s+1));
      for(int j=1;j<=n;j++)
      {
        if(s[j]=='K') cnt++,g[cnt].x=i,g[cnt].y=j,map[i][j]=7;//黑骑士 
        if(s[j]=='X') cnt++,g[cnt].x=i,g[cnt].y=j,map[i][j]=2,gx=i,gy=j;//国王
        if(s[j]=='O') qx=i,qy=j;//白骑士
        if(s[j]=='C') yx[tot].x=i,yx[tot].y=j,map[i][j]=3,b[i][j]=tot++;//城堡
        if(s[j]=='B') yx[tot].x=i,yx[tot].y=j,map[i][j]=4,b[i][j]=tot++;//主教
        if(s[j]=='Q') yx[tot].x=i,yx[tot].y=j,map[i][j]=5,b[i][j]=tot++;//王后
        if(s[j]=='P') yx[tot].x=i,yx[tot].y=j,map[i][j]=6,b[i][j]=tot++;//士兵
      }
    }
    /*
    国王 2
    城堡 3
    主教 4
    王后 5
    士兵 6
    骑士 7
    */
    for(int s=0;s<(1<<tot);s++) //建图
    {
      for(int i=1;i<=cnt;i++)
        if(map[g[i].x][g[i].y]==7)
          hqs(s,g[i].x,g[i].y);
        else
          king(s,g[i].x,g[i].y); 

      for(int i=0;i<tot;i++) if((1<<i)&s)
      {
        int x=yx[i].x;
        int y=yx[i].y;
        if(map[x][y]==3) cb(s,x,y);
        if(map[x][y]==4) zj(s,x,y);
        if(map[x][y]==5) wh(s,x,y);
        if(map[x][y]==6) sb(s,x,y);
      }
      mp[s][gx][gy]=0;
    }
    if(mp[(1<<tot)-1][qx][qy]) printf("-1\n");//我方直接GG
    else get_ans();
  }
}
