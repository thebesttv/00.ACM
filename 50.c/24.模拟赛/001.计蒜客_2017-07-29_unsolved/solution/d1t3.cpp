#include<bits/stdc++.h>
using namespace std;
int n,m,t,k,h,atk;
int dp[1050][1050][15],mp[1050][1050];
int cal(int x,int y,int at){
	return (h-1)/at*mp[x][y];
}
void dfs(int x,int y,int res,int st,int at,int dam){
	if(st) dam+=cal(x,y,at);
	if(st==k) {dp[x][y][res+1]=min(dp[x][y][res+1],dam);return;}
	if(x+1<=n) dfs(x+1,y,res,st+1,at+mp[x+1][y],dam);
	if(y+1<=m) dfs(x,y+1,res,st+1,at+mp[x][y+1],dam);	 
}
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&t,&k,&h,&atk);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&mp[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int l=0;l<=t;l++)
				dp[i][j][l]=999999999;
	dp[1][1][0]=0;
			for(int l=0;l<=t;l++)
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
				if(i+1<=n)
				dp[i+1][j][l]=min(dp[i+1][j][l],dp[i][j][l]+cal(i+1,j,atk));
				if(j+1<=m)
				dp[i][j+1][l]=min(dp[i][j+1][l],dp[i][j][l]+cal(i,j+1,atk));
				if(l!=t)
				dfs(i,j,l,0,atk,dp[i][j][l]);
			}
//for(int l=0;l<=t;l++){
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			printf("%d%c",dp[i][j][l],j==m?'\n':' ');
//		printf("\n");
//		}
	cout<<dp[n][m][t]<<endl;
}
