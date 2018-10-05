/*
	STANDARD_DEVIATION
	tested
*/
#include <bits/stdc++.h>
using namespace std;

vector<double> a;

double average(vector<double> a){
	double x=0.0;
	for (int i=0;i<a.size();i++)
		x+=a[i];
	x/=a.size();
	return x;
}
double standard(vector<double> a){
	double s=0.0;
	double x=average(a);
	for (int i=0;i<a.size();i++){
		s+=pow(a[i]-x,2);
	}
	s=sqrt(s/(a.size()-1));
	return s;
}

int main()
{
	int n,u;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>u;
		a.push_back(u);
	}
	cout<<average(a)<<"\n";
	cout<<standard(a)<<"\n";
	return 0;
}
