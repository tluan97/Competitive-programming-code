/*
	LIS
	https://vn.spoj.com/problems/LIS/
	https://uva.onlinejudge.org/external/4/481.html
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000010;
LL a[maxn],n;
LL f[maxn],b[maxn],ans;
vector<LL> t;

void solve(){
	for (int i=1;i<=n;i++){
		f[i]=lower_bound(b+1,b+ans+1,a[i])-b;
		ans=max(ans,f[i]);
		b[f[i]]=a[i];
	}
	int exp=ans;
	for (int i=n;i>=1;i--)
	if (f[i]==exp){
		t.push_back(a[i]);
		exp--;
	}
	reverse(t.begin(),t.end());
}
void spoj(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	cout<<ans<<"\n";
}
void uva(){
	while (cin>>a[n+1]) n++;
	solve();
	cout<<ans<<"\n-\n";
	for (int i=0;i<t.size();i++)
		cout<<t[i]<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	spoj();
//	uva();
	return 0;
}
