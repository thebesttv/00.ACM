/*
描述
给出班里某门课程的成绩单，请你按成绩从高到低对成绩单排序输出，如果有相同分数则名字字典序小的在前。

输入
第一行为n (0 < n < 20)，表示班里的学生数目；
接下来的n行，每行为每个学生的名字和他的成绩, 中间用单个空格隔开。名字只包含字母且长度不超过20，成绩为一个不大于100的非负整数。

输出
把成绩单按分数从高到低的顺序进行排序并输出，每行包含名字和分数两项，之间有一个空格。
*/

#include<iostream>
#include<cstdio>
#include<cstring>

#define SWAP(x,y) {struct Stu temp = (x); (x)=(y); (y)=temp;}
#define DEBUG 0

void SelectSort(struct Stu * p, int n, int left, int right);
	//n为1则对score降序排列，n为2则对dic升序排列

int n;
struct Stu{
	char name[20];
	int score;
	double dic;
}stu[20];

int main(void){

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		double temp=1e300;
		scanf("%s %d",stu[i].name,&stu[i].score);
		char t;
		for(int j=0;stu[i].name[j]!=0;j++){
			t=stu[i].name[j]; t=isupper(t) ? (t-'A'+1)*2-1 : (t-'a'+1)*2;
			stu[i].dic+=t*temp;
			temp/=1e4;
		}
	}

	SelectSort(stu,1,0,n-1);
	#if DEBUG
	printf("dic:\n");
	for(int i=0;i<n;i++)
		printf("%s %d\t\tdic:%lf\n",stu[i].name,stu[i].score,stu[i].dic);
	#endif

	for(int i=0;i<n-1;i++){
		#if DEBUG
			printf("in loop, i: %d\n",i);
		#endif
		if(stu[i].score==stu[i+1].score){
			int j;
			for(j=i+1;j<n;j++)
				if(stu[j].score!=stu[i].score) break;
			#if DEBUG
				printf("SelectSort(stu,2,%d,%d)\n",i,j-1);
			#endif
			SelectSort(stu,2,i,j-1);
			i=j-1;	//要-1，还有循环体中的i++
		}
	}

	#if DEBUG
	printf("dic:\n");
	for(int i=0;i<n;i++)
		printf("%s %d\t\tdic:%lf\n",stu[i].name,stu[i].score,stu[i].dic);
	#endif

	for(int i=0;i<n;i++)
		printf("%s %d\n",stu[i].name,stu[i].score);

	return 0;
}

void SelectSort(struct Stu * p, int n, int left, int right){
	if(n==1){
		for(int i=left;i<right;i++){
			int max=i;
			for(int j=i;j<=right;j++)
				if(p[j].score>p[max].score) max=j;
			SWAP(p[i],p[max])
		}
	}else if(n==2){
		for(int i=left;i<right;i++){
			int min=i;
			for(int j=i;j<=right;j++)
				if(p[j].dic<p[min].dic) min=j;
			SWAP(p[i],p[min])
		}
	}
}
