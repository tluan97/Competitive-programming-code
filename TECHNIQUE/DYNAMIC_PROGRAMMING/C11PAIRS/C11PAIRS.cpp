/*
	C11PAIRS
	https://vn.spoj.com/problems/C11PAIRS/
*/ 
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 500010;

int n;
LL a[maxn],s[maxn];
LL ans;

void solve(){
	int sn=0;
    s[++sn]=a[n];
    s[0]=-1;
    for (int i=n-1;i>=1;i--){
        int dau=0,cuoi=sn+1;
        while (cuoi-dau>1){
            int giua=(dau+cuoi)/2;
            if (s[giua]<=a[i]) cuoi=giua;
			else dau=giua;
        }
        if (dau==0) ans+=sn;
		else ans+=(sn-dau+1);
        while (sn!=0 && s[sn]<a[i]) sn--;
        s[++sn]=a[i];
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	cout<<ans<<"\n";
	
	return 0;
}
/*
7
2 4 1 2 2 5 1
*/
