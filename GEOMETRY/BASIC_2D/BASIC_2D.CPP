/*
	BASIC_2D
	tested
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

int ccw(Point a, Point b, Point c) {
	return cmp((b-a)%(c-a),0);
}
int RE_TRAI = ccw(Point(0, 0), Point(0, 1), Point(-1, 1));
int RE_PHAI = ccw(Point(0, 0), Point(0, 1), Point(1, 1));

istream& operator >> (istream& cin, Point& p) {
	cin >> p.x >> p.y;
	return cin;
}
ostream& operator << (ostream& cout, Point& p) {
	cout << p.x << ' ' << p.y;
	return cout;
}

// min of directed angle AOB & BOA
double angle(Point a, Point o, Point b) {
	a = a - o; b = b - o;
	return acos((a * b) / sqrt(a.norm()) / sqrt(b.norm()));
}

// angle AOB, in range [0, 2*PI)
double directed_angle(Point a, Point o, Point b) {
	double t = -atan2(a.y - o.y, a.x - o.x)
			+ atan2(b.y - o.y, b.x - o.x);
	while (t < 0) t += 2*PI;
	return t;
}

// Distance from p to Line ab (closest Point --> c)
double distToLine(Point p, Point a, Point b, Point &c) {
	Point ap = p - a, ab = b - a;
	double u = (ap * ab) / ab.norm();
	c = a + (ab * u);
	return (p-c).len();
}

// Distance from p to segment ab (closest Point --> c)
double distToLineSegment(Point p, Point a, Point b, Point &c) {
	Point ap = p - a, ab = b - a;
	double u = (ap * ab) / ab.norm();
	if (u < 0.0) {
		c = Point(a.x, a.y);
		return (p - a).len();
	}
	if (u > 1.0) {
		c = Point(b.x, b.y);
		return (p - b).len();
	}
	return distToLine(p, a, b, c);
}

// _LINE
// NOTE: WILL NOT WORK WHEN a = b = 0.
struct Line {
	double a, b, c;
	Point A, B; // Added for polygon intersect line. 
	
	Line(double a, double b, double c) : a(a), b(b), c(c) {} 
	Line(Point A, Point B) : A(A), B(B) {
		a = B.y - A.y;
		b = A.x - B.x;
		c = - (a * A.x + b * A.y);
	}
	Line(Point P, double m) {
		a = -m; b = 1;
		c = -((a * P.x) + (b * P.y));
	}
	double f(Point A) {
		return a*A.x + b*A.y + c;
	}
};

bool areParallel(Line l1, Line l2) {
	return cmp(l1.a*l2.b, l1.b*l2.a) == 0;
}
bool areSame(Line l1, Line l2) {
	return areParallel(l1 ,l2) 
			&& cmp(l1.c*l2.a, l2.c*l1.a) == 0 
			&& cmp(l1.c*l2.b, l1.b*l2.c) == 0;
}
bool areIntersect(Line l1, Line l2, Point &p) {
	if (areParallel(l1, l2)) return false;
	double dx = l1.b*l2.c - l2.b*l1.c;
	double dy = l1.c*l2.a - l2.c*l1.a;
	double d  = l1.a*l2.b - l2.a*l1.b;
	p = Point(dx/d, dy/d);
	return true;
}

void closestPoint(Line l, Point p, Point &ans) {
	if (fabs(l.b) < EPS) {
		ans.x = -(l.c) / l.a; 
		ans.y = p.y;
		return;
	}
	if (fabs(l.a) < EPS) {
		ans.x = p.x; 
		ans.y = -(l.c) / l.b;
		return;
	}
	Line perp(l.b, -l.a, - (l.b*p.x - l.a*p.y));
	areIntersect(l, perp, ans);
}

void reflectionPoint(Line l, Point p, Point &ans) {
	Point b;
	closestPoint(l, p, b);
	ans = p + (b - p) * 2;
}

// _CIRCLE
struct Circle : Point {
	double r;
	
	Circle(double x = 0, double y = 0, double r = 0) : Point(x, y), r(r) {}
	Circle(Point p, double r) : Point(p), r(r) {}
	
	bool contains(Point p) { return (*this - p).len() <= r + EPS; }
};

// Find common tangents to 2 circles
// Helper method
double sqr(double a){
	return a*a;
}
void tangents(Point c, double r1, double r2, vector<Line> & ans) {
	double r = r2 - r1;
	double z = sqr(c.x) + sqr(c.y);
	double d = z - sqr(r);
	if (d < -EPS)  return;
	d = sqrt(fabs(d));
	Line l((c.x * r + c.y * d) / z, (c.y * r - c.x * d) / z, r1);
	ans.push_back(l);
}
// Actual method: returns vector containing all common tangents
vector<Line> tangents(Circle a, Circle b) {
	vector<Line> ans; ans.clear();
	for (int i=-1; i<=1; i+=2)
	for (int j=-1; j<=1; j+=2)
		tangents(b-a, a.r*i, b.r*j, ans);
	for (int i = 0; i < ans.size(); ++i)
		ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
	
	vector<Line> ret;
	for (int i = 0; i < ans.size(); ++i) {
		bool ok = true;
		for (int j = 0; j < ret.size(); ++j)
			if (areSame(ret[j], ans[i])) {
				ok = false;
				break;
			}
		if (ok) ret.push_back(ans[i]);
	}
	
	return ret;
}

// Circle & line intersection
vector<Point> intersection(Line l, Circle cir) {
	double r = cir.r, a = l.a, b = l.b, c = l.c + l.a*cir.x + l.b*cir.y;
	vector<Point> res;
	
	double x0 = -a*c/(a*a+b*b),  y0 = -b*c/(a*a+b*b);
	if (c*c > r*r*(a*a+b*b)+EPS) return res;
	else if (fabs(c*c - r*r*(a*a+b*b)) < EPS) {
		res.push_back(Point(x0, y0) + Point(cir.x, cir.y));
		return res;
	} else {
		double d = r*r - c*c/(a*a+b*b);
		double mult = sqrt (d / (a*a+b*b));
		double ax,ay,bx,by;
		ax = x0 + b * mult;
		bx = x0 - b * mult;
		ay = y0 - a * mult;
		by = y0 + a * mult;
		
		res.push_back(Point(ax, ay) + Point(cir.x, cir.y));
		res.push_back(Point(bx, by) + Point(cir.x, cir.y));
		return res;
	}
}

// helper functions for commonCircleArea
double cir_area_solve(double a, double b, double c) {
	return acos((a*a + b*b - c*c) / 2 / a / b);
}
double cir_area_cut(double a, double r) {
	double s1 = a * r * r / 2;
	double s2 = sin(a) * r * r / 2;
	return s1 - s2;
}

// return the common area of two circle
double commonCircleArea(Circle c1, Circle c2) { 
	if (c1.r < c2.r) swap(c1, c2);
	double d = (c1 - c2).len();
	if (d + c2.r <= c1.r + EPS) return c2.r*c2.r*PI;
	if (d >= c1.r + c2.r - EPS) return 0.0;
	double a1 = cir_area_solve(d, c1.r, c2.r);
	double a2 = cir_area_solve(d, c2.r, c1.r);
	return cir_area_cut(a1*2, c1.r) + cir_area_cut(a2*2, c2.r);
}

// Check if 2 circle intersects. Return true if 2 circles touch
bool areIntersect(Circle u, Circle v) {
	if (cmp((u - v).len(), u.r + v.r) > 0) return false;
	if (cmp((u - v).len() + v.r, u.r) < 0) return false;
	if (cmp((u - v).len() + u.r, v.r) < 0) return false;
	return true;
}

// If 2 circle touches, will return 2 (same) points
// If 2 circle are same --> be careful
vector<Point> circleIntersect(Circle u, Circle v) {
	vector<Point> res;
	if (!areIntersect(u, v)) return res;
	double d = (u - v).len();
	double alpha = acos((u.r * u.r + d*d - v.r * v.r) / 2.0 / u.r / d);
	
	Point p1 = (v - u).rotate(alpha);
	Point p2 = (v - u).rotate(-alpha);
	res.push_back(p1 / p1.len() * u.r + u);
	res.push_back(p2 / p2.len() * u.r + u);
	return res;
}

// _POLYGON
typedef vector<Point> Polygon;

// Convex Hull:
// If minimum point --> #define REMOVE_REDUNDANT
// If maximum point --> no need to change.

// Known issues:
// - Max. point does not work when some points are the same.
// - https://open.kattis.com/problems/convexhull

/*
bool operator<(const Point &rhs) const {
	return make_pair(y,x) < make_pair(rhs.y,rhs.x);
}
bool operator==(const Point &rhs) const {
	return make_pair(y,x) == make_pair(rhs.y,rhs.x);
}
*/
double area2(Point a, Point b, Point c) { return a%b + b%c + c%a; }
#ifdef REMOVE_REDUNDANT
bool between(const Point &a, const Point &b, const Point &c) {
	return (fabs(area2(a,b,c)) < EPS 
		&& (a.x-b.x)*(c.x-b.x) <= 0 
		&& (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(Polygon &pts) {
	sort(pts.begin(), pts.end());
	pts.erase(unique(pts.begin(), pts.end()), pts.end());
	Polygon up, dn;
	for (int i = 0; i < pts.size(); i++) {
		while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0)
			up.pop_back();
		while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0)
			dn.pop_back();
		up.push_back(pts[i]);
		dn.push_back(pts[i]);
	}
	pts = dn;
	for (int i = (int) up.size() - 2; i >= 1; i--)
		pts.push_back(up[i]);
	
#ifdef REMOVE_REDUNDANT
	if (pts.size() <= 2) return;
	dn.clear();
	dn.push_back(pts[0]);
	dn.push_back(pts[1]);
	for (int i = 2; i < pts.size(); i++) {
		if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i]))
			dn.pop_back();
		dn.push_back(pts[i]);
	}
	if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
		dn[0] = dn.back();
		dn.pop_back();
	}
	pts = dn;
