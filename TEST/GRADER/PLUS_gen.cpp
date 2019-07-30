#include <bits/stdc++.h>
using namespace std;

const string TEST_NAME = "PLUS";

typedef long long LL;
struct random {
    LL rand16(){
        return rand() & ((1LL<<16)-1);
    }
    LL rand32(){
        return rand16()<<16 | rand16();
    }
    LL rand64(){
        return rand32()<<32 | rand32();
    }
} random;

void luan(){
    cout<<random.rand32()<<" ";
    cout<<random.rand32()<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen((TEST_NAME+".INP").c_str(),"w",stdout);
    luan();
    return 0;
}