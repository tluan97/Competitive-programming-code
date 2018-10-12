
const int B = 1024;

void count_sort(int a[], int n){
	static int a1[maxn], First[B], Last[B], Count[B];
	for (int i=0;i<B;i++) First[i]=Last[i]=Count[i]=0;
	for (int i=1;i<=n;i++) Count[a[i]%B]++;
	for (int i=1;i<B;i++) Last[i]=First[i]=First[i-1]+Count[i-1];
	for (int i=1;i<=n;i++) a1[++Last[a[i]%B]]=a[i];
	for (int i=1;i<=n;i++) a[i]=a1[i];
}
void bucket_sort(int a[], int n){ // 1-based
	static int a1[maxn], First[B], Last[B], Count[B];
	for (int i=0;i<B;i++) First[i]=Last[i]=Count[i]=0;
	for (int i=1;i<=n;i++) Count[a[i]>>10]++;
	for (int i=1;i<B;i++) Last[i]=First[i]=First[i-1]+Count[i-1];
	for (int i=1;i<=n;i++) a1[++Last[a[i]>>10]]=a[i];
	for (int i=0;i<B;i++) count_sort(a1+First[i], Count[i]);
	for (int i=1;i<=n;i++) a[i]=a1[i];
}