#endif
}
Polygon convex_hull(Polygon P){
	Polygon tmp=P;
	ConvexHull(tmp);
	return tmp;
}

// Area, perimeter, centroid
double signed_area(Polygon p) {
	double area = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i+1) % p.size();
		area += p[i].x*p[j].y - p[j].x*p[i].y;
	}
	return area / 2.0;
}
double area(const Polygon &p) {
	return fabs(signed_area(p));
}
Point centroid(Polygon p) {
	Point c(0,0);
	double scale = 6.0 * signed_area(p);
	for (int i = 0; i < p.size(); i++){
		int j = (i+1) % p.size();
		c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
	}
	return c / scale;
}
double perimeter(Polygon P) {
	double res = 0;
	for(int i = 0; i < P.size(); ++i) {
		int j = (i+1) % P.size();
		res += (P[i] - P[j]).len();
	}
	return res;
}
// Is convex: checks if polygon is convex. 
// Assume there are no 3 collinear points
bool is_convex(const Polygon &P) {
	int sz = (int) P.size();
	if (sz <= 2) return false;
	int isLeft = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < sz; i++)
	if (ccw(P[i], P[(i+1) % sz], P[(i+2) % sz]) * isLeft < 0)
		return false;
	return true;
}

// Inside polygon: O(N). Works with any polygon
// - https://open.kattis.com/problems/pointinpolygon
// - https://open.kattis.com/problems/cuttingpolygon
bool in_polygon(const Polygon &p, Point q) {
	if ((int)p.size() == 0) return false;
	// Check if point is on edge.
	int n = (int) p.size();
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		Point u = p[i], v = p[j];
		if (u > v) swap(u, v);
		if (ccw(u, v, q) == 0 && u <= q && q <= v) 
			return true;
	}
	// Check if point is strictly inside.
	int c = 0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		if ( ( p[i].y <= q.y && q.y < p[j].y
			|| p[j].y <= q.y && q.y < p[i].y)
		&& q.x < p[i].x+(p[j].x - p[i].x)*(q.y - p[i].y)/(p[j].y - p[i].y)) 
				c = !c;
	}
	return c;
}

