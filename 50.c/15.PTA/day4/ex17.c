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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

string take(string &s, int &pos){
  if(s[pos]==' '){
    while(pos<s.size() && s[pos]==' ') pos++;
    return string(" ");
  }
  if(!isalpha(s[pos])){
    return string("") + s[pos++];
  }
  string ans;
  while(pos<s.size() && isalnum(s[pos])) ans += s[pos++];
  return ans;
}

int main(void){
  int n; scanf("%d",&n); cin.get();
  while(n--){
    string line; getline(cin,line);
    cout << line << endl << "AI: ";

    for(char &c : line){
      if(isupper(c) && c!='I') c = tolower(c);
      else if(c=='?') c = '!';
    }
      
    VR<string> v;
    int pos=0;
    while(pos<line.size()) v.push_back(take(line,pos));

    // remove spaces
    while(!v.empty() && v[0]==" ") v.erase(v.begin());
    while(!v.empty() && v[v.size()-1]==" ") v.erase(v.end()-1);
#ifdef DEBUG
    cout << endl;
    for(string s : v){
      if(s==" ") s = "_";
      cout << "tok: " + s << endl;
    }
#endif
    for(string &s : v){
      //if(s == "I" || s == "me") s = "you";
      if(s == "I" || s == "me") s = "YOU";
    }

    int last=0;
    while(true){
      while(last < v.size() && !isalnum(v[last][0])) last++;
      pos = last+1;
      while(pos < v.size() && !isalnum(v[pos][0])) pos++;
      if(pos>=v.size()) break;

      if(v[last]=="can" && v[pos]=="you"){
        v[last] = "I"; v[pos] = "can";
      }else if(v[last]=="could" && v[pos]=="you"){
        v[last] = "I"; v[pos] = "could";
      }
      //last = pos+1;
      last = pos;
    }

    stack<string> st;
    for(string s : v){
      if(ispunct(s[0])){
        while(!st.empty() && st.top()==" ") st.pop();
      }
      st.push(s);
    }
    v.clear();
    while(!st.empty()) v.push_back(st.top()), st.pop();
    reverse(ALL(v));
    for(string s : v){
      if(s=="YOU") cout << "you";
      else cout << s;
    }
    cout << endl;
  }

  return 0;
}

/*
string take(string &s, int &pos){
  if(s[pos]==' '){
    while(pos<s.size() && s[pos]==' ') pos++;
    return string(" ");
  }
  if(!isalpha(s[pos])){
    return string("") + s[pos++];
  }
  string ans;
  while(pos<s.size() && isalpha(s[pos])) ans += s[pos++];
  return ans;
}

int main(void){
  int n; scanf("%d",&n); cin.get();
  while(n--){
    string line; getline(cin,line);
    cout << line << endl << "AI: ";

    for(char &c : line){
      if(isupper(c) && c!='I') c = tolower(c);
      else if(c=='?') c = '!';
    }
      
    VR<string> v;
    int pos=0;
    while(pos<line.size()) v.push_back(take(line,pos));

    // remove spaces
    while(!v.empty() && v[0]==" ") v.erase(v.begin());
    while(!v.empty() && v[v.size()-1]==" ") v.erase(v.end()-1);
#ifdef DEBUG
    for(string s : v){
      if(s==" ") s = "_";
      cout << s << endl;
    }
#endif
    for(string &s : v){
      if(s == "I" || s == "me") s = "you";
    }

    int last=0;
    while(true){
      while(last < v.size() && !isalpha(v[last][0])) last++;
      pos = last+1;
      while(pos < v.size() && !isalpha(v[pos][0])) pos++;
      if(pos>=v.size()) break;


      if(v[last]=="can" && v[pos]=="you"){
        v[last] = "I"; v[pos] = "can";
      }else if(v[last]=="could" && v[pos]=="you"){
        v[last] = "I"; v[pos] = "could";
      }
      last = pos+1;
    }
    stack<string> st;
    for(string s : v){
      if(ispunct(s[0])){
        while(!st.empty() && st.top()==" ") st.pop();
      }
      st.push(s);
    }
    v.clear();
    while(!st.empty()) v.push_back(st.top()), st.pop();
    reverse(ALL(v));
    for(string s : v) cout << s;
    cout << endl;
  }

  return 0;
}
*/
