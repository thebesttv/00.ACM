class ParTreeNode{
  private:
    value;
    ParTreeNode * parent;
    int nCount;

  public:
    ParTreeNode();
    ~ParTreeNode();
    int getValue();
    void setValue(const int value_);
    ParTreeNode * getParent();
    void setParent(ParTreeNode * parent_);
    int getCount();
    void setCount(const int count_);
};

class ParTree{
  public:
    ParTree(const int size);
    ~ParTree();
    ParTreeNOde * array;
    int size;
    ParTreeNode * find(ParTreeNode * node) const; //查找节点所在根节点
    void Union(int i, int j);       //把下标为 i,j 的两个节点合并成一棵子树
    bool Different(int i, int j);   //判断下标为 i,j 的两个节点是否在一棵树中
};

ParTreeNode ParTree::find(ParTreeNode * node) const {
  ParTreeNode * p=node;
  while(p->getParent()!=NULL) p=p->getParent();
  return p;
}
ParTreeNode ParTree::findPC(ParTreeNode * node) const { //路径压缩
  if(node->getParent()==NULL) return node;
  node->setParent(findPC(node->getParent()));
  return node->getParent();
}
void ParTree::Union(int i, int j){
  ParTreeNode * pi = find(&array[i]);
  ParTreeNode * pj = find(&array[j]);
  if(pi!=pj){
    if(pi->getCount() >= pj->getCount()){
      pj->setParent(pi);
      pi->setCount(pi->getCount() + pj->getCount());
    }else{
      pi->setParent(pj);
      pj->setCount(pi->getCount() + pj->getCount());
    }
  }
}
