#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int INF=0x3f3f3f3f;
// for vocabulary
map<string,bool> dic;
VR<string> vdic;

// for words
struct Token{
  VR<string> word;

  void print(){
    bool first=1;
    for(string s : word){
      if(first) first=0;
      else putchar(' ');
      cout << s;
    }
  }
};
struct Line{
  VR<Token> tok;
  int num;

  void print(){
    printf("%04d ",num);
    bool first=1;
    for(Token t : tok){
      if(first) first=0;
      else putchar('/');
      t.print();
    }
    putchar('\n');
  }
};
VR<Line> line;

void readVocabulary(const char *name, map<string,bool> &dic){
  FILE *p = fopen(name,"r");
  char s[100];
  while(fscanf(p,"%s",s)==1){
    dic[string(s)]=1;
    vdic.push_back(string(s));
  }
#ifdef DEBUG
  printf("read %d words from %s\n",int(dic.size()),name);
#endif
}

void readWords(const char *name, VR<Line> &line){
  FILE *p = fopen(name,"r");
  char s[1000];

  while(fgets(s,SIZ(s),p)){
    Line t; t.num=0;
    int l = 0, len=strlen(s);
    s[len-1]='/';

    FOR(i,0,4){
      if(isdigit(s[l])){
        t.num = t.num*10 + s[l]-'0';
      }
      l++;
    }

    string w; Token tok;
    while(s[l]){
      if(isalnum(s[l])){
        w.push_back(s[l]);
      }else if(s[l]==' '){
        if(w.size()){
          tok.word.push_back(w);
          w.clear();
        }
      }else if(s[l]=='/'){
        if(w.size()){
          tok.word.push_back(w);
          w.clear();
        }
        if(tok.word.size()){
          t.tok.push_back(tok);
          tok.word.clear();
        }
      }
      l++;
    }

    line.push_back(t);
  }
#ifdef DEBUG
  printf("get %d lines\n",int(line.size()));
  //for(Line l : line) l.print();
#endif
}

bool isCorrect(const string &s){
  return dic.count(s);
}

int dp(string &s1, string &s2){
  int f[100][100]; MST(f,0x3f);
  int l1 = s1.size(), l2 = s2.size();
  f[0][0]=0;
  FORR(i,1,l1) f[i][0]=i;
  FORR(j,1,l2) f[0][j]=j;

  FORR(i,1,l1) FORR(j,1,l2){
    int &a = f[i][j];
    a = min(f[i-1][j]+1, f[i][j-1]+1);
    if(s1[i-1]==s2[j-1]){
      a = min(a, f[i-1][j-1]);
    }else{
      a = min(a, f[i-1][j-1]+1);
    }
  }
  return f[l1][l2];
}

void correct(string &s1){
  int disMin=INF; string rs;
  for(string &s2 : vdic){
    int dis = dp(s1,s2);
    if(dis<disMin){
      disMin = dis; rs = s2;
    }
  }
  s1 = rs;
}

int main(void){
  readVocabulary("vocabulary.txt",dic);
  readWords("words.txt",line);

  // check every word
  for(Line &l : line){
    for(Token &t : l.tok){
      for(string &s : t.word){
        if(!isCorrect(s)){
          correct(s);
        }
      }
    }
  }
  for(Line l : line) l.print();

  return 0;
}
