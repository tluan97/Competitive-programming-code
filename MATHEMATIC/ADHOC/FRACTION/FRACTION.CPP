/*
	FRACTION
	tested
*/
#include <bits/stdc++.h>
using namespace std;

#define T long long
struct Fraction {
	T a,b;
	
	Fraction(){
		a=0; b=1;
	}
	Fraction(T _a){
		a=_a; b=1;
	}
	Fraction(T _a,T _b){
		a=_a; b=_b; norm();
	}
	Fraction(double f){
		double integral = floor(f);
		double frac = f-integral;
		const T precision = 1000000000;
		T gcd_ = __gcd((T)round(frac*precision),precision);
		T denominator = precision/gcd_;
		T numerator = round(frac*precision)/gcd_;
		a=integral*denominator+numerator;
		b=denominator;
		norm();
	}
	
	Fraction operator+(const Fraction& p) const {
		return Fraction(a*p.b+b*p.a,b*p.b);
	}
	Fraction operator-(const Fraction& p) const {
		return Fraction(a*p.b-b*p.a,b*p.b);
	}
	Fraction operator*(const Fraction& p) const {
		return Fraction(a*p.a,b*p.b);
	}
	Fraction operator/(const Fraction& p) const {
		assert(p.a!=0);
		return Fraction(a*p.b,b*p.a);
	}
	
	int cmp(Fraction p) const {
		return (a*p.b-b*p.a);
	}
	
#define Comp(x) bool operator x (Fraction p) const { return cmp(p) x 0; }
	Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp
	
	void norm(){
		if (b<0) { a=-a; b=-b; }
		if (a==0) b=1;
		else {
			T g = __gcd(llabs(a),llabs(b));
			a/=g; b/=g;
		}
	}
    
    friend istream& operator>>(istream &stream,Fraction &p){
    	string s; stream>>s;
    	int pos=s.find("/");
    	if (pos!=-1){
    		T _a=atoi(s.substr(0,pos).c_str()); 
    		T _b=atoi(s.substr(pos+1).c_str());
    		p=Fraction(_a,_b);
    	} else {
    		p=Fraction(atoi(s.c_str()),1);
    	}
    	return stream;
    }
    friend ostream& operator<<(ostream &stream,const Fraction &p){
    	stream<<p.a<<"/"<<p.b;
    	return stream;
    }
};

int main(){
	Fraction a;
	cin>>a;
	cout<<a<<"\n";
	cout<<Fraction(0.5)<<"\n";
	cout<<Fraction(1.25)<<"\n";
	cout<<Fraction(10.0/3)<<"\n";
}
