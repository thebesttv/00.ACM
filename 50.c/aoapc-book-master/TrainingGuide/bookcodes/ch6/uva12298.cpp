// UVa12298 Super Poker II
// Rujia Liu
#include <complex>
#include <cmath>
#include <vector>
using namespace std;

const long double PI = acos(0.0) * 2.0;

typedef complex<double> CD;

// Cooley-Tukey¿FFT¿¿¿¿¿¿¿¿inverse = false¿¿¿¿FFT
inline void FFT(vector<CD> &a, bool inverse) {
  int n = a.size();
  // ¿¿¿¿bit reversal
  for(int i = 0, j = 0; i < n; i++) {
    if(j > i) swap(a[i], a[j]);
    int k = n;
    while(j & (k >>= 1)) j &= ~k;
    j |= k;
  }

  double pi = inverse ? -PI : PI;
  for(int step = 1; step < n; step <<= 1) {
    // ¿¿¿¿¿¿¿step¿DFT¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿2*step¿DFT¿
    double alpha = pi / step;
    // ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿DFT¿¿¿¿¿¿¿¿¿k
    // ¿¿¿¿¿¿k¿¿¿¿¿DFT¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿E[k]¿O[k]¿¿X[k]
    // ¿¿¿¿¿¿¿http://en.wikipedia.org/wiki/Butterfly_diagram
    for(int k = 0; k < step; k++) {
      // ¿¿omega^k. ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿omega¿¿¿¿¿¿¿¿¿¿¿¿
      // ¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿¿
      CD omegak = exp(CD(0, alpha*k)); 
      for(int Ek = k; Ek < n; Ek += step << 1) { // Ek¿¿¿DFT¿¿¿E[k]¿¿¿¿¿¿¿¿¿
        int Ok = Ek + step; // Ok¿¿DFT¿¿¿O[k]¿¿¿¿¿¿¿¿¿
        CD t = omegak * a[Ok]; // ¿¿¿¿¿x1 * omega^k
        a[Ok] = a[Ek] - t;  // ¿¿¿¿¿y1 = x0 - t
        a[Ek] += t;         // ¿¿¿¿¿y0 = x0 + t
      }
    }
  }

  if(inverse)
    for(int i = 0; i < n; i++) a[i] /= n;
}

// ¿FFT¿¿¿¿¿¿¿¿¿¿
inline vector<double> operator * (const vector<double>& v1, const vector<double>& v2) {
  int s1 = v1.size(), s2 = v2.size(), S = 2;
  while(S < s1 + s2) S <<= 1;
  vector<CD> a(S,0), b(S,0); // ¿FFT¿¿¿¿¿¿¿2¿¿¿¿¿¿v1¿v2¿¿¿¿¿
  for(int i = 0; i < s1; i++) a[i] = v1[i];
  FFT(a, false);
  for(int i = 0; i < s2; i++) b[i] = v2[i];
  FFT(b, false);
  for(int i = 0; i < S; i++) a[i] *= b[i];
  FFT(a, true);
  vector<double> res(s1 + s2 - 1);
  for(int i = 0; i < s1 + s2 - 1; i++) res[i] = a[i].real(); // ¿¿¿¿0
  return res;
}

/////////// ¿¿¿¿
#include<cstdio>
#include<cstring>
const int maxn = 50000 + 10;

int composite[maxn];
void sieve(int n) {
  int m = (int)sqrt(n+0.5);
  memset(composite, 0, sizeof(composite));
  for(int i = 2; i <= m; i++) if(!composite[i])
    for(int j = i*i; j <= n; j+=i) composite[j] = 1;
}

const char* suites = "SHCD";
int idx(char suit) {
  return strchr(suites, suit) - suites;
}

int lost[4][maxn];
int main(int argc, char *argv[]) {
  sieve(50000);
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) == 3 && a) {
    memset(lost, 0, sizeof(lost));
    for(int i = 0; i < c; i++) {
      int d; char s;
      scanf("%d%c", &d, &s);
      lost[idx(s)][d] = 1;
    }   
    vector<double> ans(1,1), poly;
    for(int s = 0; s < 4; s++) {
      poly.clear();
      poly.resize(b+1, 0);
      for(int i = 4; i <= b; i++)
        if(composite[i] && !lost[s][i]) poly[i] = 1.0;
      ans = ans * poly;
      ans.resize(b+1);
    }
    for(int i = a; i <= b; i++)
      printf("%.0lf\n", fabs(ans[i]));    
    printf("\n");
  }
  return 0;
}
