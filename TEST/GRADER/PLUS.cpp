#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const string TEST_NAME = "PLUS";

void luan(){
    LL a,b;
    cin>>a>>b;
    cout<<a+b;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((TEST_NAME+".INP").c_str(),"r",stdin);
    freopen((TEST_NAME+".OUT").c_str(),"w",stdout);
    luan();
    return 0;
}