#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void){
//	freopen("dp.in","w",stdout);
	srand(time(NULL));
	int n=1000,k=(rand()*1000);
	printf("%d %d\n",n,k);
	for(int i=0;i<n;i++){
		printf("%.2lf\n",rand()/100.0);
	}

	return 0;
}
