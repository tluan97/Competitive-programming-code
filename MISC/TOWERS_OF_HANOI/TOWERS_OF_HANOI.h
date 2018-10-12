
const int maxn = 200+1;	// disk
const int maxm = 64+1;	// peg
const unsigned long long oo = 1000111000111000111LL;
struct HanoiTower {
	unsigned long long t[maxn][maxm];
	void init(){
		for (int i=0;i<maxn;i++)
		if (i>=maxm-1) t[i][3]=oo;
		else t[i][3]=(1LL<<i)-1;
		for (int j=4;j<maxm;j++)
		for (int i=0;i<maxn;i++){
			t[i][j]=t[i][j-1];
			for (int k=i-1;k>=0;k--)
				t[i][j]=min(t[i][j],
					2LL*t[k][j]+t[i-k][j-1]);
		}
	}
}ht;
