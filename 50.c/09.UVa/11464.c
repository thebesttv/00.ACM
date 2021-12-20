#include<stdio.h>
#include<stdlib.h>

int a[15+4][15+4],b[15+4][15+4];
int n;
long cou;

int check(int s);

int main(void){
	int T;
	scanf("%d",&T);
	for(int kase=1;kase<=T;kase++){
		long min=1l<<30;
		scanf("%d",&n);
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) scanf("%d",&a[i][j]);
		for(int i=0;i<(1<<n);i++){
			if(check(i)==1) min=(cou<min ? cou : min);
		}
		if(min==1l<<30) min=-1;
		printf("Case %d: %ld\n",kase,min);
	}

	return 0;
}

int check(int s){
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) b[i][j]=0;
	cou=0;
	for(int i=0;i<n;i++){
		b[0][i]=1&(s>>i);	//注意位运算是否出错
		if(a[0][i]==1 && b[0][i]==0) return 0;
		if(a[0][i]==0 && b[0][i]==1) cou++;
	}
	for(int i=1;i<n;i++) for(int j=0;j<n;j++){
		int sum=0;
		if(i>1) sum+=b[i-2][j];
		if(j>0) sum+=b[i-1][j-1];
		if(j<n-1) sum+=b[i-1][j+1];
		if(sum%2==1) b[i][j]=1;
		if(a[i][j]==1 && b[i][j]==0) return 0;
		if(a[i][j]==0 && b[i][j]==1) cou++;
	}
	return 1;
}
