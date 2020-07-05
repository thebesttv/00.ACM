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
#include<sstream>
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

void reverse(string &s){
  string t(s); s.erase();
  ROR(i,t.size()-1,0) s.push_back(t[i]);
}
void lstrip(string &s){
  int start=-1;
  FOR(i,0,s.size()) if(s[i]!='0'){
    start=i; break;
  }
  string t(s); s.erase();
  if(start!=-1){
    FOR(i,start,t.size())
      s.push_back(t[i]);
  }else{
    s.push_back('0');
  }
}
void rstrip(string &s){
  int end=-1;
  ROR(i,s.size()-1,0) if(s[i]!='0'){
    end=i+1; break;
  }
  string t(s); s.erase();
  if(end!=-1){
    FOR(i,0,end)
      s.push_back(t[i]);
  }else s.push_back('0');
}

int main(void){
  string s,ls,rs;
  cin >> s;
  int token=0, pos, len=s.size();
  FOR(i,0,len) if(!isdigit(s[i]))
    token=s[i], pos=i;

  if(token==0){ // 整数
    reverse(s);
    lstrip(s);
    cout << s << endl;
  }else if(token=='.'){ // 小数
    FOR(i,0,pos) ls.push_back(s[i]);
    FOR(i,pos+1,len) rs.push_back(s[i]);
    reverse(ls); lstrip(ls);
    reverse(rs); rstrip(rs);  // 删除小数部分的尾数0
    cout << ls << '.' << rs << endl;
  }else if(token=='/'){ // 分数
    FOR(i,0,pos) ls.push_back(s[i]);
    FOR(i,pos+1,len) rs.push_back(s[i]);
    reverse(ls); lstrip(ls);
    reverse(rs); lstrip(rs);  // 删除小数部分的尾数0
    cout << ls << '/' << rs << endl;
  }else if(token=='%'){ // 百分数
    FOR(i,0,pos) ls.push_back(s[i]);
    reverse(ls); lstrip(ls);
    cout << ls << '%' << endl;
  }


  return 0;
}
