/*
题目背景
紫女，韩国歌舞坊（实为刺客组织）紫兰轩之主，千娇百媚，美艳无方。武艺高强且极有谋略胆识，精通奇石药物，冶炼之术及制毒用毒之术独步天下，真实姓名与来历无人知晓，只因总是身着一袭紫衣，所以众人以“紫女”称之。与公子韩非共同创建了“流沙”组织。

题目描述
为了能够获取更多的韩国内部消息，紫女决定收购一批极为罕见的稀世珍宝在紫兰轩进行拍卖，以吸引更多的大人物前来紫兰轩。她准备在m天内购买一些宝物来充实库存。现在，市场上有n种物品，第i种物品的价格为vi，紫女每天最多只能购买xi个。第i天紫女得到wi的钱，她会选择不停购买能买得起的最贵的物品。她想在尽量短的时间内做出决断，所以她需要提前求出每天会购买多少个物品。
由于持有现金非常的危险，每一天买完东西后如果还剩下钱，这些钱就会被丢弃。

输入输出格式
输入格式：
第一行两个整数n,m。接下来n行每行两个整数vi,xi。接下来m行每行一个整数wi。

输出格式：
m行每行一个整数，第i行表示第i天购买的物品数量。

输入输出样例
输入样例#1：
3 3
1 1
2 2
3 3
5
10
15

输出样例#1：
2
4
6

说明
对于20%的数据，n,m<=1000。
对于另外40%的数据，xi=1。
对于100%的数据，n,m<=100000，1<=vi<=10^9，1<=xi<=10000，0<=wi<=10^18。
*/

/*
  得分：0
  解题报告：
    就直接说正解吧。。。
  正解：
    使用两次二分，第一次二分出能买的、最贵的物品，第二次二分出能买满的<b>一连串</b>物品。
    首先，将物品按照价格降序排列，这样在第一次二分时就可以使用STL中的lower_bound。
    对于每个w，先在物品中二分出能买到的、最贵的物品i，然后二分[i:n]，找到能买满的一连串物品并买下；如果连i都不能买满，则只买w/obj[i].v个i。
    对于第二次二分，可以使用两个前缀和，一个sum[i]记录买满obj[1:i]所需的钱数，另一个xsum[i]记录买满obj[1:i]共买了多少个。
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

typedef long long LL;
const int MAX=100020;
int n,m;
struct Obj{
  LL v,x;
  bool operator < (const Obj & b) const{
    return v>b.v; //降序排列
  }
}obj[MAX];
LL sum[MAX],xsum[MAX];

LL solve(LL w){
  LL cnt=0; int i=0,j;
  while(w>0){ //每次在区间[i,j]间购买
    i=lower_bound(obj+i+1,obj+n+1,(Obj){w,0})-obj;  //能买的、最贵的i（一定要在之前的i后面查找）
    if(i>n) break;

    //二分j <b>
    int l=i,r=n;
    while(l<r){
      int m=(l+r+1)>>1;
      LL t=sum[m]-sum[i-1];  //买满[i,m]之间物品的费用
      if(t>w) r=m-1;
      else l=m;
    }
    j=l;
    //</b>

    if(i==j && w<sum[i]-sum[i-1]){  //如果不能买满当前物品
      int t=w/obj[i].v;
      w-=t*obj[i].v; cnt+=t;
    }else{
      cnt+=xsum[j]-xsum[i-1]; w-=sum[j]-sum[i-1];
    }
    i=j;
  }
  return cnt;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%lld%lld",&obj[i].v,&obj[i].x);
  sort(obj+1,obj+n+1);
  FORR(i,1,n){  //初始化前缀和
    sum[i]=sum[i-1]+obj[i].v*obj[i].x; xsum[i]=xsum[i-1]+obj[i].x;
  }

  FOR(i,0,m){
    LL w; scanf("%lld",&w);
    printf("%lld\n",solve(w));
  }

  return 0;
}
