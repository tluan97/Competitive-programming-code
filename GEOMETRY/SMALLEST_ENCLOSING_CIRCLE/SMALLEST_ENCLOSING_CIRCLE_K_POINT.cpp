/*
	SMALLEST_ENCLOSING_CIRCLE_K_POINT.cpp
	http://www.spoj.com/problems/TAP2013F/
	http://vn.spoj.com/problems/TRIPOD/
	http://vn.spoj.com/problems/TRIPOD2/
*/
/*
	http://www.spoj.com/problems/TAP2013F/
*/
#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = acos(-1.0);

#ifdef DEBUG
#define  DB(x) cerr<<#x<<": "<<x<<" ";
#define  DBL(x) cerr<<#x<<": "<<x<<endl;
#else
#define DB(x) 
#define DBL(x)
#endif

using namespace std;


int n;
int k;

struct Vector{
	double x;
	double y;
	Vector(){};
	Vector(double x, double y):x(x), y(y) {};
};

struct event{
	double angle;
	int type;
	int id;
	
	event(double angle, int type, int id):angle(angle), type(type), id(id){};
};

bool operator<(const event& e1, const event e2){
	return (e1.angle==e2.angle)?((e1.type==e2.type)?e1.id<e2.id:e1.type==1):e1.angle<e2.angle;
}

double angle_norm(double a){
	if(a < 0.0) return a+2*PI;
	if(a>2*PI) return a-2*PI;
	return a;
}

double angle(const Vector& v1, const Vector& v2){
	return angle_norm(atan2(v2.y-v1.y, v2.x-v1.x));
}

double dist(const Vector& v1, const Vector& v2){
	return (v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y);
}

Vector p[500];

double ds[500][500];
double ba[500][500];


bool hasSolution(double r){
	set<event> events;
	set<int> in;
	for(int i=0;i<n;i++){
		events.clear();
		for(int j=0;j<n;j++){
			if(i==j) continue;
			double d = ds[i][j];
			if(d > (4*r*r)+EPS) continue;
			double base_angle = ba[i][j];;
			double a = acos(sqrt(d)/(2*r));
			//DB(i) DB(j) DB(base_angle) DBL(a)
			events.emplace(angle_norm(base_angle-a), 1, j);
			events.emplace(angle_norm(base_angle+a), 0, j);
		}
		in.clear();
		Vector c(p[i].x+r, p[i].y);
		for(int j=0;j<n;j++){
			if(dist(c,p[j])<=((r*r)+EPS)){
				in.insert(j);
			}
		}
		int mx = in.size();
		DB(r) DB(i) DBL(mx)
		if(mx >= k) return true;
		for(event e : events){
			if(e.type){
				in.insert(e.id);
			} else{
				in.erase(e.id);
			}
			mx = max(mx, (int)in.size());
			if(mx >= k) return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<setprecision(4)<<fixed;
	int t=1;
	cin >> t; 
	while(t--){
		cin >> n>>k;
//		cin>>n; k=3;
		for(int i=0;i<n;i++){
			cin >> p[i].x >> p[i].y;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				ba[i][j] = angle(p[i],p[j]);
				ds[i][j] = dist(p[i],p[j]);
			}
		}
		double s=0;
		double e=300000.0;
		double m;
		while((e-s) > EPS){
			m = (s+e)/2.0;
			if(hasSolution(m)){
				e=m;
			} else{
				s=m;
			}
		}
		cout<<e<<endl;
//		printf("%.5lf", e);
	}
}
