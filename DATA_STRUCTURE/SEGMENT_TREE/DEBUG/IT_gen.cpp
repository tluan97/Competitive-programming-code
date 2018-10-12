// IT_gen
#include <bits/stdc++.h>
using namespace std;

const int maxn = 11;

int main(){
	srand(time(NULL));
	freopen("IT.INP","w",stdout);
	
	int n=rand()%10+1;
	int r=rand()%n;
	int m=rand()%5;
	int a[maxn];
	for (int i=1;i<=n;i++)
		a[i]=rand()%10;
	
	cout<<n<<" "<<r<<" "<<m<<"\n";
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	
	return 0;
}
