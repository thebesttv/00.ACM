/*
公鸡一只五元，母鸡一只三元，小鸡三只一元。
现有100元，买了100只鸡，问：公鸡、母鸡、小鸡各买几只？
*/

#include<iostream>
#include<cstdio>
using namespace std;

//[1]
int main(void){
	for(int i=0;i<=100;i++) for(int k=0;k+i<=100;k+=3){
		int j=100-i-k;
		if(5*i + j*3 + k/3 == 100) printf("%d %d %d\n",i,j,k);
	}

	return 0;
}


/*
//[2]
int main(void){
	for(int i=0;i<=100;i++) for(int j=0;i+j<=100;j++){
		int k=100-i-j; if(k%3!=0) continue;
		if(i*5 + j*3 + k/3 == 100) printf("%d %d %d\n",i,j,k);
	}

	return 0;
}
*/
