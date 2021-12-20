/*
输入:
ABCDEF
BCAEDF

输出:
55
*/

/*
  解题报告：
    这道题本质上其实很简单，只是通过一棵二叉树的前序遍历和中序遍历重构原二叉树并且计算其权值。然而这道题重建二叉树的方法好像是暴搜。。。所以我就很无奈了。。。
    其实calc函数和check函数都是很简单的，calc函数计算二叉树的权值，而check函数是典型的构造中序遍历。
    但dfs函数我到现在还是看不懂。。。不过感觉一下，就差不多是那样吧 XD
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

int lefts[20], rights[20], father[20];
string s1, s2, s3;
int n, ans;

void calc(int x, int dep){  //计算构造出的树的权值
  ans = ans + dep*(s1[x] - 'A' + 1);
  if (lefts[x] >= 0) calc(lefts[x], dep+1);
  if (rights[x] >= 0) calc(rights[x], dep+1);
}
void check(int x){  //将构造出的树的中序遍历写入s3中
  if (lefts[x] >= 0) check(lefts[x]);
  s3 = s3 + s1[x];
  if (rights[x] >= 0) check(rights[x]);
}
void dfs(int x, int th){
  if (th == n){
    s3 = "";
    check(0);
    if (s3 == s2){
      ans = 0;
      calc(0, 1);
      cout<<ans<<endl;
    }
    return;
  }

  if (lefts[x] == -1 && rights[x] == -1){ //<???>
    lefts[x] = th;
    father[th] = x;
    dfs(th, th+1);
    father[th] = -1;
    lefts[x] = -1;
  }
  if (rights[x] == -1){
    rights[x] = th;
    father[th] = x;
    dfs(th, th+1);
    father[th] = -1;
    rights[x] = -1;
  }
  if (father[x] >= 0) dfs(father[x], th); //</???>
}

int main(){
  cin>>s1; cin>>s2;
  n = s1.size();
  memset(lefts, -1, sizeof(lefts));
  memset(rights, -1, sizeof(rights));
  memset(father, -1, sizeof(father));
  dfs(0, 1);

  return 0;
}
