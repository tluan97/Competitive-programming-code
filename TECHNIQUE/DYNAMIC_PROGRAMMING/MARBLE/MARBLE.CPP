/*
	MARBLE
	Cho hinh chu nhat co dien tich n*m.
	Cho k manh hinh chu nhat co the cat.
	Tim cach cat hcn n*m thanh cac hcn con sao cho
		dien tich thua bo di la it nhat co the.
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> II;
#define X first
#define Y second
const int maxn = 610;
const int oo = 1000000;

int n,m,k;
vector<II> a;
int f[maxn][maxn];
II tt;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for (int i=1;i<=k;i++){
		cin>>tt.Y>>tt.X;
		a.push_back(tt);
	}
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++){
		f[i][j]=oo;
		f[i][j]=min(f[i][j],f[i-1][j]+f[1][j-1]+1);
		f[i][j]=min(f[i][j],f[i][j-1]+f[i-1][1]+1);
		for (int h=0;h<k;h++){
			if (i>=a[h].X && j>=a[h].Y){
				f[i][j]=min(f[i][j],f[i-a[h].X][j]+f[a[h].X][j-a[h].Y]);
				f[i][j]=min(f[i][j],f[i][j-a[h].Y]+f[i-a[h].X][a[h].Y]);
			}
		}
	}
	cout<<f[m][n]<<"\n";
//	for (int i=1;i<=m;i++){
//		for (int j=1;j<=n;j++){
//			if (f[i][j]==oo){
//				cout<<"oo\t";
//			} else {
//				cout<<f[i][j]<<"\t";
//			}
//		}
//		cout<<"\n";
//	}
	return 0;
}
/*
21 11 4
10 4
6 2
7 5
15 10

3 4
3
2 3
1 3
2 2
*/