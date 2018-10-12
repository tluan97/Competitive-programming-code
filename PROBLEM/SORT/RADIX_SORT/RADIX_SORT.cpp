/*
	RADIX_SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int n,a[maxn];
int b[maxn];

void radixsort(int a[],int b[],int n,int k){
	int Count[256]={}, Start[256]={};
	for (int i=1;i<=n;i++)
		Count[(a[i]>>k)&255]++;
	for (int i=1;i<=255;i++)
		Start[i]=Start[i-1]+Count[i-1];
	for (int i=1;i<=n;i++)
		b[++Start[(a[i]>>k)&255]]=a[i];
}
void radixsort(){
	radixsort(a,b,n,0);
	radixsort(b,a,n,8);
	radixsort(a,b,n,16);
	radixsort(b,a,n,24);
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	radixsort();
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
