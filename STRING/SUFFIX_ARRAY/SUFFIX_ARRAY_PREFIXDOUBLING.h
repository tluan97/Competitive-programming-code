
string s;
int n,Rank[logmaxn][maxn];
int SA[logmaxn][maxn],SA1[maxn];
void radixsort(int a[],int b[],int n,int r[],int k){
	vector<int> Count(k+1),Start(k+1);
	for (int i=0;i<n;i++)
		Count[r[a[i]]]++;
	for (int i=1;i<=k;i++)
		Start[i]=Start[i-1]+Count[i-1];
	for (int i=0;i<n;i++)
		b[Start[r[a[i]]]++]=a[i];
}
void suffix(){
	for (int i=0;i<n;i++) Rank[0][i]=s[i];
	for (int i=0;i<n;i++) SA1[i]=i;
	radixsort(SA1,SA[0],n,Rank[0],128);
	int Name=128, Gap=1;
	for (int k=1;k<=17;k++){
		radixsort(SA[k-1],SA1,n,Rank[k-1]+Gap,Name);
		radixsort(SA1,SA[k],n,Rank[k-1],Name);
		Name=0;
		for (int i=0;i<n;i++){
			if (i==0 || 
		Rank[k-1][SA[k][i]]!=Rank[k-1][SA[k][i-1]] || 
		Rank[k-1][SA[k][i]+Gap]!=Rank[k-1][SA[k][i-1]+Gap])
				Name++;
			Rank[k][SA[k][i]]=Name;
		}
		Gap*=2;
	}
}
