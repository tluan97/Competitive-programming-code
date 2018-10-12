/*
	GRAHAM
	https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=622
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> Point;
#define X first
#define Y second

const int maxn = 10010;

Point O;
int n;
Point a[maxn];

void operator -= (Point &a,Point b){
	a.X-=b.X;
	a.Y-=b.Y;
}
bool ccw(Point o,Point a,Point b){
	a-=o; b-=o;
	return a.X*b.Y>a.Y*b.X;
}
bool cmp(Point a,Point b){
	return ccw(O,a,b);
}
void graham(){
	sort(a+1,a+n+1);
	O=a[1];
	sort(a+2,a+n+1,cmp);
	a[0]=a[n]; a[n+1]=a[1];
	int j=1;
	for (int i=1;i<=n+1;i++){
		while (j>2 && !ccw(a[j-2],a[j-1],a[i]))
			j--;
		a[j++]=a[i];
	}
	n=j-2;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int test; cin>>test;
	cout<<test<<"\n";
	while (test--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].X>>a[i].Y;
		}
		graham();
		int imin=1;
		for (int i=1;i<=n;i++){
			if (a[i].Y<a[imin].Y){
				imin=i;
			} else {
				if (a[i].Y==a[imin].Y && a[i].X<a[imin].X)
					imin=i;
			}
		}
		cout<<n+1<<"\n";
		for (int i=imin;i<=n;i++)
			cout<<a[i].X<<" "<<a[i].Y<<"\n";
		for (int i=1;i<=imin;i++)
			cout<<a[i].X<<" "<<a[i].Y<<"\n";
		if (test!=0){
			cin>>n;
			cout<<n<<"\n";
		}
	}
	return 0;
}
