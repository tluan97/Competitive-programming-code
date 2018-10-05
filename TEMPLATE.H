#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<
	int,null_type,less<int>,rb_tree_tag,
	tree_order_statistics_node_update>
ordered_set;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> II;
typedef pair<int,II> III;
typedef vector<int> VI;
typedef vector<II> VII;
typedef vector<VI> VVI;
typedef vector<VII> VVII;
typedef vector<LL> VLL;
typedef pair<double,double> point;
#define X first
#define Y second
#define double long double

const int oo = 1000111000;
const LL oooo = 1000111000111000111LL;
const int nul = -1;
const int mod = 1000000007;
const LL lmod = 1000000000000000007LL;
const int base = 2309;
const int maxn = 1010;
const double PI = acos(-1.0);
const double EPS = 1e-9;

void setup(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("FILE.INP","r",stdin);
	freopen("FILE.OUT","w",stdout);
}
void ___(){
	cout<<(fixed)<<setprecision(9)<<boolalpha;
}
