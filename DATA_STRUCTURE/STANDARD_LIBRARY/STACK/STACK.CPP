/*
	STACK
	tested
*/
#include <bits/stdc++.h>
using namespace std;

void test(){
	stack<int> st;
	for (int i=1;i<=5;i++)
		st.push(i);
	while (st.size()){
		int t=st.top();
		st.pop();
		cout<<t<<"\n";
	}
	if (st.empty())
		cout<<"empty\n";
}
int main(){
	test();
}
