/*
	SQRT_DECOMPOSITION_opt
	http://www.spoj.com/PTIT/problems/MBORECOL/
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
const int maxs = 1010;
const int oo = 1e9+7;

struct seg {
	int l, r, d;
	int min,imi;
	int max,ima;
};
int a[maxn];
seg b[maxs];
int sl,ns;

void recalcSeg(int i) {
	b[i].min = oo; b[i].max = -oo;
	for(int j = b[i].l, lj = b[i].r; j <= lj; j++) {
		if(a[j] == -1) continue;
		if(a[j] < b[i].min)
			b[i].min = a[j], b[i].imi = j;
		if(a[j] > b[i].max)
			b[i].max = a[j], b[i].ima = j;
	}
}
void buildSeg(int n) {
	sl = (int) ceil(sqrt(n));
	ns = (int) ceil(1.0 * n / sl);
	for(int i = 0; i < ns; i++) {
		b[i].l = i * sl;
		b[i].r = min(n - 1, (i + 1) * sl - 1);
		recalcSeg(i);
	}
}
void growSeg(int l, int r) {
	for(int i = 0; i < ns; i++) {
		if(b[i].d == -1) continue;
		
		if(b[i].l >= l && b[i].r <= r) b[i].d++;
		else if(l >= b[i].l && r <= b[i].r) {
			for(int j = l; j <= r; j++) {
				if(a[j] == -1) continue;
				a[j]++;
			}
			recalcSeg(i);
		}
		else {
			if(l <= b[i].r && r >= b[i].r) {
				for(int j = l, lj = b[i].r; j <= lj; j++) {
					if(a[j] == -1) continue;
					a[j]++;
				}
                recalcSeg(i);
			}
			if(l <= b[i].l && r >= b[i].l) {
				for(int j = b[i].l; j <= r; j++) {
					if(a[j] == -1) continue;
					a[j]++;
				}
                recalcSeg(i);
            }
		}
    }
}
void remvSeg(int l, int r) {
	for(int i = 0; i < ns; i++) {
		if(b[i].d == -1) continue;
		
		if(b[i].l >= l && b[i].r <= r) {
			b[i].d = -1;
			b[i].min = oo; b[i].max = -oo;
		}
		else if(l >= b[i].l && r <= b[i].r) {
			for(int j = l; j <= r; j++)
				a[j] = -1;
			recalcSeg(i);
		} 
		else {
			if(l <= b[i].r && r >= b[i].r) {
				for(int j = l, lj = b[i].r; j <= lj; j++)
					a[j] = -1;
				recalcSeg(i);
			}
			if(l <= b[i].l && r >= b[i].l) {
				for(int j = b[i].l; j <= r; j++)
					a[j] = -1;
				recalcSeg(i);
			}
		}
	}
}
int getMin(bool val) {
	int imi, mi = oo, t;
	for(int i = 0; i < ns; i++) {
		t = b[i].min + b[i].d;
		if(t < mi) {
			mi = t;
			imi = b[i].imi;
		}
	}
	return (val)?mi:imi;
}
int getMax(bool val) {
	int ima, ma = -oo, t;
	for(int i = 0; i < ns; i++) {
		t = b[i].max + b[i].d;
 		if(t > ma) {
			ma = t;
			ima = b[i].ima;
		}
	}
	return (val)?ma:ima;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, r, m;
	scanf("%d %d %d", &n, &r, &m);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	buildSeg(n);
	for(int i = 0; i < m; i++) {
		int imi = getMin(0);
		growSeg(max(imi - r, 0), min(n - 1, imi + r));
		int ima = getMax(0);
		remvSeg(max(ima - r, 0), min(n - 1, ima + r));
	}
	int rs = max(0,getMax(1));
	cout << rs;
	
	return 0;
}
