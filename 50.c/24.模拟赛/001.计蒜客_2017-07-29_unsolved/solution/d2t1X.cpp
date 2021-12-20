#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long a[11],b[11][11],ls[11],tmp[11][11];
int n;
void pow(int m)
{
	int tot=10;
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=tot;j++)
		tmp[i][j]=b[i][j];
	while(m)
	{
		if(m&1)
		{
			for(int i=1;i<=tot;i++)
				ls[i]=0;
			for(int i=1;i<=tot;i++)
				for(int j=1;j<=tot;j++)
				ls[i]+=(a[j]*b[j][i])%mod,ls[i]%=mod;
			for(int i=1;i<=tot;i++)
				a[i]=ls[i]%mod;
		}
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=tot;j++)
		{
				tmp[i][j]=0;
				for(int k=1;k<=tot;k++)
					tmp[i][j]+=(b[i][k]*b[k][j])%mod,tmp[i][j]%=mod;
			}
		for(int i=1;i<=tot;i++)
			for(int j=1;j<=tot;j++)
			b[i][j]=tmp[i][j]%mod;
		m>>=1;
	}
}
int main(){
	scanf("%d",&n);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
	a[1]=1;
	for(int i=2;i<=10;i++) b[i][1]=1;
	for(int i=1;i<=9;i++) b[i][i+1]=1;
	pow(n);
	long long ans=0;
	for(int i=1;i<=10;i++) ans=(ans+a[i])%mod;
	cout<<ans<<endl; 
}
