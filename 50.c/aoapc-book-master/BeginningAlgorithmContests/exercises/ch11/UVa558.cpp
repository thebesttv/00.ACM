// UVa558 Wormholes
// Rujia Liu
// ���⣺��һ��n����m���ߵ������Ȩͼ�����0�����Ƿ��и�ȨȦ
// �㷨��Bellman-Ford
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int INF = 1000000000;
const int maxn = 1000;

struct Edge {
  int from, to;
  double dist;
  Edge(int u, int v, double d):from(u),to(v),dist(d) {}
};

struct BellmanFord {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  bool inq[maxn];     // �Ƿ��ڶ�����
  double d[maxn];     // s��������ľ���
  int p[maxn];        // ���·�е���һ����
  int cnt[maxn];      // ���Ӵ���

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, double dist) {
    edges.push_back(Edge(from, to, dist));
    m = edges.size();
    G[from].push_back(m-1);
  }

  bool negativeCycle(int s) {
    queue<int> Q;
    memset(inq, 0, sizeof(inq));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; i++) d[i] = INF;
    d[s] = 0;
    inq[s] = true;
    Q.push(s);

    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = false;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(d[u] < INF && d[e.to] > d[u] + e.dist) {
          d[e.to] = d[u] + e.dist;
          p[e.to] = G[u][i];
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = true; if(++cnt[e.to] > n) return true; }
        }
      }
    }
    return false;
  }
};

BellmanFord solver;

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    solver.init(n);
    while(m--) {
      int u, v, w;
      scanf("%d%d%d", &u, &v, &w);
      solver.AddEdge(u, v, w);
    }
    if(solver.negativeCycle(0)) printf("possible\n"); else printf("not possible\n");
  }
  return 0;
}
