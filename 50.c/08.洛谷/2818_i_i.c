/*
题目描述
Tenshi非常幸运地被选为掌管智慧之匙的天使。在正式任职之前，她必须和其他新当选的天使一样要宣誓。宣誓仪式是每位天使各自表述自己的使命，他们的发言稿放在n个呈圆形排列的宝盒中。这些宝盒按顺时针方向被编上号码1，2，…，n－1，n。一开始天使们站在编号为n的宝盒旁。她们各自手上都有一个数字，代表她们自己的发言稿所在的盒子是从1号盒子开始按顺时针方向的第几个。例如：有7个盒子，如果Tenshi手上的数字为9，那么她的发言稿所在的盒子就是2个。现在天使们开始按照自己手上的数字来找发言稿，先找到的就可以先发言。 Tenshi一下子就找打了，于是她最先上台宣誓：“我将带领大家开启Noi之门……” Tenshi宣誓结束后，陆续有天使上台宣誓。可是有一位天使找了好久都找不到她的发言稿，原来她手上的数字m非常大，她转了好久都找不到她想找的宝盒。
请帮助这位天使找到她想找的宝盒编号。

输入输出格式
输入格式：
第一行为正整数n，第二行为正整数m，其中n,m满足2<=n<=10^8，2<=m<=10^1000

输出格式：
只有一行（包括换行符），即天使想找的宝盒的编号。

输入输出样例
输入样例#1：
7
9

输出样例#1：
2

输入样例#2：
11
108

输出样例#2：
9
*/

/*
  其实完全不需要高精模高精，只要高精模单精，即边读入边取模即可。
  在最后要考虑ans是否等于0，如果ans为0，则要改为n
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

int main(void){
  int m; scanf("%d",&m);
  int ans=0,ch;
  while(ch=getchar()){
    if(ch==EOF) break;
    if(!isdigit(ch)) continue;
    ans=(ans*10+ch-'0')%m;
  }
  if(!ans) ans=m;
  printf("%d\n",ans);

  return 0;
}

/*
//高精，依然有问题
const int BASE=100000000;
const int WIDTH=8;
const int MAX=1020;
struct BI{
  int len;
  VR<int> v;
}zero,one,two;
char t1[MAX],t2[MAX];

BI add(BI a, BI b);
BI sub(BI a, BI b);
BI mul(BI a, BI b);
BI mul(BI a, int b);
BI div(BI a, BI b);
BI mod(BI a, BI b);
BI half(BI a);
void conv(char * s, BI & a);
void print(const BI & a);
int comp(const BI & a, const BI & b);

int main(void){
  zero.len=one.len=two.len=1;
  zero.v.push_back(0); one.v.push_back(1); two.v.push_back(2);
  scanf("%s%s",t1,t2); BI a,b;
  conv(t1,a); conv(t2,b);
  BI t=add(mod(add(mod(b,a),sub(a,one)),a),one);
  //BI t=mod(b,a); if(comp(t,zero)==0) t=a;
  print(t); printf("\n");

  return 0;
}

BI add(BI a, BI b){
  if(comp(a,b)<0) swap(a,b);
  int carry=0;
  FOR(i,0,a.len){
    a.v[i]+=carry;
    if(i<b.len) a.v[i]+=b.v[i];
    carry=a.v[i]/BASE; a.v[i]%=BASE;
  }
  if(carry) {a.v.push_back(carry); a.len++;}
  return a;
}
BI sub(BI a, BI b){
  if(comp(a,b)==0) return zero;
  if(comp(a,b)<0) swap(a,b);
  FOR(i,0,a.len){
    if(i<b.len){
      if(a.v[i]<b.v[i]) {a.v[i]+=BASE-b.v[i]; a.v[i+1]--;}
      else a.v[i]-=b.v[i];
    }else if(a.v[i]<0) {a.v[i]+=BASE; a.v[i+1]--;}
  }
  while(a.len>1 && !a.v[a.len-1]) {a.len--; a.v.pop_back();}
  return a;
}
BI mul(BI a, BI b){
  if(comp(a,b)<0) swap(a,b);
  BI c=zero;
  FOR(i,0,b.len){
    BI t=mul(a,b.v[i]);
    VR<int> v; FOR(j,0,i) v.push_back(0);
    FOR(j,0,t.len) v.push_back(t.v[j]);
    t.v=v; t.len=v.size();
    c=add(c,t);
  }
  return c;
}
BI mul(BI a, int b){
  long long carry=0;
  FOR(i,0,a.len){
    carry+=1LL*a.v[i]*b;
    a.v[i]=carry%BASE; carry/=BASE;
  }
  if(carry) a.v.push_back(carry),a.len++;
  return a;
}
BI div(BI a, BI b){
  if(comp(a,b)<0) return zero;
  else if(comp(a,b)==0) return one;
  else if(comp(b,one)==0) return a;
  BI L=one,R=a,M,t;
  while(comp(L,R)<0){
    M=half(add(add(L,R),one));
    t=mul(M,b);
    if(comp(a,t)<0) R=sub(M,one);
    else if(comp(a,t)==0) return M;
    else L=M;
  }
  return L;
}
BI half(BI a){
  ROR(i,a.len-1,1){
    if(a.v[i]&1) a.v[i-1]+=BASE;
    a.v[i]/=2;
  }
  a.v[0]/=2;
  if(!a.v[a.len-1]) {a.len--; a.v.pop_back();}
  return a;
}
BI mod(BI a, BI b){
  return sub(a,mul(div(a,b),b));
}
void conv(char * s, BI & a){
  a.v.clear();
  int l=strlen(s); char t[WIDTH+2];
  while(l>=WIDTH){
    strncpy(t,s+l-WIDTH,WIDTH); t[WIDTH]=0;
    a.v.push_back(atoi(t));
    l-=WIDTH;
  }
  if(l) {strncpy(t,s,l); t[l]=0; a.v.push_back(atoi(t));}
  a.len=a.v.size();
}
void print(const BI & a){
  if(!a.len) return;
  printf("%d",a.v[a.len-1]);
  ROR(i,a.len-2,0) printf("%04d",a.v[i]);
}
int comp(const BI & a, const BI & b){
  if(a.len!=b.len) return a.len-b.len;
  ROR(i,a.len-1,0) if(a.v[i]!=b.v[i])
    return a.v[i]-b.v[i];
  return 0;
}
*/
