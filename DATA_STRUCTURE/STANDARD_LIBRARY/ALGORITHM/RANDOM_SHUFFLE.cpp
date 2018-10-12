/*
	RANDOM_SHUFFLE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

void test(){
	srand(time(NULL));
	vector<int> a;
	for (int i=0;i<=9;i++)
		a.push_back(i);
	do {
		random_shuffle(a.begin(),a.end());
		for (int i=0;i<=9;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
	} while (rand()%10);
}
int main(){
	test();
	return 0;
}
