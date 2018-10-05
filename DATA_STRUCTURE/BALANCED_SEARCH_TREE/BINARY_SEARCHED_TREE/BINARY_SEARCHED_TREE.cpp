/*
	BINARY_SEARCHED_TREE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int oo = 1000111000;

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

void test_(){
	BST a;
	a.push(9, 0);
	a.push(4, 0);
	a.push(3, 0);
	a.push(5, 0);
	a.show(); // 3 4 5 9
}
int main(){
	test_();
	return 0;
}
