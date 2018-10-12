/*
	QBRECT
	https://vn.spoj.com/problems/QBRECT/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;

int m,n,a[maxn][maxn];
int h[maxn],l[maxn],r[maxn],ans;

void solve(){
	h[0]=-1;h[n+1]=-1;
    for (int i=1;i<=m;i++) 
	{
        for (int j=1;j<=n;j++)
            h[j]=a[i][j]*(h[j]+1);
        for (int j=1;j<=n;j++) 
		{
            l[j]=j;
            while (h[l[j]-1] >= h[j]) 
				l[j]=l[l[j]-1];
        }
        for (int j=n;j>0;j--) 
		{
            r[j]=j;
            while (h[r[j]+1] >= h[j]) 
				r[j]=r[r[j]+1];
        }
        for (int j=1;j<=n;j++)
            ans=max(ans,h[j]*(r[j]-l[j]+1));
    }
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
    cin>>m>>n;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++) 
		cin>>a[i][j];
    solve();
    cout<<ans<<"\n";
    
    return 0;
}
/*
11 13
0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
1 1 1 1 1 1 1 1 1 1 1 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0 0 1 1
0 0 0 0 0 1 0 0 0 0 0 1 1
*/
