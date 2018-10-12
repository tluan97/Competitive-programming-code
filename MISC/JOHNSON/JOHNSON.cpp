/*
	JOHNSON
	https://vn.spoj.com/problems/NK2MFS/
	https://vn.spoj.com/problems/TWO/
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
typedef pair<int,II> III;
#define X first
#define Y second
const int maxn = 10010;

int n;
int aa[maxn],bb[maxn];
vector<III> a,b;
int ans;

bool compA(III a,III b){
	return a.Y.X<b.Y.X;
}
bool compB(III a,III b){
	return a.Y.Y>b.Y.Y;
}
void solve(){
	for (int i=1;i<=n;i++)
	if (aa[i]<=bb[i]){
		a.push_back(III(i,II(aa[i],bb[i])));
	} else {
		b.push_back(III(i,II(aa[i],bb[i])));
	}
	sort(a.begin(),a.end(),compA);
	sort(b.begin(),b.end(),compB);
	int ta=0,tb=0;
	for (int i=0;i<a.size();i++){
		ta+=a[i].Y.X;
		tb=max(ta,tb)+a[i].Y.Y;
	}
	for (int i=0;i<b.size();i++){
		ta+=b[i].Y.X;
		tb=max(ta,tb)+b[i].Y.Y;
	}
	ans=max(ta,tb);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>aa[i];
	for (int i=1;i<=n;i++)
		cin>>bb[i];
	solve();
	cout<<ans<<"\n";
	for (int i=0;i<a.size();i++)
		cout<<a[i].X<<" ";
	for (int i=0;i<b.size();i++)
		cout<<b[i].X<<" ";
	
	return 0;
}
