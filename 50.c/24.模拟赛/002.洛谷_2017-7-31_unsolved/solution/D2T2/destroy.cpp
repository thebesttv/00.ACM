#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,k,l,L,R,a[5005][5005],ans;
int main()
{
	freopen("destroy.in","r",stdin);
	freopen("destroy.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--)for(scanf("%d%d%d",&j,&k,&l),L=max(1,j-l),R=min(n,j+l);L<=R;L++)
	{
		i=sqrt(l*l-(L-j)*(L-j));
		a[L][max(1,k-i)]++;
		a[L][min(n,k+i)+1]--;
	}
	for(i=1,ans=n*n;i<=n;i++)for(j=1;j<=n;j++)if((a[i][j]+=a[i][j-1])>0)ans--;
	cout<<ans<<endl;
	return 0;
}

