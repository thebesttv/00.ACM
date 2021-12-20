#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

struct Ind{
	int type;	//-1: Black General, 1: Red General, 2: Chariot, 3: Cannon, 4: Horse
	int x,y;
}red[30],black[2];
int board[11][10];

void generate(int n);
bool setBlack(int type);
int checkMate(const int x,const int y);

int main(void){
	int n,bx,by;
	while(scanf("%d%d%d",&n,&bx,&by)==3 && n){
		black[0].type=-1; black[0].x=bx; black[0].y=by;
		for(int i=0;i<n;i++){
			int c,x,y;
			do{
				c=getchar();
			}while(!isalpha(c));
			scanf("%d%d",&x,&y);
			red[i].x=x; red[i].y=y;
			if(c=='G') red[i].type=1;
			else if(c=='R') red[i].type=2;
			else if(c=='C') red[i].type=3;
			else if(c=='H') red[i].type=4;
		}
		bool flag=1;
		for(int type=0;type<4;type++){
			if(!flag) break;
			generate(n);
			if(!setBlack(type)) continue;
			#ifdef DEBUG
			printf("--Black General: (%d,%d)\n",black[1].x,black[1].y);
			#endif
			bool single=0;
			for(int i=1;i<=10;i++) for(int j=1;j<=9;j++){
				if(board[i][j]>0){
					int res=checkMate(i,j);
					#ifdef DEBUG
					char c;
					if(board[i][j]==1) c='G';
					else if(board[i][j]==2) c='R';
					else if(board[i][j]==3) c='C';
					else c='H';
					printf("----%c in (%d,%d), checkMate: %d\n",c,i,j,res);
					#endif
					if(res) single=1; break;
				}
			}
			if(!single) flag=0;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

void generate(int n){
	memset(board,0,sizeof(board));
	for(int i=0;i<n;i++) board[red[i].x][red[i].y]=red[i].type;
}
bool setBlack(int type){
	int x=black[0].x, y=black[0].y;
	if(type==0) x++;
	else if(type==1) x--;
	else if(type==2) y++;
	else if(type==3) y--;
	if(x<1 || x>3 || y<4 || y>6) return 0;
	black[1].x=x; black[1].y=y;
	board[x][y]=-1;
	return 1;
}
int checkMate(const int x,const int y){
	if(board[x][y]==1){	//General
		bool empty=1;
		for(int i=x-1;i>black[1].x;i--)
			if(board[i][y]) empty=0;
		if(empty && black[1].y==y) return 11;
	}else if(board[x][y]==2){	//Chariot
		int tx,ty;
		tx=x+1; ty=y;
		while(board[tx][ty]==0 && tx>=1 && tx<=10) tx++;
		if(board[tx][ty]==-1) return 21;
		tx=x-1; ty=y;
		while(board[tx][ty]==0 && tx>=1 && tx<=10) tx--;
		if(board[tx][ty]==-1) return 22;

		tx=x; ty=y+1;
		while(board[tx][ty]==0 && ty>=1 && ty<=9) ty++;
		if(board[tx][ty]==-1) return 23;
		ty=y; ty=y-1;
		while(board[tx][ty]==0 && ty>=1 && ty<=9) ty++;
		if(board[tx][ty]==-1) return 24;
	}else if(board[x][y]==3){	//Cannon
		int tx,ty;
		tx=x+1; ty=y;
		while(board[tx][ty]==0 && tx>=1 && tx<=10) tx++;
		if(tx<9 && board[tx+1][ty]==-1) return 31;
		tx=x-1; ty=y;
		while(board[tx][ty]==0 && tx>=1 && tx<=10) tx--;
		if(tx>1 && board[tx-1][ty]==-1) return 32;

		tx=x; ty=y+1;
		while(board[tx][ty]==0 && ty>=1 && ty<=9) ty++;
		if(ty<8 && board[tx][ty+1]==-1) return 33;
		ty=y; ty=y-1;
		while(board[tx][ty]==0 && ty>=1 && ty<=9) ty++;
		if(ty>1 && board[tx][ty-1]==-1) return 34;
	}else if(board[x][y]==4){
		int tx,ty;
		if(x>2 && board[x-1][y]==0){	//up
			tx=x-2;
			if(y>1){
				ty=y-1;
				if(board[tx][ty]==-1) return 41;
			}
			if(y<9){
				ty=y+1;
				if(board[tx][ty]==-1) return 42;
			}
		}
		if(x<9 && board[x+1][y]==0){	//down
			tx=x+2;
			if(y>1){
				ty=y-1;
				if(board[tx][ty]==-1) return 43;
			}
			if(y<9){
				ty=y+1;
				if(board[tx][ty]==-1) return 44;
			}
		}
		if(y>2 && board[x][y-1]==0){	//left
			ty=y-2;
			if(x>1){
				tx=x-1;
				if(board[tx][ty]==-1) return 45;
			}
			if(x<10){
				tx=x+1;
				if(board[tx][ty]==-1) return 46;
			}
		}
		if(y<8 && board[x][y+1]==0){	//right
			ty=y+2;
			if(x>1){
				tx=x-1;
				if(board[tx][ty]==-1) return 47;
			}
			if(x<10){
				tx=x+1;
				if(board[tx][ty]==-1) return 48;
			}
		}
	}
	return 0;
}
