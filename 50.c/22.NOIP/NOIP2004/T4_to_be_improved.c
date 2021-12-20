/*
描述
所谓虫食算，就是原先的算式中有一部分被虫子啃掉了，需要我们根据剩下的数字来判定被啃掉的字母。来看一个简单的例子：

    43#9865#045
  +   8468#6633
  = 44445509678

其中#号代表被虫子啃掉的数字。根据算式，我们很容易判断：第一行的两个数字分别是5和3，第二行的数字是5。
现在，我们对问题做两个限制：
  首先，我们只考虑加法的虫食算。这里的加法是N进制加法，算式中三个数都有N位，允许有前导的0。
  其次，虫子把所有的数都啃光了，我们只知道哪些数字是相同的，我们将相同的数字用相同的字母表示，不同的数字用不同的字母表示。如果这个算式是N进制的，我们就取英文字母表中的前N个大写字母来表示这个算式中的0到N-1这N个不同的数字：但是这N个字母并不一定顺序地代表0到N-1)。输入数据保证N个字母分别至少出现一次。

    BADC
  + CBDA
  = DCCC

上面的算式是一个4进制的算式。很显然，我们只要让ABCD分别代表0123，便可以让这个式子成立了。你的任务是，对于给定的N进制加法算式，求出N个不同的字母分别代表的数字，使得该加法算式成立。输入数据保证有且仅有一组解

格式
输入格式
输入包含4行。第一行有一个正整数N(N<=26)，后面的3行每行有一个由大写字母组成的字符串，分别代表两个加数以及和。这3个字符串左右两端都没有空格，从高位到低位，并且恰好有N位。

输出格式
输出包含一行。在这一行中，应当包含唯一的那组解。解是这样表示的：输出N个数字，分别表示A，B，C……所代表的数字，相邻的两个数字用一个空格隔开，不能有多余的空格。

样例1
样例输入1
5
ABCED
BDACE
EBBAA

样例输出1
1 0 3 4 2

限制
每个测试点1s

来源
NOIp 2004
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=30;
char temp[MAX];
int a[MAX][3],n;
int val[MAX],save[MAX];
bool vis[MAX];

bool dfs(int cur, int carry);
inline bool sub3(int cur, int ans, int & v3);

int main(void){
  scanf("%d",&n);
  for(int i=0;i<3;i++){
    scanf("%s",temp);
    for(int j=0;j<n;j++) a[j][i]=temp[n-j-1]-'A';
  }
  memset(val,-1,sizeof(val));
  dfs(0,0);
  for(int i=0;i<n;i++) printf("%d ",save[i]);
  printf("\n");

  return 0;
}

bool dfs(int cur, int carry){
  if(cur==n){
    if(carry==0) memcpy(save,val,sizeof(val));
    return carry==0;
  }
  if(a[cur][0]!=a[cur][1] && a[cur][0]!=a[cur][2] && a[cur][1]!=a[cur][2]){ //"A B C"
#ifdef DEBUG
    printf("    enter \"A B C\"\n");
#endif
    int &v1=val[a[cur][0]], &v2=val[a[cur][1]], &v3=val[a[cur][2]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub3(cur,ans,v3)) return true;
      }else{  //v2==-1
        if(v3!=-1){
          int ans;
          for(v2=n-1;v2>=0;v2--) if((ans=(v1+v2+carry))%n==v3 && !vis[v2]){ vis[v2]=1;
            if(dfs(cur+1,ans/n)) return true;
            vis[v2]=0;
          }
        }else{  //v3==-1
          for(v2=n-1;v2>=0;v2--) if(!vis[v2]){ vis[v2]=1;
            int ans=v1+v2+carry;
            if(sub3(cur,ans,v3)) return true;
            vis[v2]=0;
          }
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        if(v3!=-1){
          int ans;
          for(v1=n-1;v1>=0;v1--) if((ans=v1+v2+carry)%n==v3 && !vis[v1]){ vis[v1]=1;
            if(dfs(cur+1,ans/n)) return true;
            vis[v1]=0;
          }
        }else{  //v3==-1
          for(v1=n-1;v1>=0;v1--) if(!vis[v1]){ vis[v1]=1;
            int ans=v1+v2+carry;
            if(sub3(cur,ans,v3)) return true;
            vis[v1]=0;
          }
        }
      }else{  //v2==-1
        if(v3!=-1){
          int ans;
          for(v1=n-1;v1>=0;v1--) if(!vis[v1]){ vis[v1]=1;
            for(v2=n-1;v2>=0;v2--) if((ans=v1+v2+carry)%n==v3 && !vis[v2]){ vis[v2]=1;
              if(dfs(cur+1,ans/n)) return true;
              vis[v2]=0;
            }
            vis[v1]=0;
          }
        }else{  //v3==-1
          for(v1=n-1;v1>=0;v1--) if(!vis[v1]){ vis[v1]=1;
            for(v2=n-1;v2>=0;v2--) if(!vis[v2]){ vis[v2]=1;
              int ans=v1+v2+carry;
              if(sub3(cur,ans,v3)) return true;
              vis[v2]=0;
            }
            vis[v1]=0;
          }
        }
        v2=-1;
      }
      v1=-1;
    }
  }else if(a[cur][0]==a[cur][1] && a[cur][0]!=a[cur][2]){ //"A A C"
#ifdef DEBUG
    printf("    enter \"A A C\"\n");
#endif
    int &v1=val[a[cur][0]], &v3=val[a[cur][2]];
    if(v1!=-1){
      int ans=v1*2+carry;
      if(sub3(cur,ans,v3)) return true;
    }else{  //v1==-1
      if(v3!=-1){
        for(v1=n-1;v1>=0;v1--) if((v1*2+carry)%n==v3 && !vis[v1]){ vis[v1]=1;
          if(dfs(cur+1,(v1*2+carry)/n)) return true;
          vis[v1]=0;
        }
      }else{  //v3==-1
        for(v1=n-1;v1>=0;v1--) if(!vis[v1] && !vis[(v1*2+carry)%n]){ vis[v1]=vis[(v3=(v1*2+carry)%n)]=1;
          if(dfs(cur+1,(v1*2+carry)/n)) return true;
          vis[v1]=vis[(v1*2+carry)%n]=0;
        }
        v3=-1;
      }
      v1=-1;
    }
  }else if(a[cur][0]==a[cur][2] && a[cur][0]!=a[cur][1]){ //"A C A" XXX
#ifdef DEBUG
    printf("    enter \"A C A\"\n");
#endif
    int &v1=val[a[cur][0]], &v2=val[a[cur][1]];
    if(v1!=-1){
      if(v2!=-1){
        if((v1+v2+carry)%n!=v1) return false;
        else if(dfs(cur+1,(v1+v2+carry)/n)) return true;
      }else{  //v2==-1
        if(!vis[0] && carry==0){
          v2=0; vis[0]=1;
          if(dfs(cur+1,0)) return true;
          vis[v2]=0;
        }
        if(!vis[n-1] && carry==1){
          v2=n-1; vis[v2]=1;
          if(dfs(cur+1,(v1+v2+carry)/n)) return true;
          vis[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        if(v2!=0 && v2!=n-1) return false;
        else for(v1=n-1;v1>=0;v1--) if(!vis[v1] && (v1+v2+carry)%n==v1){ vis[v1]=1;
          if(dfs(cur+1,(v1+v2+carry)/n)) return true;
          vis[v1]=0;
        }
      }else{  //v2==-1
        for(v1=n-1;v1>=0;v1--) if(!vis[v1]){ vis[v1]=1;
          if(!vis[0] && carry==0){
            v2=0; vis[0]=1;
            if(dfs(cur+1,0)) return true;
            vis[v2]=0;
          }
          if(!vis[n-1] && carry==1){
            v2=n-1; vis[v2]=1;
            if(dfs(cur+1,(v1+v2+carry)/n)) return true;
            vis[v2]=0;
          }
          vis[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else if(a[cur][1]==a[cur][2] && a[cur][0]!=a[cur][1]){ //"C A A" XXX
#ifdef DEBUG
    printf("    enter \"C A A\"\n");
#endif
    int &v1=val[a[cur][1]], &v2=val[a[cur][0]];
    if(v1!=-1){
      if(v2!=-1){
        if((v1+v2+carry)%n!=v1) return false;
        else if(dfs(cur+1,(v1+v2+carry)/n)) return true;
      }else{  //v2==-1
        if(!vis[0] && carry==0){
          v2=0; vis[0]=1;
          if(dfs(cur+1,0)) return true;
          vis[v2]=0;
        }
        if(!vis[n-1] && carry==1){
          v2=n-1; vis[v2]=1;
          if(dfs(cur+1,(v1+v2+carry)/n)) return true;
          vis[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        if(v2!=0 && v2!=n-1) return false;
        else for(v1=n-1;v1>=0;v1--) if(!vis[v1] && (v1+v2+carry)%n==v1){ vis[v1]=1;
          if(dfs(cur+1,(v1+v2+carry)/n)) return true;
          vis[v1]=0;
        }
      }else{  //v2==-1
        for(v1=n-1;v1>=0;v1--) if(!vis[v1]){ vis[v1]=1;
          if(!vis[0] && carry==0){
            v2=0; vis[0]=1;
            if(dfs(cur+1,0)) return true;
            vis[v2]=0;
          }
          if(!vis[n-1] && carry==1){
            v2=n-1; vis[v2]=1;
            if(dfs(cur+1,(v1+v2+carry)/n)) return true;
            vis[v2]=0;
          }
          vis[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else{  //"A A A"
#ifdef DEBUG
    printf("    enter \"A A A\"\n");
#endif
    int &v1=val[a[cur][0]];
    if(v1!=-1){
      if((v1*2)+carry!=v1) return false;
      else if(dfs(cur+1,((v1*2)+carry)/n)) return true;
    }else{  //v1==-1
      if(!vis[0] && carry==0){
        v1=0; vis[v1]=1;
        if(dfs(cur+1,0)) return true;
        vis[v1]=0;
      }
      if(!vis[n-1] && carry==1){
        v1=n-1; vis[v1]=1;
        if(dfs(cur+1,0)) return true;
        vis[v1]=0;
      }
      v1=-1;
    }
  }
  return false;
}
inline bool sub3(int cur, int ans, int & v3){
#ifdef DEBUG
  printf("    sub3(%d,%d,%d)\n",cur,ans,v3);
#endif
  if(v3!=-1){
    if(ans%n!=v3) return false;
    else return dfs(cur+1,ans/n);
  }else{
    if(!vis[ans%n]){
      v3=ans%n; vis[v3]=1;
      if(dfs(cur+1,ans/n)) return true;
      vis[v3]=0; v3=-1;
    }
  }
  return false;
}










































































//TODO: 重构代码，使之能够在一位中两个数确定的情况下直接确定第三个数
//      当前只对第三个数有效

/*
//一个点TLE
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

const int MAX=30;
char a[3][MAX],temp[MAX];
bool book[MAX];
int val[255],save[255];
int n;

inline bool dfs(int cur, int carry);
inline bool sub(int cur, int ans, int & v3);

int main(void){
  scanf("%d",&n);
  for(int i=0;i<3;i++){
    scanf("%s",temp);
    for(int j=0;j<n;j++) a[i][j]=temp[n-j-1];
  }

  memset(val,-1,sizeof(val));
  dfs(0,0);


  return 0;
}

inline bool dfs(int cur, int carry){
  if(cur==n){
    if(carry==0){
      for(int i='A';i<'A'+n;i++){
        if(i=='A') printf("%d",val[i]);
        else printf(" %d",val[i]);
      }
      printf("\n");
      exit(0);  //??
    }
    return carry==0;
  }

  if(a[0][cur]!=a[1][cur] && a[0][cur]!=a[2][cur] && a[1][cur]!=a[2][cur]){ //"A B C"
#ifdef DEBUG
    printf("    enter \"A B C\"\n");
#endif
    int &v1=val[a[0][cur]], &v2=val[a[1][cur]], &v3=val[a[2][cur]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub(cur,ans,v3)) return true;
      }else{  //v2==-1
        for(v2=n-1;v2>=0;v2--) if(!book[v2]){ book[v2]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v3)) return true;
          book[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v3)) return true;
          book[v1]=0;
        }
      }else{  //v2==-1
        for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
          for(v2=n-1;v2>=0;v2--) if(!book[v2]){ book[v2]=1;
            int ans=v1+v2+carry;
            if(sub(cur,ans,v3)) return true;
            book[v2]=0;
          }
          book[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else if(a[0][cur]==a[1][cur] && a[0][cur]!=a[2][cur]){ //"A A C"
#ifdef DEBUG
    printf("    enter \"A A C\"\n");
#endif
    int &v1=val[a[0][cur]], &v3=val[a[2][cur]];
    if(v1!=-1){
      int ans=v1*2+carry;
      if(sub(cur,ans,v3)) return true;
    }else{  //v1==-1
      for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
        int ans=v1*2+carry;
        if(sub(cur,ans,v3)) return true;
        book[v1]=0;
      }
      v1=-1;
    }
  }else if(a[0][cur]==a[2][cur] && a[0][cur]!=a[1][cur]){ //"A C A"
#ifdef DEBUG
    printf("    enter \"A C A\"\n");
#endif
    int &v1=val[a[0][cur]], &v2=val[a[1][cur]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub(cur,ans,v1)) return true;
      }else{
        for(v2=n-1;v2>=0;v2--) if(!book[v2]){ book[v2]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v1]=0;
        }
      }else{  //v2==-1
        for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
          for(v2=n-1;v2>=0;v2--) if(!book[v2]){ book[v2]=1;
            int ans=v1+v2+carry;
            if(sub(cur,ans,v1)) return true;
            book[v2]=0;
          }
          book[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else if(a[0][cur]!=a[1][cur] && a[1][cur]==a[2][cur]){ //"C A A"
#ifdef DEBUG
    printf("    enter \"C A A\"\n");
#endif
    int &v1=val[a[1][cur]], &v2=val[a[0][cur]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub(cur,ans,v1)) return true;
      }else{
        for(v2=n-1;v2>=0;v2--) if(!book[v2]){ book[v2]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v1]=0;
        }
      }else{  //v2==-1
        for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
          for(v2=n-1;v2>=0;v2--) if(!book[v2]){ book[v2]=1;
            int ans=v1+v2+carry;
            if(sub(cur,ans,v1)) return true;
            book[v2]=0;
          }
          book[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else{  //"A A A"
#ifdef DEBUG
    printf("    enter \"A A A\"\n");
#endif
    int &v1=val[a[0][cur]];
    if(v1!=-1){
      int ans=v1*2+carry;
      if(sub(cur,ans,v1)) return true;
    }else{
      for(v1=n-1;v1>=0;v1--) if(!book[v1]){ book[v1]=1;
        int ans=v1*2+carry;
        if(sub(cur,ans,v1)) return true;
        book[v1]=0;
      }
      v1=-1;
    }
  }
  return false;
}
inline bool sub(int cur, int ans, int & v3){
#ifdef DEBUG
  printf("  enter sub(%d,%d,%d)\n",cur,ans,v3);
#endif
  if(v3!=-1){
    if(ans%n==v3) {if(dfs(cur+1,ans/n)) return true;}
  }else{
    if(book[ans%n]) return false;
    else{
      v3=ans%n; book[v3]=1;
      if(cur==n-1 && ans/n) return false;
      if(dfs(cur+1,ans/n)) return true;
      book[v3]=0; v3=-1;
    }
  }
  return false;
}
*/

