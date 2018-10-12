/*
	QUEUE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

void test(){
	queue<int> qu;
	for (int i=1;i<=5;i++)
		qu.push(i);
	while (qu.size()){
		int t=qu.front();
		qu.pop();
		cout<<t<<"\n";
	}
	if (qu.empty())
		cout<<"empty\n";
}
int main(){
	test();
}
