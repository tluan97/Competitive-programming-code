/*
	FIBONACCI
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
const int maxn = 10010;
const ULL mod = 1000111000;

//	F(n+1) = F(n)+F(n-1)
//	F(0)+F(1)+F(2)+...+F(n) = F(n+2) - 1
//	F(1)+2F(2)+3F(3)+...+nF(n) = n F(n+2) - F(n+3)+2
ULL fibo[maxn];
ULL fibo_init(int n,ULL m){
	fibo[1]=1;fibo[2]=1;
	for (int i=3;i<=n;i++){
		fibo[i]=(fibo[i-1]+fibo[i-2])%m;
	}
	return fibo[n];
}
ULL fibo_n(int n,ULL m){
	if (n==0) return 0;
	if (n<=2) return 1;
	ULL f=0,f1=1,f2=1;
	for (int i=3;i<=n;i++){
		f=(f1+f2)%m;
		f2=f1;
		f1=f;
	}
	return f;
}
ULL fibo_Binet(int n,ULL m){
	double f=((1.0/sqrt(5))*
		(pow((1.0+sqrt(5))/2,n)
		-pow((1.0-sqrt(5))/2,n)));
	return (f-ULL(f))>0.5?ULL(f)+1:ULL(f);
}
// fibo_matrix
ULL f[maxn]={1,1}; 
ULL fm(int n){
	if (f[n]) return f[n];
	ULL k=n/2;
	if (n%2==0)
		return f[n]=(fm(k)*fm(k)+fm(k-1)*fm(k-1))%mod;
	else 
		return f[n]=(fm(k)*fm(k+1)+fm(k-1)*fm(k))%mod;
}
//	https://www.fq.math.ca/Scanned/10-4/advanced10-4.pdf
bool isSquare(ULL n){
	return ceil(sqrt(n))==floor(sqrt(n));
}
bool isFibonacci(ULL n){
	return n>=0 && isSquare(5*n*n+4) || isSquare(5*n*n-4);
}

void test_FIBONACCI(){
	fibo_init(1000,mod);
	for (int i=1;i<=1000;i++){
		if (fibo_n(i,mod)!=fibo[i])
			cout<<"fibo_n      "<<i<<"  FAIL\n";
		if (i<45 && fibo_Binet(i,mod)!=fibo[i])
			cout<<"fibo_Binet  "<<i<<"  FAIL\n";
		if (fm(i-1)!=fibo[i])
			cout<<"fibo_matrix "<<i<<"  FAIL\n";
		if (i<45 && !isFibonacci(fibo[i]))
			cout<<"isFibonacci "<<i<<"  FAIL\n";
	}
	cout<<"DONE\n";
}
int main(){
	test_FIBONACCI();
	return 0;
}
