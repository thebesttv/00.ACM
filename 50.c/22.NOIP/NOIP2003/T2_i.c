/*
描述
明明同学最近迷上了侦探漫画《柯南》并沉醉于推理游戏之中，于是他召集了一群同学玩推理游戏。游戏的内容是这样的，明明的同学们先商量好由其中的一个人充当罪犯（在明明不知情的情况下），明明的任务就是找出这个罪犯。接着，明明逐个询问每一个同学，被询问者可能会说：

证词内容  证词含义
I am guilty.  我是罪犯
I am not guilty.  我不是罪犯
xxx is guilty.  xxx 是罪犯（xxx 表示某个同学的名字）
xxx is not guilty.  xxx 不是罪犯
Today is xxx.   今天是 xxx （xxx表示星期几，是Monday Tuesday Wednesday Thursday Friday Saturday Sunday 其中之一）

证词中出现的其他话，都不列入逻辑推理的内容。
明明所知道的是，他的同学中有N个人始终说假话，其余的人始终说真。
现在，明明需要你帮助他从他同学的话中推断出谁是真正的凶手，请记住，凶手只有一个！

格式
输入格式
输入由若干行组成，第一行有二个整数，M（1≤M≤20）、N（0≤N≤M）和P（1≤P≤100）；M是参加游戏的明明的同学数，N是其中始终说谎的人数，P是证言的总数。接下来M行，每行是明明的一个同学的名字（英文字母组成，没有主格，全部大写）。往后有P行，每行开始是某个同学的名宇，紧跟着一个冒号和一个空格，后面是一句证词，符合前表中所列格式。证词每行不会超过250个字符。
输入中不会出现连续的两个空格，而且每行开头和结尾也没有空格。

输出格式
如果你的程序能确定谁是罪犯，则输出他的名字；如果程序判断出不止一个人可能是罪犯，则输出 Cannot Determine；如果程序判断出没有人可能成为罪犯，则输出 Impossible。

样例1
样例输入1
3 1 5
MIKE
CHARLES
KATE
MIKE: I am guilty.
MIKE: Today is Sunday.
CHARLES: MIKE is guilty.
KATE: I am guilty.
KATE: How are you??

样例输出1
MIKE

限制
每个测试点1s

来源
NOIP2003第二题
*/

