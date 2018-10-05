/*
	SEARCH_1
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

int n,a[maxn],m,k;
int search_(int k){
	int ll=1,rr=n;
	for (int i=ll;i<=rr;i++)
	if (a[i]>=k) return i;
	return n+1;
}
int search(int k){
	int ll=1,rr=n,i=(ll+rr)/2;
	while (ll!=i && i!=rr){
		(a[i]>=k)?rr=i:ll=i;
		i=(ll+rr)/2;
	}
	for (int i=ll;i<=rr;i++)
	if (a[i]>=k) return i;
	return n+1;
}
int lowerbound(int k){
	int ll=1,rr=n,i=(ll+rr)/2;
	while (ll!=i && i!=rr){
		(a[i]>=k)?rr=i:ll=i;
		i=(ll+rr)/2;
	}
	for (int i=ll;i<=rr;i++)
	if (a[i]>=k) return i;
	return n+1;
}
int upperbound(int k){
	int ll=1,rr=n,i=(ll+rr)/2;
	while (ll!=i && i!=rr){
		(a[i]>k)?rr=i:ll=i;
		i=(ll+rr)/2;
	}
	for (int i=ll;i<=rr;i++)
	if (a[i]<=k) return i;
	return n+1;
}

void test(){
	freopen("test.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	while (m--){
		cin>>k;
		cout<<k<<": ";
		cout<<search_(k)<<" ";
		cout<<lowerbound(k)<<" ";
		cout<<upperbound(k)<<" ";
		cout<<search(k)<<"\n";
	}
}
int main()
{
	test();
	return 0;
}
