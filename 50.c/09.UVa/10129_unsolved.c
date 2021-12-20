#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int in[26],out[26];
bool G[26][26], book[26][26];	//无向图的dfs
bool check[26];	//记录出现的首/尾字母
char temp[1004];

void dfs(int u);

int main(void){
	int T; scanf("%d",&T);
	while(T--){
		memset(G,0,sizeof(G)); memset(book,0,sizeof(book));
		for(int i=0;i<26;i++) {in[i]=0; out[i]=0;}
		int n; scanf("%d",&n); getchar();
		for(int i=0;i<n;i++){
/*			char first=getchar();
			char last=0,temp=0;
			do{
				last = temp;
				temp = getchar();
			}while(temp!='\n');
*/
			scanf("%s",temp);
			char first=temp[0], last=temp[strlen(temp)-1];
			#ifdef DEBUG
			printf("  get: %c...%c\n",first,last);
			#endif
			first-='a'; last-='a';
			G[first][last] = G[last][first] = 1;
			if(first != last) {out[first]++; in[last]++;}
			check[first] = check[last] = 1;
		}

		bool flag=1;
		int pos; for(pos=0; !check[pos]; pos++);	//寻找第一个出现的字母
		dfs(pos);
		for(pos=0; pos<26; pos++)
			if(check[pos]) {flag=0; break;}
			//
		#ifdef DEBUG
		if(flag) printf("  connected\n");
		else printf("  not connected\n");
		for(int i=0;i<26;i++) if(in[i] || out[i])
			printf("  %c: in: %d, out: %d\n",i+'a',in[i],out[i]);
		#endif

		int start=-1, end=-1;	//<b>当变量可能为 -1 时，一定不能用 char，而应用 int </b>
		if(flag) for(int i=0;i<26;i++){
			if(in[i] != out[i]){
				if(in[i]+1 == out[i]){	//start
					if(start==-1) start=i;
					else {flag=0; break;}
				}else if(in[i] == out[i]+1){	//end
					if(end==-1) end=i;
					else {flag=0; break;}
				}else{	//不能忘！！！
					flag=0; break;
				}
			}
		}

		if(flag) printf("Ordering is possible.\n");
		else printf("The door cannot be opened.\n");
	}

	return 0;
}

void dfs(int u){
	check[u]=0;
	for(int v=0;v<26;v++) if(G[u][v] && !book[u][v]){
		book[u][v] = book[v][u] = 1;
		dfs(v);
	}
}
