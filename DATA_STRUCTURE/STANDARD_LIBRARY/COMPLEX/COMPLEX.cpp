/*
	COMPLEX
	tested
*/
#include <bits/stdc++.h>
using namespace std;

void test(){
	complex<double> z;
	z.real(1);
	z.imag(2);
	cout<<z.real()<<"\n";
	cout<<z.imag()<<"\n";
	cout<<abs(z)<<"\n";
	cout<<arg(z)<<"\n";
	cout<<norm(z)<<"\n";
	cout<<conj(z)<<"\n";
	cout<<proj(z)<<"\n";
	cout<<polar(z)<<"\n";
}
int main(){
	test();
	return 0;
}
