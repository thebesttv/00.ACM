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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

/*
  方法：
    类似于并查集的方法，对每个点i，随机生成其父节点为1:i-1的数即可。
    如果要指定哪个点是根，就生成一个替换表（1:n的一个排列），rep[i]表示数字i要替换成什么，当然rep[1]=root
    替换表即为两个排列，分别为 1:root-1 和 root+1:n 的排列
*/

const int MAX=1000;
int rep[MAX];

int main(void){
  srand(time(NULL));
  int n,root; scanf("%d%d",&n,&root);
  FORR(i,1,n) rep[i]=i;   //<b>
  random_shuffle(rep+1,rep+n+1);
  int pos=-1; FORR(i,1,n) if(rep[i]==root) {pos=i; break;}
  swap(rep[1],rep[pos]);  //</b>

  printf("root: %d\n",root);
  printf("replace table:"); FORR(i,1,n) printf(" %d",rep[i]); printf("\n");
  FORR(i,2,n){  //<b>还是按照root为1的方法生成，只不过用了替换表</b>
    int u=i,f=rand()%(i-1)+1;
    u=rep[u]; f=rep[f];
    printf("node %d, f: %d\n",u,f);
  }

  return 0;
}
