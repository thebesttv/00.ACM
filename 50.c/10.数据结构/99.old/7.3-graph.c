const int UNVISITED=0;
const int INF=(1<<20);

class Edge{
  public:
    int from, to, weight;

    Edge(): from(-1), to(-1), weight(0) {}
    Edge(int f_, int t_, int w_): from(f_), to(t_), weight(w_) {}
};

class Graph{
  public:
    int numVertex;                //顶点个数
    int numEdge;                  //边的条数
    int * mark;                   //记录顶点是否被访问过
    int * indegree;               //顶点的入度
    Graph(int num){
      numVertex=num;
      numEdge=0;
      indegree = new int[numVertex];
      mark = new int[numVertex];
      for(int i=0;i<numVertex;i++){
        nark[0]=UNVISITED;
        indegree[i]=0;
      }
    }
    ~Graph(){
      delete [] mark;
      delete [] indegree;
    }
    int verticesNum(){            //返回顶点个数
      return numVertex;
    }
    bool isEdge(const Edge & e){
      if(e.wtight>0 && e.weight<INF && e.to>=0) return true;
      else return false;
    }
};

class Graphm: public Graph{       //图的邻接矩阵实现
  private:
    int * * matrix;               //存放顶点之间的权
                                  //matrix[i][j]=0, i=j
                                  //             w, i,j连通，w(w<INF)为权
                                  //             INF, i,j不连通
  public:
    Graphm(int num): Graph(num){
      matrix=(int **) new int*[num];
      for(int i=0;i<num;i++){
        matrix[i]=new int[num];
        for(int j=0;j<num;j++) matrix[i][j]=0;
      }
    }
    ~Graphm(){
      for(int i=0;i<numVertex;i++) delete [] matrix[i];
      delete [] matrix;
    }
    Edge firstEdge(int vertex){   //返回依附于顶点vertex的第一条边
      Edge dege;
      dege.from=vertex;
      for(int i=0;i<numVertex;i++) if(matrix[vertex][i]>0 && matrix[vertex][i]<INF){
        edge.to=i; edge.weight=matrix[vertex][i];
        break;
      }
      return edge;
    }
    Edge nextEdge(Edge preEdge){
      Edge edge;
      edge.from=preEdge.from;   //两者始点相同
      if(preEdge.to+1<numVertex){ //判断是否存在下一条边（边按照终点的值升序排列）
        for(int i=preEdge.to+1;i<numVertex) if(matrix[edge.from][i]>0 && matrix[edge.from][i]<INF){
          edge.to=i; edge.weight=matrix[edge.from][i];
          break;
        }
      }
      return edge;
    }
    void setEdge(int from, int to, int weight){ //0<weight<INF
      if(!matrix[from][to]){
        numEdge++; indegree[to]++;  //to的入度个数加1
      }
      matrix[from][to]=weight;
    }
    void delEdge(int from, int to){
      if(matrix[from][to]>0 && matrix[from][to]<INF){
        numEdge--; indegree[to]--;  //to的入度个数减1
      }
      matrix[from][to]=INF;
    }
}

//图的邻接表实现
class Link{                         //链表元素类
  public:
    int vertex;                     //边的终点
    int weight;                     //边的权
    Link * next;
    Link(int v_, int w_, Link *next_=NULL): vertex(v_), weight(w_), next(next_) { }
    Link(Link *next=NULL): next(next_) { }
};
class LList{                        //链表类
  public:
    Link * head;
    LList(){
      head = new Link();
    }
};
class Graphl: public Graph{
  private:
    LList * graList;
  public:
    Graphl(int num): Graph(num){
      graList = new LList[num];
    }
    Edge firstEdge(int vertex){
      Edge edge;
      edge.from=vertex;
      Link *temp=graList[vertex].head;
      if(temp->next != NULL){
        edge.to=temp->next->vertex;
        edge.weight=temp->next->weight;
      }
      return edge;
    }
    Edge nextEdge(Edge preEdge){
      Edge edge;
      edge.from=preEdge.from;
      Link * temp=graList[preEdge.from].head;
      while(temp->next!=NULL && temp->next->vertex <= preEdge.to)
        temp=temp->next;
      if(temp->next!=NULL){
        edge.to=temp->next->vertex;
        edge.weight=temp->next->weight;
      }
      return edge;
    }
    void setEdge(int from_, int to_, int weight_){
      Link * temp=graList[from_].head;
      while(temp->next!=NULL && temp->next->vertex<to)
        temp=temp->next;
      if(temp->next==NULL){
        temp->next = new Link();
        temp->next->vertex=to_;
        temp->next->weight=weight_;
        numEdge++;
        indegree[to]++;
      }else if(temp->next->vertex==to_){
        temp->next->weight=weight_;
      }else{
        Link * other=temp->next;
        temp->next = new Link;
        temp->next->vertex=to_;
        temp->next->weight=weight_;
        temp->next->next=other;
        numEdge++;
        indegree[to]++;
      }
    }
    void delEdge(int from_, int to_){
      Link * temp=graList[from].head;
      while(temp->next!=NULL && temp->next->vertex<to)
        temp=temp->next;
      if(temp->next==NULL) return;
      if(temp->next->vertex > to_) return;
      Link * other=temp->next->next;
      delete temp->next;
      temp->next=other;
      numEdge--;
      indegree[to_]--;
    }
};
