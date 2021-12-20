#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack<int> st;
int tar[1010],n;
int A,B;

int main(void){
	while(scanf("%d",&n)==1 && n){
		int t;
		while(scanf("%d",&t) && t){
			while(!st.empty()) st.pop();
			tar[1]=t;
			for(int i=2;i<=n;i++) scanf("%d",&tar[i]);
			A=1; B=1;
			bool ok=1;
//			while(A<=n && B<=n){	//WRONG
			while(B<=n){
				if(!st.empty() && st.top()==tar[B]){
					st.pop(); B++;
				}else if(A<=n){
					st.push(A++);
				}else{
					ok=0; break;
				}
			}
/*
			//Rujia Liu
			while(B<=n){
				if(A==tar[B]){
					A++; B++;
				}else if(!st.empty() && st.top()==tar[B]){
					st.pop(); B++;
				}else if(A<=n){
					st.push(A++);
				}else{
					ok=0; break;
				}
			}
*/
			printf("%s\n", (ok ? "Yes" : "No"));
		}
		printf("\n");
	}

	return 0;
}
