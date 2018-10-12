/*
	COMBINATION
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;

void debug(int a[maxn],int n){
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}	cout<<"\n-----\n";
}

int n,a[maxn];
void combination(int pos){
	if (pos==n+1){
		debug(a,n);
		return;
	}
	a[pos]=0;combination(pos+1);
	a[pos]=1;combination(pos+1);
}

int main()
{
	cin>>n;
	cout<<"\n";
	combination(1);
	return 0;
}
