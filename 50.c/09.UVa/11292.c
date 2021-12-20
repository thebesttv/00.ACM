#include<stdio.h>
#include<stdlib.h>

#define SWAP(x,y) {int Temp=(x);(x)=(y);(y)=Temp;}

int a[20000],b[20000];

void Sort(int a[], int left, int right);

int main(void){
	int n,m;

	while(scanf("%d%d",&n,&m)==2){
		if(n==0 && m==0) break;
		for(int i=0;i<n;i++) scanf("%d",&a[i]);
		for(int i=0;i<m;i++) scanf("%d",&b[i]);
		Sort(a,0,n-1);
		Sort(b,0,m-1);

		int cur=0,i=0,sum=0;
		while(cur<n && i<m){
			if(b[i++]>=a[cur]){
				sum+=b[i-1];
				cur++;
			}
		}
		if(cur<n) printf("Loowater is doomed!\n");
		else printf("%d\n",sum);
	}

	return 0;
}

void Sort(int a[], int left, int right){
	if(left>=right) return;
	int i=left, j=right, k=a[left];
	while(i!=j){
		while(i<j && a[j]>=k) j--;
		while(i<j && a[i]<=k) i++;
		SWAP(a[j],a[i]);
	}
	SWAP(a[left],a[i]);
	Sort(a,left,i-1);
	Sort(a,i+1,right);
}
