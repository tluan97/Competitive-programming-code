// Original Recurrence:
//   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i
// Condition:
//   b[j] >= b[j+1]
//   a[i] <= a[i+1]
// To solve:
// Hull hull;
// FOR(i,1,n) {
//   dp[i] = hull.get(a[i]);
//   hull.add(b[i], dp[i]);
// }

const int maxn = 100100;

struct Hull {
	LL a[maxn], b[maxn];
	double x[maxn];
	int head, tail;

	Hull(): head(1), tail(0) {}

	LL get(LL xQuery) {
		if (head > tail) return 0;
		while (head < tail && x[head + 1] <= xQuery) head++;
		x[head] = xQuery;
		return a[head] * xQuery + b[head];
	}
	void add(LL aNew, LL bNew) {
		double xNew = -1e18;
		while (head <= tail) {
			if (aNew == a[tail]) return;
			xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
			if (head == tail || xNew >= x[tail]) break;
			tail--;
		}
		a[++tail] = aNew;
		b[tail] = bNew;
		x[tail] = xNew;
	}
};