// Check point in convex polygon, O(logN)
// On edge --> false
#define Det(a,b,c) \
	((double)(b.x-a.x)*(double)(c.y-a.y) \
	-(double)(b.y-a.y)*(double)(c.x-a.x))
bool in_convex(Polygon& l, Point p) {
	int a = 1, b = l.size()-1, c;
	if (Det(l[0], l[a], l[b]) > 0) swap(a,b);
	// Allow on edge --> if (Det... > 0 || Det ... < 0)
	if (Det(l[0], l[a], p) >= 0 || Det(l[0], l[b], p) <= 0) 
		return false;
	while (abs(a-b) > 1) {
		c = (a+b)/2;
		if (Det(l[0], l[c], p) > 0) b = c; 
		else a = c;
	}
	// Alow on edge --> return Det... <= 0
	return Det(l[a], l[b], p) < 0;
}

// Cut a polygon with a line. Returns one half.
// To return the other half, reverse the direction of Line l (by negating l.a, l.b)
// The line must be formed using 2 points
Polygon polygon_cut(const Polygon& P, Line l) {
	Polygon Q;
	for (int i = 0; i < P.size(); ++i) {
		Point A = P[i], B = (i == P.size()-1) ? P[0] : P[i+1];
		if (ccw(l.A, l.B, A) != -1) Q.push_back(A);
		if (ccw(l.A, l.B, A)*ccw(l.A, l.B, B) < 0) {
			Point p; areIntersect(Line(A, B), l, p);
			Q.push_back(p);
		}
	}
	return Q;
}

