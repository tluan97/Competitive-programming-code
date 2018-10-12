/*
	BASIC_3D
	http://www.spoj.com/problems/CH3D/
*/
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;

// Quay điểm P quanh trục vector đơn vị (x,y,z) 1 góc a
// [ txx + c  | txy – sz | txz + sy ]
// [ txy + sz | tyy + c  | tyz – sx ]
// [ txz - sy | tyz + sx | tzz + c  ]
// Với: c = cos(a), s = sin(a), t = 1 – cos(a)

inline double det(double a, double b, double c, double d) {
	return a * d - b * c;
}
struct Point3 {
	double x, y, z;
	
	// http://mathworld.wolfram.com/images/eps-gif/SphericalCoordinates_1201.gif
	struct Spherical {
		double r,
		theta,	// 0 <= theta < 2*PI
		phi;	// 0 <= phi <= PI
	
		Spherical(Point3 P) {
			r = sqrt(P.x*P.x + P.y*P.y + P.z*P.z);
			theta = atan(P.y / P.x); 
			if (theta < 0) theta += 2 * PI;
			phi = acos(P.z / r);
		}
	};
	
	Point3() { x = y = z = 0; }
	Point3(double x, double y, double z) : x(x), y(y), z(z) {}
	Point3(Spherical P) {
		x = P.r * cos(P.theta) * sin(P.phi);
		y = P.r * sin(P.theta) * sin(P.phi);
		z = P.r * cos(P.phi);
	}
	
	double length() {
		return sqrt(x * x + y * y + z * z);
	}
	Point3 operator * (double k) const { return Point3(x*k, y*k, z*k); }

	double operator * (Point3 a) const { return x*a.x + y*a.y + z*a.z; }
	Point3 operator + (Point3 a) { return Point3(x+a.x, y+a.y, z+a.z); }
	Point3 operator - (Point3 a) { return Point3(x-a.x, y-a.y, z-a.z); }
	Point3 operator %(const Point3 &op) const {
		return Point3(	
			det(y, z, op.y, op.z), 
		   -det(x, z, op.x, op.z), 
			det(x, y, op.x, op.y));
	}
};
struct Space {
	double a, b, c, d;
	Space(Point3 p0, Point3 p1, Point3 p2) {
		a = p0.y * (p1.z - p2.z) + p1.y * (p2.z - p0.z) + p2.y * (p0.z - p1.z);
		b = p0.z * (p1.x - p2.x) + p1.z * (p2.x - p0.x) + p2.z * (p0.x - p1.x);
		c = p0.x * (p1.y - p2.y) + p1.x * (p2.y - p0.y) + p2.x * (p0.y - p1.y);
		d = - p0.x * (p1.y * p2.z - p2.y * p1.z) 
			- p1.x * (p2.y * p0.z - p0.y * p2.z) 
			- p2.x * (p0.y * p1.z - p1.y * p0.z);
	}
};
// Chiếu vector v lên vector u
Point3 projection(Point3 v, Point3 u) { 
	double scalar = (v * u) / (u * u);
	return u * scalar;
}
// Chiếu điểm p lên mặt phẳng ABC
Point3 projection(Point3 p, Point3 a, Point3 b, Point3 c) { 
	Point3 u = (b - a) % (c - a), v = p - a;
	double scalar = (v * u) / (u * u);
	return p - (u * scalar);
}
// Khoảng cách từ p tới đường thẳng AB
double dist(Point3 p, Point3 a, Point3 b) { 
	p = p - a;
	Point3 proj = projection(p, b - a);
	return sqrt(p * p - proj * proj);
}
// Diện tích tam giác ABC
double area(Point3 a, Point3 b, Point3 c) { 
	double h = dist(a, b, c);
	return (h * (b - c).length()) / 2;
}
// Thể tích của 3 vector 
double volume(Point3 x, Point3 y, Point3 z) { 
	Point3 base = Point3(
		y.y * z.z - y.z * z.y, 
		y.z * z.x - y.x * z.z, 
		y.x * z.y - y.y * z.x);
	return fabs(x.x * base.x + x.y * base.y + x.z * base.z) / 3;
}
// Diện tích của đa giác lồi P
double area(vector<Point3> P){
	double res = 0.0;
	for (int i=1;i<P.size()-1;i++){
		res+=area(P[0],P[i],P[i+1]);
	}
	return res;
}
// 
// V - E + F = 2  |  E <= 3V – 6  |  F <= 2V - 4

// 3D convex hull
inline int sign(double x) 
	{ return x < -eps ? -1 : x > eps ? 1 : 0; }
vector<Point3> arr;
vector<int> rnd;
set<int> used;

typedef vector<int> Side;
Side getFirstSide(vector<Point3> &p) {
	int i1 = 0;
	for (int i=0;i<p.size();i++) {
		if (p[i].z < p[i1].z || (p[i].z == p[i1].z && p[i].x < p[i1].x)
		|| (p[i].z == p[i1].z && p[i].x == p[i1].x && p[i].y < p[i1].y)) {
			i1 = i;
		}
	}
	int i2 = (i1 == 0) ? 1 : 0;
	for (int i=0;i<p.size();i++) {
		if (i != i1) {
			Point3 zDir(0, 0, 1);
			double curCos = (p[i] - p[i1]) * zDir / (p[i] - p[i1]).length();
			double bestCos = (p[i2] - p[i1]) * zDir / (p[i2] - p[i1]).length();
			if (curCos < bestCos) {
				i2 = i;
			}
		}
	}
	int i3 = -1;
	int n = p.size();
	for (int ri=0;ri<n;ri++) {
		int i = rnd[ri];
		if (i != i1 && i != i2) {
			Point3 norm = (p[i1] - p[i]) % (p[i2] - p[i]);
			bool sg[] = { 0, 0, 0 };
			for (int t=0;t<n;t++) {
				int j = rnd[t];
				sg[1 + sign((p[j] - p[i]) * norm)] = true;
				if (sg[0] && sg[2]) {
					break;
				}
			}
			if (sg[0] ^ sg[2]) {
				i3 = i;
				if (!sg[0]) {
					swap(i3, i2);
				}
				break;
			}
		}
	}
	vector<int> res;
	res.push_back(i1);
	res.push_back(i2);
	res.push_back(i3);
	return res;
}

