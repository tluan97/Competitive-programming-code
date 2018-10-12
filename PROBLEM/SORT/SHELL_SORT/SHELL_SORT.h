
void shellSort(){
	for (int k=n/2;k>0;k/=2){
		for (int i=k,j;i<n;i++){
			float t=a[i];
			for (j=i;j>=k && a[j-k]>t;j-=k){
				a[j]=a[j-k];
			}
			a[j]=t;
		}
	}
}
