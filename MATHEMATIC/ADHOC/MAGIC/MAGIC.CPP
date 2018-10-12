/*
	MAGIC
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

//	Given array D[i]
//	Calculate D'[i] = sum( D[j] | j is subset of i )
//	If we want to calculate D'[i] = sum( D[j] | j is superset of i ),
//		change D[t|i] += D[f|i] --> D[f|i] += D[t|i]
void magic(int D[maxn],int K) {
	for(int b=0; b<K; b++) {
		int f=0, t=(1<<b);
		for(int g=0; g<(1<<(K-1-b)); 
		f+=(1<<(b+1)), t+=(1<<(b+1)), g++)
			for(int i=0; i<(1<<b); i++)
				D[t|i] += D[f|i];
//				D[f|i] += D[t|i];
	}
}

void test_magic(){
	int a[maxn]={0,1,2,3,4},n=5;
	magic(a,n);
	cout<<n<<"\n";
	for (int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<"\n"; 
}
int main(){
	test_magic();
	return 0;
}