/*
  得分：50
  解题报告：
    因为凶手只有一个，枚举凶手和日期，进行判断。若只有一个符合要求，直接输出姓名，若有多个符合要求，则 Cannot Determin，若无符合要求，则impossible。
  错误原因：
 <b>1.在判断一组关于罪犯i的枚举中，当枚举正确时没有及时退出到下一个人的枚举，失去40+10分。</b>
    2.人名数组开太小，失去10分。（详情见吐槽[1]的测试点10）

  吐槽（源自网络）：
  [1]
    数据。。我感到了深深的无奈。
    * 测试点#1：有一位同志，名字叫做“GUILTY”。如果你事先把证词的大小写变化了，那么就完了。
    * 测试点#2：有一位诚实的同志，既承认自己有罪，又承认自己无罪。
    * 测试点#4：有七位同志，名字分别是“MONDAY”、……、“SUNDAY”。
    * 测试点#7：“I am not guity.”！按照约定，这句话作废（guilty 缺一个字母）。
    * 测试点#8：“SUE is guity.”！同样要作废。
    * 测试点#9：“I is not guilty.”，I 是人名。
    * 测试点#10：有一个人的名字长达 204 个字符，翻译成汉语，竟然是一段话：曾经有一段真挚的感情放在在我面前，我没有珍惜。等到失去了以后，才追悔莫及。人世间最痛苦的事莫过于此。如果上天能给我一个再来一次的机会，我会对那个女孩子说三个字……
    （接下来这个人说了三句话：“I love you!”、“If there must be a deadline,”、“I hope it is 10000 years!!!”。按照约定，这三句话都要作废。所以，实际上他一句话也没有说。）

  [2]
    【我走的最长的路就是你的套路】

  [3]

  数据（供观赏）：  //没有想到CCF也能这么不正经 XD
  [1]
    2 2 4
    HELLO
    GUILTY
    HELLO: What is your name?
    GUILTY: I am GUILTY.      //这人恐怕一辈子都得背黑锅了吧
    GUILTY: Are you guilty?   //GUILTY: I hope we have the same name...
    HELLO: I am not guilty.

  [2]
    1 0 2
    A
    A: I am guilty.
    A: I am not guilty.   //幸亏我判bt了。。。

  [3] //平凡的数据
    5 1 5
    A
    B
    C
    D
    E
    A: Today is Monday.
    B: Today is Thursday.
    C: Today is Monday.
    B: D is not guilty.
    E: I am not guilty.

  [4] //来自星期家族
    7 3 10
    MONDAY
    TUESDAY
    WEDNESDAY
    THURSDAY
    FRIDAY
    SATURDAY
    SUNDAY
    MONDAY: Today is Monday.
    TUESDAY: Today is Tuesday.
    WEDNESDAY: Today is Wednesday.
    THURSDAY: Today is Thursday.
    FRIDAY: MONDAY is not guilty.
    FRIDAY: TUESDAY is not guilty.
    FRIDAY: WEDNESDAY is not guilty.
    FRIDAY: THURSDAY is not guilty.
    SATURDAY: SUNDAY is not guilty.
    SUNDAY: SATURDAY is not guilty.

  [5] //无聊。。。
    4 1 5
    KYO
    IORI
    CHIZURU
    OROCHI
    KYO: I am guilty.
    IORI: I am not guilty.
    CHIZURU: OROCHI is guilty.
    OROCHI: Today is Monday.
    OROCHI: I am guilty.

  [6] //人肉方阵hh
    10 7 20
    A
    AA
    AAA
    AAAA
    AAAAA
    AAAAAA
    AAAAAAA
    AAAAAAAA
    AAAAAAAAA
    AAAAAAAAAA
    A: Today is Monday.
    AA: Today is Monday.
    AAA: Today is Monday.
    AAAA: Today is Monday.
    AAAAA: Today is Monday.
    AAAAAA: Today is Monday.
    AAAAAAA: Today is Monday.
    AAAAAAAA: Today is Sunday.
    AAAAAAAAA: Today is Sunday.
    AAAAAAAAAA: Today is Sunday.
    AAAAAAAAAA: AAA is not guilty.
    AAAAAAAAA: A is not guilty.
    AAAAAAAA: AAAAA is not guilty.
    AAAAAAA: AAAAAA is guilty.
    AAAAAA: AAAAAAAAAA is guilty.
    AAAAA: AAAAAAAA is guilty.
    AAAA: AAAAAAA is guilty.
    AAA: AA is guilty.
    AA: AAAAAAAAA is guilty.
    A: AAAAA is guilty.

  [7]
    1 1 2
    ALAN
    ALAN: I am not guity. //去你的
    ALAN: I am not not guity. //土你白

  [8]
    3 3 3
    SAM
    SANDY
    SUE
    SAM: I am not guity. Am I???  //Oh, I wish you were. （我是怎么通过这组数据的???）
    SUE: SANDY is guity.
    SANDY: SUE is guity.

  [9]
    10 10 10
    A
    B
    C
    D
    E
    F
    G
    H
    I
    J
    A: B is guilty.
    B: C is guilty.
    C: D is guilty.
    D: E is guilty.
    E: F is guilty.
    F: G is guilty.
    G: H is guilty.
    H: I love you!  //。。。
    I: I am not guilty.
    J: I is not guilty. //题目描述：“没有主格”，恩，就是这样。。。
  [10]  //Lanerd: I don't know what to say~
    1 0 3
    CENGJINGYOUYIDUANZHENZHIDEGANQINGFANGZAIWOMIANQIANWOMEIYOUZHENXIDENGDAOSHIQULEYIHOUCAIZHUIHUIMOJIRENSHIJIANZUITONGKUDESHIMOGUOYUCIRUGUOSHANGTIANNENGGEIWOYIGEZAILAIYICIDEJIHUIWOHUIDUINAGENVHAIZISHUOSANGEZI
    CENGJINGYOUYIDUANZHENZHIDEGANQINGFANGZAIWOMIANQIANWOMEIYOUZHENXIDENGDAOSHIQULEYIHOUCAIZHUIHUIMOJIRENSHIJIANZUITONGKUDESHIMOGUOYUCIRUGUOSHANGTIANNENGGEIWOYIGEZAILAIYICIDEJIHUIWOHUIDUINAGENVHAIZISHUOSANGEZI: I love you!
    CENGJINGYOUYIDUANZHENZHIDEGANQINGFANGZAIWOMIANQIANWOMEIYOUZHENXIDENGDAOSHIQULEYIHOUCAIZHUIHUIMOJIRENSHIJIANZUITONGKUDESHIMOGUOYUCIRUGUOSHANGTIANNENGGEIWOYIGEZAILAIYICIDEJIHUIWOHUIDUINAGENVHAIZISHUOSANGEZI: If there must be a deadline,
    CENGJINGYOUYIDUANZHENZHIDEGANQINGFANGZAIWOMIANQIANWOMEIYOUZHENXIDENGDAOSHIQULEYIHOUCAIZHUIHUIMOJIRENSHIJIANZUITONGKUDESHIMOGUOYUCIRUGUOSHANGTIANNENGGEIWOYIGEZAILAIYICIDEJIHUIWOHUIDUINAGENVHAIZISHUOSANGEZI: I hope it is 10000 years!!!
    //人名翻译（配标点符号）：
    //曾经有一段真挚的感情放在我面前，我没有珍惜。等到失去了以后才追悔莫及。人世间罪痛苦的事莫过于此。如果上天能给我一个再来一次的机会，我会对那个女孩子说三个字：
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=22;
struct Ind{
  bool isTrue,isFalse;      //枚举时的记录
  bool saidGuilty,isGuilty; //是否说自己有/无罪
  bool saidTaGuilty;        //是否说别人有/无罪
  int guilty[MAX];          //guilty[i]: 1:i有罪, 0:i无罪, -1:没有提到i
  int today;                //-1:没说, 0:6: 说了（注：不能判bt）

  Ind(){
    memset(guilty,-1,sizeof(guilty)); today=-1;
  }
}ind[MAX];
int n,lier; //lier:说谎人个数
char temp[300];
char name[MAX][300];
bool bt=0;  //判断bt输入，即：又说自己无罪又说自己有罪，又说他人无罪又说他人有罪之类，不符合“一直说谎”或“一直说真话”

int getNum(char * str);
int getDay(char * str);
void init(char * str);
bool check(int guilty, int today);

int main(void){
  int tot; fgets(temp,sizeof(temp),stdin);
  char * p=strtok(temp," \n\r"); n=atoi(p);
  p=strtok(NULL," \n\r"); lier=atoi(p);
  p=strtok(NULL," \n\r"); tot=atoi(p);
  for(int i=0;i<n;i++){ //读入人名
    fgets(temp,sizeof(temp),stdin); char * p=strtok(temp," \n\r");
    strcpy(name[i],temp);
  }
#ifdef DEBUG
  printf("  get n: %d, lier: %d, tot: %d\n",n,lier,tot);
  for(int i=0;i<n;i++) printf("    %s\n",name[i]);
#endif
  for(int i=0;i<tot;i++){fgets(temp,sizeof(temp),stdin); init(temp);} //读入证言并初始化
#ifdef DEBUG
  printf("  init successfully\n");
#endif

  if(bt) printf("Impossible\n");  //bt输入
  else{
    int isRight=0;  //枚举对的次数
    int taNum;      //最后一次正确枚举的有罪的人
    //char taName[300]; memset(taName,0,sizeof(taName));
    for(int ta=0;ta<n;ta++) for(int today=0;today<7;today++){ //ta: 有罪的人, today: 今天星期几
      for(int i=0;i<n;i++) ind[i].isTrue=ind[i].isFalse=0;
      if(check(ta,today)){
#ifdef DEBUG
        printf("  true in guilty: %d, today: %d\n",ta, today);
#endif
        isRight++; taNum=ta;
        break;  //<b><b>枚举正确后一定要退出，否则一个人可能被记录多次</b></b>（4/5个点的数据的错误原因都是这个。。。）
      }
    }

    if(isRight==1) printf("%s\n",name[taNum]);
    else if(isRight>1) printf("Cannot Determine\n");
    else printf("Impossible\n");
  }
  return 0;
}

/*
   bool isTrue,isFalse;
   bool saidGuilty,isGuilty;
   bool saidTaGuilty;
   int guilty[MAX];
   int today;
 */
