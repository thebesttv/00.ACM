#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
using namespace std;

int b[9][9];
int cur;
int to[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
class Rec{
public:
	int x,y;

	bool operator < (const Rec & b) const {
		if(x<b.x) return 1;
		else if(x==b.x) return y<b.y;
		else return 0;
	}
};
set<Rec> st;
set<Rec>::iterator it;

void list();
void move(const int x, const int y);
void printBoard();
void place(int x1, int y1, int x2, int y2, int dir);
void printNum();

int main(void){
	int kase; scanf("%d",&kase);
	while(kase--){
		int c; memset(b,0,sizeof(b));
		for(int i=1;i<=8;i++) for(int j=1;j<=8;j++){
			do c=getchar(); while(c!='-' && c!='B' && c!='W');
			c= c=='-' ? 0 : (c=='B' ? -1 : 1);
			b[i][j]=c;
		}
		do c=getchar(); while(c!='B' && c!='W');
		cur= c=='B' ? -1 : 1;
		char temp[5];
		while(scanf("%s",temp)==1){
			if(temp[0]=='L')		list();
			else if(temp[0]=='M')	move(temp[1]-'0', temp[2]-'0');
			else					{printBoard(); break;}
		}
		if(kase) putchar('\n');
	}
	return 0;
}

void list(){
	st.clear(); Rec t;
	bool flag=0;
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) if(b[i][j]==cur){	//从与当前子相同的子开始查找
		for(int dir=0;dir<8;dir++){
			int tx=i, ty=j;
			do {tx=tx+to[dir][0]; ty=ty+to[dir][1];} while(b[tx][ty]==-cur);
			if(tx<1 || tx>8 || ty<1 || ty>8) continue;
			if(b[tx][ty]==0 && !(tx==i+to[dir][0] && ty==j+to[dir][1])){	//find blank && not around (i,j)
				#ifdef DEBUG
//				printf("  list: find, from (%d,%d) to (%d,%d), dir: %d\n",i,j,tx,ty,dir);
				#endif
				flag=1;
				t.x=tx; t.y=ty;
				st.insert(t);
			}
		}
	}
	if(!flag){
		printf("No legal move.\n");
	}else{
		flag=0;
		for(it=st.begin();it!=st.end();it++){
			if(flag) putchar(' ');
			else flag=1;
			printf("(%d,%d)",it->x,it->y);
		}
		putchar('\n');
	}
}
void move(const int x, const int y){
	bool flag=0;
	for(int dir=0;dir<8;dir++){
		int tx=x, ty=y;
		do {tx=tx+to[dir][0]; ty=ty+to[dir][1];} while(b[tx][ty]==-cur);
		if(tx<1 || tx>8 || ty<1 || ty>8) continue;
		if(b[tx][ty]==cur && !(tx==x+to[dir][0] && ty==y+to[dir][1])){
			flag=1; place(x,y,tx,ty,dir);
			#ifdef DEBUG
			printf("  move: place from (%d,%d) to (%d,%d), dir: %d\n",x,y,tx,ty,dir);
			#endif
		}
	}
	cur=-cur;
	if(!flag) move(x,y);
	else printNum();
}
void printBoard(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++) printf("%c",b[i][j]==0 ? '-' : (b[i][j]==-1 ? 'B' : 'W'));
		putchar('\n');
	}
}
void place(int x1, int y1, int x2, int y2, int dir){
	do{
		b[x1][y1]=cur;
		x1=x1+to[dir][0]; y1=y1+to[dir][1];
	}while(x1!=x2 || y1!=y2);
}
void printNum(){
	int leftB=0,leftW=0;
	for(int i=1;i<=8;i++) for(int j=1;j<=8;j++)
		if(b[i][j]==1) leftW++;
		else if(b[i][j]==-1) leftB++;
	printf("Black - %2d White - %2d\n",leftB,leftW);
}
