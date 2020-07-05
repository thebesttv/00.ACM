#include <bits/stdc++.h>
#define MIN(a,b) ((((a)<(b)?(a):(b))))
#define MAX(a,b) ((((a)>(b)?(a):(b))))
#define ABS(a) ((((a)>0?(a):-(a))))
using namespace std;

template <typename T>
void read(T &x) {
  int s = 0, c = getchar();
  x = 0;
  while (isspace(c)) c = getchar();
  if (c == 45) s = 1, c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  if (s) x = -x;
}

template <typename T>
void write(T x, char c = ' ') {
  int b[40], l = 0;
  if (x < 0) putchar(45), x = -x;
  while (x > 0) b[l++] = x % 10, x /= 10;
  if (!l) putchar(48);
  while (l) putchar(b[--l] | 48);
  putchar(c);
}

const int N=1e5+8;

bool sign[N];

int n,ma,u[N],cnt[N];

LL ans;

vector<int> d[N];

stack<LL> s;

void pre(){
  for(int i=1;i<=ma;++i){
    for(int j=i;j<=ma;j+=i)
      d[j].push_back(i); 

    if (i==1)
      u[i]=1;
    else if (i/d[i][1]%d[i][1]==0)
      u[i]=0;
    else
      u[i]=-u[i/d[i][1]];
  }
}

int coprime(int x){
  int tmp=0;
  for(int i:d[x])
    tmp+=u[i]*cnt[i];
  return tmp;
}

void updata(int x,int val){
  for(int i:d[x])
    cnt[i]+=val;
}

int main(void) {
  //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  read(n);
  for(int a,i=1;i<=n;++i){
    read(a); sign[a]=true;
    ma=MAX(ma,a);
  }
  pre();

  for(int i=1;i<=ma;++i)
    for(int j=2;i*j<=ma;++j)
      sign[i]|=sign[i*j];

  for(int qwq,i=ma;i>=1;--i){
    if (!sign[i]) continue;
    qwq=coprime(i);
    while(qwq){
      if (__gcd(s.top(),(LL)i)==1){
        ans=max(s.top()*(LL)i,ans);
        --qwq;
      }
      updata(s.top(),-1);
      s.pop();
    }
    updata(i,1);
    s.push((LL)i);
  }
  write(ans,'\n');
  return 0;
}
