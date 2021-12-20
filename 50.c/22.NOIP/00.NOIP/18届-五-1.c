/*
排列数
输入两个正整数 n, m (1 ≤ n ≤ 20, 1 ≤ m ≤ n),在 1~n 中任取 m 个数,按字典
序从小到大输出所有这样的排列。例如

输入:
3 2

输出:
1 2
1 3
2 1
2 3
3 1
3 2
*/

/*
  解题报告：
    这个其实就是一个按照字典序的排列程序，不过它的原理我还没怎么搞清楚。。。
*/

#include<iostream>
#include<cstring>
using namespace std;

const int SIZE = 25;
bool used[SIZE];
int data[SIZE];
int n, m, i, j, k;
bool flag;

int main(){
  cin>>n>>m;
  memset(used,false,sizeof(used));
  for(i=1;i<=m;i++){
    data[i]=i; used[i]=true;
  }
  flag=true;

  while(flag){
    for(i=1;i<=m-1;i++) cout<<data[i]<<" ";
    cout<<data[m]<<endl;

    flag=false;
    for(i=m;i>=1;i--){
      used[data[i]]=false;  //<b></b>
      for(j=data[i]+1;j<=n;j++) if(!used[j]){
        used[j]=true;
        data[i]=j;
        flag=true;
        break;
      }
      if(flag){ //<???> 已经改变了序列，但因为要求字典序，因此将序列重新更新
        for(k=i+1;k<=m;k++) for(j=1;j<=n;j++) if(!used[j]){
          data[k]=j;
          used[j]=true;
          break;
        }
        break;
      }         //</???>
    }
  }

  return 0;
}