/*
  得分：0
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=30;
char a[3][MAX],temp[MAX];
bool book[MAX];
int val[255],save[255];
int n;

bool dfs(int cur, int carry);
bool sub(int cur, int ans, int & v3);

int main(void){
  scanf("%d",&n);
  for(int i=0;i<3;i++){
    scanf("%s",temp);
    for(int j=0;j<n;j++) a[i][j]=temp[n-j-1];
  }
#ifdef DEBUG
  printf("  get:\n");
  for(int i=0;i<3;i++) printf("  %s\n",a[i]);
#endif

  memset(val,-1,sizeof(val));
  dfs(0,0);
  
  for(int i='A';i<'A'+n;i++){
    if(i=='A') printf("%d",save[i]);
    else printf(" %d",save[i]);
  }
  printf("\n");

  return 0;
}

bool dfs(int cur, int carry){
#ifdef DEBUG
  printf("  in dfs(%d,%d):",cur,carry);
  for(int i='A';i<'A'+n;i++) printf(" %d",val[i]);
  printf("\n");
  printf("    %c + %c = %c\n",a[0][cur],a[1][cur],a[2][cur]);
  printf("    %d + %d = %d\n",val[a[0][cur]],val[a[1][cur]],val[a[2][cur]]);
#endif
  if(cur==n){
#ifdef DEBUG
    printf("  *** dfs succeed ***\n");
#endif
    if(carry==0) memcpy(save,val,sizeof(val));
    return carry==0;
  }

  if(a[0][cur]!=a[1][cur] && a[0][cur]!=a[2][cur] && a[1][cur]!=a[2][cur]){ //"A B C"
#ifdef DEBUG
    printf("    enter \"A B C\"\n");
#endif
    int &v1=val[a[0][cur]], &v2=val[a[1][cur]], &v3=val[a[2][cur]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub(cur,ans,v3)) return true;
      }else{  //v2==-1
        for(v2=0;v2<n;v2++) if(!book[v2]){ book[v2]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v3)) return true;
          book[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v3)) return true;
          book[v1]=0;
        }
      }else{  //v2==-1
        for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
          for(v2=0;v2<n;v2++) if(!book[v2]){ book[v2]=1;
            int ans=v1+v2+carry;
            if(sub(cur,ans,v3)) return true;
            book[v2]=0;
          }
          book[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else if(a[0][cur]==a[1][cur] && a[0][cur]!=a[2][cur]){ //"A A C"
#ifdef DEBUG
    printf("    enter \"A A C\"\n");
#endif
    int &v1=val[a[0][cur]], &v3=val[a[2][cur]];
    if(v1!=-1){
      int ans=v1*2+carry;
      if(sub(cur,ans,v3)) return true;
    }else{  //v1==-1
      for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
        int ans=v1*2+carry;
        if(sub(cur,ans,v3)) return true;
        book[v1]=0;
      }
      v1=-1;
    }
  }else if(a[0][cur]==a[2][cur] && a[0][cur]!=a[1][cur]){ //"A C A"
#ifdef DEBUG
    printf("    enter \"A C A\"\n");
#endif
    int &v1=val[a[0][cur]], &v2=val[a[1][cur]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub(cur,ans,v1)) return true;
      }else{
        for(v2=0;v2<n;v2++) if(!book[v2]){ book[v2]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v1]=0;
        }
      }else{  //v2==-1
        for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
          for(v2=0;v2<n;v2++) if(!book[v2]){ book[v2]=1;
            int ans=v1+v2+carry;
            if(sub(cur,ans,v1)) return true;
            book[v2]=0;
          }
          book[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else if(a[0][cur]!=a[1][cur] && a[1][cur]==a[2][cur]){ //"C A A"
#ifdef DEBUG
    printf("    enter \"C A A\"\n");
#endif
    int &v1=val[a[1][cur]], &v2=val[a[0][cur]];
    if(v1!=-1){
      if(v2!=-1){
        int ans=v1+v2+carry;
        if(sub(cur,ans,v1)) return true;
      }else{
        for(v2=0;v2<n;v2++) if(!book[v2]){ book[v2]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v2]=0;
        }
        v2=-1;
      }
    }else{  //v1==-1
      if(v2!=-1){
        for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
          int ans=v1+v2+carry;
          if(sub(cur,ans,v1)) return true;
          book[v1]=0;
        }
      }else{  //v2==-1
        for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
          for(v2=0;v2<n;v2++) if(!book[v2]){ book[v2]=1;
            int ans=v1+v2+carry;
            if(sub(cur,ans,v1)) return true;
            book[v2]=0;
          }
          book[v1]=0;
        }
        v2=-1;
      }
      v1=-1;
    }
  }else{  //"A A A"
#ifdef DEBUG
    printf("    enter \"A A A\"\n");
#endif
    int &v1=val[a[0][cur]];
    if(v1!=-1){
      int ans=v1*2+carry;
      if(sub(cur,ans,v1)) return true;
    }else{
      for(v1=0;v1<n;v1++) if(!book[v1]){ book[v1]=1;
        int ans=v1*2+carry;
        if(sub(cur,ans,v1)) return true;
        book[v1]=0;
      }
      v1=-1;
    }
  }
  return false;
}
bool sub(int cur, int ans, int & v3){
#ifdef DEBUG
  printf("  enter sub(%d,%d,%d)\n",cur,ans,v3);
#endif
  if(v3!=-1){
    if(ans%n==v3) {if(dfs(cur+1,ans/n)) return true;}
  }else{
    if(book[ans%n]) return false;
    else{
      v3=ans%n; book[v3]=1;
      if(dfs(cur+1,ans/n)) return true;
      book[v3]=0; v3=-1;
    }
  }
  return false;
}
*/
