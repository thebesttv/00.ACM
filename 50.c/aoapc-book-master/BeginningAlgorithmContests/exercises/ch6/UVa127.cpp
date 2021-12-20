// UVa127 "Accordian" Patience
// Rujia Liu
/*

���⣺

  ��52���ƴ������źã�ÿ�����Գ�һ���ƶ�(pile)��
  ��ĳ����������������ƻ�����ߵ������ơ�match������ɫsuit���ߵ���rank��ͬ����ʱ�򣬾Ͱ��������Ƶ�����������ȥ��
  �ƶ�֮��Ҫ�����Ƿ���Խ����������ƶ���ֻ��λ���ƶѶ������Ʋ����ƶ����߲���match��
  ���ƶ�֮����ֿ�϶��ʱ��Ҫ���̰��ұߵ������ƶ�����һ�������϶��
  ����ж����ƿ����ƶ������ƶ�����ߵ������ƣ�����ȿ�����һ��Ҳ�����������ʱ�������� 

�㷨��ÿ������һ��ջ�������ƶ��γ�һ������Ϊ�˷����жϺʹ洢����(rank, suit)ת��������rank*4+suit

*/

#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int ncard = 52;

struct Pile {
  int t;
  int cards[ncard];
  int next, prev;
  int top() const { return cards[t]; }
  int pop() { return cards[t--]; }
  void push(int v) { cards[++t] = v; }
  bool empty() const { return t == -1; }
} pile[ncard+1]; // pile[52]�������

const char* suits = "CDHS";
const char* ranks = "A23456789TJQK";

int card2int(char r, char s) {
  int suit = strchr(suits, s) - suits;
  int rank = strchr(ranks, r) - ranks;
  return rank*4+suit;
}

bool read_input() {
  char card[5];
  for(int i = 0; i < ncard; i++) {
    if(scanf("%s", card) != 1) return false;
    pile[i].cards[0] = card2int(card[0], card[1]);
    pile[i].t = 0;
    pile[i].prev = i-1;
    pile[i].next = i+1;
  }
  return true;
}

// ��p�����k�ѵı��
int left(int p, int k) {
  while(k--) {
    p = pile[p].prev;
    if(p < 0) return -1;
  }
  return p;
}

inline int match(int card1, int card2) {
  return card1 % 4 == card2 % 4 || card1 / 4 == card2 / 4;
}

// �ƶ�p���������Ƿ�����ƶ�
bool can_move(int p) {
  int card = pile[p].top();
  int p1 = left(p, 1);
  int p3 = left(p, 3);
  if(p3 >= 0 && match(card, pile[p3].top())) return true;
  if(p1 >= 0 && match(card, pile[p1].top())) return true;
  return false;
}

void move(int p) {
  int card = pile[p].top();
  int cur = p;
  for(;;) {
    int p1 = left(cur, 1);
    int p3 = left(cur, 3);
    if(p3 >= 0 && match(card, pile[p3].top())) { cur = p3; continue; }
    if(p1 >= 0 && match(card, pile[p1].top())) { cur = p1; continue; }
    break;
  }
  // ��p�ƶ���cur
  pile[p].pop();
  pile[cur].push(card);
  if(pile[p].empty()) {
    int left = pile[p].prev, right = pile[p].next;
    pile[left].next = right; pile[right].prev = left;
  }
}

int main() {
  for(;;) {
    if(!read_input()) break;
    for(;;) {
      // ��һ�ſ����ƶ�����
      int p = 0;
      while(p < ncard) {
        if(can_move(p)) break;
        p = pile[p].next;
      }
      if(p == ncard) break; // ���ƿ����ƶ�
      move(p);
    }

    // ���
    vector<int> ans;
    int p = 0;
    while(p < ncard) {
      ans.push_back(pile[p].t+1);
      p = pile[p].next;
    }
    int n = ans.size();
    printf("%d pile", n);
    if(n > 1) printf("s");
    printf(" remaining:");
    for(int i = 0; i < n; i++) printf(" %d", ans[i]);
    printf("\n");
  }
  return 0;
}
