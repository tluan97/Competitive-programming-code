
#define RED 1
#define BLACK 0
typedef bool colour;
struct node{
    node *parent,*left,*right;
    int key;
    colour color;
};
#define NIL &sentinel
/* all leafs are sentinels */
node sentinel = {0,NIL, NIL, 0, BLACK};

node *root;
void rotateLeft(node *x){
    if(x->right==NIL) return;
    node *y=x->right;
    x->right=y->left;
    if(y->left!=NIL) y->left->parent=x;
    y->parent = x->parent;
    if(x!=root){
        if(x==x->parent->left)
            x->parent->left=y;
        else x->parent->right=y;
    }
    else root=y;
    y->left=x;
    x->parent=y;
}
void rotateRight(node *x){
    if(x->left==NIL) return;
    node *y=x->left;
    x->left=y->right;
    if(y->right!=NIL) y->right->parent=x;
    y->parent = x->parent;
    if(x!=root){
        if(x==x->parent->left)
            x->parent->left=y;
        else x->parent->right=y;
    }
    else root=y;
    y->right=x;
    x->parent=y;
}
void fixinsert(node* x){
    while(x!=root&&x->parent->color==RED){
        if(x->parent==x->parent->parent->left){
            node *y=x->parent->parent->right;
            if(y->color==RED){
                x->parent->color=BLACK;
                y->color=BLACK;
                x->parent->parent->color=RED;
                x=x->parent->parent;
            }
            else{
                if(x==x->parent->right){
                    x=x->parent;
                    rotateLeft(x);
                }
                x->parent->color=BLACK;
                x->parent->parent->color=RED;
                rotateRight(x->parent->parent);
            }
        }
        else{
            node *y=x->parent->parent->left;
            if(y->color==RED){
                x->parent->color=BLACK;
                y->color=BLACK;
                x->parent->parent->color=RED;
                x=x->parent->parent;
            }
            else{
                if(x==x->parent->left){
                    x=x->parent;
                    rotateRight(x);
                }
                x->parent->color=BLACK;
                x->parent->parent->color=RED;
                rotateLeft(x->parent->parent);
            }
        }
    }
    root->color=BLACK;
}
void insert(int key){
    if(root==NIL){
        root=new node;
        root->left=NIL;
        root->right=NIL;
        root->parent=NULL;
        root->color=BLACK;
        root->key=key;
        return;
    }
    node *parent,*current,*x;
    parent=NULL;
    current=root;
    while(current!=NIL){
        if(key==current->key) return;
        parent=current;
        if(key>current->key) current=current->right;
        else current=current->left;
    }
    x=new node;
    x->parent=parent;
    x->left=NIL;
    x->right=NIL;
    x->color=RED;
    x->key=key;
    if(key>parent->key) parent->right=x;
    else parent->left=x;
    fixinsert(x);
    return;
}
void fixerase(node *x){
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            node *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateLeft (x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rotateRight (w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                rotateLeft (x->parent);
                x = root;
            }
        } else {
            node *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rotateRight (x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    rotateLeft (w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rotateRight (x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}
void erase(int key){
    node *x,*y,*current;
    current=root;
    while(current!=NIL){
        if(current->key==key) break;
         if(key>current->key) current=current->right;
        else current=current->left;
    }
    if(current==NIL) return;
    if(current->left==NIL||current->right==NIL){
        y=current;
    }
    else{
        y=current->right;
        while(y->left!=NIL) y=y->left;
    }
    if(y->left!=NIL) x=y->left;
    else x=y->right;
    x->parent=y->parent;
    if(y->parent!=NULL){
        if(y==y->parent->left)
            y->parent->left=x;
        else y->parent->right=x;
    }
    else root=x;
    current->key=y->key;
    if(y->color==BLACK)
        fixerase(x);
    free(y);
    return;
}
int Min(){
    node *current=root;
    while(current->left!=NIL) current=current->left;
    return current->key;
}
int Max(){
    node *current=root;
    while(current->right!=NIL) current=current->right;
    return current->key;
}
node *succ(int key,bool ch){
    node *current=root;
    node *ans=NULL;
    while(current!=NIL){
        if(current->key==key){
            if(ch){
                ans=current;
                return ans;
            }
        }
        else{
            if(current->key>key) ans=current;
        }
        if(current->key>key) current=current->left;
        else current=current->right;
    }
    return ans;
}
node *pred(int key,bool ch){
    node *current=root;
    node *ans=NULL;
    while(current!=NIL){
        if(current->key==key){
            if(ch){
                ans=current;
                return ans;
            }
        }
        else{
            if(current->key<key) ans=current;
        }
        if(current->key>=key) current=current->left;
        else current=current->right;
    }
    return ans;
}
void cppset(){
	root=NIL;
    int x,y;
    while(cin>>x&&x){
        if(x==1){
            cin>>y;
            insert(y);
        }
        else if(x==2){
            cin>>y;
            erase(y);
        }
        else if(x==3){
            if(root==NIL) printf("empty\n");
            else printf("%d\n",Min());
        }
        else if(x==4){
            if(root==NIL) printf("empty\n");
            else printf("%d\n",Max());
        }
        else if(x==5||x==6){
            cin>>y;
            if(root==NIL) printf("empty\n");
            else{
                node *r=succ(y,x-5);
                if(r==NULL) printf("no\n");
                else printf("%d\n",r->key);
            }
        }
        else{
            cin>>y;
            if(root==NIL) printf("empty\n");
            else{
                node *r=pred(y,x-7);
                if(r==NULL) printf("no\n");
                else printf("%d\n",r->key);
            }
        }
    }
}
