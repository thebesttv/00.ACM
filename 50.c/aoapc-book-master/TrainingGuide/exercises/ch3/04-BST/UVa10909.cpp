// UVa10909 Lucky Number
// Rujia Liu
// ˼·�����http://www.algorithmist.com/index.php/User:Sweepline/UVa_10909.cpp
// ������ֻ��Treap��Ӧ��չʾ���������ķ������þ�̬BST

#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxnode = 600000; // ʵ����571458�����

struct Node {
  Node *ch[2]; // ��������
  int r; // ������ȼ�
  int v; // ֵ
  int s; // �������
  Node(int v = 0):v(v) { ch[0] = ch[1] = NULL; r = rand(); s = 1; }
  int cmp(int x) const {
    if (x == v) return -1;
    return x < v ? 0 : 1;
  }
  void maintain() {
    s = 1;
    if(ch[0] != NULL) s += ch[0]->s;
    if(ch[1] != NULL) s += ch[1]->s;
  }
} pool[maxnode]; // ����

int pool_head;

inline Node* new_node(int x) {
  Node* p = &pool[pool_head++];
  p->v = x;
  return p;
}

void rotate(Node* &o, int d) {
  Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o; 
  o->maintain(); k->maintain(); o = k;
}

void insert(Node* &o, int x) {
  if(o == NULL) o = new_node(x);
  else {
    int d = (x < o->v ? 0 : 1); // ��Ҫ��cmp��������Ϊ���ܻ�����ͬ���
    insert(o->ch[d], x);
    if(o->ch[d]->r > o->r) rotate(o, d^1);
  }
  o->maintain();
}

Node* find(Node* o, int x) {
  if(o == NULL) return NULL;
  if(x == o->v) return o;
  return x < o->v ? find(o->ch[0], x) : find(o->ch[1], x);
}

// Ҫȷ��������
void remove(Node* &o, int x) {
  int d = o->cmp(x);
  if(d == -1) {
    Node* u = o;
    if(o->ch[0] != NULL && o->ch[1] != NULL) {
      int d2 = (o->ch[0]->r > o->ch[1]->r ? 1 : 0);
      rotate(o, d2); remove(o->ch[d2], x);
    } else {
      if(o->ch[0] == NULL) o = o->ch[1]; else o = o->ch[0];
    }
  } else
    remove(o->ch[d], x);
  if(o != NULL) o->maintain();
}

int kth(Node* o, int k) {
  if(o == NULL || k <= 0 || k > o->s) return 0;
  int s = (o->ch[0] == NULL ? 0 : o->ch[0]->s);
  if(k == s+1) return o->v;
  else if(k <= s) return kth(o->ch[0], k);
  else return kth(o->ch[1], k-s-1);
}

// ����oΪ���������У�ֵ��xС�Ľ��������1
int rank(Node* o, int x) {
  if(o == NULL) return 1;
  if(x <= o->v) return rank(o->ch[0], x);
  return rank(o->ch[1], x) + (o->ch[0] == NULL ? 0 : o->ch[0]->s) + 1;
}

//////// ��Ŀ���

const int maxn = 2000000;
int lucky[maxn + 10];

void dfs(Node* n) {
  if(n == NULL) return;
  lucky[n->v] = 1;
  dfs(n->ch[0]);
  dfs(n->ch[1]);
}

int main() {
  pool_head = 0;
  Node* root = NULL;
  memset(lucky, 0, sizeof(lucky));

  // �����ʼ��㣬ֱ������ǰ���ֻᱻɾ���Ľ��
  for(int i = 1, k = 1; k <= maxn; k += 6) {
    if(i % 7 != 0) insert(root, k); i++;
    if(i % 7 != 0) insert(root, k+2); i++;
  }

  // ɾ�������ӵ����ֿ�ʼִ��
  for(int i = 4; i <= root->s; i++) {
    int step = kth(root, i);
    if(step > root->s) break;
    for(int j = step; j <= root->s; j += step-1)
      remove(root, kth(root, j));
  }

  // ���lucky number
  dfs(root);

  // �ش�ѯ��
  int n;
  while(scanf("%d", &n) == 1) {
    int ok = 0;
    if(n % 2 == 0) { // ż���ſ����н�
      for(int x = n/2; x > 0; x--) if(lucky[x] && lucky[n-x]) {
        printf("%d is the sum of %d and %d.\n", n, x, n-x);
        ok = 1;
        break;
      }
    }
    if(!ok) printf("%d is not the sum of two luckies!\n", n);
  }
  return 0;
}
