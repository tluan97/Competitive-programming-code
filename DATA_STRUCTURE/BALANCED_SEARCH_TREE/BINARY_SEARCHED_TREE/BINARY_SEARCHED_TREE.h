
class BST {
public:
	struct node {
		int left, right, value;
		node(int p) { left=right=0; value=p; }
	};
	vector <node*> a;
	
	BST() { a.push_back(new node(-oo)); }   
	int makenew(int p){
		a.push_back(new node(p));
		return a.size()-1;
	}
	void push(int p, int u){
		if (p>a[u]->value){
			if (a[u]->right==0)
				a[u]->right = makenew(p);
			else push(p, a[u]->right);
		} else {
			if (a[u]->left==0)
				a[u]->left = makenew(p);
			else push(p, a[u]->left);
		}
	}
	void clear(){
		for (int i=0; i<a.size(); i++)
			delete a[i];
		a.clear();
	}
	void show(int u){
		if (u==0) return ;
		show(a[u]->left);
		printf("%d,", a[u]->value);
		show(a[u]->right);       
	}
	void show(){
		show(a[0]->left);
		show(a[0]->right);
	} 
};
