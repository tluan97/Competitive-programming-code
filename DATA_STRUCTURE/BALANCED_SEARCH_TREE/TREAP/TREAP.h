
#define NIL &leaf
struct node {
	node *p, *l,*r;
	int key,pr;
};
node *root,leaf;
node* newnode(node* parent,int key) {
	node *x=new node;
	x->p=parent;
	x->l=x->r=NIL;
	x->pr=rand();
	x->key=key;
	if(parent!=NIL) {
		if(parent->key>key)
			parent->l=x;
		else parent->r=x;
	}
	else root=x;
	return x;
}
void init() {
	leaf.l=leaf.r=leaf.p=NIL;
	leaf.key=-oo;
	leaf.pr=-1;
	root=NIL;
}
void link(node* x,node* y) {
	if(y==root) root=x;
	else if(y==y->p->l) y->p->l=x;
	else y->p->r=x;
	x->p=y->p;
	y->p=x;
}
void uptree(node* x) {
	node *parent=x->p;
	link(x,parent);
	if(x==parent->l) {
		parent->l=x->r;
		if(parent->l!=NIL)
			parent->l->p=parent;
		x->r=parent;
	}
	else {
		parent->r=x->l;
		if(parent->r!=NIL)
			parent->r->p=parent;
		x->l=parent;
	}
}
void insert(int key) {
	node* x=root,*parent=NIL;
	while(x!=NIL) {
		parent=x;
		if(key==x->key) return;
		if(key<x->key) x=x->l;
		else x=x->r;
	}
	x=newnode(parent,key);
	while(x!=root&&x->pr>x->p->pr)
		uptree(x);
}
node* find(int key) {
	node* x=root;
	while(x!=NIL) {
		if(key==x->key) return x;
		if(key<x->key) x=x->l;
		else x=x->r;
	}
	return NIL;
}
void delall(node* x) {
	if(x==root) root=NIL;
	else if(x==x->p->l) x->p->l=NIL;
	else x->p->r=NIL;
}
bool del(int key) {
	node* x=find(key);
	if(x==NIL) return false;
	while(x->l!=NIL&&x->r!=NIL) {
		if(x->l->pr>x->r->pr)
			uptree(x->l);
		else uptree(x->r);
	}
	if(x->l!=NIL) link(x->l,x);
	else if(x->r!=NIL) link(x->r,x);
	else delall(x);
	free(x);
	return true;
}
node* Min() {
	node* x=root;
	while(x->l!=NIL) {
		x=x->l;
	}
	return x;
}
node* Max() {
	node* x=root;
	while(x->r!=NIL) {
		x=x->r;
	}
	return x;
}
node* succ(int key) {
	node* ans=NIL;
	node* x=root;
	while(x!=NIL) {
		if(key<x->key) {
			ans=x;
			x=x->l;
		}
		else x=x->r;
	}
	return ans;
}
node* pred(int key) {
	node* ans=NIL;
	node* x=root;
	while(x!=NIL) {
		if(key>x->key) {
			ans=x;
			x=x->r;
		}
		else x=x->l;
	}
	return ans;
}
void CPPSET(){
	init();
	int n, x;
	while(cin>>n&&n) {
		if(n==1) {
			cin>>x;
			insert(x);
		}
		else if(n==2) {
			cin>>x;
			del(x);
		}
		else if(n==3) {
			if(root==NIL) {
				puts("empty");
				continue;
			}
			printf("%d\n",Min()->key);
		}
		else if(n==4) {
			if(root==NIL) {
				puts("empty");
				continue;
			}
			printf("%d\n",Max()->key);
		}
		else if(n==5) {
			cin>>x;
			if(root==NIL) {
				puts("empty");
				continue;
			}
			node* f=succ(x);
			if(f!=NIL) 
				printf("%d\n",f->key);
			else puts("no");
		}
		else if(n==6) {
			cin>>x;
			if(root==NIL) {
				puts("empty");
				continue;
			}
			node* f=find(x);
			if(f==NIL) f=succ(x);
			if(f!=NIL) 
				printf("%d\n",f->key);
			else puts("no");
		}
		else if(n==7) {
			cin>>x;
			if(root==NIL) {
				puts("empty");
				continue;
			}
			node* f=pred(x);
			if(f!=NIL)
				printf("%d\n",f->key);
			else puts("no");
		}
		else if(n==8) {
			cin>>x;
			if(root==NIL) {
				puts("empty");
				continue;
			}
			node* f=find(x);
			if(f==NIL) f=pred(x);
			if(f!=NIL)
				printf("%d\n",f->key);
			else puts("no");
		}
	}
}
