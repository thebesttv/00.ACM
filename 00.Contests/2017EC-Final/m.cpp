#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define scan(x) scanf("%d",&x)
int main(){
  int  t;
	scan(t);
	for(int i1=1;i1<=t;i1++){
		int a[6];
		for(int i=1;i<=5;i++){
		scan(a[i]);		
		}
    int n;
    scan(n);
    ll sum=0;
    for(int i=1;i<=n;i++){
      int a1;
      scan(a1);
      if(a1<=48)sum+=a[1];
      else if(a1<=56)sum+=a[2];
      else if(a1<=60)sum+=a[3];
      else if(a1<=62)sum+=a[4];
      else sum+=a[5];
    }
    sum*=10000;
    printf("Case #%d: %lld\n",i1,sum);
	}
}
