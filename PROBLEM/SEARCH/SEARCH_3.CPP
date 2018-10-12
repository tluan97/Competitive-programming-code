/*
	SEARCH_3
	tested
*/
/*
	Cho 2 diem A va B
	Tim diem C tren truc hoanh Ox
		sao cho AC+BC la nho nhat
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> point;
#define X first
#define Y second

point p1,p2,p3;

double euler(double x,double y){
	return sqrt(x*x+y*y);
}
double dist(point p1,point p2){
	return euler(p1.X-p2.X,p1.Y-p2.Y);
}
double f(point p1,point p2,point p3){
	double AC = dist(p1,p3);
	double BC = dist(p2,p3);
	return AC+BC;
}
double f(double x){
	return f(p1,p2,point(x,0));
}

double search(point p1,point p2){
	double rr=max(p1.X,p2.X);
    double ll=min(p1.X,p2.X);
    double ml=(ll+ll+rr)/3;
    double mr=(ll+rr+rr)/3;
	while (ll!=ml && ml!=mr && mr!=rr){
		(f(ml)>f(mr))?ll=ml:rr=mr;
		ml=(ll+ll+rr)/3;
        mr=(ll+rr+rr)/3;
	}
	return (ll+rr)/2;
}

int main()
{
	double u,v;
	cin>>u>>v;p1=point(u,v);
	cin>>u>>v;p2=point(u,v);
	u=search(p1,p2);
	p3=point(u,0);
	cout<<u<<"\n";
	cout<<f(p1,p2,p3)<<"\n";
	
	return 0;
}
