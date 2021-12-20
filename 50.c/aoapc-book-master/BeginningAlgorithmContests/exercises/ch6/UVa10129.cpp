// UVa10129 Play on Words
// Rujia Liu
// ���⣺����n�����ʣ��Ƿ�����ų�һ�����У�ʹ��ÿ�����ʵĵ�һ����ĸ����һ�����ʵ����һ����ĸ��ͬ
// �㷨������ĸ������㣬���ʿ�������ߣ����н⵱�ҽ���ͼ����ŷ��·����ע��Ҫ������ͨ
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxn = 1000 + 5;

// ���鼯������ժ�ԡ��㷨�������ž��䡪��ѵ��ָ�ϡ������£�
int pa[256];
int findset(int x) { return pa[x] != x ? pa[x] = findset(pa[x]) : x; } 

int used[256], deg[256]; // �Ƿ���ֹ�������

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n;
    char word[maxn];

    scanf("%d", &n);
    memset(used, 0, sizeof(used));
    memset(deg, 0, sizeof(deg));
    for(int ch = 'a'; ch <= 'z'; ch++) pa[ch] = ch; // ��ʼ�����鼯
    int cc = 26; // ��ͨ�����

    for(int i = 0; i < n; i++) {
      scanf("%s", word);
      char c1 = word[0], c2 = word[strlen(word)-1];
      deg[c1]++;
      deg[c2]--;
      used[c1] = used[c2] = 1;
      int s1 = findset(c1), s2 = findset(c2);
      if(s1 != s2) { pa[s1] = s2; cc--; }
    }

    vector<int> d;
    for(int ch = 'a'; ch <= 'z'; ch++) {
      if(!used[ch]) cc--; // û���ֹ�����ĸ
      else if(deg[ch] != 0) d.push_back(deg[ch]);
    }
    bool ok = false;
    if(cc == 1 && (d.empty() || (d.size() == 2 && (d[0] == 1 || d[0] == -1)))) ok = true;
    if(ok) printf("Ordering is possible.\n");
    else printf("The door cannot be opened.\n");
  }
  return 0;
}
