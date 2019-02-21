/*
	QUICK_SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

void quick_sort(int a[maxn],int ll,int rr){
	int pivot=a[(ll+rr)/2];
	int i=ll,j=rr;
	while (i<=j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if (ll<j) quick_sort(a,ll,j);
	if (i<rr) quick_sort(a,i,rr);
}

int n,a[maxn];
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	quick_sort(a,1,n);
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}