inline int getSideKey(int i, int j, int k) {
	int key = (i * 1000 + j) * 1000 + k;
	return key;
}
inline bool isUsed(int i, int j, int k) {
	return used.find(getSideKey(i, j, k)) != used.end();
}
inline double getAngle(const Point3 &n1, const Point3 &n2) {
	return atan2((n1 % n2).length(), n1 * n2);
}
inline double getNormsAngle(int i, int j, int k, int t, vector<Point3> &p) {
	Point3 n1 = (p[j] - p[i]) % (p[k] - p[i]);
	Point3 n2 = (p[t] - p[i]) % (p[j] - p[i]);
	return getAngle(n1, n2);
}

void dfs(int i, int j, int k, vector<Point3> &p, vector<Side> &sides) {
	if (i < j && i < k) {
		vector<int> side(3);
		side[0] = i;
		side[1] = j;
		side[2] = k;
		sides.push_back(side);
	}
	int key = getSideKey(i, j, k);
	used.insert(key);
	int n = p.size();
	if (!isUsed(j, k, i))
		dfs(j, k, i, p, sides);
	if (!isUsed(k, i, j))
		dfs(k, i, j, p, sides);

	int bestT = -1;
	double bestAngle = 1e20;
	Point3 curNorm = (p[j] - p[i]) % (p[k] - p[i]);
	Point3 dir = p[j] - p[i];
	for (int t=0;t<n;t++) {
		if (t != i && t != j && t != k) {
			Point3 newNorm = (p[t] - p[i]) % dir;
			double curAng = curNorm * newNorm / newNorm.length();
			if (bestT == -1 || curAng > bestAngle) {
				bestT = t;
				bestAngle = curAng;
			}
		}
	}
	if (!isUsed(i, bestT, j)) {
		dfs(i, bestT, j, p, sides);
	}
}
vector<Side> convexHull3d(vector<Point3> p) {
	used.clear();
	rnd.resize(p.size());
	for (int i=0;i<p.size();i++)
		rnd[i] = i;
	random_shuffle(rnd.begin(), rnd.end());
	Side side0 = getFirstSide(p);
	vector<Side> sides;

	dfs(side0[0], side0[1], side0[2], p, sides);
	return sides;
}

/* eliminate conflict sides */
inline bool isEmpty(Point3 x, Point3 y, Point3 z) {
	return abs(x * Point3(
		y.y * z.z - y.z * z.y, 
		y.z * z.x - y.x * z.z, 
		y.x * z.y - y.y * z.x)) <= eps;
}
inline bool conflict(Side a, Side b) {
	Point3 x = arr[a[0]], y = arr[a[1]], z = arr[a[2]];
	for (int i=0;i<3;i++) {
		Point3 t = arr[b[i]];
		if (!isEmpty(x - t, y - t, z - t))
			return false;
	}
	return true;
}
vector<Side> eliminate(vector<Side> p) {
	vector<Side> res;
	vector<bool> fre;
	fre.resize(p.size(), true);
	for (int i=0;i<p.size();i++) {
		if (!fre[i]) continue;
		res.push_back(p[i]);
		for (int j=i+1;j<p.size();j++)
			if (fre[j]) {
				if (conflict(p[i], p[j])) {
					fre[j] = false;
					res.back().insert(
						res.back().end(), 
						p[j].begin(), 
						p[j].end());
				}
			}
	}
	for (int i=0;i<res.size();i++) {
		sort(res[i].begin(), res[i].end());
		res[i].resize(
			unique(res[i].begin(), res[i].end())
			- res[i].begin());
	}
	return res;
}
// End of 3D convex hull

void print(Point3 p){
	printf("(%.4f,%.4f,%.4f)\n",p.x,p.y,p.z);
}
void test_CH3D(){
	freopen("CH3D.INP","r",stdin);
//	freopen("CH3D.OUT","w",stdout);
	int test,n; 
	double x,y,z;
	vector<Point3> p;
	scanf("%d",&test);
	while (test--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%f %f %f",&x,&y,&z);
			p.push_back(Point3(x,y,z));
		}
	}
	for (int i=0;i<p.size();i++){
		print(p[i]);
	}
	// find convex hull
	vector<Side> hull = convexHull3d(p); 
	// find the surface area
	double areaHull=0.0;
	vector<Point3> tmp;
	for (int s=0;s<hull.size();s++){
		tmp.clear();
		for (int j=0;j<hull[s].size();j++){
			tmp.push_back(p[hull[s][j]]);
			print(p[hull[s][j]]);
		}
		cout<<"\n";
		areaHull+=area(tmp);
	}
	cout<<areaHull<<"\n";
}
int main(){
	test_CH3D();
}
