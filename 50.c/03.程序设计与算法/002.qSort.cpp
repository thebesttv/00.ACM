#include<iostream>
#include<cstdio>
#include<cstdlib>	//qsort函数头文件

#define ORDER 1	//1为升序，0为降序
#define MAX 1000

int Compare(const void * p1,const  void * p2);

int a[MAX];

int main(){
	int i=0;

	while(scanf("%d",&a[i])==1 && i<MAX){
		i++;
	}
	printf("total: %d\n",i);
	qsort(a,i,sizeof(int),Compare);
	for(int j=0;j<i;j++){
		printf("%d",a[j]);
		if(j!=i-1) printf(" ");
	}
	printf("\n");

	return 0;
}

int Compare(const void * p1, const void * p2){
	int * n1=(int *)p1;
	int * n2=(int *)p2;
	if(ORDER==1)
		return *n1-*n2;
	else
		return *n2-*n1;
}
