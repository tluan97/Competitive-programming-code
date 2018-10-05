/*
	KMP
	http://vn.spoj.com/problems/SUBSTR/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxl = 1000010;

int pi[maxl],cnt[maxl];
void initKMP(string p){
	int m=p.size();
	for (int i=1,j=0;p[i];i++){
		while (j && (p[i]!=p[j]))
			j=pi[j-1];
		if (p[i]==p[j]) pi[i]=++j;
	}
}
void getKMP(string s,string p){
	int n=s.size();
	int m=p.size();
	for (int i=0,j=0;s[i];i++){
		while (j && (s[i]!=p[j]))
			j=pi[j-1];
		if (s[i]==p[j]){
			cnt[++j]++;
			if (j==m){
				cout<<i-m+2<<" ";
				j=pi[j-1];
			}
		}
	}
}

int main()
{
	string s,l;cin>>s>>l;
	int n=s.size();
	int m=l.size();
	
	initKMP(l);
	getKMP(s,l);
//	for (int i=1;i<=m;i++)
//		cout<<cnt[i]<<" ";cout<<"\n";
	cout<<"\n";
}
