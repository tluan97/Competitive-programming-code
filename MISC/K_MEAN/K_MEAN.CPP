/*
	K_MEAN
	tested
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<double,double> point;
#define X first
#define Y second

const int maxk = 11;
const int maxn = 11;
const int oo = 1000111000;

struct kmean {	
	int n,k;
	vector<point> a;
	point g[maxk];
	vector<point> p[maxk];
	
	void init(){
		a.clear();
		for (int i=0;i<maxk;i++){
			g[i]=point(0,0);
			p[i].clear();
		}
	}
	void add(double x,double y){
		a.push_back(point(x,y));
	}
	double dist(point p,point o){
		return (p.X-o.X)*(p.X-o.X)+(p.Y-o.Y)*(p.Y-o.Y);
	}
	int near(point p){
		double d=oo;
		int ans=0;
		for (int i=1;i<=k;i++){
			if (dist(p,g[i])<d){
				d=dist(p,g[i]);
				ans=i;
			}
		}
		return ans;
	}
	void classify(){
		n=a.size();
		for (int i=1;i<=k;i++){
			g[i]=a[i-1];
		}
		bool stop=false;
		while (!stop){
			stop=true;
			for (int j=0;j<n;j++){
				p[near(a[j])].push_back(a[j]);
			}
			for (int i=1;i<=k;i++){
				double xx=0,yy=0;
				for (int j=0;j<p[i].size();j++){
					xx+=p[i][j].X;
					yy+=p[i][j].Y;
				}
				if (p[i].size()!=0){
					xx/=p[i].size();
					yy/=p[i].size();
				}
				if (g[i]!=point(xx,yy)){
					g[i]=point(xx,yy);
					stop=false;
				}
			}
			if (stop==false){
				for (int i=1;i<=k;i++)
					p[i].clear();
			}
		}
	}
	void print(){
		cout<<"\n----------\n";
		for (int i=1;i<=k;i++){
			cout<<"\n"<<i<<"\n";
			for (int j=0;j<p[i].size();j++)
				cout<<p[i][j].X<<" "<<p[i][j].Y<<"\n";
		}
	}
}c;

int main(){
	freopen("K_MEAN.INP","r",stdin);
	freopen("K_MEAN.OUT","w",stdout);
	
	double u,v;
	while (cin>>c.n && c.n!=0){
		c.init();
		for (int i=0;i<c.n;i++){
			cin>>u>>v;
			c.add(u,v);
		}
		cin>>c.k;
		c.classify();
		c.print();
	}
	
	return 0;
}
