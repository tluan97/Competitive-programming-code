/*
	KADANE_2D
	tested
Cho mot mang hai chieu n*n
tim hinh chu nhat ma tong cac phan tu trong do la lon nhat
O(n**3)
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;
const int oo = 1000111000;

int n;
int a[maxn][maxn];
int s[maxn][maxn][maxn];
int ans;

int kadane(int i,int j){
	int lowest=0;
	int current=0;
	int result=-oo;
	for (int k=1;k<=n;k++){
		current+=s[i][j][k];
		result=max(result,current-lowest);
		lowest=min(lowest,current);
	}
    return result;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n; ans=-oo;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		cin>>a[i][j];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
	for (int k=1;k<=n;k++)
		s[i][j][k]=s[i][j-1][k]+a[j][k];
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		ans=max(ans,kadane(i,j));
	cout<<ans<<"\n";
	
	return 0;
}
