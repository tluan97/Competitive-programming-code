/*
	CHINESE_REMAINDER
	https://open.kattis.com/problems/generalchineseremainder
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL extgcd(LL a, LL b, LL &x, LL &y){
	LL g = a; x = 1; y = 0;
	if (b != 0){
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

//	Solve linear congruences equation:
//	a[i] * x = b[i] MOD m[i] 
//	(mi don't need to be co-prime)
//	CHINESE REMAINDER THEOREM
struct CRT {
	vector<LL> a,b,m;
	LL x,M;
	void init(){
		a.clear();
		b.clear();
		m.clear();
	}
	void add(LL b_, LL m_){
		a.push_back(1LL);
		b.push_back(b_);
		m.push_back(m_);
	}
	bool linearCongruences(){
		LL n=a.size();
		x=0;; M=1;
		for (int i=0;i<n;i++){
			LL a_=a[i]*M, b_=b[i]-a[i]*x,m_=m[i];
			LL y,t,g=extgcd(a_,m_,y,t);
			if (b_%g) return false;
			b_/=g; m_/=g;
			x+=M*(y*b_%m_);
			M*=m_;
		}
		x=(x+M)%M;
		return true;
	}
}crt;

void test_GCR(){
	LL u,v;
	int test; cin>>test;
	while (test--){
		crt.init();
		cin>>u>>v;
		crt.add(u,v);
		cin>>u>>v;
		crt.add(u,v);
		if (crt.linearCongruences()){
			cout<<crt.x<<" "<<crt.M<<"\n";
		} else cout<<"no solution\n";
	}
}
int main(){
	test_GCR();
	return 0;
}

