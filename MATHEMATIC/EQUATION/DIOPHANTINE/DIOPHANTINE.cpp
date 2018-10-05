/*
	DIOPHANTINE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

int extgcd(int a,int b,int &x,int &y){
	int g=a; x=1;y=0;
	if (b!=0){
		g=extgcd(b,a%b,y,x);
		y-=(a/b)*x;
	}
	return g;
}

// a * x + b * y = c , c % gcd(a, b) == 0
int diophantine(int a,int b,int c,int &x,int &y){
	int g=extgcd(a,b,x,y);
	x=c/g*x; y=c/g*y;
	return g;
}

void test_diophantine(){
	srand(time(NULL));
	int a,b,c,x,y,g;
	for (int i=1;i<=1000000;i++){
		a=rand()%10000;
		b=rand()%10000;
		c=rand()%10000;
		g=diophantine(a,b,c,x,y);
		if (c%g==0 && a*x+b*y!=c){
			cout<<a<<" "<<b<<" "<<c<<" ";
			cout<<x<<" "<<y<<"   FAIL\n";
		}
	}
	cout<<"DONE\n";
}
int main(){
	test_diophantine();
	return 0;
}
