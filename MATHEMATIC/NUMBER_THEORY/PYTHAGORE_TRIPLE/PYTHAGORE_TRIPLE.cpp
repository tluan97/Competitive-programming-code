/*
	PYTHAGORE_TRIPLE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

//	a^2 + b^2 == c^2
//	To generate all primitive triples:
//	a = m^2 - n^2, b = 2mn, c = m^2 + n^2 (m > n)
//	Primitive triples iff gcd(m, n) == 1 && (m - n) % 2 == 1
//	sinh bo 3 pytago nguyen thuy voi x, y, z <= n
vector<vector<int> > genPrimitivePytTriples(int n) {
	vector<vector<int> > ret;
	for (int r=1; r*r<=n; ++r) 
	for (int s=(r%2==0)?1:2; s<r; s+=2) 
	if (__gcd(r,s)==1 && (r-s)%2==1) {
		vector<int> t;
		t.push_back(r*r+s*s); 	// z
		t.push_back(2*r*s); 	// y
		t.push_back(r*r-s*s); 	// x
		if (t[0]<=n) ret.push_back(t);        
	}
	sort(ret.begin(), ret.end());
	return ret;
}

int main(){
	vector<vector<int> > ans=genPrimitivePytTriples(1000);
	for (int i=0;i<ans.size();i++){
		for (int j=ans[i].size()-1;j>=0;j--){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
