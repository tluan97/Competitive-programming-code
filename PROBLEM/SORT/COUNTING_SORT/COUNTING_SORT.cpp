/*
	COUNTING_SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

unordered_map<int,int> cs;
unordered_map<int,int>::iterator it;
void countingSort(vector<int> a){
	int n = a.size();
	for (int i=0;i<n;i++)
		cs[a[i]]++;
	for (it=cs.begin();it!=cs.end();it++){
		cout<<it->X<<" "<<it->Y<<"\n";
	}
}

int main(){
	srand(time(NULL));
	int n=rand()%1000;
	vector<int> a;
	a.reserve(n);
	for (int i=0;i<n;i++)
		a.push_back(rand()%10);
	countingSort(a);
}
