/*
题目背景
Aldnoah——火星上超古代文明留下的能量源，承认初代火星移民雷伊·雷加利亚博士（即后来的薇瑟帝国初代皇帝）为正统继承者，启动因子融入皇族的遗传因子中，只有皇族天生具有Aldnoah的启动能力。可以把Aldnoah看成是有认主能力的特殊矿产。在火星骑士的扬陆城中，安置有Aldnoah的启动装置。

题目描述
两天前，被授予启动能力的斯雷因·特洛耶特伯爵准备对启动装置进行加密，以防有人趁其不备破坏装置。
他将这个任务交给了他的心腹哈库莱特。忠实的哈库莱特认为，只需要输入密码就能解锁的加密装置实在是太不安全了，所以他决定用一个特别的加密装置来对Aldnoah启动装置进行保护。
他精心设计了这样一套加密装置：
该装置会给定解密者两个字符串s,t，其中s只包含小写字母以及*，t只包含小写字母。解密者可以进行任意多次操作，每次选择s中的一个*，将它修改为任意多个（可以是0个）它的前一个字符。询问是否能将s修改为t。
聪明的哈库莱特当然不会只给予解密者一组数据啦，所以解密时会有多组数据出现，并且每组数据只有在规定时间内答对才能够继续解密下一组数据。
今天他制作好了加密装置交给了斯雷因·特洛耶特伯爵，斯雷因准备先进行测试过后再将它安装在启动装置上。他随机制造了几组测试数据输入装置，然后让哈库莱特进行解密。哈库莱特会怎么做呢？

输入输出格式
输入格式：
第一行一个整数T表示数据组数。
每组数据两行，第一行一个字符串s，第二行一个字符串t。

输出格式：
每组数据输出一行，如果能将s修改为t，输出Yes，否则输出No。

输入输出样例
输入样例#1：
2
a*
aaaa
a*
ab

输出样例#1：
Yes
No

说明
对于20%的数据，|s|,|t|<=7。
对于60%的数据，|s|,|t|<=300。
对于100%的数据，T<=100，|s|,|t|<=30000。
*/

/*
  得分：0
  解题报告：
    一开始以为直接模拟一下就可以，然而没有想到a为"a*a*a*"，b为"aaaaa"的数据，于是就错了。最尴尬的是想了几天才想到错在哪里。。。
  正解：
    如果用双指针直接模拟是一定不行的，因为模拟的时候只关注了当前的a[i]。如果有a[i]=='a',a[i+1]=='*'，然后又这样重复的数据，就会在遇到a中的第二个"a*"前就把b中的'a'用掉。那么就要想办法每次判断时更有“大局观”。
    可以将a,b分为多个连续的段，其中每一段的字母都是相同的（对于a，段内可以有'*'，且在段尾要有尽量多的'*'，即如果段尾是字母且字母后还有'*'，那么就要把那个'*'加入段中（因为'*'只能复制其前面的字母））。
    可以看出，a,b之间每段是一一对应的，即段ai与段bi对应。
    令a,b划分后的段组分别为A,B，每段Ai或Bi中的字母数为s(Ai/Bi)，则
      当s(Ai)<s(Bi)时，Ai中一定要有'*'
      当s(Ai)=s(Bi)时，Ai中有没有'*'都可以
      当s(Ai)>s(Bi)是，不可行，因为Bi不可以扩张来符合Ai，Ai也不可以缩短来符合Bi
    那么就可以使用遍历段的放法来求解了。
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

const int MAX=30020;
char a[MAX],b[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s%s",a,b);
    int lena=strlen(a),lenb=strlen(b);
    int i=0,j=0;
    bool ok=1;
    while(ok && i<lena && j<lenb){
      char ch=a[i]; //段中的字母
      if(ch!=b[j]) {ok=0; break;}
      int cnta=0,cntb=0; bool canAdd=0; //canAdd: Ai中是否有'*'，即Ai能否变长
      while(i<lena && (a[i]==ch || a[i]=='*')){ //遍历Ai
        cnta+=(a[i]==ch); i++;
        a[i]=='*' ? canAdd=1 : 0;
      }
      while(j<lenb && b[j]==ch){  //遍历Bi
        cntb++; j++;
      }
      if((cnta>cntb) || (cnta<cntb && !canAdd)) {ok=0; break;}  //判断
    }
    if(i!=lena || j!=lenb) ok=0;  //判断是否多出段
    printf("%s\n",ok ? "Yes" : "No");
  }
  return 0;
}

/*
const int MAX=30020;
char a[MAX],b[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(a,0); MST(b,0);
    scanf("%s%s",a,b); VR<char> v;
    int lena=strlen(a),lenb=strlen(b);
    FOR(i,0,lena)
      if(a[i]!='*') v.push_back(a[i]);
      else if(v.size() && v[v.size()-1]!='*') v.push_back(a[i]);
    MST(a,0); FOR(i,0,v.size()) a[i]=v[i];
    lena=v.size();

    int p=0,q=0;
    bool ok=1;
    while(p<lena && q<lenb){
      if(a[p]==b[q]) p++,q++;
      else if(a[p]=='*'){
        int t=p-1; //while(t && a[t]=='*') t--;
        while(q<lenb && b[q]==a[t]) q++;
        p++;
      }else {ok=0; break;}
    }
    if(a[p]=='*') p++;
    if(p!=lena || q!=lenb) ok=0;
    if(ok) printf("Yes\n");
    else printf("No\n");
  }

  return 0;
}
*/
