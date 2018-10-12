
LL mul_mod(LL a,LL b,LL p){
	if (b==0) return 0;
	if (b==1) return (a%p);
	LL t=mul_mod(a,b>>1,p);
	t=t+t;
	if (b&1) return (t+a)%p;
	else return (t)%p;
}
LL mul_mod_(LL a,LL b,LL p){
	LL c32,a0,b0,a1,b1;
	LL t,tt,jj,d[4]={};
	
	c32=(1LL<<32);
	a0=a%c32;b0=b%c32;
	a1=a>>32;b1=b>>32;
	
	t=a0*b0;
	d[0]=t%c32;tt=t>>32;
	t=(a0*b1+a1*b0)+tt;
	d[1]=t%c32;tt=t>>32;
	t=a1*b1+tt;
	d[2]=t%c32;d[3]=t>>32;
	t=(d[3]<<32|d[2])%p;
	
	for (LL i=1;i>=0;i--)
	for (LL j=7;j>=0;j--){
		jj=j*4;
		tt=(d[i]>>jj&15);
		t=(t<<4)|tt;
		t%=p;
	}
	return t;
}
