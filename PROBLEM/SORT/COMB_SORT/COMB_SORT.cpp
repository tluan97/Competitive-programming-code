/*
	COMB_SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

void compsort(int a[maxn],int n){
	int g=n,s=0,j;
	while (g>1 || s!=0){
		g=g*77/96; // ~3/4
		if (g<=1) g=1;
		s=0;
		for (j=1;j+g<=n;j++)
		if (a[j]>a[j+g]){
			swap(a[j],a[j+g]);
			s=1;
		}
	}
}

int n,a[maxn];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	compsort(a,n);
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
