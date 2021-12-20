#include<bits/stdc++.h>
using namespace std;
int n,m,k,t,sx,sy,tx,ty;
char mp[25][25],s[15][3];
int sp[15],st[15];
int dp[60000][25][25],Pow[15];
int q[24000000][3];
int cal_spd(int x){
	for(int i=1;i<=t;i++) st[i]=0;
	int tmp=0;
	while(x){
		tmp++;st[tmp]=x%3;x/=3;
	}
	int ans=k;
	for(int i=1;i<=t;i++)
	if(st[i]==1) ans+=sp[i];
	if(ans<1) ans=1;
	return ans;
}
int pick(int num,int x,int y){
	for(int i=1;i<=t;i++) st[i]=0;
	int tmp=0;
	while(num){
		tmp++;st[tmp]=num%3;num/=3;
	}
	int nu=0;
	for(int i=1;i<=t;i++) if(s[i][0]==mp[x][y]) nu=i;
	if(st[nu]) return 0;
	st[nu]=1;
	for(int i=t;i>=1;i--){
		num=num*3+st[i];
	}
	return num;
}
int drop1(int x){
	for(int i=1;i<=t;i++) st[i]=0;
	int tmp=0;
	while(x){
		tmp++;st[tmp]=x%3;x/=3;
	}
	for(int i=1;i<=t;i++)
		if(st[i]==1&&sp[i]>0) st[i]=2;
	for(int i=t;i>=1;i--){
		x=x*3+st[i];
	}
	return x;
}
int drop2(int x){
	for(int i=1;i<=t;i++) st[i]=0;
	int tmp=0;
	while(x){
		tmp++;st[tmp]=x%3;x/=3;
	}
	for(int i=1;i<=t;i++)
		if(st[i]==1) st[i]=2;
	for(int i=t;i>=1;i--){
		x=x*3+st[i];
	}
	return x;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%s",mp[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='s') sx=i,sy=j;
			if(mp[i][j]=='t') tx=i,ty=j;
			if(mp[i][j]>='A'&&mp[i][j]<='Z') t++;
		}
//	cout<<t<<endl;
	Pow[0]=1;
	for(int i=1;i<=t;i++)
		Pow[i]=Pow[i-1]*3;
	for(int i=1;i<=t;i++)
		scanf("%s%d",s[i],&sp[i]);
	memset(dp,127,sizeof(dp));
	dp[0][sx][sy]=0;
	q[0][0]=0,q[0][1]=sx,q[0][2]=sy;
	int head=0,tail=0;
//	cout<<cal_spd(3)<<endl;
	while(head<=tail){
		int now=head;head++;
		int nx=q[now][1],ny=q[now][2],nst=q[now][0];
	//	cout<<nst<<' '<<nx<<' '<<ny<<' '<<dp[nst][nx][ny]<<endl;
		int spd=cal_spd(nst);//cout<<spd<<endl;
		if(nx+1<=n&&mp[nx+1][ny]!='#'&&dp[nst][nx+1][ny]>dp[nst][nx][ny]+spd) {
			dp[nst][nx+1][ny]=dp[nst][nx][ny]+spd;
			tail++;
			q[tail][0]=nst,q[tail][1]=nx+1,q[tail][2]=ny;
		}
		if(ny+1<=m&&mp[nx][ny+1]!='#'&&dp[nst][nx][ny+1]>dp[nst][nx][ny]+spd) {
			dp[nst][nx][ny+1]=dp[nst][nx][ny]+spd;
			tail++;
			q[tail][0]=nst,q[tail][1]=nx,q[tail][2]=ny+1;
		}
		if(nx-1>0&&mp[nx-1][ny]!='#'&&dp[nst][nx-1][ny]>dp[nst][nx][ny]+spd) {
			dp[nst][nx-1][ny]=dp[nst][nx][ny]+spd;
			tail++;
			q[tail][0]=nst,q[tail][1]=nx-1,q[tail][2]=ny;
		}
		if(ny-1>0&&mp[nx][ny-1]!='#'&&dp[nst][nx][ny-1]>dp[nst][nx][ny]+spd) {
			dp[nst][nx][ny-1]=dp[nst][nx][ny]+spd;
			tail++;
			q[tail][0]=nst,q[tail][1]=nx,q[tail][2]=ny-1;
		}
		if(mp[nx][ny]>='A'&&mp[nx][ny]<='Z'){
			int nxst=pick(nst,nx,ny);
			if(nxst&&dp[nxst][nx][ny]>dp[nst][nx][ny]){
			dp[nxst][nx][ny]=dp[nst][nx][ny];
			tail++;
			q[tail][0]=nxst,q[tail][1]=nx,q[tail][2]=ny;
		}
		}
		if(mp[nx][ny]=='t') {
			int nxst1=drop1(nst),nxst2=drop2(nst);
			if(dp[nxst1][nx][ny]>dp[nst][nx][ny]){
			dp[nxst1][nx][ny]=dp[nst][nx][ny];
			tail++;
			q[tail][0]=nxst1,q[tail][1]=nx,q[tail][2]=ny;
		}
		if(dp[nxst2][nx][ny]>dp[nst][nx][ny]){
			dp[nxst2][nx][ny]=dp[nst][nx][ny];
			tail++;
			q[tail][0]=nxst2,q[tail][1]=nx,q[tail][2]=ny;
		}
		}
	}
//	cout<<head<<' '<<tail<<endl;
	printf("%d\n",dp[Pow[t]-1][tx][ty]);
}
