/*
	8_PUZZLE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int oo = 1000111000;

int a[4][4],b[4][4];
int r0,c0,g,h,_h,z0,zp,t,h_old;
int dr[]={0,0,1,-1,0};
int dc[]={0,1,0,0,-1};
int p[9][2];

void input(){
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++){
		cin>>a[i][j];
		if (a[i][j]==0){
			r0=i; c0=j;
		}
	}
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++){
		cin>>t;
		p[t][0]=i;
		p[t][1]=j;
	}
}
void output(){
	cout<<"g="<<g<<" ";
	cout<<"h="<<h<<" ";
	cout<<"f="<<g+h<<"\n";
	for (int i=1;i<=3;i++){
		for (int j=1;j<=3;j++){
			cout<<a[i][j]<<" ";
		}	cout<<"\n";
	}	cout<<"\n";
	cout<<"---------------\n";
}
bool check(int z){
	if (r0+dr[z]<1 || 3<r0+dr[z] ||
		c0+dc[z]<1 || 3<c0+dc[z])
		return false;
	return true;
}
int try_taci(int z){
	int t=0,ii,jj;
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++)
		b[i][j]=a[i][j];
	b[r0][c0]=b[r0+dr[z]][c0+dc[z]];
	b[r0+dr[z]][c0+dc[z]]=0;
	
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++){
		if (b[i][j]==0) continue;
		ii=p[b[i][j]][0];
		jj=p[b[i][j]][1];
		t+=(abs(ii-i)+abs(jj-j));
//		t+=(abs(ii-i)+abs(jj-j)==0)?0:1;
	}
	return t;
}
void puzzle_8(){
	output();
	for (g=1;;g++){
		h_old=h;
		h=oo; zp=z0; z0=0;
		for (int z=1;z<=4;z++){
			if (z!=5-zp && check(z)){
				_h=try_taci(z);
				if (_h<h){
					h=_h; z0=z;
				}
			}
		}
		a[r0][c0]=a[r0+dr[z0]][c0+dc[z0]];
		a[r0+dr[z0]][c0+dc[z0]]=0;
		r0+=dr[z0]; c0+=dc[z0];
		output();
		if (h_old<h && g>1){
			cout<<"No solution\n";
			return;
		}
		if (h==0) break;
	}
}

int main(){
	freopen("8_PUZZLE.INP","r",stdin);
	freopen("8_PUZZLE.OUT","w",stdout);
	
	input();
	puzzle_8();
//	output();
	
	return 0;
}
