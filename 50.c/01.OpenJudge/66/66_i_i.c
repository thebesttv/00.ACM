/*
描述
仙境的居民们决定举办一场程序设计区域赛。裁判委员会完全由自愿组成，他们承诺要组织一次史上最公正的比赛。他们决定将选手的电脑用星形拓扑结构连接在一起，即将它们全部连到一个单一的中心服务器。为了组织这个完全公正的比赛，裁判委员会主席提出要将所有选手的电脑等距离地围绕在服务器周围放置。
为购买网线，裁判委员会联系了当地的一个网络解决方案提供商，要求能够提供一定数量的等长网线。裁判委员会希望网线越长越好，这样选手们之间的距离可以尽可能远一些。
该公司的网线主管承接了这个任务。他知道库存中每条网线的长度（精确到厘米），并且只要告诉他所需的网线长度（精确到厘米），他都能够完成对网线的切割工作。但是，这次，所需的网线长度并不知道，这让网线主管不知所措。
你需要编写一个程序，帮助网线主管确定一个最长的网线长度，并且按此长度对库存中的网线进行切割，能够得到指定数量的网线。

输入
第一行包含两个整数N和K，以单个空格隔开。N（1 <= N <= 10000）是库存中的网线数，K（1 <= K <= 10000）是需要的网线数量。
接下来N行，每行一个数，为库存中每条网线的长度（单位：米）。所有网线的长度至少1m，至多100km。输入中的所有长度都精确到厘米，即保留到小数点后两位。

输出
网线主管能够从库存的网线中切出指定数量的网线的最长长度（单位：米）。必须精确到厘米，即保留到小数点后两位。
若无法得到长度至少为1cm的指定数量的网线，则必须输出“0.00”（不包含引号）。
*/

//实数二分（参照网络）
//unsolved
/*
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const double EPS=1e-3;
double a[10000];
int n,k;

bool Check(double l){
	int sum=0;
	l=floor(l*100)/100;
	for(int i=0;i<n;i++)
		sum+=floor(a[i]/l);
//printf("  %lf: sum: %d\n",l,sum);
	return sum>=k;
}

int main(void){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%lf",&a[i]);
	sort(a,a+n);
	double L=0.0,R=a[n-1],M;
	while(R-L>EPS){
		M=L+(R-L)/2;
		if(Check(M))
			L=M;
		else
			R=M;
	}
	if(!Check(L)) L=0.0;
	printf("%.2lf\n",floor(L*100)/100);

	return 0;
}
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[10000],n,k;

bool Check(int len);

int main(void){
	scanf("%d%d",&n,&k);
	double t; int maxL=0;
	for(int i=0;i<n;i++){
		scanf("%lf",&t);
		a[i]=(int)(t*100);	//将长度乘100，变为整数
		maxL=max(maxL,a[i]);
	}
	sort(a,a+n);
	int L=1,R=maxL+1,flag=0;

	while(L+1<R){	//???
		int M=L+(R-L)/2;
//printf("%d %d %d\n",L,R,M);
		if(Check(M)) {L=M; flag=1;}
		else R=M;
	}	//为什么？
	if(flag==0) L=0;
	printf("%.2lf\n",(double)L/100);

	return 0;
}

bool Check(int len){
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=a[i]/len;
	return sum>=k;
}

/*
//网络
	int L=1,R=maxL+1,flag=0;
	while(L+1<R){	//???
		int M=L+(R-L)/2;
//printf("%d %d %d\n",L,R,M);
		if(Check(M)) {L=M; flag=1;}
		else R=M;
	}	//为什么？
	if(flag==0) L=0;
	printf("%.2lf\n",(double)L/100);
*/

/*
//网络答案
//实数二分
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

int k,n;
double l[10005];

bool C(double x){
	int num=0;
	for(int i=1;i<=n;i++)
		num+=(int)(l[i]/x);
	return num>=k;
}

int main(){
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> l[i];
	double lb=0,ub=0x7fffffff;
	for(int i=1;i<=100;i++){
		double mid=(lb+ub)/2;
		if(C(mid)) lb=mid;
		else ub=mid;
	}
	printf("%.2f\n",floor(ub*100)/100);
	return 0;
}
*/
