#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

int check[30];
stack<int> st[30];

void move(int a, int b);
void pile(int a, int b);
void clear(int a);
void print(stack<int> st,int n);

int main(void){
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++) {st[i].push(i); check[i]=i;}
	char temp1[10],temp2[10]; int a,b;
	while(scanf("%s",temp1)==1 && temp1[0]!='q'){
		scanf("%d%s%d",&a,temp2,&b);
		if(check[a]==check[b]) continue;
		if(temp1[0]=='m'){
			clear(a);
			if(temp2[1]=='n') clear(b);
			move(a,b);
		}else{
			if(temp2[1]=='n') clear(b);
			pile(a,b);
		}
		#ifdef DEBUG
		printf("  %c %d %c %d\n",temp1[0],a,temp2[1],b);
		for(int i=0;i<n;i++) print(st[i],i);
		#endif
	}
	for(int i=0;i<n;i++){
		printf("%d:",i);
		stack<int> t;
		while(!st[i].empty()) {t.push(st[i].top()); st[i].pop();}
		while(!t.empty()) {printf(" %d",t.top()); t.pop();}
		printf("\n");
	}
	return 0;
}

void move(int a_, int b_){
	int a=check[a_],b=check[b_];
	st[a].pop();
	st[b].push(a_); check[a_]=b;
}
void pile(int a_, int b_){
	int a=check[a_],b=check[b_];
	stack<int> t;
	while(!st[a].empty()){
		t.push(st[a].top()); st[a].pop();
		if(t.top()==a_) break;
	}
	while(!t.empty()){
		st[b].push(t.top()); check[t.top()]=b;
		t.pop();
	}
}
void clear(int a_){
	int a=check[a_];
	while(!st[a].empty() && st[a].top()!=a_){
		check[st[a].top()]=st[a].top(); st[st[a].top()].push(st[a].top());
		st[a].pop();
	}
//	st[a].push(a_); check[a_]=a;
}
void print(stack<int> st, int n){
	printf("  %d:",n);
	stack<int> t;
	while(!st.empty()) {t.push(st.top()); st.pop();}
	while(!t.empty()) {printf(" %d",t.top()); t.pop();}
	printf("\n");
}
