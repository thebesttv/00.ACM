// UVa128 Software CRC
// Rujia Liu
// ���⣺����һ���ַ���������Ϊ�գ��������з������������CRC��
// CRC���壺��ÿ���ַ�������һλ256������֮���ټ������ֽ�֮��ʹ���ܱ�34943���������ж�⣬���ϵ������ֽ�Ӧ����С��
// �㷨�����մ���ȡ��ķ������ַ��������00 00֮�����34943������m����m=0ʱ��Ϊ0���������34943-m��
#include<cstdio>
#include<cstring>
const int MOD = 34943;
const int maxn = 1024 + 10;
char s[maxn], buf[5];

int main() {
  while(fgets(s, maxn, stdin)) {
    if(s[0] == '#') break;
    int m = 0, n = strlen(s) - 1; // ��1��ȥ���س���
    for(int i = 0; i < n; i++)
      m = (m * 256 + s[i]) % MOD;
    m = (long long)m * 65536 % MOD; // ע�����65536���ܻ����
    if(m > 0) m = MOD - m;
    sprintf(buf, "%04X", m);
    printf("%c%c %c%c\n", buf[0], buf[1], buf[2], buf[3]);
  }
  return 0;
}
