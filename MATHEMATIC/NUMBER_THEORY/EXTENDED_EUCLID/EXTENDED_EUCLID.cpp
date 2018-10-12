/*
	EXTENDED_EUCLID
	uva 10104
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a,LL b){
	return (b==0)?a:gcd(b,a%b);
}

// 	Dùng Extended Euclid để tìm nghiệm 
//		của phương trình ax + by = gcd(a, b).
// 	Giả sử kết quả trả về là (x0, y0), 
//		họ nghiệm của phương trình 
//		sẽ là (x_0+kb/d,y_0-ka/d) với k∈Z.
// 	Phương trình tổng quát ax + by = d 
//		chỉ có nghiệm khi d chia hết cho gcd(a, b).
// 	a x + b y = gcd(a, b)
LL extgcd(LL a, LL b, LL &x, LL &y){
	LL g = a; x = 1; y = 0;
	if (b != 0){
		g = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	return g;
}

void test_EXTENDED_EUCLID(){
	LL a,b,x,y;
	for (int t=0;t<100000;t++){
		a=rand();
		b=rand();
		extgcd(a,b,x,y);
		if (a*x+b*y!=gcd(a,b)){
			cout<<a<<" "<<b<<"  FAIL\n";
		}
	}
	cout<<"DONE\n";
}
void uva10104(){
	LL a,b,x,y,d;
	while (cin>>a>>b){
		extgcd(a,b,x,y);
		d=gcd(a,b);
		cout<<x<<" "<<y<<" "<<d<<"\n";
	}
}
int main(){
//	test_EXTENDED_EUCLID();
	uva10104();
	return 0;
}
