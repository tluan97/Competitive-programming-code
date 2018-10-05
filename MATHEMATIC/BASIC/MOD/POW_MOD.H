
LL pow_mod(LL a,LL b,LL p){
	if (b==0) return (1%p);
	if (b==1) return (a%p);
	LL t=pow_mod(a,b>>1,p);
	t=(t*t)%p;
	if (b&1) return (t*a)%p;
	else return (t)%p;
}

