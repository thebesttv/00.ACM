#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[2050][2050],b[4050][4050],s[4050][4050],vis[4050][4050];
int main(){
	scanf("%d%d%d",&n,&k);m=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	int l=n+n-1,ll=2*l-1;
	for(int i=1;i<=ll;i++){
		if(i>=n&&(i-n)%2==0){
			int num=(i-n)/2+1;
			//if(i==9) cout<<num<<endl;
			for(int j=num;j<=num+n-1;j++)
				b[j][i+1-j]=a[j-num+1][num],vis[j][i+1-j]=1;
		}
	}
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			s[i][j]=b[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	int ans=0;
	for(int i=1;i<=l;i++)
		for(int j=1;j<=l;j++)
			if(vis[i][j]){
				int zsx=max(1,i-k+1),zsy=max(1,j-k+1),zxx=min(l,i+k-1),zxy=max(1,j-k+1);
				int ysx=max(1,i-k+1),ysy=min(l,j+k-1),yxx=min(l,i+k-1),yxy=min(l,j+k-1);
				ans=max(ans,s[yxx][yxy]-s[ysx-1][yxy]-s[zxx][zxy-1]+s[zsx-1][zsy-1]);
		}
	printf("%d\n",ans);
}
