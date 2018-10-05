/*
	BINOMIAL_COEFFICIENTS
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;

const int maxn = 60;
ULL BC[maxn][maxn];
void binomialCoeff(){
	BC[0][0]=1;
	for (int i=1;i<maxn;i++)
	for (int j=0;j<=i;j++)
	if (j==0) BC[i][j]=1;
	else BC[i][j]=BC[i-1][j-1]+BC[i-1][j];
}
ULL binomialCoeff(int n,int k){
	ULL res=1;
	if (k>=n-k) k=n-k;
	for (int i=0;i<k;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}

void test_(){
	binomialCoeff();
	int t=1000;
	while (t--){
		int n=rand()%maxn;
		int k=rand()%(n+1);
		if (binomialCoeff(n,k)!=BC[n][k]){
			cout<<n<<" "<<k<<" "<<BC[n][k]<<"\n";
		}
	}
}
int main(){
	test_();
	return 0;
}
