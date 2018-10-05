/*
	8_QUEENS
	tested
*/
#include <bits/stdc++.h>
using namespace std;

int a[9][9],b[9][9];
int r0,c0,h,_h;
int dr[]={0,0,1,0,-1,-1,1,1,-1};
int dc[]={0,1,0,-1,0,1,1,-1,-1};
bool sol=true;

void input(){
	int n,t;cin>>n;
	for (int i=1;i<=n;i++){
		cin>>t;
		a[i][0]=t;
	}
}
void output(){
	if (!sol){
		cout<<"No solution\n";
		return;
	}
	for (int i=1;i<=8;i++){
		cout<<a[i][0]<<"  ";
		for (int j=1;j<=8;j++){
			if (j==a[i][0]) cout<<"Q ";
			else cout<<"_ ";
		}	cout<<"\n";
	}	cout<<"\n";
}
void print(bool real){
	for (int i=1;i<=8;i++){
		for (int j=1;j<=8;j++){
			if (real) cout<<a[i][j]<<" ";
			else cout<<b[i][j]<<" ";
		}	cout<<"\n";
	}	cout<<"---------------\n";
}
void update(int i,int j,bool real){
	for (int z=1;z<=8;z++){
		for (int r=i,c=j;
			1<=r && r<=8 && 1<=c && c<=8;
			r+=dr[z],c+=dc[z])
			if (real) a[r][c]=1;
			else b[r][c]=1;
	}
}
int try_queen(int rr,int cc){
	int t=0;
	for (int i=1;i<=8;i++)
	for (int j=1;j<=8;j++)
		b[i][j]=a[i][j];
	update(rr,cc,0);
	for (int i=1;i<=8;i++)
	for (int j=1;j<=8;j++)
		if (b[i][j]==0)
			t++;
	return t;
}
void queens_8(){
	for (int i=1;i<=8;i++){
		if (a[i][0]==0){
			h=-1;
			for (int j=1;j<=8;j++){
				if (a[i][j]==0){
					_h=try_queen(i,j);
					if (_h>h){
						h=_h;
						r0=i; c0=j;
					}
				}
			}
			a[i][0]=c0;
			if (a[i][0]==a[i-1][0])
				sol=false;
		}
		update(i,a[i][0],1);
	}
}

int main(){
	freopen("8_QUEENS.INP","r",stdin);
	freopen("8_QUEENS.OUT","w",stdout);
	
	input();
	queens_8();
	output();
	
	return 0;
}
