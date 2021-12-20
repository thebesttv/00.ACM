#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

class Node;
class Tree;

int main(void){

  return 0;
}

class Node{
  public:
    int n;
    Node *leftMostChild, *rightSibling;

    bool isLeaf() {return leftMostChild==NULL && rightSibling==NULL;}
    void visit();
    void insertFirst(Node * node);
    void insertNext(Node * node);
};

class Tree{
  public:
    Node *root;

    bool isEmpty();
    Node * parent(Node * cur);
    Node * prevSibling(Node * cur);
    void deleteSubtree(Node * subroot);
    void destroyNodes(Node * root);
    void RootFirstTraverse(Node * root);
    void RootLastTraverse(Node * root);
    void bfs(Node * root);
};

Node * Tree::parent(Node * cur){
  queue<Node*> q;
  Node *p=root, *last=NULL;
  while(p!=NULL){
    if(p==cur) return NULL;
    q.push(p);
    p=p->rightSibling;
  }
  while(!q.empty()){
    p=q.front(); q.pop();
    last=p;
    p=p->leftMostChild;
    while(p!=NULL){
      if(p==cur) return last;
      q.push(p);
      p=p->rightSibling;
    }
  }
  return NULL;
}
Node * Tree::prevSibling(Node * cur){

}
void Tree::destroyNodes(Node * root){
  if(root){
    destroyNodes(root->leftMostChild);
    destroyNodes(root->rightSibling);
    delete root;
  }
}
void Tree::deleteSubtree(Node * subroot){ //<b></b>
  if(subroot==NULL) return;
  Node *p=parent(subroot);
  if(p==NULL){  //subroot 为某个树根
    p=root;
    while(p->rightSibling != subroot)  //寻找左邻树根
      p=p->rightSibling;
    p->rightSibling = subroot->rightSibling; //前后挂接，subroot 脱落
  }else if(p->leftMostChild==subroot){  //subroot 为最左子
    p->leftMostChild = subroot->rightSibling;
  }else{  //subroot 为右兄弟
    p=p->leftMostChild;
    while(p->rightSibling!=subroot)
      p=p->rightSibling;
    p->rightSibling = subroot->rightSibling;
  }
  subroot->rightSibling=NULL; //<b></b>
  destroyNodes(subroot);
}
void Tree::RootFirstTraverse(Node * root){
  while(root!=NULL){
    root->visit();
    RootFirstTraverse(root->leftMostChild);
    root = root->rightSibling;
  }
}
void Tree::RootLastTraverse(Node * root){
  while(root!=NULL){
    RootLastTraverse(root->leftMostChild);
    root->visit();
    root = root->rightSibling;
  }
}
void Tree::bfs(Node * root){
  queue<Node*> q;
  while(root!=NULL){
    q.push(root);
    root = root->rightSibling;
  }
  while(!q.empty()){
    Node *p=q.front(); q.pop();
    p->visit();
    p=p->leftMostChild;
    while(p!=NULL){
      q.push(p);
      p = p->rightSibling;
    }
  }
}
