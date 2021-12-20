//递归=动归
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

const int MAX=104;
int a[MAX][MAX],n,check[MAX][MAX];

int maxSum(int i, int j){
	if(check[i][j]!=-1) return check[i][j];
	if(i==n-1) return a[i][j];
	return check[i][j]=max(maxSum(i+1,j),maxSum(i+1,j+1))+a[i][j];
}

int main(void){
	srand(time(NULL));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			a[i][j]=rand()%100;
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	memset(check,-1,sizeof(check));
	printf("max: %d\n",maxSum(0,0));

	return 0;
}
