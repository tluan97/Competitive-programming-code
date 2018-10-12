/*
	CLOSEST_PAIR_OF_POINT
	uva 10245
*/
#include <bits/stdc++.h>
using namespace std;

#define double long double
typedef pair<double,double> Point;
#define X first
#define Y second
const double oo = 1000111000111000111;

int n;
vector<Point> a;
double u,v;
double ans;

bool comp(Point a,Point b){
	if (a.X==b.X) return a.Y>b.Y;
	return a.X>b.X;
}
double dist(Point a,Point b){
	return sqrt(
		(a.X-b.X)*(a.X-b.X)+
		(a.Y-b.Y)*(a.Y-b.Y)
	);
}
double closestPoint_(vector<Point> a,int l,int r){
	double res=oo;
	for (int i=l;i<r;i++)
	for (int j=i+1;j<=r;j++)
	if (dist(a[i],a[j])<res)
		res=dist(a[i],a[j]);
	return res;
}
double closestPoint(vector<Point> a,int l,int r){
	if (l>r) return oo;
	if (r-l<=10) return closestPoint_(a,l,r);
	int m=(l+r)/2;
	double dl=closestPoint(a,l,m);
	double dr=closestPoint(a,m+1,r);
	double res=(dl<dr)?dl:dr;
	double line=(a[m].X+a[m+1].X)/2;
	for (int i=m;line-a[i].X<res && i>=l;i--)
	for (int j=m+1;a[j].X-line<res && j<=r;j++){
		double tmp=dist(a[i],a[j]);
		if (tmp<res) res=tmp;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
//	freopen("CLOSESTPAIR.INP","r",stdin);
//	freopen("CLOSESTPAIR.OUT","w",stdout);
	
	while (cin>>n && n){
		a.clear();
		for (int i=0;i<n;i++){
			cin>>u>>v;
			a.push_back(Point(u,v));
		}
		sort(a.begin(),a.end(),comp);
		ans=closestPoint(a,0,n-1);
		if (ans>=10000) cout<<"INFINITY\n";
		else cout<<(fixed)<<setprecision(4)<<ans<<"\n";
	}
	
	return 0;
}
/*
3
0 0
10000 10000
20000 20000
5
0 2
6 67
43 71
39 107
189 140
0
*/
