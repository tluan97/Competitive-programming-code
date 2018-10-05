/*
	PERMUTATION
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
int b[maxn];
bool used[maxn];
void permutation(){
	do {
		debug(a,n);
	} while (next_permutation(a+1,a+n+1));
}
void permutation(int pos){
	if (pos==n+1){
		debug(b,n);
		return;
	}
	for (int i=1;i<=n;i++)
	if (!used[i]){
		b[pos]=a[i];used[i]=1;
		permutation(pos+1);
		used[i]=0;
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	cout<<"\n";
	permutation();
	cout<<"\n";
	permutation(1);
	
	return 0;
}
