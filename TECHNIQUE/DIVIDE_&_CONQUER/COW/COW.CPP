/*
	COW
	Cho n vi tri can dat c vat the sao cho 
		khoang cach giua 2 vat the bat ki
		la lon nhat co the
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
const int oo = 1000111000;

int n,c,t;
vector<int> a;
int ans;
int lmi;

bool check(int k){
	int in=-oo, cc=c;
	for (int i=0;cc>0 && i<n;i++){
		if (a[i]-in>=k){
			in=a[i];
			cc--;
		}
	}
	if (cc>0) return false;
	return true;
}
void solve(){
	sort(a.begin(),a.end());
	lmi=oo;
	for (int i=1;i<n;i++)
		lmi=min(lmi,a[i]-a[i-1]);
	int ll=lmi,rr=(a[n-1]-a[0])/(c-1),mm=(ll+rr)/2;
	while (ll+1!=rr){
//		cout<<ll<<" "<<rr<<" "<<mm<<"--\n";
		if (check(mm)) ll=mm;
		else rr=mm;
		mm=(ll+rr)/2;
	}
	if (check(rr)) ans=rr;
	else ans=ll;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; cin>>test;
	while (test--){
		cin>>n>>c;
		a.clear();
		for (int i=0;i<n;i++){
			cin>>t;
			a.push_back(t);
		}
		solve();
		cout<<ans<<"\n";
	}
	return 0;
}
