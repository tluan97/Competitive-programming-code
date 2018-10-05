/*
	SMALLEST_ENCLOSING_CIRCLE
	http://www.spoj.com/problems/QCJ4/
	http://vn.spoj.com/problems/ALIENS/
*/
#include <bits/stdc++.h>
using namespace std;

// _POINT
#define EPS 1e-6
const double PI = acos(-1.0);

double DEG_to_RAD(double d) { return d*PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/PI; }

inline int cmp(double a, double b) {
	return (a < b-EPS) ? -1 : ((a > b+EPS) ? 1 : 0);
}

struct Point {
	double x,y;
	
	Point() { x = y = 0.0; }
	Point(double x,double y) : x(x),y(y) {}
	
	Point operator + (const Point& a) const 
		{ return Point(x+a.x, y+a.y); }
	Point operator - (const Point& a) const 
		{ return Point(x-a.x, y-a.y); }
	Point operator * (double k) const 
		{ return Point(x*k, y*k); }
	Point operator / (double k) const 
		{ return Point(x/k, y/k); }
	double operator * (const Point& a) const 
		{ return x*a.x + y*a.y; } // dot product
	double operator % (const Point& a) const 
		{ return x*a.y - y*a.x; } // cross product
	
	int cmp(Point q) const { 
		if (int t = ::cmp(x,q.x)) return t; 
		return ::cmp(y,q.y); 
	}
	
#define Comp(x) bool operator x (Point q) const { return cmp(q) x 0; }
	Comp(>) Comp(<) Comp(==) Comp(>=) Comp(<=) Comp(!=)
#undef Comp
	
	Point conj() { return Point(x, -y); }
	double norm() { return x*x + y*y; }
	
	// Note: There are 2 ways for implementing len():
	// 1. sqrt(norm()) --> fast, but inaccurate 
	//		(produce some values that are of order X^2)
	// 2. hypot(x, y) --> slow, but much more accurate
	double len() { return sqrt(norm()); }
	
	Point rotate(double alpha) {
		double cosa = cos(alpha), sina = sin(alpha);
		return Point(x * cosa - y * sina, x * sina + y * cosa);
	}
};

// _CIRCLE
struct Circle : Point {
	double r;
	
	Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}
	Circle(Point p, double r) : Point(p), r(r) {}
	
	bool contains(Point p) { return (*this - p).len() <= r + EPS; }
};

// Smallest enclosing circle:
// Given N points. Find the smallest circle enclosing these points.
// Amortized complexity: O(N)

struct SmallestEnclosingCircle {
	Circle getCircumcircle(Point a, Point b, Point c) {
		double d = 2.0*(a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y));
		assert(fabs(d) > EPS);
		double x = (a.norm()*(b.y-c.y)+b.norm()*(c.y-a.y)+c.norm()*(a.y-b.y))/d;
		double y = (a.norm()*(c.x-b.x)+b.norm()*(a.x-c.x)+c.norm()*(b.x-a.x))/d;
		Point p(x, y);
		return Circle(p, (p-a).len());
	}
	
	Circle getCircle(vector<Point> points) {
		assert(!points.empty());
		random_shuffle(points.begin(), points.end());
		Circle c(points[0], 0);
		int n = points.size();
		
		for (int i = 1; i < n; i++)
			if ((points[i]-c).len() > c.r+EPS) {
				c = Circle(points[i], 0);
				for (int j = 0; j < i; j++)
					if ((points[j]-c).len() > c.r+EPS) {
						c = Circle((points[i]+points[j])/2, (points[i]-points[j]).len()/2);
						for (int k = 0; k < j; k++)
							if ((points[k]-c).len() > c.r+EPS)
								c = getCircumcircle(points[i], points[j], points[k]);
					}
			}
		return c;
	}
};

void test_QCJ4(){
	int test, n;
    double x, y;
	test=1;
    while (test--) {
        cin >> n;
        vector<Point> points;
        while (n--) {
            scanf("%lf %lf", &x, &y);
            points.push_back(Point(x, y));
        }

        SmallestEnclosingCircle scc;
        Circle c = scc.getCircle(points);
		printf("%.2lf\n", c.r*2);
    }
}
void test_ALIENS(){
	int test, n;
    double x, y;
    cin >> test;
    while (test--) {
        cin >> n;
        vector<Point> points;
        while (n--) {
            scanf("%lf %lf", &x, &y);
            points.push_back(Point(x, y));
        }

        SmallestEnclosingCircle scc;
        Circle c = scc.getCircle(points);
        printf("%.2lf\n%.2lf %.2lf\n", c.r, c.x, c.y);
    }
}

int main(){
//	test_QCJ4();
//	test_ALIENS();
}
