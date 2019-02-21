
void merge(int a[maxn],int ll,int mm,int rr){
	int n1=mm-ll+1;
	int n2=rr-mm;
	int l[maxn]={},r[maxn]={};
	for (int i=1;i<=n1;i++){
		l[i]=a[ll+i-1];
	}
	l[n1+1]=oo;
	for (int i=1;i<=n2;i++){
		r[i]=a[mm+i];
	}
	r[n2+1]=oo;
	for (int k=ll,i=1,j=1;k<=rr;k++){
		if (l[i]<=r[j]){
			a[k]=l[i];
			i++;
		} else {
			a[k]=r[j];
			j++;
		}
	}
}
void merge_sort(int a[maxn],int ll,int rr){
	if (ll<rr){
		int mm=(ll+rr)/2;
		merge_sort(a,ll,mm);
		merge_sort(a,mm+1,rr);
		merge(a,ll,mm,rr);
	}
}
