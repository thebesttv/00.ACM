// UVa10330 Power Transmission
// Rujia Liu
// ���⣺��һ���������磬ÿ���ڵ�Ҳ��һ���������������
// �㷨�����������յ��⣬ÿ�������i���������2i��2i+1��Դ����0�������1
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 200 + 10;
const int INF = 1000000000;

struct Edge {
  int from, to, cap, flow;
  Edge(int u, int v, int c, int f):from(u),to(v),cap(c),flow(f) {}
};

struct EdmondsKarp {
  int n, m;
  vector<Edge> edges;    // ����������
  vector<int> G[maxn];   // �ڽӱ�G[i][j]��ʾ���i�ĵ�j������e�����е����
  int a[maxn];           // ����㵽i�ĿɸĽ���
  int p[maxn];           // ���·����p���뻡���

  void init(int n) {
    for(int i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(int from, int to, int cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m-2);
    G[to].push_back(m-1);
  }

  int Maxflow(int s, int t) {
    int flow = 0;
    for(;;) {
      memset(a, 0, sizeof(a));
      queue<int> Q;
      Q.push(s);
      a[s] = INF;
      while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if(!a[e.to] && e.cap > e.flow) {
            p[e.to] = G[x][i];
            a[e.to] = min(a[x], e.cap-e.flow);
            Q.push(e.to);
          }
        }
        if(a[t]) break;
      }
      if(!a[t]) break;
      for(int u = t; u != s; u = edges[p[u]].from) {
        edges[p[u]].flow += a[t];
        edges[p[u]^1].flow -= a[t];
      }
      flow += a[t];
    }
    return flow;
  }
};

EdmondsKarp g;

int main() {
  int n, m, u, v, c, b, d;
  while(scanf("%d", &n) == 1 && n) {
    g.init(2*n+2);
    // ���
    for(int i = 1; i <= n; i++) {
      scanf("%d", &c);
      g.AddEdge(i*2, i*2+1, c);
    }
    scanf("%d", &m);
    while(m--) {
      scanf("%d%d%d", &u, &v, &c);
      g.AddEdge(u*2+1, v*2, c);
    }
    scanf("%d%d", &b, &d);
    while(b--) { scanf("%d", &u); g.AddEdge(0, u*2, INF); }
    while(d--) { scanf("%d", &u); g.AddEdge(u*2+1, 1, INF); }
    printf("%d\n", g.Maxflow(0, 1));
  }
  return 0;
}