// Find intersection of 2 convex polygons
// Helper method
bool intersect_1pt(Point a, Point b, Point c, Point d, Point &r) {
	double D =  (b - a) % (d - c);
	if (cmp(D, 0) == 0) return false;
	double t =  ((c - a) % (d - c)) / D;
	double s = -((a - c) % (b - a)) / D;
	r = a + (b - a) * t;
	return cmp(t, 0) >= 0 
		&& cmp(t, 1) <= 0 
		&& cmp(s, 0) >= 0 
		&& cmp(s, 1) <= 0;
}
Polygon convex_intersect(Polygon P, Polygon Q) {
	const int n = P.size(), m = Q.size();
	int a = 0, b = 0, aa = 0, ba = 0;
	enum { Pin, Qin, Unknown } in = Unknown;
	Polygon R;
	do {
		int a1 = (a+n-1) % n, b1 = (b+m-1) % m;
		double C = (P[a] - P[a1]) % (Q[b] - Q[b1]);
		double A = (P[a1] - Q[b]) % (P[a] - Q[b]);
		double B = (Q[b1] - P[a]) % (Q[b] - P[a]);
		Point r;
		if (intersect_1pt(P[a1], P[a], Q[b1], Q[b], r)) {
			if (in == Unknown) aa = ba = 0;
			R.push_back( r );
			in = B > 0 ? Pin : A > 0 ? Qin : in;
		}
		if (C == 0 && B == 0 && A == 0) {
			if (in == Pin) { b = (b + 1) % m; ++ba; }
			else           { a = (a + 1) % m; ++aa; }
		} else if (C >= 0) {
			if (A > 0) { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
			else       { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
		} else {
			if (B > 0) { if (in == Qin) R.push_back(Q[b]); b = (b+1)%m; ++ba; }
			else       { if (in == Pin) R.push_back(P[a]); a = (a+1)%n; ++aa; }
		}
	} while ( (aa < n || ba < m) && aa < 2*n && ba < 2*m );
	if (in == Unknown) {
		if (in_convex(Q, P[0])) return P;
		if (in_convex(P, Q[0])) return Q;
	}
	return R;
}

// Find the diameter of polygon.
// Rotating callipers
double convex_diameter(Polygon pt) {
	const int n = pt.size();
	int is = 0, js = 0;
	for (int i = 1; i < n; ++i) {
		if (pt[i].y > pt[is].y) is = i;
		if (pt[i].y < pt[js].y) js = i;
	}
	double maxd = (pt[is]-pt[js]).norm();
	int i, maxi, j, maxj;
	i = maxi = is;
	j = maxj = js;
	do {
		int jj = j+1; if (jj == n) jj = 0;
		if ((pt[i] - pt[jj]).norm() > (pt[i] - pt[j]).norm())
			j = (j+1) % n;
		else i = (i+1) % n;
		if ((pt[i]-pt[j]).norm() > maxd) {
			maxd = (pt[i]-pt[j]).norm();
			maxi = i; maxj = j;
		}
	} while (i != is || j != js);
	return maxd; /* farthest pair is (maxi, maxj). */
}

// Closest pair
// - https://open.kattis.com/problems/closestpair2
// - https://open.kattis.com/problems/closestpair1

#define MAXN 100
double mindist = 1e20; // will be the result
Point x,y; // will be the result
bool cmpy(Point u, Point v) {
	if (u.x==v.x) return u.y<v.y;
	return u.x<v.x;
}
void upd_ans(Point _x, Point _y) {
	x=_x; y=_y;
}
void rec(int l, int r, Point a[]) {
	if (r - l <= 3) {
		for (int i=l; i<=r; ++i)
		for (int j=i+1; j<=r; ++j)
			upd_ans(a[i], a[j]);
		sort(a+l, a+r+1, cmpy);
		return;
	}
	
	int m = (l + r) >> 1;
	int midx = a[m].x;
	rec(l, m, a), rec(m+1, r, a);
	static Point t[MAXN];
	merge(a+l, a+m+1, a+m+1, a+r+1, t, cmpy);
	copy(t, t+r-l+1, a+l);
	
	int tsz = 0;
	for (int i=l; i<=r; ++i)
	if (fabs(a[i].x - midx) < mindist) {
		for (int j=tsz-1; j>=0 && a[i].y - t[j].y < mindist; --j)
			upd_ans(a[i], t[j]);
		t[tsz++] = a[i];
	}
}

// Pick theorem
// Given non-intersecting polygon.
// S = area
// I = number of integer points strictly Inside
// B = number of points on sides of polygon
// S = I + B/2 - 1

// Check if we can form triangle with edges x, y, z.
bool isSquare(long long x) {
	long long tmp = (long long)sqrt(x);
	return (x==tmp*tmp);
}
bool isIntegerCoordinates(int x, int y, int z) {
	long long s=(long long)(x+y+z)*(x+y-z)*(x+z-y)*(y+z-x);
	return (s%4==0 && isSquare(s/4));
}

// _TEST
void test_Point_Line(){
	Point P1, P2, P3(0, 1);
    assert((P1 == P2) == true);
    assert((P1 == P3) == false);

    vector<Point> P;
    P.push_back(Point(2, 2));
    P.push_back(Point(4, 3));
    P.push_back(Point(2, 4));
    P.push_back(Point(6, 6));
    P.push_back(Point(2, 6));
    P.push_back(Point(6, 5));

    // sorting points demo
    sort(P.begin(), P.end());
    assert(P[0] == Point(2, 2));
    assert(P[1] == Point(2, 4));
    assert(P[2] == Point(2, 6));
    assert(P[3] == Point(4, 3));
    assert(P[4] == Point(6, 5));
    assert(P[5] == Point(6, 6));

    // rearrange the points as shown in the diagram below
    P.clear();
    P.push_back(Point(2, 2));
    P.push_back(Point(4, 3));
    P.push_back(Point(2, 4));
    P.push_back(Point(6, 6));
    P.push_back(Point(2, 6));
    P.push_back(Point(6, 5));
    P.push_back(Point(8, 6));

    /*
    // the positions of these 7 points (0-based indexing)
    6   P4      P3  P6
    5           P5
    4   P2
    3       P1
    2   P0
    1
    0 1 2 3 4 5 6 7 8
    */

    double d = (P[0] - P[5]).len();
    assert(cmp(d, 5.0) == 0);
	
	// Line equations
    Line l1(P[0], P[1]);
    assert(cmp(l1.a * P[0].x + l1.b * P[0].y + l1.c, 0) == 0);
    assert(cmp(l1.a * P[1].x + l1.b * P[1].y + l1.c, 0) == 0);

    Line l2(P[0], P[2]);
    assert(cmp(l2.a * P[0].x + l2.b * P[0].y + l2.c, 0) == 0);
    assert(cmp(l2.a * P[2].x + l2.b * P[0].y + l2.c, 0) == 0);

    // parallel, same, and Line intersection tests
    Line l3(P[2], P[3]);
    assert(areParallel(l1, l2) == false);
    assert(areParallel(l1, l3) == true);

    Line l4(P[2], P[4]);
    assert(areSame(l1, l2) == false);
    assert(areSame(l2, l4) == true);

    Point p12;
    bool res = areIntersect(l1, l2, p12);
    assert(res);
    assert(p12 == Point(2, 2));

    // other distances
    Point ans;
    d = distToLine(P[0], P[2], P[3], ans);
    assert(cmp(d, 1.788854382) == 0);
    assert(ans == Point(1.2, 3.6));

    closestPoint(l3, P[0], ans);
    assert(cmp(d, 1.788854382) == 0);
    assert(ans == Point(1.2, 3.6));

    d = distToLineSegment(P[0], P[2], P[3], ans);
    assert(cmp(d, 2) == 0);
    assert(ans == Point(2, 4));

    d = distToLineSegment(P[1], P[2], P[3], ans);
    assert(cmp(d, 1.788854382) == 0);
    assert(ans == Point(3.2, 4.6));

    d = distToLineSegment(P[6], P[2], P[3], ans);
    assert(cmp(d, 2) == 0);
    assert(ans == Point(6, 6));

    reflectionPoint(l4, P[1], ans);
    assert(ans == Point(0, 3));

    assert(cmp(RAD_to_DEG(angle(P[0], P[4], P[3])), 90) == 0);
    assert(cmp(RAD_to_DEG(angle(P[0], P[2], P[1])), 63.434948823) == 0);
    assert(cmp(RAD_to_DEG(angle(P[4], P[3], P[6])), 180) == 0);

    assert(ccw(P[0], P[2], P[3]) == -1);
    assert(ccw(P[0], P[3], P[2]) == 1);

    assert(ccw(P[0], P[2], P[3]) != 0);
    assert(ccw(P[0], P[2], P[4]) == 0);

    Point p(3, 7), q(11, 13), r(35, 30);
    assert(ccw(p, q, r) == -1);

    /*
    // the positions of these 6 points
     E<--  4
           3       B D<--
           2   A C
           1
    -4-3-2-1 0 1 2 3 4 5 6
          -1
          -2
    F<--   -3
    */

    // translation
    Point A(2.0, 2.0);
    Point B(4.0, 3.0);
    Point v = B - A;

    Point C(3.0, 2.0);
    Point D = C + v;
    assert(D == Point(5, 3));
    Point E = C + v * 0.5;
    assert(E == Point(4, 2.5));

    // rotation
    assert(B == Point(4, 3));
    Point F = B.rotate(DEG_to_RAD(90));
    assert(F == Point(-3, 4));
    Point G = B.rotate(DEG_to_RAD(180));
    assert(G == Point(-4, -3));

    cout << "All tests passed in test Point and Line" << endl;
}
void test_Circle(){
	// Example: Check point inside circle
    Circle C1(2, 2, 7);
    assert(cmp((C1 - Point(8, 2)).norm(), C1.r * C1.r) < 0);
    assert(cmp((C1 - Point(9, 2)).norm(), C1.r * C1.r) == 0);
    assert(cmp((C1 - Point(10, 2)).norm(), C1.r * C1.r) > 0);

    // Find common tangents
    Circle c2(1, 2, sqrt(5.0));
    Circle c3(5, 0, 0);

    vector<Line> t = tangents(c2, c3);
    assert(t.size() == 2);
    assert(cmp(t[0].f(Point(5, 0)), 0) == 0);
    assert(cmp(t[1].f(Point(5, 0)), 0) == 0);
    cout << "All tests passed in test Circle" << endl;
}
void test_Polygon(){
	cout << (fixed) << setprecision(9);
    Polygon P;
    P.push_back(Point(1, 1));
    P.push_back(Point(3, 3));
    P.push_back(Point(9, 1));
    P.push_back(Point(12, 4));
    P.push_back(Point(9, 7));
    P.push_back(Point(1, 7));

    // Basic methods
    assert(cmp(perimeter(P), 31.638263819) == 0);
    assert(cmp(area(P), 49.00) == 0);
    assert(!is_convex(P));

    // in_polygon
    //7 P5--------------P4
    //6 |                  \
    //5 |                    \
    //4 |   P7                P3
    //3 |   P1___            /
    //2 | / P6    \ ___    /
    //1 P0              P2
    //0 1 2 3 4 5 6 7 8 9 101112

    assert(in_polygon(P, Point(3, 4)));
    assert(!in_polygon(P, Point(3, 2)));

    // Polygon cutting
    //7 P5--------------P4
    //6 |               |  \
    //5 |               |    \
    //4 |               |     P3
    //3 |   P1___       |    /
    //2 | /       \ ___ |  /
    //1 P0              P2
    //0 1 2 3 4 5 6 7 8 9 101112
    // new polygon (notice the index are different now):
    //7 P4--------------P3
    //6 |               |
    //5 |               |
    //4 |               |
    //3 |   P1___       |
    //2 | /       \ ___ |
    //1 P0              P2
    //0 1 2 3 4 5 6 7 8 9

    P = polygon_cut(P, Line(P[2], P[4]));
    assert(cmp(perimeter(P), 29.152982445) == 0);
    assert(cmp(area(P), 40.00) == 0);

    // convex hull
    //7 P3--------------P2
    //6 |               |
    //5 |               |
    //4 |   P7          |
    //3 |               |
    //2 |               |
    //1 P0--------------P1
    //0 1 2 3 4 5 6 7 8 9

    P = convex_hull(P);
    assert(cmp(perimeter(P), 28.00) == 0);
    assert(cmp(area(P), 48.00) == 0);
    assert(is_convex(P));
    assert(in_convex(P, Point(3, 4)));
    assert(in_convex(P, Point(3, 2)));
    assert(!in_convex(P, Point(3, 1)));
    assert(!in_convex(P, Point(3, 0)));

    assert(in_polygon(P, Point(3, 4)));
    assert(in_polygon(P, Point(3, 2)));
    assert(!in_polygon(P, Point(3, 0)));

    P.clear();
    for(int i = 0; i < 10; ++i)
        for(int j = 0; j < 10; ++j)
            for(int turn = 0; turn < 3; ++turn)
                P.push_back(Point(i, j));
    P = convex_hull(P);
    assert(P.size() == 4);
    assert(P[0] == Point(0, 0));
    assert(P[1] == Point(9, 0));
    assert(P[2] == Point(9, 9));
    assert(P[3] == Point(0, 9));

    P.clear();
    for(int i = 0; i < 10; ++i)
        P.push_back(Point(7, 7 * i));
    P = convex_hull(P);
    assert(P.size() == 2);
    assert(P[0] == Point(7, 0));
    assert(P[1] == Point(7, 63));

    P.clear();
    for(int i = 0; i < 10; ++i)
        P.push_back(Point(7, 7));
    P = convex_hull(P);
    assert(P.size() == 1);
    assert(P[0] == Point(7, 7));
    cout << "All tests passed in test Polygon" << endl;
}
int main(){
	test_Point_Line();
	test_Circle();
	test_Polygon();
	return 0;
}
