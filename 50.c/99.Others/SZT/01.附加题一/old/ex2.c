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
map<string,bool> dic;
VR<string> vdic;
char s[1000];
int dis(const string &ts1, const string &ts2){
  char s1[100], s2[100];
  int f[100][100]; MST(f,0x3f);
  int l1=ts1.size(), l2=ts2.size();
  FOR(i,0,l1) s1[i+1] = ts1[i];
  FOR(i,0,l2) s2[i+1] = ts2[i];
  f[0][0]=0;
  FORR(i,0,l1) f[i][0] = i;
  FORR(i,0,l2) f[0][i] = i;
  FORR(i,1,l1) FORR(j,1,l2){
    if(s1[i]==s2[j]){
      f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
      f[i][j] = min(f[i][j], f[i-1][j-1]);
    }else{
      f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
      f[i][j] = min(f[i][j], f[i-1][j-1]+1);
    }
  }
#ifdef DEBUG
  cout << endl << "** " << ts1 << ", " << ts2 << ": " << f[l1][l2] << " **" << endl;
#endif
  return f[l1][l2];
}
struct Token{
  VR<string> v; // words
  void print(){
    bool first=1;
    for(string s : v){
      if(first) first=0;
      else putchar(' ');
      cout << s;
    }
  }
  void correct(){
    FOR(i,0,v.size()) if(!dic.count(v[i])){
      int disMin=INF; string rs;
      for(string s2 : vdic){
        int tdis = dis(v[i],s2);
        if(tdis < disMin){
          disMin = tdis; rs = s2;
        }
      }
      v[i] = rs;
    }
  }
};
struct Line{
  VR<Token> v;
  int n;
};
VR<Line> line;

int main(void){
  FILE *p1 = fopen("vocab","r");
  FILE *p2 = fopen("words.txt","r");

  while(fscanf(p1,"%s",s)!=EOF){
    dic[string(s)]=1;
    vdic.push_back(string(s));
  }
  while(fgets(s,SIZ(s),p2)){
    int n=0;
    FOR(i,0,4){
      n = n*10 + (s[i]-'0');
    }
    Line t; t.n = n;
    int len = strlen(s); s[len-1]='/';
    string str; Token tok;
    FOR(i,4,len) if(isalnum(s[i]) || s[i]=='/' || s[i]==' '){
      if(s[i]=='/'){
        if(str.size()){
          tok.v.push_back(str);
          str.clear();
        }

        if(tok.v.size()){
          t.v.push_back(tok);
          tok.v.clear();
        }
      }else if(s[i]==' '){
        if(str.size()){
          tok.v.push_back(str);
          str.clear();
        }
      }else{
        str.push_back(s[i]);
      }
    }
    line.push_back(t);
  }
  printf("have read %d vocabs\n",vdic.size());
  printf("get %d lines\n", line.size());

  for(Line l : line){
    printf("%04d ",l.n);
    bool first=1;
    for(Token tok : l.v){
      if(first) first=0;
      else putchar('/');
      tok.correct();
      tok.print();
    }
    printf("\n");
  }

  fclose(p1);
  fclose(p2);

  return 0;
}
