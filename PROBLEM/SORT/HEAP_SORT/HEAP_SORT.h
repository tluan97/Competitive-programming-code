
void heapify(int a[maxn],int n,int i){
	int m=i;
	int l=2*i;
	int r=2*i+1;
	if (l<n && a[l]>a[m]) m=l;
	if (r<n && a[r]>a[m]) m=r;
	if (m!=i){
		swap(a[i],a[m]);
		heapify(a,n,m);
	} 
}
void heap_sort(int a[maxn],int n){
	for (int i=n/2-1;i>=0;i--){
		heapify(a,n,i);
	}
	for (int i=n-1;i>=0;i--){
		swap(a[0],a[i]);
		heapify(a,i,0);
	}
}
