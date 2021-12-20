//“人人为我”的递推型动归程序
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;

const int MAX=104;
int a[MAX][MAX],n,check[MAX];

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
	for(int i=0;i<n;i++) check[i]=a[n-1][i];
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<=i;j++) check[j]=max(check[j],check[j+1])+a[i][j];
	}
	printf("max: %d\n",check[0]);

	return 0;
}
