#include<iostream>
#define cin std::cin
#define cout std::cout
#define NONE -1
#define oo 1e9
struct NODEMAX{	int imax,max;	};
struct NODEMIN{	int imin,min;	};
int lazy[4000007];
NODEMAX nodesmax[4000007];
NODEMIN	nodesmin[4000007];
int a[1000007];
void Down(int idx){
	int t=lazy[idx];	
	if(t==NONE){
		lazy[(idx<<1)]=t;	lazy[(idx<<1)|1]=t;	t=oo;
		nodesmax[(idx<<1)].max=-t;		nodesmax[(idx<<1)|1].max=-t;	
		nodesmin[(idx<<1)].min=t;		nodesmin[(idx<<1)|1].min=t;
	}
	else{
		lazy[(idx<<1)]+=t;	lazy[(idx<<1)|1]+=t;	lazy[idx]=0;
		nodesmax[(idx<<1)].max+=t;		nodesmax[(idx<<1)|1].max+=t;	
		nodesmin[(idx<<1)].min+=t;		nodesmin[(idx<<1)|1].min+=t;
	}
}
void Merge(int idx){
	if(nodesmax[(idx<<1)].max>=nodesmax[(idx<<1)|1].max){
		nodesmax[idx].max=nodesmax[(idx<<1)].max;
		nodesmax[idx].imax=nodesmax[(idx<<1)].imax;
	}
	else{
		nodesmax[idx].max=nodesmax[(idx<<1)|1].max;
		nodesmax[idx].imax=nodesmax[(idx<<1)|1].imax;
	}
	if(nodesmin[(idx<<1)].min<=nodesmin[(idx<<1)|1].min){
		nodesmin[idx].min=nodesmin[(idx<<1)].min;
		nodesmin[idx].imin=nodesmin[(idx<<1)].imin;
	}
	else{
		nodesmin[idx].min=nodesmin[(idx<<1)|1].min;
		nodesmin[idx].imin=nodesmin[(idx<<1)|1].imin;
	}
}
void Update(int idx,int l,int r,int u,int v,int val){
	if(v<l||r<u)	return;
	if(u<=l&&r<=v){
		if(val==NONE){	nodesmax[idx].max=-oo;	nodesmin[idx].min=oo;	lazy[idx]=val;	}
		else{	nodesmax[idx].max+=val;	nodesmin[idx].min+=val;	lazy[idx]+=val;	}
		return;
	}
	int m=(l+r)>>1;	Down(idx);
	Update((idx<<1),l,m,u,v,val);	Update((idx<<1)|1,m+1,r,u,v,val);
	Merge(idx);
}
int _imax,_imin,_max,_min;
void Get(int idx,int l,int r,int u,int v){
	if(v<l||r<u)	return;
	if(u<=l&&r<=v){
		_imax=nodesmax[idx].imax;	_imin=nodesmin[idx].imin;
		_max=nodesmax[idx].max;	_min=nodesmin[idx].min;
		return;
	}
	int m=(l+r)>>1;
	Down(m);
	Get((idx<<1),l,m,u,v);	Get((idx<<1)|1,m+1,r,u,v);
}
void Build(int idx,int l,int r){
	if(l==r){
		nodesmax[idx].imax=nodesmin[idx].imin=l;
		nodesmax[idx].max=nodesmin[idx].min=a[l];
		return;
	}
	int m=(l+r)>>1;
	Build((idx<<1),l,m);	Build((idx<<1)|1,m+1,r);
	Merge(idx);
}
void Test(int n){
	for(int i=1;i<=n;++i){
		_max=-oo;	_min=oo;	Get(1,1,n,i,i);	cout<<_max<<" ";
	}cout<<"\n";
}
int main(){
	freopen("IT.INP","r",stdin);
	freopen("IT.ANS","w",stdout);
	int n,r,m;	cin>>n>>r>>m;
	for(int i=1;i<=n;++i)	cin>>a[i];
	Build(1,1,n);
	_max=-oo;	_min=oo;
//	Test(n);
	Get(1,1,n,1,n);	
	for(int i=1;i<=m;++i){
		if(_max==-oo)	break;
		Update(1,1,n,std::max(1,_imin-r),std::min(n,_imin+r),1);
//		Test(n);
		_max=-oo;	_min=oo;	
		Get(1,1,n,1,n);	if(_max==-oo)	break;	
		Update(1,1,n,std::max(1,_imax-r),std::min(n,_imax+r),NONE);
	}
//	Test(n);
	Get(1,1,n,1,n);	
	int rs=std::max(0,_max);
	cout<<rs;
}
