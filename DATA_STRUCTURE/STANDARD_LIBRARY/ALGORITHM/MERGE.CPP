/*
	MERGE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

int n,m,t,k;
vector<int> a,b,c;

void merge_(){
	k=n+m;
	c.resize(k);
	merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
}
void merge_test(){
	int i=0,j=0,l=0;
	while (i+j<=n+m+1){
		if (j>m) c[l++]=a[i++];
		else if (i>n) c[l++]=b[j++];
		else if (a[i]<b[j]) c[l++]=a[i++];
		else c[l++]=b[j++];
	}
}

int main(){
	srand(time(NULL));
	n=rand()%10;
	m=rand()%10;
	for (int i=0;i<n;i++)
		a.push_back(rand());
	for (int i=0;i<m;i++)
		b.push_back(rand());
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	merge_();
	cout<<k<<"\n";
	for (int i=0;i<k;i++)
		cout<<c[i]<<" ";
}
