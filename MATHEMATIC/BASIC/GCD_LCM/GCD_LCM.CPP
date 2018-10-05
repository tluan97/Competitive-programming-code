/*
	GCD_LCA
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
	return (b==0)?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
	return (b*(a/gcd(a,b)));
}

void test(){
	cout<<gcd(5,20)<<"\n";	// 5
	cout<<gcd(4,5)<<"\n";	// 1
	cout<<gcd(3,9)<<"\n";	// 3
	cout<<gcd(0,0)<<"\n";	// 0
	cout<<gcd(0,1)<<"\n";	// 1
	cout<<gcd(1,0)<<"\n";	// 1
	
	cout<<lcm(5,20)<<"\n";	// 20
	cout<<lcm(4,5)<<"\n";	// 20
	cout<<lcm(1,1)<<"\n";	// 1
	cout<<lcm(3,9)<<"\n";	// 9
	cout<<lcm(0,1)<<"\n";	// 0
	cout<<lcm(1,0)<<"\n";	// 0
}

int main()
{
	test();
	return 0;
}
