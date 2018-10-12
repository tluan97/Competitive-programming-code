/*
	RABIN_KARP_base0
	http://vn.spoj.com/problems/SUBSTR/
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000010;
const int mod = 1000000007;
const int base = 2309;
const int maxl = 1000010;

struct HashString{
	
	LL m[maxl];
	vector<LL> h[maxn];
	vector<string> a;
	int n;
	
	void init(){
		m[0]=1LL;
		for (int i=1;i<maxl;i++){
			m[i]=(m[i-1]*base)%mod;
		}
	}
	void addString(string s){
		a.push_back(" "+s);
		n++;
	}
	void buildHash(int i){
		int l=a[i].size();
		h[i].resize(l+1,0);
		for (int j=1;j<l;j++){
			h[i][j]=(h[i][j-1]*base+1LL*a[i][j])%mod;
		}
	}
	LL getHash(int i,int l,int r){
		l++; r++;
		return (h[i][r]-h[i][l-1]*m[r-l+1]+1LL*mod*mod)%mod;
	}
	
}hash;

int main()
{
	string s;
	cin>>s;hash.addString(s);int la=s.size();
	cin>>s;hash.addString(s);int lb=s.size();
	hash.init();
	for (int i=0;i<hash.n;i++)
		hash.buildHash(i);
		
	for (int i=0;i<=la-lb;i++) {
//		cout<<hash.getHash(0,i,i+lb-1)<<"\n";
        if (hash.getHash(0,i,i+lb-1)==hash.getHash(1,0,lb-1))
        	cout<<i+1<<" ";
    }
    cout<<"\n";
	
	return 0;
}

