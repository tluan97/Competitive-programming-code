
LL mod_inv(LL a,LL m){
	LL x,y;
	extgcd(a,m,x,y);
	return (m+x%m)%m;
}
