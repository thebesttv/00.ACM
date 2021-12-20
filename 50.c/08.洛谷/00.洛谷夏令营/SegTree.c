#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=1000;
const int INF=1<<30;
struct SegTree{
  int n;
  int addMark;  //lazy tag: 记录对当前节点的<b>子节点</b>还没执行的操作
}segTree[MAX];

void build(int root, int * array, int L, int R);
void pushDown(int root);
int query(int root, int cL, int cR, int qL, int qR);
void update(int root, int cL, int cR, int uL, int uR, int addVal);

int main(void){

  return 0;
}

void build(int root, int * array, int L, int R){
  segTree[root].addMark=0;  //<b></b>
  if(L==R) {segTree[root].n=array[L];}
  else{
    int M=L+(R-L)/2;
    build(root*2,array,L,M);
    build(root*2+1,array,M+1,R);
    segTree[root].n=min(segTree[root*2].n, segTree[root*2+1].n);
  }
}
void pushDown(int root){
  if(segTree[root].addMark){
    int leftchild=root*2, rightchild=root*2+1;
    segTree[leftchild].addMark+=segTree[root].addMark;
    segTree[rightchild].addMark+=segTree[root].addMark;
    segTree[leftchild].n+=segTree[root].addMark;
    segTree[rightchild].n+=segTree[root].addMark;
    segTree[root].addMark=0;  //<b>lazy tag传递完成，取消放置</b>
  }
}
int query(int root, int cL, int cR, int qL, int qR){
  if(qL>cR || qR<cL) return INF;  //current区间不被覆盖
  if(qL<=cL && qR>=cR) return segTree[root].n;  //current区间被全部覆盖
  pushDown(root); //current区间被部分覆盖，在继续查询前要先传递addMark
  int M=cL+(cR-cL)/2;
  return min(query(root*2,cL,M,qL,qR), query(root*2+1,M+1,cR,qL,qR));
}
void update(int root, int cL, int cR, int uL, int uR, int addVal){
  if(uL>cR || uR<cL) return;  //current区间不被覆盖
  if(uL<=cL && uR>=cR){ //current区间被全部覆盖，直接放置lazy tag并更新当前节点，不对子节点操作
    segTree[root].addMark+=addVal;
    segTree[root].n+=addVal;
    return;
  }
  pushDown(root); //current区间被部分覆盖，先把先前的addMark传递给子树
  int M=cL+(cR-cL)/2;
  update(root*2,cL,M,uL,uR,addVal);
  update(root*2+1,M+1,cL,uL,uR,addVal);
  segTree[root].n=min(segTree[root*2].n, segTree[root*2+1].n);  //更新当前节点
}
