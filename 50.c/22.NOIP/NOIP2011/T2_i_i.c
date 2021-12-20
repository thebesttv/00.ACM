/*
描述
丽江河边有n家很有特色的客栈，客栈按照其位置顺序从1到n编号。每家客栈都按照某一种色调进行装饰（总共k种，用整数0~ k-1表示），且每家客栈都设有一家咖啡店，每家咖啡店均有各自的最低消费。
两位游客一起去丽江旅游，他们喜欢相同的色调，又想尝试两个不同的客栈，因此决定分别住在色调相同的两家客栈中。晚上，他们打算选择一家咖啡店喝咖啡，要求咖啡店位于两人住的两家客栈之间（包括他们住的客栈），且咖啡店的最低消费不超过p。
他们想知道总共有多少种选择住宿的方案，保证晚上可以找到一家最低消费不超过p元的咖啡店小聚。

格式
输入格式
第一行三个整数n，k，p，每两个整数之间用一个空格隔开，分别表示客栈的个数，色调的数目和能接受的最低消费的最高值；
接下来的n行，第i+1行两个整数，之间用一个空格隔开，分别表示i号客栈的装饰色调和i号客栈的咖啡店的最低消费。

输出格式
输出只有一行，一个整数，表示可选的住宿方案的总数。

样例1
样例输入1
5 2 3
0 5
1 3
0 2
1 4
1 5

样例输出1
3

限制
1s

提示
对于30%的数据，有n≤100；
对于50%的数据，有n≤1,000；
对于100%的数据，有2≤n≤200,000，0<k≤50，0≤p≤100，0≤最低消费≤100。

来源
NOIp2011提高组Day1第二题
*/

/*
  得分：60
  解题报告：
    那个200000的数据实在不知道不知道怎么求。。。
    用min[l,r]表示[l,r]中最小的价格，对min动规，然后枚举。
  正解： O(n)
    首先，抛开套路，抛开dp，真正模拟一遍，即是不是用与正解相同的方法，也会有一点感觉。
    顺序扫描一遍，因为不能重复，所有对每个客栈，都只考虑让它与之前客栈配对。
      对于色调为i的客栈，能与其配对的客栈一定要满足：
        1.色调相同
        2.两个客栈端点或之间有一家价格符合预期的咖啡店
      那么，为了使得能够最多地配对，那家咖啡店一定是与当前客栈最近的，也就是最后一个价格<=p的咖啡店。
      因此，想到维护一个last变量，表示最后一个价格<=p的咖啡店位置。
      但并不是在当前客栈之前的所有色调相同的客栈都是在last或其前面，还有些是在last后面，因此要使用一个数组c[i]表示色调为i的、且在last或其前面的咖啡店的个数。而想要维护c，还需要更多变量。
      需要数组a和数组b，a[i],b[i]分别表示最后一个色调为i的客栈的位置色色调为i的客栈的个数。
        每次读入，先判断是否符合预期，并更新last。
        然后，如果连最后一个色调为i的客栈都在last或其前面，则可以更新c[i]，否则不更新。
        再使其配对，即sum增加c[i]，最后更新a[i],b[i]即可。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=200020;
int a[MAX]; //a[i]: 最后一个色调为i的客栈的位置
int b[MAX]; //b[i]: 色调为i的客栈的个数
int c[MAX]; //c[i]: 在last即其之前的色调为i的客栈的个数，用于计算sum
int n,k,p;

int main(void){
  scanf("%d%d%d",&n,&k,&p);
  int color,price;
  int last=0,sum=0; //last: 最后一个价格<=p的咖啡店位置
  for(int i=0;i<n;i++){
    scanf("%d%d",&color,&price);
    if(price<=p) last=i;
    if(a[color]<=last) c[color]=b[color];
    //如果连最后一个色调相同的客栈都在last或其前面，那么之前每个色调相同的客栈都可以与当前客栈配对形成一种方案
    //否则，则不更新，c[color]中的客栈数目还是之前的
    sum+=c[color];
    b[color]++; a[color]=i;
  }
  printf("%d\n",sum);
  
  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<list>
using namespace std;

const int MAX=1000+20;
int check[MAX][MAX];
int color[MAX],price[MAX];
list<int> li[60];

int getMin(int l, int r){
  int & a=check[l][r];
  if(a!=-1) return a;
  if(l==r) a=price[l];
  else a=min(price[l],getMin(l+1,r));
  return a;
}

int main(void){
  memset(check,-1,sizeof(check));
  int n,k,p; scanf("%d%d%d",&n,&k,&p);
  for(int i=0;i<n;i++) {scanf("%d%d",&color[i],&price[i]); li[color[i]].push_back(i);}
  int cnt=0;
  list<int>::iterator it1,it2;

  //for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(color[i]==color[j]){
  //  int tMin=getMin(i,j);
  //  if(tMin<=p) cnt++;
  //}

  for(int i=0;i<k;i++) for(it1=li[i].begin();it1!=li[i].end();it1++){
    it2=it1; it2++;
    for(;it2!=li[i].end();it2++){
      int tMin=getMin(*it1,*it2);
      if(tMin<=p) cnt++;
    }
  }
  printf("%d\n",cnt);

  return 0;
}
*/
