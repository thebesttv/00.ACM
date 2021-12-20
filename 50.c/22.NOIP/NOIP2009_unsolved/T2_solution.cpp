/*
先分解b1的质因数，因为按理说b1是大于等于a1和b0的，那么正常情况下a1的质因数和b0的质因数是包含在内的。

于是开始找。用b1.c[i]、b0.c[i]、a0.c[i]、a0.c[i]表示前面那个数的质因数数组（这里4个应该是一样的）_.len[i]表示前面那个数的当前质因数个数

怎么找质因数？定义x=2，用while循环和x++即可。

接下来就是处理。我们可以想到，枚举第i个质因数时，若b1含的指数是大于b0的，那么x只能为b1的那个指数。原因：若x比b1指数小，则最小公倍数为x或者b0，而非b1。若x比b1指数大，则最小公倍数为x。因此此时x取指数只能为唯一情况。同理，若a0的指数大于a1，则x只能为a1的那个指数，解释方法相同。那么这两种情况同时存在呢？这个时候，x的2个取值b1.num[i]！=a1.num[i]，则与题意矛盾，这组数据无解。当然，若b1.num[i]<a1.num[i]也是无解，因为这是不可能存在的。

最后的最后，若b1.num[i]=b0.num[i]&&a1.num[i]==a0.num[i]，则x能取的指数个数则为两个个数中间的那个区间。这样就求出了x在各个质数能取的情况，最后用乘法原理乘起来就得到了ans         ~\(≧▽≦)/~啦啦啦！

代码：
 */

#include<iostream>
#include<cstdio>
using namespace std;
int n,ans=0;int p=1;
struct node{
  int la,c[2005],num[2005],tot;
}a0,a1,b0,b1;
int l[2005],r[2005];
int main() {
  freopen("son.in","r",stdin);
  freopen("son.out","w",stdout);
  scanf("%d",&n);//cin>>n;//数据数
  while(n>0) {
    n--;p=1;
    scanf("%d %d %d %d",&a0.la,&a1.la,&b0.la,&b1.la);//cin>>a0.la>>a1.la>>b0.la>>b1.la;
    int x=2;b1.tot=0;
    while(b1.la>=x*x){//分解质因数
      int len=0;
      while(b1.la%x==0){
        len++;
        b1.la/=x;
      }
      if(len>0){
        b1.c[++b1.tot]=x;
        b1.num[b1.tot]=len;
      }
      x++;
    }
    if(b1.la!=1){ //分解质因数
      b1.c[++b1.tot]=b1.la;
      b1.num[b1.tot]=1;
    }
    for(int i=1;i<=b1.tot;i++){
      int len=0;a0.c[i]=b1.c[i];
      while(a0.la%b1.c[i]==0){
        len++;
        a0.la/=b1.c[i];
      }
      a0.num[i]=len;
    }
    for(int i=1;i<=b1.tot;i++){
      int len=0;a1.c[i]=b1.c[i];
      while(a1.la%b1.c[i]==0){
        len++;
        a1.la/=b1.c[i];
      }
      a1.num[i]=len;
    }
    for(int i=1;i<=b1.tot;++i){
      int len=0;b0.c[i]=b1.c[i];
      while(b0.la%b1.c[i]==0){
        len++;
        b0.la/=b1.c[i];
      }
      b0.num[i]=len;
    }
    for(int i=1;i<=b1.tot;++i){
      if(b1.num[i]<a1.num[i]){ //不符
        p=0;
        break;
      }
      if(a1.num[i]!=a0.num[i]&&b1.num[i]>a1.num[i]&&b1.num[i]!=b0.num[i]){//不符
        p=0;
        break;
      }
      if(a1.num[i]!=a0.num[i]){
        l[i]=a1.num[i];
        r[i]=a1.num[i];
        continue;
      }
      if(b1.num[i]!=b0.num[i]){
        l[i]=b1.num[i];
        r[i]=b1.num[i];
        continue;
      }
      l[i]=a1.num[i];r[i]=b1.num[i];//若都等于
    }
    ans=1;
    for(int i=1;i<=b1.tot;i++) ans*=(r[i]-l[i]+1);
    if(p==0)ans=0;
    printf("%d\n",ans);//cout<<ans<<endl;
  }
  return 0;
}
