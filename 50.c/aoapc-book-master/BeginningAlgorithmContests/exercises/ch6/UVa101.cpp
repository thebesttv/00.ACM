// UVa101 The Blocks Problem
// Rujia Liu
/*
  ���⣺
  ��������n��ľ�飬���Ϊ0~n-1��Ҫ��ģ��һЩ�����������֣������a��b����ľ���ţ���
  move a onto b����a��b�Ϸ���ľ��ȫ����λ��Ȼ���a����b����
  move a over b����a�Ϸ���ľ��ȫ����λ��Ȼ���a����b����ľ��ѵĶ���
  pile a onto b����b�Ϸ���ľ��ȫ����λ��Ȼ���a�������ľ����������b����
  pile a over b����a�������ľ����������b����ľ��ѵĶ���
  ����quitʱ��ֹһ�����ݡ�a��b��ͬһ�ѵ�ָ���ǷǷ�ָ�Ӧ�����ԡ�
*/

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

// ��ľ��a���ڵ�pile��height
void find_block(int a, int& p, int& h) {
  for(p = 0; p < n; p++)
    for(h = 0; h < pile[p].size(); h++)
      if(pile[p][h] == a) return;
}

void clear_above(int p, int h) {
  for(int i = h+1; i < pile[p].size(); i++) {
    int b = pile[p][i];
    pile[b].push_back(b); // ��ľ��b�Ż�ԭλ
  }
  pile[p].resize(h+1);
}

// �ѵ�p�Ѹ߶�h�����Ϸ���ľ�������ƶ���p2�ѵĶ���
void pile_onto(int p, int h, int p2) {
  for(int i = h; i < pile[p].size(); i++)
    pile[p2].push_back(pile[p][i]);
  pile[p].resize(h);
}

void print() {
  for(int i = 0; i < n; i++) {
    printf("%d:", i);
    for(int j = 0; j < pile[i].size(); j++) printf(" %d", pile[i][j]);
    printf("\n");
  }  
}

int main() {
  int a, b;
  cin >> n;
  string s1, s2;
  for(int i = 0; i < n; i++) pile[i].push_back(i);
  while(cin >> s1 >> a >> s2 >> b) {
    int pa, pb, ha, hb;
    find_block(a, pa, ha);
    find_block(b, pb, hb);
    if(pa == pb) continue; // �Ƿ�ָ��
    if(s2 == "onto") clear_above(pb, hb);
    if(s1 == "move") clear_above(pa, ha);
    pile_onto(pa, ha, pb);
  }
  print();
  return 0;
}
