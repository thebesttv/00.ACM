#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class Cube{
public:
	char f[7];

	void routate(int n);
	void print();
}ori,test,t;
char temp[20];
int save[6];
int position[24][6]={{1,2,3,4,5,6},{1,3,5,2,4,6},{1,4,2,5,3,6},{1,5,4,3,2,6},{2,1,4,3,6,5},{2,3,1,6,4,5},{2,4,6,1,3,5},{2,6,3,4,1,5},{3,1,2,5,6,4},{3,2,6,1,5,4},{3,5,1,6,2,4},{3,6,5,2,1,4},{4,1,5,2,6,3},{4,2,1,6,5,3},{4,5,6,1,2,3},{4,6,2,5,1,3},{5,1,3,4,6,2},{5,3,6,1,4,2},{5,4,1,6,3,2},{5,6,4,3,1,2},{6,2,4,3,5,1},{6,3,2,5,4,1},{6,4,5,2,3,1},{6,5,3,4,2,1}};

int main(void){
	while(scanf("%s",temp)==1){
		for(int i=0;i<6;i++) ori.f[i]=temp[i];
		for(int i=6;i<12;i++) test.f[i-6]=temp[i];
		bool flag=0;
		for(int i=0;i<24;i++){
			t=test; t.routate(i);
			if(!strcmp(ori.f,t.f)){
				flag=1; break;
			}
		}
		if(flag) printf("TRUE\n");
		else printf("FALSE\n");
	}

	return 0;
}

void Cube::routate(int n){
	Cube t_=(*this);
	for(int i=0;i<6;i++)
		this->f[i]=t_.f[position[n][i]-1];
}
