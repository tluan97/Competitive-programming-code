/*
	WATERJUG
	Cho 2 binh dong nuoc co the tich a va b.
	Can dong luong nuoc c.
	Tim cach dong voi so luong buoc la it nhat.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL d=1000000000LL;
typedef pair<int,int> II;
typedef pair<int,II> III;
#define X first
#define Y second

int a,b,c,ans;
int r,u,v;
unordered_map<long long,bool> mp;

int gcd(int a, int b){
	return b==0?a:gcd(b,a%b);
}
void solve_mp(){
	if ((c>a && c>b) || c%gcd(a,b)!=0){
		ans=-1;
		return;
	}
	mp.clear();
	priority_queue<III,vector<III>,greater<III> > pq;
	pq.push(III(0,II(0,0)));
	while (!pq.empty()){
		r=pq.top().X;
		u=pq.top().Y.X;
		v=pq.top().Y.Y;
		pq.pop();
		mp[u*d+v]=true;
		if (u==c || v==c){
			ans=r; return;
		}
		if (mp[0*d+v]==false){
			pq.push(III(r+1,II(0,v)));
		}
		if (mp[u*d+0]==false){
			pq.push(III(r+1,II(u,0)));
		}
		if (mp[a*d+v]==false){
			pq.push(III(r+1,II(a,v)));
		}
		if (mp[u*d+b]==false){
			pq.push(III(r+1,II(u,b)));
		}
		if (u+v>=a && mp[a*d+u+v-a]==false){
			pq.push(III(r+1,II(a,u+v-a)));
		}
		if (u+v<a && mp[(u+v)*d+0]==false){
			pq.push(III(r+1,II(u+v,0)));
		}
		if (u+v>=b && mp[(u+v-b)*d+b]==false){
			pq.push(III(r+1,II(u+v-b,b)));
		}
		if (u+v<b && mp[0*d+u+v]==false){
			pq.push(III(r+1,II(0,u+v)));
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int test; cin>>test;
	while (test--){
		cin>>a>>b>>c;
		solve_mp();
		cout<<ans<<"\n";
	}
}
