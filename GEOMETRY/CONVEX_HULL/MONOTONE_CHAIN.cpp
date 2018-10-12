/*
	MONOTONE_CHAIN
	https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=622
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

struct Point {
	int X,Y;
	bool operator < (const Point &v){
		return X==v.X ? Y<v.Y : X<v.X;
	}
	int cross(const Point &p, const Point &q) const {
		return (p.X-X)*(q.Y-Y)-(p.Y-Y)*(q.X-X);
	}
};

int n;
Point a[maxn],p[maxn];

void monotonechain(){
	sort(a+1,a+n+1);
	int k=1;
	for (int i=1;i<=n;i++){
		while (k>=3 && p[k-2].cross(p[k-1],a[i])<=0) 
			k--;
		p[k++]=a[i];
	}
	for (int i=n-1,t=k+1;i>0;i--){
		while (k>=t && p[k-2].cross(p[k-1],a[i])<=0) 
			k--;
		p[k++]=a[i];
	}
	for (int i=1;i<k;i++){
		a[i]=p[i];
	}
	n=k-2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; cin>>test;
	cout<<test<<"\n";
	while (test--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].X>>a[i].Y;
		}
		monotonechain();
		int imin=1;
		for (int i=1;i<=n;i++){
			if (a[i].Y<a[imin].Y){
				imin=i;
			} else {
				if (a[i].Y==a[imin].Y && a[i].X<a[imin].X)
					imin=i;
			}
		}
		cout<<n+1<<"\n";
		for (int i=imin;i<=n;i++)
			cout<<a[i].X<<" "<<a[i].Y<<"\n";
		for (int i=1;i<=imin;i++)
			cout<<a[i].X<<" "<<a[i].Y<<"\n";
		if (test!=0){
			cin>>n;
			cout<<n<<"\n";
		}
	}
	return 0;
}

