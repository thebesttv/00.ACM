// UVa565 Pizza Anyone?
// Rujia Liu
// ���⣺��A~P��16�֣���n������+A-B+D��Լ������ʾҪA���߲�ҪB����ҪD������һ�ַ�����������Լ��
// �㷨�����ݷ�
// ��ʾ���������ݽ϶ֱ࣬��2^16�Ӽ�ö�ٻᳬʱ�����ݷ����Ա������õ�ö�٣����ע��
// ���⻹��һ������������������Լ�������㷽ʽ������������ÿ����ĸҪ���ǲ�Ҫ�����߿���һ��
#include<cstdio>
#include<cstring>
const int C = 'P' - 'A' + 1;
int n;
int mask[C][2]; // mask[i][v]��ʾ��i����ĸȡv��0����1��ʱ������ֱ�������Լ������

bool dfs(int d, int used, int satisfied) {
  if(d == C) {
    if(satisfied < (1<<n) - 1) return false;
    printf("Toppings: ");
    for(int i = 0; i < C; i++) if(used & (1<<i)) printf("%c", 'A'+i);
    printf("\n");
    return true;
  }
  int m0 = satisfied | mask[d][0];
  int m1 = satisfied | mask[d][1];
  if(dfs(d+1, used, m0)) return true;
  if(m0 != m1 && dfs(d+1, used | (1<<d), m1)) return true; // ��������ö�١�����Ż���Ȼ�򵥵�Ч���ǳ���
  return false;
}

bool init() {
  n = 0;
  memset(mask, 0, sizeof(mask));
  for(;;) {
    char line[50];
    if(scanf("%s", line) != 1) return false;
    if(line[0] == '.') return true;
    for(int i = 0; i < strlen(line)-1; i += 2) {
      int elem = line[i+1] - 'A';
      int v = line[i] == '+' ? 1 : 0;
      mask[elem][v] |= 1 << n;
    }
    n++;
  }
}

int main() {
  for(;;) {
    if(!init()) break;
    if(!dfs(0, 0, 0)) printf("No pizza can satisfy these requests.\n");
  }
  return 0;
}
