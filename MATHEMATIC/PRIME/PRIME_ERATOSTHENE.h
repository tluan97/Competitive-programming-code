
bitset<maxn> b;
VLL primes;
LL ssize;
void eratosthene(LL upperbound){
	ssize=upperbound+1;
	b.set(); b[0]=b[1]=0;
	for (LL i=2;i<=ssize;i++)
	if (b[i]){
		for (LL j=i*i;j<=ssize;j+=i)
			b[j]=0;
		primes.push_back(i);
	}
}
bool isPrime(LL x){
	if (x<=ssize) return b[x];
	for (int i=0;i<primes.size();i++)
	if (x%primes[i]==0) return false;
	return true;
}
