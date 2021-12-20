#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
void calc(long long n,long long m){
    if(!m)return;
    ans+=n/m;
    calc(m,n%m);
}
int main(){
    cin>>n>>m;
    calc(n,m);
    cout<<ans<<endl;
    return 0;
}
