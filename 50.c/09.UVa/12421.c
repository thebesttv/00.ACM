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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1000;
const int MAX_TOKEN_LEN=100;
const int RES_SIZ=21;
const int RES=1;
const int NUM=2;
const int STR=3;
const int SYM=4;
const int NAM=5;
const int EOL=6;
const int COM=7;
const char token_type_name[8][20]={"",
  "RESERVED",
  "NUMBER",
  "STRING",
  "SYMBOL",
  "NAME",
  "EOL",
  "COMMENT"
};
const char res_name[RES_SIZ][20]={
  "and","break","do","else","elseif",
  "end","false","for","function","if",
  "in","local","nil","not","or","repeat",
  "return","then","true","until","while"
};
char t1[MAX]; int len;
struct Token{
  int type;
  char s[MAX_TOKEN_LEN];
  int pos;
  bool operator < (const Token & b) const {return pos<b.pos;}
  Token(int t_, string s_, int p_): type(t_), pos(p_) {
    MST(s,0); int len=s_.length();
    FOR(i,0,len) s[i]=s_[i];
  }
  Token() {MST(s,0);}
};
VR<Token> tok;

void clear_com(char * s);  //1.最先进行，清除注释
void a_str(char * s);      //2.处理所有引号内的文本
void a_res(char * s);      //3.处理所有保留字
void a_num(char * s);      //4.处理所有数字
void a_nam(char * s);      //5.处理所有标识符，nam左右不能有字符或数字
void a_sym(char * s);      //6.处理所有符号，要在5之后进行，因为有 16.3e-7
void analyze(char * s){
  len=strlen(s);
  clear_com(s); //1
  a_str(s);     //2
  a_res(s);
  a_num(s);
  a_nam(s);
  a_sym(s);
  tok.push_back(Token(EOL,"",len));
}

int main(void){
  while(FGETS(t1)){
    tok.clear();
    analyze(t1);
    sort(tok.begin(),tok.end());
    FOR(i,0,tok.size()){
      Token & t=tok[i];
      printf("[%s]",token_type_name[t.type]);
      if(t.type!=EOL) printf(" %s",t.s);
      printf("\n");
    }
  }

  return 0;
}

void clear_com(char * s){
  bool inq=0; int pos=-1;
  FOR(i,0,len){
    if(s[i]=='-' && s[i+1]=='-' && !inq) {pos=i; break;}
    else if(s[i]=='\"' || s[i]=='\'') inq=!inq;
  }
  if(pos!=-1) while(pos<len) s[pos++]=' ';
}
void a_str(char * s){
  int i=0;
  while(i<len){ //寻找第一个引号并删除STR
    while(i<len){
      if(s[i]=='\"' || s[i]=='\'') break;
      i++;
    }
    if(i==len) return;
    //找到引号
    if(!i || s[i-1]=='\\') continue;  //若为转义字符则跳过
    int l=i++;
    while(i<len){
      if((s[i]=='\"' || s[i]=='\'') && s[i-1]!='\\') break;
      i++;
    }
    int r=i++;
    string str;
    FORR(j,l,r) {str+=s[j]; s[j]=' ';}
    tok.push_back(Token(STR,str,l));
  }
}
void a_res(char * s){
  FOR(k,0,RES_SIZ){
    int tlen=strlen(res_name[k]);
    Token t; t.type=RES; strcpy(t.s,res_name[k]);
    FOR(i,0,len) if(isalpha(s[i]) && !strncmp(s+i,res_name[k],tlen)){
      if(isalnum(s[i-1]) || isalnum(s[i+tlen]) || s[i-1]=='_' || s[i+tlen]=='_'){
        i+=tlen-1; continue;
      }
      t.pos=i; tok.push_back(t);
      FOR(j,0,tlen) s[i+j]=' ';
      i+=tlen-1;
    }
  }
}
void a_num(char * s){ //TODO
  FOR(i,0,len){
    string str;
    int j=i;
    if(isdigit(s[i])){
      if(i && (isalpha(s[i-1]) || s[i-1]=='_')) continue;
      //ok=1;
      if(s[i]=='0' && (s[i+1]=='X' || s[i+1]=='x')){  //十六进制
        while(j+1<len && isalnum(s[j+1])) j++;
      }else{  //十进制
        while(j+1<len && isdigit(s[j+1])) j++;
        /*
        if(s[j+1]=='e' || s[j+1]=='.'){ //XXX 7.e8
          j++;
          if(s[j]=='e' && (s[j+1]=='+' || s[j+1]=='-')) j++;
          if(s[j+1]=='e') j++;
          while(j+1<len && isdigit(s[j+1])) j++;
        }
        */
        if(s[j+1]=='e'){  //9e+10, 7e-4
          j++;
          if(s[j+1]=='+' || s[j+1]=='-') j++;
          while(j+1<len && isdigit(s[j+1])) j++;
        }else if(s[j+1]=='.'){  //7.3, 7.e3
          j++;
          if(s[j+1]=='e'){
            j++;
            if(s[j+1]=='+' || s[j+1]=='-') j++;
          }
          while(j+1<len && isdigit(s[j+1])) j++;
        }
      }
    }else if(s[i]=='.' && (isdigit(s[i+1]) || s[i+1]=='e' || s[i+1]=='E')){  //.7, .e7, .e+7
      while(j+1<len && isdigit(s[j+1])) j++;
      if(s[j+1]=='e' || s[j+1]=='E'){
        j++;
        if(s[j+1]=='+' || s[j+1]=='-') j++;
        while(j+1<len && isdigit(s[j+1])) j++;
      }
    }else continue;
    FORR(k,i,j) {str+=s[k]; s[k]=' ';}
    tok.push_back(Token(NUM,str,i));
    i=j;
  }
}
void a_nam(char * s){
  int i=0;
  FOR(i,0,len) if(isalpha(s[i])){
    //if((s[i]=='e' || s[i]=='E') && (isdigit(s[i-1]) || s[i-1]=='.')) continue; //判断是否为科学计数法
    //NAM 在 NUM 后面进行
    int j=i;
    while(j+1<len && (isalnum(s[j+1]) || s[j+1]=='_')) j++;
    string str;
    FORR(k,i,j) {str+=s[k]; s[k]=' ';}
    tok.push_back(Token(NAM,str,i));
    i=j;
  }
}
void a_sym(char * s){
  FOR(i,0,len){
    char ch=s[i];
    if(isalnum(s[i]) || s[i]==' ' || s[i]=='_') continue;

    if(strchr("+-*/%^#;:,(){}[]",ch)){
      tok.push_back(Token(SYM,string(1,ch),i));
      s[i]=' ';
    }else if(strchr("=<>~",ch)){
      if(s[i+1]=='='){
        string str(1,ch); str+="=";
        tok.push_back(Token(SYM,str,i));
        s[i]=s[i+1]=' '; i++;
      }else{
        tok.push_back(Token(SYM,string(1,ch),i));
        s[i]=' ';
      }
    }else if(ch=='.'){
      string str;
      if(s[i+1]=='.'){
        if(s[i+2]=='.'){
          str="..."; s[i]=s[i+1]=s[i+2]=' ';
        }else{
          str=".."; s[i]=s[i+1]=' ';
        }
      }else{
        str="."; s[i]=' ';
      }
      tok.push_back(Token(SYM,str,i));
    }
  }
}
