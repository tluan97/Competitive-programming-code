
int sieve[maxn];
void modifiedSieve(){
	memset(sieve,0,sizeof(sieve));
	for (int i=2;i<maxn;i++)
	if (sieve[i]==0){
		for (int j=i;j<maxn;j+=i){
			sieve[j]++;
		}
	}
}
