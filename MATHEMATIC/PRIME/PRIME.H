
bool isPrime(int x){
	if (x==2 || x==3) return true;
	if (x==1 || x%2==0 || x%3==0) return false;
	int sqrtx = (int)sqrt(x);
	for (int i=5;i<=sqrtx;i+=6)
	if (x%i==0 || x%(i+2)==0) return false;
	return true;
}
bool RabinMiller(ULL n, int k){
	if (n<=50) return isPrime(n);
	ULL d=n-1, s=0;
	while (d%2==0) {s++; d/=2;}
	for (int i=1;i<=k;i++){
		ULL a = rand()%(n-2)+2;
		ULL x = pow_mod(a,d,n);
		if (x==1 || x==n-1) continue;
		for (int j=1;j<s;j++){
			x = (ULL)(x*x)%n;
			if (x==1) return false;
			if (x==n-1) break;
		}
		if (x!=n-1) return false;
	}
	return true;
}
