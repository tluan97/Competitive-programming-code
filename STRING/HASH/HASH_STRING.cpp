/*
	HASH_STRING
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int maxl = 1010;
const LL base = 257;
const LL mod = 1000000007;
LL H[maxl];
void initHash(){
	H[0]=1ll;
	for (int i=1;i<maxl;i++)
		H[i]=(H[i-1]*base)%mod;
}
struct HashString {
	string s;
	LL h[maxl];
	HashString(string s): s(s) {
		int n=s.length();
		h[0]=s[0]%mod;
		for (int i=1;i<n;i++)
			h[i]=(h[i-1]*base+s[i])%mod;
	}
	LL getHash(int l,int r){
		if (l==0) return h[r];
		return (h[r]-h[l-1]*H[r-l+1]+mod*mod)%mod;
	}
};

void test_(){
	initHash();
	string s; cin>>s;
	HashString hs(s);
	for (int i=0;i<s.size();i++)
	for (int j=i;j<s.size();j++)
		cout<<hs.getHash(i,j)<<"\n";
}
int main(){
	test_();
	return 0;
}
