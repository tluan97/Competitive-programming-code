
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
