#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int a[1000000],c[1000000];

void Sort(int a[], int left, int right);

int main(void){
	int n,m;
	while(scanf("%d",&n)==1){
		unsigned long sum=0,ans=0;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		m=sum/n;

		c[0]=0;sum=0;
		for(int i=1;i<n;i++){
			sum+=a[i];
			c[i]=sum-i*m;
		}
		Sort(c,1,n-1);
		int x=c[n/2];
		for(int i=0;i<n;i++) ans+=abs(x-c[i]);
		printf("%ld\n",ans);
	}
	return 0;
}

void Sort(int a[], int left, int right){
	if(left>=right) return;
	int i=left, j=right, k=a[left];
	while(i!=j){
		while(i<j && a[j]>=k) j--;
		while(i<j && a[i]<=k) i++;
		int t=a[i];a[i]=a[j];a[j]=t;
	}
	int t=a[i];a[i]=a[left];a[left]=t;
	Sort(a,left,i-1);
	Sort(a,i+1,right);
}