bool check(int guilty, int today){
  for(int i=0;i<n;i++){
    Ind & ta=ind[i];

    if(ta.saidGuilty){  //说自己有/无罪
      if(ta.isGuilty && guilty!=i) ta.isFalse=true;
      else if(!ta.isGuilty && guilty==i) ta.isFalse=true;
      else ta.isTrue=true;
    }

    if(ta.saidTaGuilty) for(int j=0;j<n;j++){  //说别人有/无罪
      if(ta.guilty[j]==0){
        if(guilty==j){  //假话
          if(ta.isTrue) return false;
          else ta.isFalse=true;
        }else{  //真话
          if(ta.isFalse) return false;
          else ta.isTrue=true;
        }
      }else if(ta.guilty[j]==1){
        if(guilty!=j){ //假话
          if(ta.isTrue) return false;
          else ta.isFalse=true;
        }else{  //真话
          if(ta.isFalse) return false;
          else ta.isTrue=true;
        }
      }
    }
    if(ta.today!=-1){ //说星期
      if(ta.today!=today){  //假话
        if(ta.isTrue) return false;
        else ta.isFalse=true;
      }else{  //真话
        if(ta.isFalse) return false;
        else ta.isTrue=true;
      }
    }
  }
#ifdef DEBUG
  for(int i=0;i<n;i++) printf("    %s: isTrue: %d, isFalse: %d\n",name[i],ind[i].isTrue,ind[i].isFalse);
#endif

  int cntT=0,cntF=0;  //记录说真话和说假话的人数
  for(int i=0;i<n;i++)
    if(ind[i].isTrue) cntT++;
    else if(ind[i].isFalse) cntF++;
  if(cntF>lier || cntT>(n-lier)) return false;  //<b>只有人数超过才算错</b>
  return true;
}
int getNum(char * str){
  for(int i=0;i<n;i++) if(!strcmp(name[i],str)) return i;
  return -1;
}
int getDay(char * str){
  int today=-1;
  if(!strcmp(str,"Monday")) today=0;
  else if(!strcmp(str,"Tuesday")) today=1;
  else if(!strcmp(str,"Wednesday")) today=2;
  else if(!strcmp(str,"Thursday")) today=3;
  else if(!strcmp(str,"Friday")) today=4;
  else if(!strcmp(str,"Saturday")) today=5;
  else if(!strcmp(str,"Sunday")) today=6;
  return today;
}
void init(char * str){
  char temp[300];
  int pos,len=strlen(str);
  for(pos=0;pos<len;pos++) if(str[pos]==':') break; pos+=2; strcpy(temp,str+pos);
  char * p=strtok(str," :\n\r.");
  for(int i=strlen(temp)-1;i>=0;i--)
    if(temp[i]=='\n' || temp[i]=='\r') temp[i]=0;
    else break;
  int num=getNum(p);
#ifdef DEBUG
  printf("  init: %s\n",temp);
  printf("    speaker: %s, num: %d\n",p,num);
#endif
  if(!strcmp(temp,"I am guilty.")){
    if(ind[num].saidGuilty && !ind[num].isGuilty) {bt=1; return;} //bt
    ind[num].saidGuilty=ind[num].isGuilty=true;
  }else if(!strcmp(temp,"I am not guilty.")){
    if(ind[num].saidGuilty && ind[num].isGuilty) {bt=1; return;} //bt
    ind[num].saidGuilty=true; ind[num].isGuilty=false;
  }else if(strstr(temp,"is") && strstr(temp,"guilty.")){
    bool isGuilty = strstr(temp,"not")==NULL;
    p=strtok(NULL," :\n\r."); int ta=getNum(p);
    if(ind[num].saidTaGuilty && ind[num].guilty[ta]!=-1 && ind[num].guilty[ta]!=isGuilty) {bt=1; return;} //bt
    ind[num].saidTaGuilty=true; ind[num].guilty[ta]=isGuilty;
  }else if(strstr(temp,"Today is")){  //不能判bt
    strtok(NULL," :\n\r."); strtok(NULL," :\n\r.");
    p=strtok(NULL," :\n\r.");
    int today=getDay(p);
    ind[num].today=today;
  }
}
