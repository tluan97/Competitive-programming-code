
const int maxc = 41;
const LL base = 1e15;
struct bignum_ {
	LL l,h;
	void operator+=(const bignum_ &a){
		l+=a.l; h+=a.h;
		h+=l/base;
		l%=base;
	}
	void operator/=(LL x){
		l+=(h%x)*base;
		h/=x; l/=x; 
	}
	void operator=(LL x){
		h=0; l=x;
	}
	void load(){
		char s[maxc]; scanf("%s",s);
		int n=strlen(s);
		if (n>15){
			sscanf(s+n-15,"%lld",&l);
			s[n-15]=0;
			sscanf(s,"%lld",&h);
		} else {
			h=0;
			sscanf(s,"%lld",&l);
		}
	}
	void show(){
		if (h==0) printf("%lld",l);
		else printf("%lld%015lld",h,l);
	}
};
