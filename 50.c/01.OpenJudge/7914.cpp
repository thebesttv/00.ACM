/*
描述
世博会志愿者的选拔工作正在 A 市如火如荼的进行。为了选拔最合适的人才，A市对所有报名的选手进行了笔试，笔试分数达到面试分数线的选手方可进入面试。面试分数线根据计划录取人数的150%划定，即如果计划录取m名志愿者，则面试分数线为排名第m*150%（向下取整）名的选手的分数，而最终进入面试的选手为笔试成绩不低于面试分数线的所有选手。

现在就请你编写程序划定面试分数线，并输出所有进入面试的选手的报名号和笔试成绩。

输入
第一行，两个整数n，m（5 ≤ n ≤ 5000，3 ≤ m ≤ n），中间用一个空格隔开，其中n 表示报名参加笔试的选手总数，m 表示计划录取的志愿者人数。输入数据保证m*150%向下取整后小于等于n。
第二行到第 n+1 行，每行包括两个整数，中间用一个空格隔开，分别是选手的报名号k（1000 ≤ k ≤ 9999）和该选手的笔试成绩s（1 ≤ s ≤ 100）。数据保证选手的报名号各不相同。

输出
第一行，有两个整数，用一个空格隔开，第一个整数表示面试分数线；第二个整数为进入面试的选手的实际人数。
从第二行开始，每行包含两个整数，中间用一个空格隔开，分别表示进入面试的选手的报名号和笔试成绩，按照笔试成绩从高到低输出，如果成绩相同，则按报名号由小到大的顺序输出。
*/

#include<iostream>
#include<cstdio>
#include<cmath>

struct Reg{
	int n;
	int score;
}ply[5000],temp;

void SortS(struct Reg * p, int left, int right);
void SortN(struct Reg * p, int left, int right);

int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	m=floor(m*1.5);
	for(int i=0;i<n;i++) scanf("%d%d",&ply[i].n,&ply[i].score);
	SortS(ply,0,n-1);

	for(int i=0;i<n-1;i++){
		if(ply[i].score==ply[i+1].score){
			int tot;
			for(tot=i+1;tot<n;tot++) if(ply[tot].score!=ply[i].score) break;
			SortN(ply,i,tot-1);
			i=tot-1;	//重要，要把i用tot赋值，还要考虑for循环自带的i++
		}
	}

	while(ply[m-1].score==ply[m].score) ++m;
	printf("%d %d\n",ply[m-1].score,m);
	for(int i=0;i<m;i++) printf("%d %d\n",ply[i].n,ply[i].score);

	return 0;
}

void SortS(struct Reg * p, int left, int right){
	if(left>=right) return;
	int i=left, j=right, k=p[left].score;
	while(i!=j){
		while(i<j && p[j].score<=k) j--;
		while(i<j && p[i].score>=k) i++;
		temp=p[i];p[i]=p[j];p[j]=temp;
	}
	temp=p[i];p[i]=p[left];p[left]=temp;
	SortS(p,left,i-1);
	SortS(p,i+1,right);
}
void SortN(struct Reg * p, int left, int right){
        if(left>=right) return;
        int i=left, j=right, k=p[left].n;
        while(i!=j){
                while(i<j && p[j].n>=k) j--;
                while(i<j && p[i].n<=k) i++;
                temp=p[i];p[i]=p[j];p[j]=temp;
        }
        temp=p[i];p[i]=p[left];p[left]=temp;
        SortN(p,left,i-1);
        SortN(p,i+1,right);
}
