/*
描述
7月17日是Mr.W的生日，ACM-THU为此要制作一个体积为 N*pi 的M层生日蛋糕，每层都是一个圆柱体。
设从下往上数第i(1 <= i <= M)层蛋糕是半径为Ri, 高度为Hi的圆柱。当i < M 时，要求Ri > Ri+1且Hi > Hi+1。
由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积Q最小。
令Q = S*pi
请编程对给出的N和M，找出蛋糕的制作方案（适当的Ri和Hi的值），使S最小。
（除Q外，以上所有数据皆为正整数）

输入
有两行，第一行为N（N <= 10000），表示待制作的蛋糕的体积为Nπ；第二行为M(M <= 20)，表示蛋糕的层数为M。

输出
仅一行，是一个正整数S（若无解则S = 0）。
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int N,M;
int minV[24],minA[24];
int minArea = 1<<30;

int MaxVofMHR(int m, int h, int r){
	int v=0;
	for(int i=0;i<m;i++) v += (h-i)*(r-i)*(r-i);
	return v;
}
void dfs(int v, int m, int maxH, int maxR, int area){
	if(m==0){
		if(!v)	//<b></b>
			minArea = min(area, minArea);
		return;
	}
	if(v<=0) return;						//
	if(area + minA[m] >= minArea) return; 	//1
	if(maxH < m || maxR < m) return;		//2
	if(minV[m] > v) return;					//3
	if(MaxVofMHR(m,maxH,maxR) < v) return;	//4

	for(int r=maxR; r>=m; r--){
		if(m==M) area = r*r;
		for(int h=maxH; h>=m; h--){	//枚举当前第n层的半径、高，先r再h
			int curV = h*r*r, curA = 2*r*h;
			if(v-curV < 0) continue;			//
			dfs(v-curV,m-1,h-1,r-1,area+curA);
		}
	}
}

int main(void){
	scanf("%d%d",&N,&M);
	for(int i=1;i<=20;i++){
		minV[i] = minV[i-1] + i*i*i;
		minA[i] = minA[i-1] + 2*i*i;
	}
	if(minV[M] <= N){
		int maxH = (double)(N-minV[M-1])/(M*M) + 1;
		int maxR = sqrt((double)(N-minV[M-1])/M) + 1;
		dfs(N,M,maxH,maxR,0);
//		for(int h=maxH; h>=M;h--) for(int r=maxR; r>=M; r--){	//不要循环，dfs中的参数表示最大h和最大r
//			dfs(N,M,h,r,r*r);
//		}
	}
	if(minArea == 1<<30) minArea=0;
	printf("%d\n",minArea);

	return 0;
}
