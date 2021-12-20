#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

typedef set<int> Set;
Set::iterator it;
map<Set,int> IDcache;
vector<Set> Setcache;

int getID(Set a){
	if(IDcache.count(a)) return IDcache[a];
	Setcache.push_back(a);
	return IDcache[a]=Setcache.size()-1;
}

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		stack<int> st;
		//IDcache.clear(); Setcache.clear();
		char temp[10];
		int n; scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%s",temp);
			if(temp[0]=='P')
				st.push(getID(Set()));
			else if(temp[0]=='D')
				st.push(st.top());
			else{	//very tricky <b>
				Set s1=Setcache[st.top()]; st.pop();
				Set s2=Setcache[st.top()]; st.pop();
				if(temp[0]=='U'){
					for(it=s1.begin();it!=s1.end();it++) s2.insert(*it);
				}else if(temp[0]=='I'){
					for(it=s2.begin();it!=s2.end();it++)
						if(s1.find(*it)==s1.end()) s2.erase(it);
				}else if(temp[0]=='A'){
					s2.insert(getID(s1));
				}
				st.push(getID(s2));
				//</b>
			}
			printf("%d\n",Setcache[st.top()].size());
		}
		printf("***\n");
	}
	return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

typedef set<int> Set;
map<Set,int> IDcache;
vector<Set> Setcache;

int ID(Set x){
	if(IDcache.count(x)) return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x]=Setcache.size()-1;
}

int main(void){
	int T; scanf("%d",&T);
	while(T--){
		stack<int> s;
		int n; scanf("%d",&n);
		char temp[10];
		for(int i=0;i<n;i++){
			scanf("%s",temp);
			if(temp[0]=='P') s.push(ID(Set()));
			else if(temp[0]=='D') s.push(s.top());
			else{
				Set x1=Setcache[s.top()]; s.pop();
				Set x2=Setcache[s.top()]; s.pop();
				Set x;
				if(temp[0]=='U')
					set_union(ALL(x1),ALL(x2),INS(x));
				else if(temp[0]=='I')
					set_intersection(ALL(x1),ALL(x2),INS(x));
				else if(temp[0]=='A'){
					x=x2; x.insert(ID(x1));
				}
				s.push(ID(x));
			}
			printf("%d\n",Setcache[s.top()].size());
		}
		printf("***\n");
	}
	return 0;
}
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<stack>
using namespace std;

typedef set<int> Set;
stack<int> st;
map<Set,int> getID_;
vector<Set> getSet_;
//Set zeroSet;
Set::iterator it;

int getID(Set s);
Set getSet(int ID);
Set Union(const Set s1, const Set s2);
Set Intersect(const Set s1, const Set s2);

int main(void){
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		getID_.clear(); getSet_.clear();
		while(!st.empty()) st.pop();
		int n; scanf("%d",&n);
		char temp[10];
		for(int i=0;i<n;i++){
			scanf("%s",temp);
			if(temp[0]=='P'){
				st.push(getID(Set()));
			}else if(temp[0]=='D'){
				st.push(st.top());
			}else{
				Set s1=getSet(st.top()); st.pop();
				Set s2=getSet(st.top()); st.pop();
				if(temp[0]=='U')
					for(it=s1.begin();it!=s1.end();it++) s2.insert(*it);
				else if(temp[0]=='I')
					for(it=s2.begin();it!=s2.end();it++)
						if(s1.find(*it)==s1.end()) s2.erase(it);
				else s2.insert(getID(s1));
				st.push(getID(s2));
			}
			printf("%d\n",getSet(st.top()).size());
		}
	}
	return 0;
}

int getID(Set s){
	if(getID_.count(s)) return getID_[s];
//	int ID=getID_.size();
//	getSet_[ID]=s; getID_[s]=ID;
	getSet_.push_back(s);
	return getID_[s]=getSet_.size()-1;
}
Set getSet(int ID){
	return getSet_[ID];
}
Set Union(const Set s1, const Set s2){
	Set s3;
	for(it=s1.begin();it!=s1.end();it++) s3.insert(*it);
	for(it=s2.begin();it!=s2.end();it++) s3.insert(*it);
	return s3;
}
Set Intersect(const Set s1, const Set s2){
	Set s3;
	for(it=s1.begin();it!=s1.end();it++){
		if(*(s2.lower_bound(*it))==(*it)) s3.insert(*it);
	}
	return s3;
}
*/
