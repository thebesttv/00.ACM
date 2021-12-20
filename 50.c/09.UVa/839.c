#include<iostream>
#include<cstdio>
using namespace std;

bool tree(int & w){
	int w1,d1,w2,d2;
	scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
	bool b1=1, b2=1;
	if(!w1) b1=tree(w1);
	if(!w2) b2=tree(w2);
	w=w1+w2;
	return b1 && b2 && w1*d1 == w2*d2;
}

int main(void){
	int T; scanf("%d",&T);
	while(T--){
		int w;
		if(tree(w)) printf("YES\n");
		else printf("NO\n");
		if(T) printf("\n");
	}

	return 0;
}
