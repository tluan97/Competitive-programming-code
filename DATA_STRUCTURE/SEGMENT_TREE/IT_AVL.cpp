/*
	IT_AVL
	http://vn.spoj.com/problems/QMAX3VN/
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5+10;
const int oo = 1000111000;

int Max[maxn],Size[maxn],Height[maxn];
int Left[maxn],Right[maxn],Peak;

void update(int id){
	int ll=Left[id],rr=Right[id];
	Max[id]=max(Max[ll],Max[rr]);
	Size[id]=Size[ll]+Size[rr];
	Height[id]=max(Height[ll],Height[rr])+1;
}
int create(int Value){
	int id = ++Peak;
	Max[id]=Value;
	Size[id]=1;
	return id;
}
int link(int ll,int u,int rr){
	Left[u]=ll,Right[u]=rr;
	return update(u),u;
}
int right_rotate(int u){ 
	int ll = Left[u]; 
	return link(Left[ll],ll,link(Right[ll],u,Right[u]));
}
int left_rotate(int u){
	int rr = Right[u];
	return link(link(Left[u],u,Left[rr]),rr,Right[rr]);
}
int balance(int u){
	if (abs(Height[Left[u]]-Height[Right[u]])<=1) return u;
	//Left[u]=balance(Left[u]); // to be careful
	//Right[u]=balance(Right[u]);
	bool x=Height[Left[u]]>Height[Right[u]];
	int v=(x?Left[u]:Right[u]);
	bool y=Height[Left[v]]>Height[Right[v]];
	if (x && y) u=right_rotate(u);
	if (!x && !y) u=left_rotate(u);
	if (x && !y) {
		Left[u]=v=left_rotate(v);
		u=right_rotate(u);
	}
	if (!x && y) {
		Right[u]=v=right_rotate(v);
		u=left_rotate(u);
	}
	return u;
}
struct node {
	int ll,rr,id;
	node (int L,int X) 
	{ ll=L,id=X; rr=ll+Size[id]-1; }
	node left()
	{ return node(ll,Left[id]); }
	node right()
	{ return node(ll+Size[Left[id]],Right[id]); }
	
	void insert(int u,int Value) {
		if (ll>u || u>rr) return ;
		if (ll==rr) {
			Left[id]=create(Value);
			Right[id]=create(Max[id]);
			update(id); return ;
		}
		left().insert(u,Value);
		right().insert(u,Value);
		Left[id]=balance(Left[id]);
		Right[id]=balance(Right[id]);
		update(id);	
	}
	int max_range(int L,int R) {
		if (L>rr || ll>R || L>R) return -oo;
		if (L<=ll && rr<=R) return Max[id];
		int Max1 = left().max_range(L,R);
		int Max2 = right().max_range(L,R);
		return max(Max1,Max2);
	}
};
ostream& operator<<(ostream& cout,node a){
	if (a.ll==a.rr) return cout<<Max[a.id];
	return cout<<"("<<a.left()<<" "<<a.right()<<")";
	//return cout<<a.left()<<" "<<a.right();
}

void QMAX3VN(){
	create(-oo);
	int m; cin>>m;
	while (m--){
		char c; int x,y;
		cin>>c>>x>>y;
		if (c=='A') node(1,1).insert(y,x);
		else cout<<node(1,1).max_range(x,y)<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	QMAX3VN();
	return 0;
}
