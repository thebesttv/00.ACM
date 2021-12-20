/*
  链式前向星

  前向星
    前向星是一种特殊的边集数组，数组中记录每个条边的起点、终点和权值，按照起点升序排列，如果起点相同，则按终点升序排列。
    len[i]：以i为起点的边的数量
    head[i]：以i为起点的边在数组中的第一个出现位置
    但前向星的实现需要排序，复杂度较高。
  链式前向星
    struct Edge{
      int to; //终点
      int w;  //权值
      Edge * next; //edge[i].next指向与i起点相同的下一条边
    };
    Edge * head[i]：以i为起点的第一条边的存储位置
    如果使用数组模拟，head一般为-1
    链式前向星的存储：相当于每次在链表的头部进行操作，因此其遍历顺序是相反的
*/

const int MAX=1000;
struct Edge{
  int to;
  int w;
  int next;
}edge[MAX];
int head[MAX],tail=0;

void addEdge(int u, int v, int w){
  edge[tail].to=v; edge[tail].w=w;
  edge[tail].next=head[u];
  head[u]=tail++;
}

void travel(int u){
  if(u>tot_head) return;
  for(int i=head[u];i!=-1;i=edge[i].next){
    //visit(i);
  }
  travel(u+1);
}

int main(void){
  memset(head,-1,sizeof(head)); //<b></b>

  return 0;
}
