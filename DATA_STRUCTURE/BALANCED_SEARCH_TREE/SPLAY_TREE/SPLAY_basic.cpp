#include <stdio.h>
#include <stdlib.h>

struct node {
   node *ll, *rr, *pp;
   int size, value, max;
};

node *nil, *root;

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

void init(){
   nil = new node();
   nil->ll = nil->rr = nil->pp = nil;
   nil->size = nil->value = nil->max=0;
}

node* lljoin(node* a, node* b){ b->ll=a; a->pp=b; return b; }
node* rrjoin(node* a, node* b){ b->rr=a; a->pp=b; return b; }

void show(node* root){
   if (root==nil) return;
   printf("(");
   show(root->ll);
   printf(" %d ", root->value);
   show(root->rr);
   printf(")");
}

void show_max(node* root){
   if (root==nil) return;
   printf("(");
   show_max(root->ll);
   printf(" %d ", root->max);
   show_max(root->rr);
   printf(")");
}

void update_size(node* a){ 
   if (a==nil) return;
   a->size = a->ll->size + a->rr->size + 1; 
}

void update_data(node* a){ 
   if (a==nil) return;
   a->max = a->value;
   if (a->ll!=nil) maximize(a->max, a->ll->max);
   if (a->rr!=nil) maximize(a->max, a->rr->max);
}

node* create(int n){
   if (n==0) return nil;
   node* u = new node();
   lljoin(create((n-1)/2), u);
   rrjoin(create((n-1)-(n-1)/2), u);
   u->pp=nil;
   update_size(u);
   return u;
}

void zig(node* a){
   if (a==nil) return;
   node* b=a->pp;
   if (b==nil) return;
   node* c=b->pp;
   if (a==b->ll) { lljoin(a->rr, b); rrjoin(b, a); }
   else { rrjoin(a->ll, b); lljoin(b, a); }
   if (c==nil) { root=a; a->pp=nil; }
   else if (b==c->ll) lljoin(a, c); 
   else rrjoin(a, c);
   update_size(b); update_size(a);
   update_data(b); update_data(a);
}

node* splay(node* a){
   if (a==nil) return nil;
   while (a->pp!=nil){
      node* b = a->pp;
      node* c = b->pp;
      if (c!=nil){
         if (a==b->ll xor b==c->ll) zig(a);
         else zig(b);
      }
      zig(a);
   }
   return a;
}

node* at(int pos, node* a){   
   if (pos>=a->size) return nil;
   while (pos != a->ll->size){
      if (pos<a->ll->size) a=a->ll;
      else { pos-=a->ll->size+1; a=a->rr; }
   }
   splay(a);
   return a;
}

node* split(node* &a, int pos){
   if (pos>=a->size) return nil;
   node* b = at(pos, a);
   a = b->ll;
   a->pp = nil;
   b->ll = nil;
   update_size(b);
   update_data(b);
   return b;
}

node* at(int ll, int rr){  
   node* part3 = split(root, rr+1);
   node* part2 = split(root, ll);
   node* part1 = root;
   if (part1==nil) part1=part2;
   else part1 = rrjoin(part2, at(part1->size-1, part1));
   if (part3==nil) root=part1;
   else root = lljoin(part1, at(0, part3));
   update_size(part1); update_size(root);
   update_data(part1); update_data(root);
   return part2;
}

#define SetLength(a, n, t) a = (t*) calloc(n, sizeof (t))

int n, m;
int * a;

main(){
   int i, p, q, w;
   node* just;
   init();
   scanf("%d", &n);
   root=create(n);
   SetLength(a, n+1, int);

   scanf("%d", &m);
   for (i=1; i<=m; i++){
      scanf("%d%d%d", &p, &q, &w);
      a[p]+=w; a[q+1]-=w;
   }
   for (i=1; i<=n; i++) a[i]+=a[i-1];
   for (i=1; i<=n; i++) {
      (just=at(i-1,i-1))->value=a[i];
      update_data(just);
      update_data(root);
   }
   
   scanf("%d", &m);
   for (i=1; i<=m; i++){
      scanf("%d%d", &p, &q); p--, q--;
      printf("%d\n", at(p,q)->max);
   }
}
