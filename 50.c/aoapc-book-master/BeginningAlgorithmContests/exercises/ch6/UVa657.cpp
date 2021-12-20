// UVa657 The die is cast
// Rujia Liu
// ���⣺��һ��ͼ��������'.'��ʾ��������'.'�ַ���ɵ���ͨ��Ϊɸ�ӡ�ÿ��ɸ�����ְ��������ַ�������'X'��ɵ���ͨ���ʾɸ���ϵĵ�
// ͳ��ÿ��ɸ�����ж��ٸ���X����ͨ��
// �㷨��������DFS�ҳ�������ͨ�飬��ɸ�ӣ�'.'��'X'���͵㣨'X'���������0��1��ʾ��Ȼ��ͳ��0����ͨ���1����ͨ��֮��İ�����ϵ�����������
// �ڴ����У�cnt[i]Ϊ��i����ͨ��ĸ�����idx[i][r][c]Ϊ����(r,c)����i����ͨ�����ı��
// enclose[i][j]��ʾ���Ϊi�ĵ�0����ͨ���Ƿ�������Ϊj�ĵ�1����ͨ��
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50;   // ͼƬ�߳������ֵ
const int maxd = 1000; // ɸ�ӵ�������
const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

char pic[maxn][maxn];
int h, w, idx[2][maxn][maxn], cnt[2]; 
int enclose[maxd][maxd*6];

bool is_type(int type, char ch) {
  if(type == 0) return ch != '.'; // ɸ�ӣ������㣩
  return ch == 'X'; // ��
}

// DFS�ҵ�type����ͨ�飬������id
void dfs(int r, int c, int type, int id) {
  if(r < 0 || r >= h || c < 0 || c >= w) return;
  if(!is_type(type, pic[r][c])) return;
  if(idx[type][r][c] > 0) return;
  idx[type][r][c] = id;
  for(int d = 0; d < 4; d++)
    dfs(r+dr[d], c+dc[d], type, id);
}

// ���(r,c)����0����ͨ��������Ϊid��1����ͨ��
void mark(int r, int c, int id) {
  if(r >= 0 && r < h && c >= 0 && c < w)
    enclose[idx[0][r][c]][id] = 1;
}

int main() {
  int kase = 0;
  while(scanf("%d%d", &w, &h) == 2 && w) {
    for(int i = 0; i < h; i++)
      scanf("%s", pic[i]);

    // DFS����ͨ��
    memset(idx, 0, sizeof(idx));
    cnt[0] = cnt[1] = 0;
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++) 
        for(int t = 0; t < 2; t++) {
          if(idx[t][i][j] == 0 && is_type(t, pic[i][j])) dfs(i, j, t, ++cnt[t]);
        }

    // ���������ϵ
    memset(enclose, 0, sizeof(enclose));
    for(int i = 0; i < h; i++)
      for(int j = 0; j < w; j++)
        if(pic[i][j] == 'X')
          for(int d = 0; d < 4; d++)
            mark(i+dr[d], j+dc[d], idx[1][i][j]);

    // ͳ�Ƶ�����ע��������ͨ�����1��ʼ���
    int ans[maxd];
    for(int i = 1; i <= cnt[0]; i++) {
      ans[i] = 0;
      for(int j = 1; j <= cnt[1]; j++)
        if(enclose[i][j]) ans[i]++;
    }
    sort(ans+1, ans+cnt[0]+1);

    // �����ע����ĩ��Ҫ�������ո�
    printf("Throw %d\n", ++kase);
    for(int i = 1; i < cnt[0]; i++)
      printf("%d ", ans[i]);
    printf("%d\n\n", ans[cnt[0]]);
  }
  return 0;
}
