
void radixsort(int a[],int b[],int n,int k){
	int Count[256]={}, Start[256]={};
	for (int i=1;i<=n;i++)
		Count[(a[i]>>k)&255]++;
	for (int i=1;i<=255;i++)
		Start[i]=Start[i-1]+Count[i-1];
	for (int i=1;i<=n;i++)
		b[++Start[(a[i]>>k)&255]]=a[i];
}
void radixsort(){
	radixsort(a,b,n,0);
	radixsort(b,a,n,8);
	radixsort(a,b,n,16);
	radixsort(b,a,n,24);
}
