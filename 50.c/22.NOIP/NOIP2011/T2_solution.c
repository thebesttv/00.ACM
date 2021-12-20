/*
   a 数组是记录同一种颜色中的酒店所出现的最后一次的位置；
   b 数组记录同一种颜色的酒店的出现次数，
   而c数组则是临时记录当前同样颜色的酒店出现的次数，
   也就是为找对应点而进行的临时记录（也可以理解为当前色调的方法数量）。
   那么，通过使用上述方法，仅仅需要一个for循环，即可解决问题
*/
#include<iostream>
using namespace std;
int a[100],b[100],c[100];

int main(){
  int n,k,p,m,x,y,sum;
  cin>>n>>k>>p;

  for(int i=1;i<=n;i++){
    cin>>x>>y;
    if(y<=p) m=i; //如果咖啡店的最低消费低于标准，那么记录其位置
    if(m>=a[x]) c[x]=b[x];  //如果在当前颜色的酒店之前有出现过同样颜色的酒店那么记录当前同种颜色的酒店的出现次数
    /*
       特注：当到COODVS上第四组数据时也许会因为“y<=p”不会记录当前的位置，
       但是会记录之前有满足“y<=p”条件的位置，
       也就是说两个人住的客栈之间有满足条件的咖啡馆，
       那么也就可以让c数组的对应颜色加上1了，即“c[x]=b[x]”
       从而使后面的总数加上1
    */

    a[x]=i; //记录同样颜色的酒店最后一次的出现位置
    sum+=c[x];
    /*
       每一个酒店都可以作为对应点，所以不需要再去加上任何的判断，记录住宿的方法，
       c数组可以理解为当前色调位置，到之前满足“y<=p”色调位置的方案
    */
    b[x]++;//记录出现次数的总数
  }
  cout<<sum;
  return 0;
}


//看了楼上的题解 很久才明白 我把它讲清楚些
#include <cstdio>

int main(){
  int n,k,p,color,last=-1,v,a[60]={0},b[60]={0},c[60]={0},ans=0;
  //a[i]=m 色调i最后出现的位置为m
  //b[i]=m 色调i已经出现了m次
  //c[i]=m 最新一个可以作为咖啡馆的客栈 该客栈之前的色调为i的总数为m

  //last 最新一个可以作为咖啡馆的客栈 
  scanf("%d%d%d",&n,&k,&p);
  for(int i=1;i<=n;i++){
    scanf("%d%d",&color,&v);
    if(v<=p) last=i;
    if(a[color]<=last)  //(1)找到咖啡馆可以使 客栈i 与 last之前的客栈 形成方案 
      c[color]=b[color];
    ans+=c[color];
    a[color]=i; b[color]++; 
    //如果 (1) 处更新 代表i点可以成为咖啡馆 那么i与i之前的可以形成方案
    //如果 (1) 处未更新 则i可以 以last为咖啡馆 与last之前的形成方案
  }
  printf("%d",ans); 
  return 0;
}
