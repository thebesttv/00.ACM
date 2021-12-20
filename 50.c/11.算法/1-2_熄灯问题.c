#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int a[5],s[5],temp[5];

int GetBit(int n, int i);
void PutBit(int * p, int i, int d);
void Flip(int * p, int i);
bool Convert(int sw);

int main(void){
	for(int i=0;i<5;i++) for(int j=0;j<6;j++){
		int t; scanf("%d",&t);
		PutBit(&a[i],j,t);
	}
	for(int i=0;i<(1<<6);i++){
		if(Convert(i)){
			for(int j=0;j<5;j++){
				for(int k=0;k<6;k++){
					if(k!=0) printf(" ");
					printf("%d",GetBit(s[j],k));
					if(k==5) printf("\n");
				}
			}
			break;	//解的唯一性？
		}
	}

	return 0;
}

int GetBit(int n, int i){
	return (n>>i)&1;
}
void PutBit(int * p, int i, int d){
	if(d)	*p|=(1<<i);
	else	*p&=~(1<<i);
}
void Flip(int * p, int i){
	*p^=(1<<i);
}
bool Convert(int sw){
	memset(s,0,sizeof(s));
	s[0]=sw;
	for(int i=0;i<5;i++) temp[i]=a[i];
	for(int i=0;i<6;i++){	//根据sw设置temp[0]
		if(GetBit(sw,i)){
			if(i>0) Flip(&temp[0],i-1);
			Flip(&temp[0],i);
			if(i<5) Flip(&temp[0],i+1);
			Flip(&temp[1],i);	//莫忘
		}
	}
	for(int i=1;i<5;i++) for(int j=0;j<6;j++){	//递推
		if(GetBit(temp[i-1],j)){ PutBit(&s[i],j,1);
			Flip(&temp[i-1],j);
			if(j>0) Flip(&temp[i],j-1);
			Flip(&temp[i],j);
			if(j<5) Flip(&temp[i],j+1);
			if(i<4) Flip(&temp[i+1],j);
		}
	}

	return temp[4]==0;
}
