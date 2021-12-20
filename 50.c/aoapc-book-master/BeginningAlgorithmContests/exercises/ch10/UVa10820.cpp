// UVa10820 Send a Table
// Rujia Liu
// ���⣺һ��������Ŀ������������x, y��1<=x,y<=n�������ĳ������f(x,y)��ĳ���뽻�����Ǳ�̫����Ҫ����
// ��֪�����׸���f(x,y)���f(x*k, y*k)����˺��߾Ͳ���Ҫ����ˡ�����n�������Ĵ�С��
// �����������n������ж��ٶ�(x,y)����1<=x,y<=n, gcd(x,y)=1
// �㷨���������x<y�ĸ�����f(n)������ô�𰸾���2f(n)+1�����ѷ���f(n)=phi(2)+phi(3)+...+phi(n)
#include<cstdio>
#include<cmath>
const int maxn = 50000;
int phi[maxn+1], phi_psum[maxn+1];

void phi_table(int n) {
  phi[1] = 0;
  for(int i = 2; i <= n; i++) if(phi[i] == 0)
  for(int j = i; j <= n; j += i) {
    if(phi[j] == 0) phi[j] = j;
    phi[j] = phi[j] / i * (i-1);
  }
}

int main(){
  int n;
  phi_table(maxn);
  phi_psum[0] = 0;
  for(int i = 1; i <= maxn; i++)
    phi_psum[i] = phi_psum[i-1] + phi[i];
  while(scanf("%d", &n) == 1 && n)
    printf("%d\n",2*phi_psum[n] + 1);
  return 0;
}
