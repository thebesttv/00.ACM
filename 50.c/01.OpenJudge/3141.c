/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
不同的武士有不同的特点。
dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。
iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
wolf没特点。
请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。
制造武士需要生命元。
制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：
1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in blue headquarter
表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
如果造出的是dragon，那么还要输出一行，例：
It has a arrow,and it's morale is 23.34
表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
如果造出的是ninjia，那么还要输出一行，例：
It has a bomb and a arrow
表示该ninjia降生时得到了bomb和arrow。
如果造出的是iceman，那么还要输出一行，例：
It has a sword
表示该iceman降生时得到了sword。
如果造出的是lion，那么还要输出一行，例：
It's loyalty is 24
表示该lion降生时的忠诚度是24。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在 10点整，红方司令部停止制造武士

输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数,代表测试数据组数。
每组测试数据共两行。
第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

char weapon[3][6] = {"sword", "bomb", "arrow"};
char name[5][10] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int to[2][5] = {{4,3,0,1,2},{1,2,3,0,4}};
struct Ind{
	char name[10];
	int strength;
	int haveWeapon;
	bool haveMorale, haveLoyalty;
	int cnt;
}red[5],blue[5];
int redStrength, blueStrength;
int redNum, blueNum;
int redNext, blueNext;
bool redStop, blueStop;
int Time=0;

void Init();
void Print(int n, bool isBlue);

int main(void){
	#ifdef LOCAL
	freopen("out","w",stdout);
	#endif
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		Init();
		#ifdef DEBUG
		for(int i=0;i<5;i++) Print(i,0);
		for(int i=0;i<5;i++) Print(i,1);
		#endif
		printf("Case:%d\n",kase+1);
		while(!redStop || !blueStop){
			if(!redStop){
				int cnt=0;
				do {redNext = (redNext+1)%5; cnt++;} while(redStrength - red[redNext].strength < 0 && cnt<6);
				if(cnt<6){
					redStrength -= red[redNext].strength;
					red[redNext].cnt++; redNum++;
					Print(redNext,0);
				}else{
					redStop=1;
					printf("%03d red headquarter stops making warriors\n",Time);
				}
			}
			if(!blueStop){
				int cnt=0;
				do {blueNext = (blueNext+1)%5; cnt++;} while(blueStrength - blue[blueNext].strength < 0 && cnt<6);
				if(cnt<6){
					blueStrength -= blue[blueNext].strength;
					blue[blueNext].cnt++; blueNum++;
					Print(blueNext,1);
				}else{
					blueStop=1;
					printf("%03d blue headquarter stops making warriors\n",Time);
				}
			}
			Time++;
		}
	}

	return 0;
}
void Init(){
	memset(red,0,sizeof(red)); memset(blue,0,sizeof(blue));
	redNum = blueNum= 0;
	redNext = blueNext = -1;	//
	redStop = blueStop = 0;
	Time=0;
	scanf("%d",&redStrength); blueStrength=redStrength;
	for(int i=0;i<5;i++){
		int tS; scanf("%d",&tS);
		Ind &r=red[to[0][i]], &b=blue[to[1][i]];
		strcpy(r.name,name[i]);
		r.strength=tS;
		switch(i){
			case 0: r.haveWeapon=1; r.haveMorale=1; break;
			case 1: r.haveWeapon=2; break;
			case 2: r.haveWeapon=1; break;
			case 3: r.haveLoyalty=1; break;
		}
		b = r;	//<b></b>
	}
}
void Print(int n, bool isBlue){	//type 0: red, 1: blue
	Ind a; int num; double strength; char type[6];
	if(!isBlue){
		num = redNum; strength = (double)redStrength;
		a = red[n]; strcpy(type,"red");
	}else{
		num = blueNum; strength = (double)blueStrength;
		a = blue[n]; strcpy(type,"blue");
	}
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
		Time, type, a.name, num, a.strength, a.cnt, a.name, type);

	if(a.haveWeapon==1 && !a.haveMorale) printf("It has a %s\n",weapon[num%3]);
	else if(a.haveWeapon==1 && a.haveMorale) printf("It has a %s",weapon[num%3]);
	if(a.haveWeapon==2) printf("It has a %s and a %s\n",weapon[num%3],weapon[(num+1)%3]);
	if(a.haveMorale) printf(",and it's morale is %.2lf\n",floor((strength/a.strength)*100+0.5)/100.0);
	if(a.haveLoyalty) printf("It's loyalty is %d\n", (int)strength);
}
