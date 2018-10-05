/*
	DEBUG_CHECK
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
#define X first
#define Y second
const int maxn = 10;

void debug(int n){
	cout<<n<<"\n-----\n";
}
void debug (II ii){
	cout<<ii.X<<" "<<ii.Y<<"\n-----\n";
}
void debug(int a[maxn],int n){
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}	cout<<"\n-----\n";
}
void debug(int a[maxn][maxn],int m,int n){
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			cout<<a[i][j]<<" ";
		}	cout<<"\n";
	}	cout<<"\n-----\n";
}

void test(){
	int n=5,m=2,t=1;
	int a[]={0,1,2,3,4,5};
	int b[maxn][maxn];
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		b[i][j]=t++;
	debug(m);debug(n);
	debug(a,n);
	debug(b,m,n);
}

int main()
{
	test();
	return 0;
}
