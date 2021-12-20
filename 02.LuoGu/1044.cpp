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

const int MAX = 40;
int n;
LL f[MAX][MAX];                 // f[i][j]: i 已经入栈, 共有j个数出栈

int main(void){
    // f[0][0] = 1
    // f[1][0] = 1
    // f[1][1] = 1
    // f[2][0] = f[1][0] = 1
    // f[2][1] = f[1][1] + f[2][0] = 2
    // f[2][2] = f[2][1] = 2
    // f[3][0] = f[2][0] = 1
    // f[3][1] = f[3][0] + f[2][1] = 3
    // f[3][2] = f[3][1] + f[2][2] = 3 + 2 = 5
    // f[3][3] = f[3][2] = 5
    scanf("%d",&n);
    f[0][0] = 1;
    FORR(i,1,n) {
        FORR(j,0,i) {
            LL &a = f[i][j];
            a = 0;
            if (j) a += f[i][j-1];
            if (i-1 >= j) a += f[i-1][j];
        }
    }
    printf("%lld\n", f[n][n]);

    return 0;
}
