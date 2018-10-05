/*
	KNIGHT_TOUR
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int oo = 1000111000;
const int maxn = 10010;

int a[maxn][maxn],b[maxn][maxn];
int m,n,r0,c0,h,_h,z0;
int dr[]={0,-2,-1,1,2,2,1,-1,-2};
int dc[]={0,1,2,2,1,-1,-2,-2,-1};
bool sol=true;

bool check(int r,int c,int z){
	if (r+dr[z]<1 || m<r+dr[z] ||
		c+dc[z]<1 || n<c+dc[z] ||
		a[r+dr[z]][c+dc[z]]!=0)
		return false;
	return true;
}
void input(){
	cin>>m>>n>>r0>>c0;
}
void output(){
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			printf("%4d",a[i][j]);
		}	cout<<"\n";
	}	cout<<"---------------\n";
	
	if (!sol){
		cout<<"Khong co duong di Hamilton\n";
	} else {
		bool tour=false;
		for (int z=1;z<=8;z++){
			if (check(r0,c0,z) && a[r0+dr[z]][c0+dc[z]]==1){
				tour=true;
				z=9;
			}
		}
		if (tour) cout<<"Co chu trinh Hamilton\n";
		else cout<<"Co duong di Hamilton\n";
	}
}
int try_knight_tour(int s,int z){
	int t=0;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		b[i][j]=a[i][j];
	int r=r0+dr[z],c=c0+dc[z];
	b[r][c]=s;
	for (int _z=1;_z<=8;_z++)
		if (check(r,c,_z))
			t++;
	return t;
}
void knight_tour(){
	a[r0][c0]=1;
	for (int i=2;i<=m*n;i++){
		h=oo; z0=0;
		for (int z=1;z<=8;z++){
			if (check(r0,c0,z)){
				_h=try_knight_tour(i,z);
				if (_h<h){
					h=_h;
					z0=z;
				}
			}
		}
		r0+=dr[z0];
		c0+=dc[z0];
		a[r0][c0]=i;
		if (z0==0){
			sol=false;
			return;
		}
	}
}

int main(){
	freopen("KNIGHT_TOUR.INP","r",stdin);
	freopen("KNIGHT_TOUR.OUT","w",stdout);
	
	input();
	knight_tour();
	output();
	
	return 0;
}
