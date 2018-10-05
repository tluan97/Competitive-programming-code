/*
	SUM_ARRAY
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;

int n,a[maxn],f[maxn];
void sumArray(int n, int a[maxn], int f[maxn]){
	for (int i=1;i<=n;i++)
		f[i]=f[i-1]+a[i];
}
int getSum(int u,int v){
	return f[v]-f[u-1];
}

void testSumArray(){
	n=rand()%20; cout<<n<<"\n";
	for (int i=1;i<=n;i++){
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}	cout<<"\n";
	sumArray(n,a,f);
	int u,v;
	while (cin>>u>>v){
		cout<<getSum(u,v)<<"\n";
	}
}
int main(){
	srand(time(NULL));
	testSumArray();
}
