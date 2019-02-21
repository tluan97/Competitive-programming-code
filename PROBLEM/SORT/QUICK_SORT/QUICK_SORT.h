
void quick_sort(int a[maxn],int ll,int rr){
	int pivot=a[(ll+rr)/2];
	int i=ll,j=rr;
	while (i<=j){
		while (a[i]<pivot) i++;
		while (a[j]>pivot) j--;
		if (i<=j){
			swap(a[i],a[j]);
			i++;
			j--;
		}
	}
	if (ll<j) quick_sort(a,ll,j);
	if (i<rr) quick_sort(a,i,rr);
}
