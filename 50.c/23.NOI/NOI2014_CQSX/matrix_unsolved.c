#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long int LL;
LL a[44];
int n,m;

int get(int x, int y, int type);
bool check();
inline bool getBit(LL n, int i);
inline void setBit(LL & n, int i, bool a);

int main(void){
	scanf("%d%d",&m,&n);
	bool reversed=0, flag=0; if(m<n) {reversed=1; swap(m,n);}
	for(a[0]=1;a[0]<(1<<n);a[0]++) if(check()){
		flag=1; break;
	}
	#ifdef DEBUG
	if(!flag) {printf("No answer\n"); return 0;}
	#endif
	if(!reversed){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(j) printf(" ");
				printf("%d",getBit(a[i],j));
			}
			printf("\n");
		}
		#ifdef DEBUG
		for(int i=0;i<m;i++) for(int j=0;j<n;j++)
			if(get(i,j,1)%2) printf("wrong in (%d,%d)\n",i,j);
		#endif
	}else{
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(j) printf(" ");
				printf("%d",getBit(a[j],i));
			}
			printf("\n");
			#ifdef DEBUG
			for(int i=0;i<n;i++) for(int j=0;j<m;j++)
				if(get(j,i,1)%2) printf("wrong in (%d,%d)\n",j,i);
			#endif
		}
	}

	return 0;
}

int get(int x, int y, int type){
	int sum=0;
	if(x>0) sum+=getBit(a[x-1],y);
	if(type && x<m-1) sum+=getBit(a[x+1],y);
	sum+=getBit(a[x],y);
	if(y>0) sum+=getBit(a[x],y-1);
	if(y<n-1) sum+=getBit(a[x],y+1);
	return sum;
}
bool check(){
	for(int i=0;i<m-1;i++) for(int j=0;j<n;j++){
		setBit(a[i+1],j,get(i,j,0)%2);
	}
	for(int j=0;j<n;j++){
		int cou=0;
		if(j>0) cou+=getBit(a[m-1],j-1);
		if(j<n-1) cou+=getBit(a[m-1],j+1);
		cou+=getBit(a[m-2],j);
		cou+=getBit(a[m-1],j);
		if(cou%2) return false;
	}
	return true;
}
inline bool getBit(LL n, int i){
	return (n>>i)&1;
}
inline void setBit(LL & n, int i, bool a){
	if(a){
		n|=1<<i;
	}else{
		n&=~(1<<i);
	}
}
