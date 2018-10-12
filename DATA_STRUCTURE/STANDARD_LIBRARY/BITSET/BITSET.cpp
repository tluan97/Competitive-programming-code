/*
	BITSET
	tested
*/
#include <bits/stdc++.h>
using namespace std;

void test(){
	bitset<10> b1,b2;
	bitset<10> b3(24);
	bitset<10> b4("11000101");
	cout<<b3.to_string()<<"\n";
	cout<<b4.to_string()<<"\n";
	
	b1[1]=1; b2[2]=1; 
	cout<<(b1==b2)<<"\n";
	cout<<(b1!=b2)<<"\n";
	cout<<b1.test(1)<<"\n";
	cout<<b1.all()<<"\n";
	cout<<b1.any()<<"\n";
	cout<<b1.none()<<"\n";
	cout<<b1.count()<<"\n";
	cout<<b1.size()<<"\n";
	cout<<b1.set()<<"\n";
	cout<<b1.reset()<<"\n";
	cout<<b1.flip()<<"\n";
	cout<<b1.to_string()<<"\n";
	cout<<b1.to_ulong()<<"\n";
	cout<<b1.to_ullong()<<"\n";
}
int main(){
	test();
	return 0;
}
