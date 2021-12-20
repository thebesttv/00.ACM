/*
描述
为了迎接08年的奥运会，让大家更加了解各种格斗运动，facer新开了一家冷血格斗场。格斗场实行会员制，但是新来的会员不需要交入会费，而只要同一名老会员打一场表演赛，证明自己的实力。

我们假设格斗的实力可以用一个正整数表示，称为实力值，两人的实力值可以相同。另外，每个人都有一个唯一的id，也是一个正整数。为了使得比赛更好看，每一个新队员都会选择与他实力最为接近的人比赛，即比赛双方的实力值之差的绝对值越小越好，如果有多个人的实力值与他差别相同，则他会选择id最小的那个。

不幸的是，Facer一不小心把比赛记录弄丢了，但是他还保留着会员的注册记录。现在请你帮facer恢复比赛纪录，按照时间顺序依次输出每场比赛双方的id。

输入
第一行一个数n(0 < n <=100000)，表示格斗场新来的会员数（不包括facer）。以后n行每一行两个数，按照入会的时间给出会员的id和实力值。一开始，facer就算是会员，id为1，实力值1000000000。

输出
N行，每行两个数，为每场比赛双方的id，新手的id写在前面。
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

multimap<int,int> mp;

int Find(multimap<int,int>::iterator p, int pos);

int main(void){
//freopen("in","r",stdin);
//freopen("out","w",stdout);
	int n,minId;
	multimap<int,int>::iterator p,minp,maxp;
	mp.insert(make_pair(1000000000,1));
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int tid,tpow;
		scanf("%d%d",&tid,&tpow);
		p=mp.insert(make_pair(tpow,tid));
		//计算minp，maxp
		if(p==mp.begin()){minp=maxp=++p; p--;}
		else if(p==mp.end()){maxp=minp=--p; p++;}
		else {minp=--p; p++; maxp=++p; p--;}
		mp.erase(p);	//防止“当前选手打自己”
//printf("minp[%d]: %d, maxp[%d]: %d\n",minp->second,minp->first,maxp->second,maxp->first);
		//选择pow差值最小的计算minId，差值相等时都计算
		if(abs(minp->first-tpow) < abs(maxp->first-tpow)) minId=Find(minp,0);
		else if(abs(minp->first-tpow) > abs(maxp->first-tpow)) minId=Find(maxp,1);
		else minId=min(Find(minp,0),Find(maxp,1));
		printf("%d %d\n",tid,minId);
		p=mp.insert(make_pair(tpow,tid));
	}
	return 0;
}

int Find(multimap<int,int>::iterator p, int pos){
	int minId=p->second,pow=p->first;
	multimap<int,int>::iterator ans=p;
	if(p==mp.begin()){
		for(;p!=mp.end() && p->first==pow;p++)
			if(p->second<minId){ans=p; minId=p->second;}
	}else if(p==mp.end()){
		for(;p!=mp.begin() && p->first==pow;p--)
			if(p->second<minId){ans=p; minId=p->second;}
		if(p==mp.begin() && p->first==pow && p->second<minId)
			{ans=p; minId=p->second;}
	}else if(pos==0){
		for(;p!=mp.begin() && p->first==pow;p--)
			if(p->second<minId){ans=p; minId=p->second;}
		if(p==mp.begin() && p->first==pow && p->second<minId){ans=p; minId=p->second;}
	}else if(pos==1){
		for(;p!=mp.end() && p->first==pow;p++)
			if(p->second<minId){ans=p; minId=p->second;}
	}
	return minId;
}
