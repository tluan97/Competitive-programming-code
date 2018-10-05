/*
	SEARCH_0
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
int n,a[maxn],m,k;

void test(){
	freopen("test.txt","r",stdin);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	while (m--){
		cin>>k;
		cout<<k<<": ";
		cout<<lower_bound(a+1,a+n+1,k)-a<<" ";
		// k <= all
		cout<<upper_bound(a+1,a+n+1,k)-a<<"\n";
		// all < k
	}
}

int main()
{
	test();
	return 0;
}
