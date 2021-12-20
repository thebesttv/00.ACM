/*
描述
一个城市中有两个犯罪团伙A和B，你需要帮助警察判断任意两起案件是否是同一个犯罪团伙所为，警察所获得的信息是有限的。
假设现在有N起案件（N<=100000），编号为1到N，每起案件由团伙A或团伙B所为。你将按时间顺序获得M条信息（M<=100000），这些信息分为两类：
  1. D [a] [b] 其中[a]和[b]表示两起案件的编号，这条信息表明它们属于不同的团伙所为
  2. A [a] [b] 其中[a]和[b]表示两起案件的编号，这条信息需要你回答 [a] 和 [b] 是否是同一个团伙所为
注意你获得信息的时间是有先后顺序的，在回答的时候只能根据已经接收到的信息做出判断。

输入
第一行是测试数据的数量T（1<=T<=20）。
每组测试数据的第一行包括两个数N和M，分别表示案件的数量和信息的数量，其后M行表示按时间顺序收到的M条信息。

输出
对于每条需要回答的信息，你需要输出一行答案。
如果是同一个团伙所为，回答"In the same gang."，如果不是，回答"In different gangs."，如果不确定，回答”Not sure yet."。

样例输入
1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4

样例输出
Not sure yet.
In different gangs.
In the same gang.
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=100000+10;
int p[MAX],r[MAX];

int getParent(int x);
void merge_different(int x, int y);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    memset(p,-1,sizeof(p)); memset(r,0,sizeof(r));
    int n,m; scanf("%d%d",&n,&m);
    char type; int x, y;
    for(int i=0;i<m;i++){
      do type=getchar(); while(!isalpha(type));
      scanf("%d%d",&x,&y);
      if(type=='A'){
        if(getParent(x)==getParent(y)){
          if(r[x]==r[y]) printf("In the same gang.\n");
          else printf("In different gangs.\n");
        }else{
          printf("Not sure yet.\n");
        }
      }else{
        merge_different(x,y);
      }
#ifdef DEBUG
      printf("    "); for(int i=1;i<=n;i++) printf(" %2d",i); printf("\n");
      printf("  p:"); for(int i=1;i<=n;i++) printf(" %2d",p[i]); printf("\n");
      printf("  r:"); for(int i=1;i<=n;i++) printf(" %2d",r[i]); printf("\n");
#endif
    }
  }

  return 0;
}

int getParent(int x){
  if(p[x]<0) return x;
  else{
    int t=p[x];
    p[x]=getParent(p[x]);
    r[x]= r[x]^r[t];
    return p[x];
  }
}
void merge_different(int x, int y){
  int px=getParent(x),py=getParent(y);
  p[py]=px;
  r[py]=!(r[x]^r[y]);
#ifdef DEBUG
  printf("  in merge_different(%d,%d), r[%d]==%d\n",x,y,py,r[py]);
#endif
}



















































/*
//核心思想：p[a]与p[a+n]属于不同集合
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

const int MAX=100000+10;
int p[MAX*2];

int getParent(int n);
void merge(int a, int b);
bool same(int a, int b);

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int n,m; scanf("%d%d",&n,&m);
    memset(p,-1,sizeof(p));
    int type,a,b;
    for(int i=0;i<m;i++){
      do type=getchar(); while(!isalpha(type));
      scanf("%d%d",&a,&b);
      if(type=='D'){
        merge(a,b+n);
        merge(b,a+n);
      }else{
        if(same(a,b)) printf("In the same gang.\n");
        else if(same(a,b+n)) printf("In different gangs.\n");
        else printf("Not sure yet.\n");
      }
    }
  }

  return 0;
}

int getParent(int n){
  if(p[n]<0) return n;
  else return p[n]=getParent(p[n]);
}
void merge(int a, int b){
  int pa=getParent(a),pb=getParent(b);
  if(pa==pb) return;
  int tot=p[pa]+p[pb];
  if(p[pa]<p[pb]){
    p[pb]=pa;
    p[pa]=tot;
  }else{
    p[pa]=pb;
    p[pb]=tot;
  }
}
bool same(int a, int b){
  return getParent(a)==getParent(b);
}
*/

/*
 * 源自网络：
 *     稍微扯远一点，最近看完了《数学之美》这本书，里面提到了最大熵模型，也就是“包含所有可能性”的模型。
 * 这道题目其实归根结底就是保留了所有可能性，我们只知道x和y不属于同一集合，但我们不能确定究竟x属于
 * 集合A还是集合B，于是我们保留所有可能性，对x-A和x-B都做了一次记录。
 */
