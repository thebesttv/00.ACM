/*
题目描述
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分（注：重合部分可<b>任取</b>），例如 beast 和 astonish ，如果接成一条龙则变为 beastonish ，另外相邻的两部分不能存在真包含关系（注：一个单词可以与自己连接，如ava连接成avava），例如 at 和 atide 间不能相连。

输入输出格式
输入格式：
输入的第一行为一个单独的整数n (n<=20)表示单词数，以下 n 行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在。

输出格式：
只需输出以此字母开头的最长的“龙”的长度。

输入输出样例
输入样例#1：
5
at
touch
cheat
choose
tact
a

输出样例#1：
23
(连成的“龙”为atoucheatactactouchoose)

说明
NOIP2000提高组第三题
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=50;
bool G[MAX][MAX];
char str[MAX][200];
char slen[MAX];
char save[1000];
int n,ansMax=0;
int vis[MAX];

void dfs(int last, int len){
  ansMax=max(ansMax,len);
  for(int i=0;i<n;i++) if(G[last][i] && vis[i]<2){
    int tlen=slen[i];
    bool flag=0; int k;
    for(k=1;k<tlen;k++) if(!strncmp(save+len-k,str[i],k)) {flag=1; break;}
    if(!flag) continue;

    for(int m=0;m<(tlen-k);m++) save[len+m]=str[i][m+k];
    vis[i]++;
    dfs(i,len+tlen-k);
    vis[i]--;
    for(int m=0;m<(tlen-k);m++) save[len+m]=0;
  }
}

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) {scanf("%s",str[i]); slen[i]=strlen(str[i]);}
  scanf("%s",save); char ch=save[0];

  for(int i=0;i<n;i++) for(int j=0;j<n;j++){
    int len=slen[i];
    for(int k=1;k<len;k++) if(!strncmp(str[i]+len-k,str[j],k)) {G[i][j]=1; break;}
  }

  for(int i=0;i<n;i++) if(str[i][0]==ch){
    memset(save,0,sizeof(save)); memset(vis,0,sizeof(vis));
    strcpy(save,str[i]); vis[i]++;
    dfs(i,slen[i]);
  }
  printf("%d\n",ansMax);

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
char str[24][200],save[1000];
int vis[24]; bool G[24][24];
int ansMax=0;

void dfs(int last, int len);
bool contain(char * str1, char * str2);

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%s",str[i]);
  scanf("%s",save); char ch=save[0];
  for(int i=0;i<n;i++) for(int j=0;j<n;j++){  //i可以等于j，即自己与自己配对
    int len=strlen(str[i]);
    //if(contain(str[i],str[j])) continue;
    for(int k=1;k<len;k++) if(!strncmp(str[i]+len-k,str[j],k)) {G[i][j]=1; break;}
  }
#ifdef DEBUG
  for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(G[i][j]) printf("  %s -> %s\n",str[i],str[j]);
#endif
  for(int i=0;i<n;i++) if(str[i][0]==ch){
    memset(save,0,sizeof(save)); memset(vis,0,sizeof(vis));
    strcpy(save,str[i]); vis[i]++;
    dfs(i,strlen(str[i]));
  }
  printf("%d\n",ansMax);

  return 0;
}

void dfs(int last, int len){
#ifdef DEBUG
  printf("  in dfs(%d,%d): %s\n",last,len,save);
#endif
  ansMax=max(len,ansMax);
  for(int i=0;i<n;i++) if(G[last][i] && vis[i]<2){
    int tlen=strlen(str[i]); int k;
    bool flag=0;
    for(k=1;k<tlen-1;k++) if(!strncmp(save+len-k,str[i],k)) {flag=1; break;}
    //if(k==tlen) continue; //wrong
    if(!flag) continue;
    for(int m=0;m<(tlen-k);m++) save[len+m]=str[i][m+k];
    vis[i]++;
    dfs(i,len+tlen-k);
    vis[i]--;
    for(int m=0;m<(tlen-k);m++) save[len+m]=0;
  }
}
bool contain(char * str1, char * str2){
  if(!strcmp(str1,str2)) return false;
  int len1=strlen(str1),len2=strlen(str2);;
  return (len1>=len2 && !strncmp(str1+len1-len2,str2,len2)) ||  //i包含j
         (len1<len2 && !strncmp(str1,str2,len1));               //j包含i
}
*/
