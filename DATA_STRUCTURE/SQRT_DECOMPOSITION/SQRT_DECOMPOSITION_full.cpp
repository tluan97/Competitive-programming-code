/*
	SQRT_DECOMPOSITION_full
	---
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
const int maxnb = 1010;
const int oo = ~(1<<31);
const int nul = -oo;

struct SqrtArray{
	
	int a[maxn],n,sn,nb;
	struct Block{
		int l,r,d;
		int mi,imi;
		int ma,ima;
		int sum;
	}b[maxnb];
	
	void recalcIndex(int i){
		int j=i/sn;
		if (b[j].mi>a[i]) 
			b[j].mi=a[i],b[j].imi=i;
		if (b[j].ma<a[i]) 
			b[j].ma=a[i],b[j].ima=i;
	}
	void recalcBlock(int j){
		if (b[j].d==nul) return;
		b[j].mi=oo; b[j].ma=-oo;
		b[j].sum=0;
		for (int i=b[j].l;i<=b[j].r;i++){
			if (a[i]==nul) continue;
			recalcIndex(i);
			b[j].sum+=a[i];
		}
	}
	void buildBlock(int arr[maxn],int nn){
		n=nn; sn=(int)sqrt(n); nb=n/sn;
		for (int i=0;i<n;i++) a[i]=arr[i];
		for (int j=0;j<nb;j++){
			b[j].l=j*sn; 
			b[j].r=(j+1)*sn-1;
			b[j].d=0;
			b[j].sum=0;
			recalcBlock(j);
		}
	}
	
	void setIndex(int i,int v){
		if (a[i]==nul) return;
		int j=i/sn;
		b[j].sum+=v-a[i]; a[i]=v;
		recalcIndex(i);
	}
	void setBlock(int j,int v){
		b[j].d=0;
		for (int i=b[j].l;i<=b[j].r;i++){
			if (a[i]==nul) continue;
			a[i]=v;
		}
		recalcBlock(j);
	}
	void updateIndex(int i,int v){
		if (a[i]==nul) return;
		int j=i/sn;
		b[j].sum+=v; a[i]+=v;
		recalcIndex(i);
	}
	void updateBlock(int j,int v){
		b[j].d+=v;
	}
	void eraseIndex(int i){
		a[i]=nul;
	}
	void eraseBlock(int j){
		b[j].d=nul;
	}
	
	void set(int l,int r,int v){
		while (l<r && l%sn!=0){
			setIndex(l,v); l++;
		}
		while (l+sn<=r){
			setBlock(l/sn,v); l+=sn;
		}
		while (l<=r){
			setIndex(l,v); l++;
		}
	}
	void update(int l,int r,int v){
		while (l<r && l%sn!=0){
			updateIndex(l,v); l++;
		}
		while (l+sn<=r){
			updateBlock(l/sn,v); l+=sn;
		}
		while (l<=r){
			updateIndex(l,v); l++;
		}
	}
	void erase(int l,int r){
		int bl=l/sn,br=r/sn;
		while (l<r && l%sn!=0){
			eraseIndex(l); l++;
		}
		while (l+sn<=r){
			eraseBlock(l/sn); l+=sn;
		}
		while (l<=r){
			eraseIndex(l); l++;
		}
		recalcBlock(bl);
		recalcBlock(br);
	}
	
	int getMin(int l,int r,bool v){
		int bl=l/sn,br=r/sn;
		int mi=oo,imi,j,t;
		while (l<r && l%sn!=0)
		if (b[bl].d!=nul && a[l]!=nul){
			t=a[l]+b[bl].d;
			if (t<mi)
				mi=t,imi=l;
			l++;
		}else l++;
		while (l+sn<=r)
		if (b[l/sn].d!=nul){
			j=l/sn;
			t=b[j].mi+b[j].d;
			if (t<mi)
				mi=t,imi=b[j].imi;
			l+=sn;
		}else l+=sn;
		while (l<=r)
		if (b[br].d!=nul && a[l]!=nul){
			t=a[l]+b[br].d;
			if (t<mi)
				mi=t,imi=l;
			l++;
		}else l++;
		return (v)?mi:imi;
	}
	int getMax(int l,int r,bool v){
		int bl=l/sn,br=r/sn;
		int ma=-oo,ima,j,t;
		while (l<r && l%sn!=0)
		if (b[bl].d!=nul && a[l]!=nul){
			t=a[l]+b[bl].d;
			if (t>ma)
				ma=t,ima=l;
			l++;
		}else l++;
		while (l+sn<=r)
		if (b[l/sn].d!=nul){
			j=l/sn;
			t=b[j].ma+b[j].d;
			if (t>ma)
				ma=t,ima=b[j].ima;
			l+=sn;
		}else l+=sn;
		while (l<=r)
		if (b[br].d!=nul && a[l]!=nul){
			t=a[l]+b[br].d;
			if (t>ma)
				ma=t,ima=l;
			l++;
		}else l++;
		return (v)?ma:ima;
	}
	int getSum(int l,int r){
		int bl=l/sn,br=r/sn;
		int s=0,j,t;
		while (l<r && l%sn!=0)
		if (b[bl].d!=nul && a[l]!=nul){
			t=a[l]+b[bl].d;
			s+=t;
			l++;
		}else l++;
		while (l+sn<=r)
		if (b[l/sn].d!=nul){
			j=l/sn;
			t=b[j].sum+b[j].d*sn;
			s+=t;
			l+=sn;
		}else l+=sn;
		while (l<=r)
		if (b[br].d!=nul && a[l]!=nul){
			t=a[l]+b[br].d;
			s+=t;
			l++;
		}else l++;
		return s;
	}
	
	void print(){
		for (int i=0;i<n;i++){
			if (a[i]!=nul && b[i/sn].d!=nul){
				cout<<a[i]+b[i/sn].d<<" ";
			} else cout<<"-1 ";
		}
		cout<<"\n";
	}
	
}sqrta;

int main()
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	int n=10;
	
	sqrta.buildBlock(a,n);
	sqrta.print(); 			// 0,1,2,3,4,5,6,7,8,9 
	
	sqrta.setIndex(2,4);
	sqrta.set(4,7,5);
	sqrta.print();			// 0,1,4,3,5,5,5,5,8,9
	
	sqrta.updateIndex(2,-1);
	sqrta.update(5,9,1);
	sqrta.print();			// 0,1,3,3,5,6,6,6,9,10
	
	sqrta.eraseIndex(1);
	sqrta.erase(3,5);
	sqrta.print();			// 0,-1,3,-1,-1,-1,6,6,9,10
	
	cout<<sqrta.getMin(0,2,1)<<endl;	// 0
	cout<<sqrta.getMax(2,6,1)<<endl;	// 6
	cout<<sqrta.getSum(4,9)<<endl;		// 31
	
	return 0;
}
