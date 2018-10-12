
LL factorial(int n,LL mod){
	if (n<=1) return 1LL%mod;
	return mul_mod(n,factorial(n-1,mod),mod);
}

vector<LL> factors;
void init_factors(int maxn,LL mod){
	factors.clear();
	factors.push_back(1);
	LL temp;
	for (int i=1;i<=maxn;i++){
		temp=mul_mod(i,factors[i-1],mod);
		factors.push_back(temp);
	}
}
