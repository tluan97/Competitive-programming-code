
LL sumDigitBF(LL n){
	LL res=0;
	while (n){
		res+=n%10;
		n/=10;
	}
	return res;
}
LL sumDigit(LL n){
	if (n<=0) return 0;
	LL res;
	if (n%10==0){
		res=10LL*sumDigit(n/10)+45LL*(n/10);
	} else {
		res=sumDigit(n-1)+sumDigitBF(n-1);
	}
	return res;
}

