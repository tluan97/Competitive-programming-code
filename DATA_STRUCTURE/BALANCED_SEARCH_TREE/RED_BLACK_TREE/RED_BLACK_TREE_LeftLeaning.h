
struct node *Nil, *Root;
struct node {
	int Key, Value;
	node *ll, *rr;
	bool Red;
	node (int AKey, int AValue, bool IsRed)
	{ Key=AKey; Value=AValue; Red=IsRed; ll=rr=Nil; }
	int get(int AKey) {
		if (Key==AKey || this==Nil) return Value;
		return (AKey<Key ? ll : rr)->get(AKey);
	}
	void flip_color()
	{ Red^=1; ll->Red^=1; rr->Red^=1; }
};

void init(){
	Root = Nil = new node(-1, -1, 0);
	Nil->ll = Nil->rr = Nil;
}
node* rotate_left(node* x) {
	node *y = x->rr;
	x->rr=y->ll; y->ll=x;
	y->Red=x->Red; x->Red=true;
	return y;
}
node* rotate_right(node* x) {
	node *y=x->ll;
	x->ll=y->rr; y->rr=x;
	y->Red=x->Red; x->Red=true;
	return y;
}
node* insert(node* x, int Key, int Value) {
	if (x==Nil)
		return new node(Key, Value, true);
	if (x->ll->Red && x->rr->Red)
		x->flip_color();
	if (Key==x->Key)
		x->Value = Value;
	else if (Key < x->Key)
		x->ll = insert(x->ll, Key, Value);
	else
		x->rr = insert(x->rr, Key, Value);
	if (x->rr->Red)
		x=rotate_left(x);
	if (x->ll->Red && x->ll->ll->Red)
		x=rotate_right(x);
	return x;
}
ostream& operator << (ostream& cout, node* x){
	if (x==Nil) return cout;
	return cout<<"("<<x->ll<<x->Key<<x->rr<<")";
}
