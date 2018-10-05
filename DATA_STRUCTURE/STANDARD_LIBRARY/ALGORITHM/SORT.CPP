/*
	SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

void sort_(){
	sort(a.begin(),a.end());
}

int main(){
	srand(time(NULL));
	int n=rand()%10;
	for (int i=0;i<n;i++)
		a.push_back(rand());
	sort_();
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
}
