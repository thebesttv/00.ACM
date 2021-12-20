#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

const double EPS=1e-6;
class Ind{
public:
	long long SID;
	int CID;
	char name[30];
	int score[4],total;
	int rank;

	void Remove(){
		memset(this,0,sizeof(Ind));
	}
	void Print(){
		printf("--%d %010lld %d %s %d %d %d %d %d\n",
			rank,SID,CID,name,score[0],score[1],score[2],score[3],total);
	}
	void PrintQuery();
	int BlurGet();

	bool operator < (const Ind & b){
		return total>b.total;
	}
}ind[100],ind2[100],t;
class Result{
public:
	int sumScore[4];	//the sum of the score of each subject
	int pass[4]; 		//for each subject, the number of the students who pass
	int passNum[5];		//the number of the students who pass 0,1,2,3,4 subject(s)
	int tot;			//the total number of the stduents

	void Count(int cla);
	void Print();
}result;
char temp[200];
int tail=0;

void PrintMain();
void Add();
void Remove();
void Query();
void ShowRanking();
void ShowStatistics();

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n; PrintMain();
	while(scanf("%d",&n)==1 && n){
		switch(n){
			case 1: Add(); break;
			case 2: Remove(); break;
			case 3: Query(); break;
			case 4: ShowRanking(); break;
			case 5: ShowStatistics();
		}
	}

	return 0;
}

void Add(){
	while(1){
		printf("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		t.Remove(); scanf("%lld",&t.SID);
		if(t.SID==0){
			#ifdef DEBUG
			result.Count(0);
			result.Print();
			#endif
			PrintMain(); return;
		}
		scanf("%d%s%d%d%d%d",&t.CID,t.name,&t.score[0],&t.score[1],&t.score[2],&t.score[3]);
		t.total=t.score[0]+t.score[1]+t.score[2]+t.score[3];
		bool rep=0;
		for(int i=0;i<tail;i++) if(ind[i].SID==t.SID) rep=1;
		if(rep) {printf("Duplicated SID.\n"); continue;}
		ind[tail++]=t;
	}
}

void Remove(){
	while(1){
		int cou=0;
		int type=t.BlurGet();
		if(type==0){
			#ifdef DEBUG
			for(int i=0;i<tail;i++) if(ind[i].SID){
				ind[i].Print();
			}
			#endif
			PrintMain(); return;
		}else if(type==1){
			for(int i=0;i<tail;i++) if(ind[i].SID==t.SID){
				ind[i].Remove(); cou++;
			}
		}else{
			for(int i=0;i<tail;i++) if(!strcmp(t.name,ind[i].name)){
				ind[i].Remove(); cou++;
			}
		}
		printf("%d student(s) removed.\n",cou);
	}
}
void Query(){
	//rank
	for(int i=0;i<tail;i++){
		int rank=1;
		for(int j=0;j<tail;j++){
			if(!ind[j].SID) continue;
			if(ind[i].total<ind[j].total) rank++;
		}
		ind[i].rank=rank;
	}

	while(1){
		int type=t.BlurGet();
		if(type==0){
			PrintMain(); return;
		}else if(type==1){
			for(int i=0;i<tail;i++) if(ind[i].SID==t.SID){
				ind[i].PrintQuery();
			}
		}else{
			for(int i=0;i<tail;i++) if(!strcmp(ind[i].name,t.name)){
				ind[i].PrintQuery();
			}
		}
	}
}
void ShowRanking(){
	printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
	PrintMain();
}
void ShowStatistics(){
	printf("Please enter class ID, 0 for the whole statistics.\n");
	int cla; Result tR; memset(&tR,0,sizeof(tR));
	scanf("%d",&cla);
	tR.Count(cla);
	#ifdef DEBUG
	tR.Print();
	#endif
	for(int i=0;i<4;i++){
		if(i==0) printf("Chinese\n");
		else if(i==1) printf("Mathematics\n");
		else if(i==2) printf("English\n");
		else printf("Programming\n");
		printf("Average Score: %.2lf\n",(double)tR.sumScore[i]/tR.tot+EPS);
		printf("Number of passed students: %d\n",tR.pass[i]);
		printf("Number of failed students: %d\n",tR.tot - tR.pass[i]);
		printf("\n");
	}
	printf("Overall:\n");
	printf("Number of students who passed all subjects: %d\n",tR.passNum[4]);
	printf("Number of students who passed 3 or more subjects: %d\n",tR.passNum[3]+tR.passNum[4]);
	printf("Number of students who passed 2 or more subjects: %d\n",tR.passNum[2]+tR.passNum[3]+tR.passNum[4]);
	printf("Number of students who passed 1 or more subjects: %d\n",
		tR.passNum[1]+tR.passNum[2]+tR.passNum[3]+tR.passNum[4]);
	printf("Number of students who failed all subjects: %d\n",tR.passNum[0]);
	printf("\n");
	PrintMain();
}
void PrintMain(){
	printf("\
Welcome to Student Performance Management System (SPMS).\n\n\
1 - Add\n\
2 - Remove\n\
3 - Query\n\
4 - Show ranking\n\
5 - Show Statistics\n\
0 - Exit\n\n");
}

void Result::Count(int cla=0){
	#ifdef DEBUG
	printf("--in Count(%d)\n",cla);
	#endif
	for(int i=0;i<tail;i++){
		if(ind[i].SID==0) continue;
		if(cla!=0 && ind[i].CID!=cla) continue;
		int passN=0;
		for(int j=0;j<4;j++){
			sumScore[j]+=ind[i].score[j];
			if(ind[i].score[j]>=60){pass[j]++; passN++;}
		}
		passNum[passN]++; tot++;
	}
}
void Result::Print(){
	printf("--sum:\t\t"); for(int i=0;i<4;i++) printf("%d ",sumScore[i]); printf("\n");
	printf("--pass:\t\t"); for(int i=0;i<4;i++) printf("%d ",pass[i]); printf("\n");
	printf("--passNum:\t"); for(int i=0;i<5;i++) printf("%d ",passNum[i]); printf("\n");
	printf("--total:\t"); printf("%d\n",tot);
}
int Ind::BlurGet(){
	printf("Please enter SID or name. Enter 0 to finish.\n");
	this->Remove();
	scanf("%s",temp);
	if(isdigit(temp[0])){
		SID=atoll(temp); if(SID==0) return 0;
		return 1;
	}else{
		strcpy(name,temp); return 2;
	}
}
void Ind::PrintQuery(){
	printf("%d %010lld %d %s %d %d %d %d %d %.2lf\n",
		rank,SID,CID,name,score[0],score[1],score[2],score[3],total,total/4.0 + EPS);
}
