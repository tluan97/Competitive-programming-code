/*
	SQUARE
	Cho mang 2 chieu m*n gom "*" va "."
	Tim hinh vuong lon nhat toan "*"
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int n,m,a[maxn][maxn];
string u;
int maxx=0,s,kk;

int main()
{
	cin>>n>>m; cin.ignore();
	for (int i=1;i<=n;i++)
	{
		getline(cin,u);
		u=" "+u;
		for (int j=1;j<=m;j++)
		{
			if (u[j]=='.')
				a[i][j]=0;
			else a[i][j]=1;
				a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	{
		kk=min(i,j);
		for (int k=1;k<=kk;k++)
		{
			s=a[i][j]-a[i-k][j]-a[i][j-k]+a[i-k][j-k];
			if (s==k*k)
				maxx=max(maxx,k);
		}
	}
	cout<<maxx;
	return 0;
}
/*
5 6
..*.*.
*.****
*****.
*****.
...*..
*/
