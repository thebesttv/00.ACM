// Tag: 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<numeric>
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
    int s = 0, ch;
    do ch = getchar(); while(!isdigit(ch));
    while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
    return s;
}

int n;
string s;

int main(void){
    scanf("%d",&n);
    int x, ch = '0';
    while (scanf("%d",&x) == 1) {
        s += string(x, ch);
        ch = ch=='0' ? '1' : '0';
    }

    auto it = s.cbegin();
    FOR(i,0,n) {
        FOR(j,0,n) putchar(*it++);
        putchar('\n');
    }

    return 0;
}
