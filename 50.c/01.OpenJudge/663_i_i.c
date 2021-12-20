/*
描述
"Help Jimmy" 是在下图所示的场景上完成的游戏。

         *
        _____

     ______
             _____
    ___
                   __
        ____

_____________________________(ground)

场景中包括多个长度和高度各不相同的平台。地面是最低的平台，高度为零，长度无限。
Jimmy老鼠在时刻0从高于所有平台的某处开始下落，它的下落速度始终为1米/秒。当Jimmy落到某个平台上时，游戏者选择让它向左还是向右跑，它跑动的速度也是1米/秒。当Jimmy跑到平台的边缘时，开始继续下落。Jimmy每次下落的高度不能超过MAX米，不然就会摔死，游戏也会结束。
设计一个程序，计算Jimmy到底地面时可能的最早时间。

输入
第一行是测试数据的组数t（0 <= t <= 20）。每组测试数据的第一行是四个整数N，X，Y，MAX，用空格分隔。N是平台的数目（不包括地面），X和Y是Jimmy开始下落的位置的横竖坐标，MAX是一次下落的最大高度。接下来的N行每行描述一个平台，包括三个整数，X1[i]，X2[i]和H[i]。H[i]表示平台的高度，X1[i]和X2[i]表示平台左右端点的横坐标。1 <= N <= 1000，-20000 <= X, X1[i], X2[i] <= 20000，0 < H[i] < Y <= 20000（i = 1..N）。所有坐标的单位都是米。
Jimmy的大小和平台的厚度均忽略不计。如果Jimmy恰好落在某个平台的边缘，被视为落在平台上。所有的平台均不重叠或相连。测试数据保证问题一定有解。

输出
对输入的每组测试数据，输出一个整数，Jimmy到底地面时可能的最早时间。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int INF=1<<28;
int x,y,n,MAX;
struct Flat{
	int x1,x2,h;
	Flat *nextL, *nextR;

	bool operator < (const Flat & b) const {
		return h>b.h;
	}
}flat[1004];
int Time[1004][2];	//从板i左、右端点下落的最短时间为Time[i][0],Time[i][1]

int Left(Flat * p);
int Right(Flat * p);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	#endif
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		memset(flat,0,sizeof(flat)); memset(Time,-1,sizeof(Time));
		scanf("%d%d%d%d",&n,&x,&y,&MAX);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&flat[i].x1,&flat[i].x2,&flat[i].h);
		flat[0].x1=flat[0].x2=x; flat[0].h=y;
		sort(flat,flat+n+1);
		for(int i=0;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				if(flat[j].x1<=flat[i].x1 && flat[j].x2>=flat[i].x1)
				if(flat[i].nextL==NULL && 
				(flat[j].x1<=flat[i].x1 && flat[j].x2>=flat[i].x1) && 
				(flat[i].h-flat[j].h)<=MAX)
					flat[i].nextL = &flat[j];
//				if(flat[j].x1<=flat[i].x2 && flat[j].x2>=flat[i].x2)
				if(flat[i].nextR==NULL && 
				(flat[j].x1<=flat[i].x2 && flat[j].x2>=flat[i].x2) && 
				(flat[i].h-flat[j].h)<=MAX)
					flat[i].nextR = &flat[j];
				if(flat[i].nextL!=NULL && flat[i].nextR!=NULL) break;
			}
			#ifdef DEBUG
			printf("  flat[%d]: x1: %d, x2: %d, h: %d\n",i,flat[i].x1,flat[i].x2,flat[i].h);
			if(flat[i].nextL==NULL) printf("    nextL: NULL, ");
			else printf("    nextL: flat[%d], ",flat[i].nextL-flat);
			if(flat[i].nextR==NULL) printf("nextR: NULL\n");
			else printf("nextR: flat[%d]\n",flat[i].nextR-flat);
			#endif
		}
		int time=Left(flat);
		#ifdef DEBUG
		for(int i=0;i<=n;i++) printf("Time[%d]: %d, %d\n",i,Time[i][0],Time[i][1]);
		#endif
		printf("%d\n",time);
	}

	return 0;
}

int Left(Flat * p){
	int pos=p-flat;
	if(Time[pos][0]!=-1) return Time[pos][0];
	if(p->nextL){
		Time[pos][0]=((p->h)-(p->nextL->h) + 
			min(Left(p->nextL) + ((p->x1)-(p->nextL->x1)), 
			   Right(p->nextL) + (p->nextL->x2)-(p->x1)));
	}else{
		Time[pos][0]=(p->h<=MAX ? p->h : INF);
	}
	return Time[pos][0];
}
int Right(Flat * p){
	int pos=p-flat;
	if(Time[pos][1]!=-1) return Time[pos][1];
	if(p->nextR){
		Time[pos][1]=((p->h)-(p->nextR->h) + 
			min(Left(p->nextR) + ((p->x2)-(p->nextR->x1)), 
			   Right(p->nextR) + (p->nextR->x2)-(p->x2)));
	}else{
		Time[pos][1]=(p->h<=MAX ? p->h : INF);
	}
	return Time[pos][1];
}
