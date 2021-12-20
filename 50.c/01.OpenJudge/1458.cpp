/*
描述
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).

His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

输入
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi

输出
* Line 1: One integer: the largest minimum distance
*/
//排序太慢
#include<iostream>
#include<cstdio>

long n,c;
long a[100000];

long Cow(register long dis);
void Sort(long a[],register  long left,register  long right);

int main(){
freopen("in.txt","r",stdin);
	register long sum=0,last=0;
	long t;
	scanf("%ld%ld",&n,&c);
	for(register int i=0;i<n;i++){
		scanf("%ld",&t);
		a[i]=t;
	}
//	if(a[0]==1)
		Sort(a,0,n-1);

	register long L=a[0], R=a[n-1]/(c-1);
	while(L<=R){
		register long M=L+(R-L)/2;
//printf("  %ld %ld %ld\n",L,R,Cow(M));
		if(Cow(M)>=c) {last=L;L=(M>L ? M : M+1);}
		else R=(M<R ? M : M-1);
	}
	printf("%ld\n",last);

	return 0;
}

long Cow(register long dis){
	register long cou=1;
	for(register long i=1;i<n;i++){
		register long tot=a[i]-a[i-1];
		if(tot<dis)
			for(register int j=i+1;j<n;j++){
				tot+=a[j]-a[j-1]; i=j;
				if(tot>=dis) break;
			}
		if(tot>=dis) cou++;
	}
	return cou;
}

void Sort(long a[],register  long left,register  long right){
	if(left>=right) return;
	register long i=left,j=right,k=a[left];
	while(i!=j){
		while(i<j && a[j]>=k) j--;
		while(i<j && a[i]<=k) i++;
		register long t=a[j]; a[j]=a[i]; a[i]=t;
	}
	register long t=a[left]; a[left]=a[i]; a[i]=t;
	Sort(a,left,i-1);
	Sort(a,i+1,right);
}

/*
//改进版 自然快排(效果未必会好)
void Sort(long a[],register  long left,register  long right){
	if(left>=right) return;
	register long i=left,j=right,u;
	switch(right%3){
		case 0: u=left; break;
		case 1: u=left+(right-left)/2; break;
		case 2: u=right; break;
	}
	register long t=a[u]; a[u]=a[left]; a[left]=t;
	register long k=a[left];
	while(i!=j){
		while(i<j && a[j]>=k) j--;
		while(i<j && a[i]<=k) i++;
		t=a[j]; a[j]=a[i]; a[i]=t;
	}
	t=a[left]; a[left]=a[i]; a[i]=t;
	Sort(a,left,i-1);
	Sort(a,i+1,right);
}
*/
