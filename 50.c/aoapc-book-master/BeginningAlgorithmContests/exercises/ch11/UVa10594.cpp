// UVa10594 Data Flow
// Rujia Liu
// ���⣺��һ���������磬���1��n������ΪD����С������
// �㷨����һ����0����һ��0->1������ΪD����Ϊ0�Ļ�����0��n����С���������
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<cassert>
using namespace std;

const int maxn = 100 + 10;
const int INF = 1000000000;

typedef long long LL;

struct Edge {
  int from, to, cap, flow, cost;
  Edge(int u, int v, int c, int f, int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};

struct MCMF {
  int n, m;
  vector<Edge> edges;
  vector<int> G[maxn];
  int inq[maxn];         // �Ƿ��ڶ�����
  int d[maxn];           // Bellman-Ford
  int p[maxn];           // ��һ����
  int a[maxn];           // �ɸĽ���

  void init(int n) {
    this->n = n;
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap, int cost) {
    edges.push_back(Edge(from, to, cap, 0, cost));
    edges.push_back(Edge(to, from, 0, 0, -cost));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  bool BellmanFord(int s, int t, int& flow, LL& cost) {
    for(int i = 0; i < n; i++) d[i] = INF;
    memset(inq, 0, sizeof(inq));
    d[s] = 0; inq[s] = 1; p[s] = 0; a[s] = INF;

    queue<int> Q;
    Q.push(s);
    while(!Q.empty()) {
      int u = Q.front(); Q.pop();
      inq[u] = 0;
      for(int i = 0; i < G[u].size(); i++) {
        Edge& e = edges[G[u][i]];
        if(e.cap > e.flow && d[e.to] > d[u] + e.cost) {
          d[e.to] = d[u] + e.cost;
          p[e.to] = G[u][i];
          a[e.to] = min(a[u], e.cap - e.flow);
          if(!inq[e.to]) { Q.push(e.to); inq[e.to] = 1; }
        }
      }
    }
    if(d[t] == INF) return false;
    flow += a[t];
    cost += (LL)d[t] * (LL)a[t];
    for(int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += a[t];
      edges[p[u]^1].flow -= a[t];
    }
    return true;
  }

  // ��Ҫ��֤��ʼ������û�и�ȨȦ
  int MincostMaxflow(int s, int t, LL& cost) {
    int flow = 0; cost = 0;
    while(BellmanFord(s, t, flow, cost));
    return flow;
  }

};

MCMF g;

const int maxm = 5000 + 5;
int u[maxm], v[maxm], c[maxm];

int main() {
  int n, m, d, k;
  while(scanf("%d%d", &n, &m) == 2) {
    g.init(n+1);
    for(int i = 0; i < m; i++)
      scanf("%d%d%d", &u[i], &v[i], &c[i]);
    scanf("%d%d", &d, &k);
    for(int i = 0; i < m; i++) {
      g.AddEdge(u[i], v[i], k, c[i]);
      g.AddEdge(v[i], u[i], k, c[i]);
    }
    g.AddEdge(0, 1, d, 0);

    LL cost;
    int flow = g.MincostMaxflow(0, n, cost);
    if(flow < d) printf("Impossible.\n");
    else printf("%lld\n", cost);
  }
  return 0;
}
