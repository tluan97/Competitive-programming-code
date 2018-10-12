/*
	SHELL_SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

int n;
int a[maxn];

void shellSort(){
	for (int k=n/2;k>0;k/=2){
		for (int i=k,j;i<n;i++){
			float t=a[i];
			for (j=i;j>=k && a[j-k]>t;j-=k){
				a[j]=a[j-k];
			}
			a[j]=t;
		}
	}
}

int main(){
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	shellSort();
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}
