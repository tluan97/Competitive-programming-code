/*
	Z_FUNCTION
	http://vn.spoj.com/problems/SUBSTR/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxl = 2000010;

int z[maxl];
void zfunc(string s,int z[maxl]){
	int n=s.size();
	for (int i=1,l=0,r=0;i<n;i++){
		if (i<=r) z[i]=min(r-i+1,z[i-l]);
		while (i+z[i]<n && s[z[i]]==s[i+z[i]])
			z[i]++;
		if (i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}

int main()
{
	string s,l,ss;
	cin>>s>>l;
	int n=s.size();
	int m=l.size();
	ss=l+"@"+s;
	int k=ss.size();
	
	zfunc(ss,z);
	
	for (int i=m+1;i<k-m+1;i++){
		if (z[i]==m) cout<<i-m<<" ";
	}
	cout<<"\n";
	
	return 0;
}
