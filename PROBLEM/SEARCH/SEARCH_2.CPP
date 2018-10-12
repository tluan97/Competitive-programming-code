/*
	SEARCH_2
	tested
*/
#include <bits/stdc++.h>
using namespace std;

double arcsin(double x){
	double ll=0,rr=M_PI/2;
	double i=(ll+rr)/2;
	while (ll!=i && i!=rr){
		(sin(i)>=x)?rr=i:ll=i;
		i=(ll+rr)/2;
	}
	return (ll+rr)/2;
}

int main()
{
	double x;cin>>x; // 0<=x<=1
	cout<<arcsin(x)<<"\n";
	cout<<asin(x)<<"\n";
	return 0;
}
