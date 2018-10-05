/*
	TOWERS_OF_HANOI
	http://vn.spoj.com/problems/CHNTOWER
	https://www.udebug.com/UVa/10444
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200+1;	// disk
const int maxm = 64+1;	// peg
const unsigned long long oo = 1000111000111000111;
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

void test_CHNTOWER(){
	unsigned long long n,m;
	cin>>n>>m;
	cout<<ht.t[n][m]<<"\n";
}
void test_uva10444(){
	unsigned long long n,m,t=0;
	while (cin>>n>>m && n|m){
		cout<<"Case "<<++t<<": "<<ht.t[n][m]<<"\n";
	}
}
int main(){
//	freopen("test.txt","r",stdin);
//	freopen("test.out.txt","w",stdout);
	ht.init();
	test_CHNTOWER();
//	test_uva10444(); //AC
}
