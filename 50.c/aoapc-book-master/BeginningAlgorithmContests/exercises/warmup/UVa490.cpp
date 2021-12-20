// UVa490 Rotating Sentences
// Rujia Liu
// ע�����UVaOJҪ����������ϸ�Ϊ�ַ������ÿո��룬����ʵ��Ŀ�����ﲢû�������һҪ��
#include<cstdio>
#include<cstring>
const int maxn = 100 + 5;
int r, c;
char line[maxn], buf[maxn][maxn];

int main() {
  r = c = 0;
  memset(buf, ' ', sizeof(buf));
  while(fgets(line, maxn, stdin) != NULL) {
    int len = strlen(line);
    if(line[len-1] == '\n') len--;
    if(len > c) c = len;
    for(int i = 0; i < len; i++) buf[r][i] = line[i];
    r++;
  }
  for(int i = 0; i < c; i++) {
    for(int j = r-1; j >= 0; j--)
      printf("%c", buf[j][i]);
    printf("\n");
  }
  return 0;
}
