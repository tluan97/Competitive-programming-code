/*
	SMALLEST_ENCLOSING_CIRCLE_TRICK
	http://www.spoj.com/problems/QCJ4/
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
const int maxn = 100010;
const double eps = 1e-9;

typedef pair<double, double> point;
typedef pair<point, double> circle;
point operator + (point a, point b) { return point(a.X+b.X, a.Y+b.Y); }
point operator - (point a, point b) { return point(a.X-b.X, a.Y-b.Y); }
point operator / (point a, double x) { return point(a.X/x, a.Y/x); }
double abs(point a) { return sqrt(a.X*a.X+a.Y*a.Y); }
point center_from(double bx, double by, double cx, double cy) {
	double B=bx*bx+by*by, C=cx*cx+cy*cy, D=bx*cy-by*cx;
	return point((cy*B-by*C)/(2*D), (bx*C-cx*B)/(2*D));
}
circle circle_from(point A, point B, point C) {
	point I = center_from(B.X-A.X, B.Y-A.Y, C.X-A.X, C.Y-A.Y);
	return circle(I+A, abs(I));
}

int n,x[maxn],y[maxn];
point a[maxn];
circle f(int n, vector<point> t){
	if (t.size()==3 || n==0){
		if (t.size()==0) return circle(point(0,0),-1);
		if (t.size()==1) return circle(t[0],0);
		if (t.size()==2) return circle((t[0]+t[1])/2,abs(t[0]-t[1])/2);
		return circle_from(t[0],t[1],t[2]);
	}
	random_shuffle(a+1,a+n+1);
	circle res = f(0,t);
	for (int i=1;i<=n;i++)
	if (abs(res.X-a[i])>res.Y+eps){
		t.push_back(a[i]);
		res=f(i-1,t);
		t.pop_back();
	}
	return res;
}

int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		a[i]=point(x[i],y[i]);
	}
	circle C=f(n,vector<point>());
	(cout<<fixed).precision(2);
	cout<<2*C.Y<<"\n";
}
