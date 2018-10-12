/*
	RABIN_KARP_base1
	http://vn.spoj.com/problems/SUBSTR/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000010;
const int mod = 1000000007;
const int base = 2309;
const int maxl = 1000010;

LL m[maxl];
void initHash(){
	m[0]=1LL;
	for (int i=1;i<maxl;i++){
		m[i]=(m[i-1]*base)%mod;
	}
}
void buildHash(string s,LL h[maxl]){
	int l=s.size();h[0]=0;
	for (int i=1;i<l;i++){
		h[i]=(h[i-1]*base+1LL*s[i])%mod;
	}
}
LL getHash(LL h[maxl],int l,int r){
	return (h[r]-h[l-1]*m[r-l+1]+1LL*mod*mod)%mod;
}

LL hs[maxl],hl[maxl];
int main()
{
	string s,l;cin>>s>>l;
	int n1=s.size();s=" "+s;
	int n2=l.size();l=" "+l;
	
	initHash();
	buildHash(s,hs);
	buildHash(l,hl);
	
	for (int i=1;i<=n1-n2+1;i++){
//		cout<<getHash(hs,i,i+n2-1)<<"\n";
		if (getHash(hs,i,i+n2-1)==hl[n2])
			cout<<i<<" ";
	}
	cout<<"\n";
	
	return 0;
}
