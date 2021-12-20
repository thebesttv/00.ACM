/*
描述
平面上有一个大矩形，其左下角坐标（0，0），右上角坐标（R,R)。大矩形内部包含一些小矩形，小矩形都平行于坐标轴且互不重叠。所有矩形的顶点都是整点。要求画一根平行于y轴的直线x=k（k是整数) ，使得这些小矩形落在直线左边的面积必须大于等于落在右边的面积，且两边面积之差最小。并且，要使得大矩形在直线左边的的面积尽可能大。注意：若直线穿过一个小矩形，将会把它切成两个部分，分属左右两侧。

输入
第一行是整数R，表示大矩形的右上角坐标是(R,R) (1 <= R <= 1,000,000)。
接下来的一行是整数N,表示一共有N个小矩形(0 < N <= 10000)。
再接下来有N 行。每行有4个整数，L,T, W 和 H, 表示有一个小矩形的左上角坐标是(L,T),宽度是W，高度是H (0<=L,T <= R, 0 < W,H <= R). 小矩形不会有位于大矩形之外的部分。

输出
输出整数n，表示答案应该是直线 x=n。 如果必要的话，x=R也可以是答案。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int sl[1000000],sr[1000000],totS=0;
int r,n,maxX=0;

int main(void){
	scanf("%d%d",&r,&n);
	for(int i=0;i<n;i++){
		int x,y,w,h;
		scanf("%d%d%d%d",&x,&y,&w,&h);
		totS+=w*h; maxX=max(maxX,x);
		for(int i=x+1;i<=x+w;i++){
			sl[i]+=h;
		}
	}
	for(int i=1,t=0;i<=r;i++) sl[i]+=sl[i-1];
	for(int i=r;i>=0;i--) sr[i]=totS-sl[i];
//for(int i=0;i<=maxX+10;i++) printf("  sl[%d]: %d, sr[%d]: %d\n",i,sl[i],i,sr[i]);
	int i=0;
	while(sl[i]<sr[i] && i<r) i++;
	int minS=sl[i]-sr[i];
	for(i=r;i>=0;i--) if(sl[i]-sr[i]==minS) break;
	printf("%d\n",i);

	return 0;
}

/*
struct Str{
	int x;
	int y;
	int w;
	int h;
}squ[1000000];
int r,n,minS=~(1<<31),maxP=0;
//set<int> st;

bool Check(int k);	//return 小矩形S左>=S右; 返回前记录差最小y于st
//bool Check2(int x);	//在差最小中查找

int main(void){
	scanf("%d%d",&r,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&squ[i].x,&squ[i].y,&squ[i].w,&squ[i].h);
	}
	int L=0,R=r;
	while(L<R){
		int M=L+(R-L)/2;
printf("%d %d\n",L,R);
		if(Check(M)) R=M;
		else L=M+1;
	}
//	set<int>::iterator p=st.end(); p--;
	printf("%d\n",maxP);

	return 0;
}

bool Check(int k){
	int sl=0,sr=0;
	for(int i=0;i<n;i++){
		int x=squ[i].x,w=squ[i].w,h=squ[i].h;
		if(x+w<=k) sl+=w*h;
		else if(x>=k) sr+=w*h;
		else {
			int r=x+w-k;
			sl+=(x+w-r)*h; sr+=r*h;
		}
	}
	if(sl<sr) return false;
	if(sl-sr<minS){minS=sl-sr; maxP=k;}
	else if(sl-sr==minS) maxP=max(maxP,k);
printf("  x=%d, sl:%d, sr:%d, maxP: %d\n",k,sl,sr,maxP);
	return true;
}
*/
