#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <memory>
using namespace std;

string unify(const string &ori){
  string s(ori);
  for(char &c : s)
    if(isupper(c))
      c = tolower(c);
    else if(ispunct(c))
      c = ' ';
  return s;
}

class QueryResult{
public:
  QueryResult(string s, shared_ptr<set<int>> ps, shared_ptr<vector<string>> pv):
    word(s), ps(ps), pv(pv) { }
  void print(ostream &out){
    out << "\"" + word + "\"" << " occures " << ps->size() << " time(s)" << endl;
    for(int x : *ps){
      //out << "  (line " << x << ") " << (*pv)[x] << endl;
      out << "  (line " << x << ") " << pv->at(x) << endl;
    }
  }
private:
  string word;
  shared_ptr<set<int>> ps;
  shared_ptr<vector<string>> pv;
};

class TextQuery{
public:
  TextQuery(istream &in){
    pv = make_shared<vector<string>>();
    pv->push_back("");  // 第 0 行为空串
    string line, word; int lineNum = 0;
    while(getline(in,line)){
      pv->push_back(line); ++lineNum;
      istringstream ss(unify(line));
      while(ss >> word){
        addItem(word, lineNum);
      }
    }
  }

  shared_ptr<QueryResult> query(const string &ori){
    string word(ori);
    for(char &c : word)
      c = tolower(c);
    shared_ptr<QueryResult> p;
    if(mp.find(word)!=mp.end())
      p = make_shared<QueryResult>(word, mp[word], pv);
    return p;
  }

private:
  shared_ptr<vector<string>> pv;
  map<string, shared_ptr<set<int>>> mp;

  void addItem(const string &word, int n){
#ifdef DEBUG
    printf(" addItem(%s, %d)\n",word.c_str(),n);
#endif
    if(mp.find(word)==mp.end()){
      mp[word] = make_shared<set<int>>();
    }
    mp[word]->insert(n);
  }
};

void runQueries(ifstream &in){
  TextQuery tq(in);
  while(true){
    cout << "enter word to look for, or q to quit: ";
    string s;
    if(!(cin >> s) || s=="q") break;
    auto p = tq.query(s);
    if(!p) cerr << "no such word" << endl;
    else p-> print(cout);
  }
}

int main(int argc, char *argv[]){
  ifstream in(argv[1]);
  runQueries(in);

  return 0;
}
