/*
	BITMASK
	tested
*/
#include <bits/stdc++.h>
using namespace std;

template<class type>
struct bit {
	type n;
	int get(int i){
		return (n>>i)&1;
	}
	void on(int i){
		n|=(type(1)<<i);
	}
	void off(int i){
		n&=(~(type(1)<<i));
	}
	void invert(int i){
		n^=(type(1)<<i);
	}
	void print(int m){
		for (int i=m-1;i>=0;i--)
			cout<<get(i);
		cout<<"\n";
	}
	void subset(){
		bit<type> t;
		type nn=n;
		cout<<"---\n";
		do {
			t.n=nn;
			t.print(16);
		} while (nn=(nn-1)&n);
		cout<<"---\n";
	}
	void misc(){
		cout<<(n&(n-1))<<"\n";
		// set last one bit to 0
		cout<<(n&-n)<<"\n";
		// set all to 0 except for last one bit
		cout<<(n|(n-1))<<"\n";
		// invert all bit after last one bit
		cout<<(n&(n-1))<<"\n";
		// if power of two equal 0
		cout<<__builtin_clz(n)<<"\n";
		// the number of leading 0-bits in x
		cout<<__builtin_ctz(n)<<"\n";
		// the number of trailing 0-bits in x
		cout<<__builtin_popcount(n)<<"\n";
		// the number of 1-bits in x
		cout<<__builtin_parity(n)<<"\n";
		// the number of 1-bits in x modulo 2. 
	}
};

void test_(){
	bit<int> a; a.n=5328;
	a.on(5);
	a.print(16);
	a.invert(5);
	a.print(16);
	a.subset();
	a.misc();
}
int main(){
	test_();
	return 0;
}
