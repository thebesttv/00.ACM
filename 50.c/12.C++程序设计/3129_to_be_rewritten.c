/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
红司令部，City 1，City 2，……，City n，蓝司令部
两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。
双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。
武士在刚降生的时候有一个生命值。
在每个整点，双方的司令部中各有一个武士降生。
红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。
制造武士需要生命元。
制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。
如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
一共有两种事件，其对应的输出样例如下：
1) 武士降生
输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
2) 司令部停止制造武士
输出样例： 010 red headquarter stops making warriors
表示在10点整，红方司令部停止制造武士

输出事件时：
首先按时间顺序输出；
同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。
每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。
第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。
接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class Ind{
public:
	char name[16];
	int life, cou, num;
	static int rNum, bNum;

	void born(int type){
		cou++;
		if(!type) rNum++;
		else bNum++;
	}
	void print(int time, int type){
		if(!type) printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n",
			time, name, rNum, life, cou, name);
		else printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n",
			time, name, bNum, life, cou, name);
	}
}r[6],b[6];
int Ind::rNum, Ind::bNum;
int match[2][5] = {{5,4,1,2,3}, {2,3,4,1,5}};
char name[5][16] = {"dragon", "ninja", "iceman", "lion", "wolf"};

int main(void){
	#ifdef LOCAL
	freopen("out","w",stdout);
	#endif
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		memset(r,0,sizeof(r)); memset(b,0,sizeof(b)); Ind::rNum = Ind::bNum = 0;
		int m,t; scanf("%d",&m);
		for(int i=0;i<5;i++){
			scanf("%d",&t);
			int red = match[0][i];
			int blue = match[1][i];
			strcpy(r[red].name, name[i]); r[red].life=t; r[red].cou=0; r[red].num=red;
			strcpy(b[blue].name, name[i]); b[blue].life=t; b[blue].cou=0; b[blue].num=blue;
		}
		#ifdef DEBUG
		printf("  ");
		for(int i=0;i<5;i++) printf("%d ",match[0][i]); printf("\n");
		printf("  ");
		for(int i=0;i<5;i++) printf("%d ",match[1][i]); printf("\n");
		printf("  red:\n");
		for(int i=1;i<=5;i++){
			printf("    "); r[i].print(-1,0);
		}
		printf("  blue:\n");
		for(int i=1;i<=5;i++){
			printf("    "); b[i].print(-1,1);
		}
		#endif
		bool rStop=0, bStop=0;
		int rLife=m, bLife=m;
		int rNext=-1, bNext=-1;
		printf("Case:%d\n",kase+1);
		#ifdef DEBUG
		printf("  red: %d\n",rLife);
		printf("  blue: %d\n",bLife);
		#endif
		for(int i=0;;i++){
			if(rStop && bStop) break;
			if(!rStop){
				int cou=0;
				do {rNext = (rNext+1)%5; cou++;} while(rLife - r[rNext+1].life < 0 && cou<6);	//cou的判断
				if(cou==6){																		//
					rStop=1;
					printf("%03d red headquarter stops making warriors\n",i);
				}else{
					r[rNext+1].born(0); rLife -= r[rNext+1].life;
					r[rNext+1].print(i,0);
					#ifdef DEBUG
					printf("  red: %d\n",rLife);
					#endif
				}
			}if(!bStop){
				int cou=0;
				do {bNext = (bNext+1)%5; cou++;} while(bLife - b[bNext+1].life < 0 && cou<6);
				if(cou==6){
					bStop=1;
					printf("%03d blue headquarter stops making warriors\n",i);
				}else{
					b[bNext+1].born(1); bLife -= b[bNext+1].life;
					b[bNext+1].print(i,1);
					#ifdef DEBUG
					printf("  blue: %d\n",bLife);
					#endif
				}
			}
		}
	}

	return 0;
}
