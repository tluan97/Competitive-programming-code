/*
	SOLUTION_BAG
	https://open.kattis.com/problems/estimation
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 2010;
const LL oo = 1000111000111000111LL;

int n,k;
LL a[maxn];
LL cost[maxn][maxn];
LL dp[maxn];
LL ans;

void solve(){
	priority_queue<LL> lower;
	priority_queue<LL,vector<LL>,greater<LL> > upper;
	int sumlower,sumupper;
	LL v,median,costlower,costupper;
	
	for (int i=1;i<=n;i++){
		while (!lower.empty()) lower.pop();
		while (!upper.empty()) upper.pop();
		sumlower=0;
		sumupper=0;
		for (int j=i;j<=n;j++){
			sumlower+=a[j];
			lower.push(a[j]);
			if (lower.size()>upper.size() ||
				upper.size()>0 &&
				lower.top()>upper.top()){
				v=lower.top();
				lower.pop();
				upper.push(v);
				sumlower-=v;
				sumupper+=v;	
			}
			if (upper.size()>lower.size()){
				v=upper.top();
				upper.pop();
				lower.push(v);
				sumupper-=v;
				sumlower+=v;
			}
			median=lower.top();
			costlower=lower.size()*median-sumlower;
			costupper=sumupper-upper.size()*median;
			cost[i][j]=costlower+costupper; 
		}
	}
	for (int i=1;i<=n+1;i++)
		dp[i]=oo;
	dp[1]=0;
	for (int kk=1;kk<=k;kk++)
	for (int i=n;i>=1;i--)
	for (int j=i;j<=n;j++)
		dp[j+1]=min(dp[j+1],dp[i]+cost[i][j]);
	ans=dp[n+1];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	cout<<ans<<"\n";
	
	return 0;
}

