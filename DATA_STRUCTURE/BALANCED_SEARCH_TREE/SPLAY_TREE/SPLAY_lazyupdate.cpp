#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
   node *ll, *rr, *pp;
   int size, id;
   int value, max_value, lazy_add;
   node(int _id, int x, node* nil){
      ll=rr=pp=nil;
      id=_id; size=1;
      value=x; max_value=x; lazy_add=0;
   }
};

bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

node *nil, *root;

int llindex(node* a){
   if (a==nil) return 0;
   else return a->id-a->ll->size;
}

int rrindex(node* a){
   if (a==nil) return 0;
   else return a->id+a->rr->size;
}


// Assertion

int a[12309];

node* left_most(node* a){
   if (a->ll==nil) return a;
   else return left_most(a->ll);
}

node* right_most(node* a){
   if (a->rr==nil) return a;
   else return right_most(a->rr);
}

void hard_add(int ll, int rr, int value){
   return ;
   for (int i=ll; i<=rr; i++) a[i]+=value;
}

ostream& operator << (ostream& cout, node* x){
   if (x==nil) return cout;
   return cout << "(" << x->ll << " " << x->value << " " << x->rr << ")";
}

void ensure(node* x){
   return ;
   if (x==nil) return;
// cout << x << endl;
   assert(x->value==a[x->id]);
   assert(x->pp==nil || x==x->pp->ll || x==x->pp->rr);
   assert(x->max_value == *max_element(a+llindex(x), a+rrindex(x)+1));
   assert(x->size == right_most(x)->id - left_most(x)->id + 1);
   if (x->ll->lazy_add==0) ensure(x->ll);
   if (x->rr->lazy_add==0) ensure(x->rr);
}

// 

node* update_lazy(node* a){
   if (a==nil) return nil;
   if (a->lazy_add != 0){
      a->value += a->lazy_add;
      a->max_value += a->lazy_add;
      if (a->ll!=nil) a->ll->lazy_add += a->lazy_add;
      if (a->rr!=nil) a->rr->lazy_add += a->lazy_add;
      a->lazy_add=0;
   }
   return a;
}

node* update_size(node* a){
   if (a==nil) return nil;
   a->size = 1 + a->ll->size + a->rr->size;
}

node* update_data(node* a){
   if (a==nil) return nil;
   a->max_value = a->value;
   if (a->ll!=nil) { update_lazy(a->ll); maximize(a->max_value, a->ll->max_value); }
   if (a->rr!=nil) { update_lazy(a->rr); maximize(a->max_value, a->rr->max_value); }
// cout << a << endl;
// assert(a->max_value == *max_element(::a+llindex(a), ::a+rrindex(a)+1));
}

node* lljoin(node* a, node* b){ 
   if (b==nil) { a->pp=nil; root=a; return root; }
   else { a->pp=b; b->ll=a; return b; }
}
node* rrjoin(node* a, node* b){ 
   if (b==nil) { a->pp=nil; root=a; return root; }
   else { a->pp=b; b->rr=a; return b; }
}

node* create(int ll, int rr){
   if (ll>rr) return nil;
   int mm=(ll+rr)/2;
   node* u=new node(mm, 0, nil);
   lljoin(create(ll, mm-1), u);
   rrjoin(create(mm+1, rr), u);
   update_size(u); update_data(u);
   return u;
}


node* zig(node* a){
   if (a==nil || a==root) return a;
// cout << "zig " << a << endl;
   update_lazy(a);
   node* b=a->pp;
   node* c=b->pp;
   if (a==b->ll) { lljoin(a->rr, b); rrjoin(b, a); }
   else { rrjoin(a->ll, b); lljoin(b, a); }
   if (b==c->ll) lljoin(a, c); else rrjoin(a, c);
   update_size(b); update_data(b);
   update_size(a); update_data(a);
// cout << "zig last " << a << endl;
   ensure(a);
   return a;
}

node* splay(node* a){
   if (a==nil) return nil;
   while (a->pp!=nil){
      node* b=a->pp;
      node* c=b->pp;
      if (c!=nil){
         if (a==b->ll xor b==c->ll) zig(a);
         else zig(b);
      }
      zig(a);
   }
   update_lazy(a);
   ensure(a);
   return a;
}

node* at(int pos, node* root){
   node* a=root;
   while (a->id!=pos){
      if (a==nil) return nil;
      update_lazy(a);
      if (pos<a->id) a=a->ll; 
      else a=a->rr;
   }
   update_lazy(a);
   ensure(a);
   return splay(a);
}

node *part1, *part2, *part3;

node* split(node* &a, int pos){
   node* b=at(pos, a);
   if (b==nil) return nil;
   a=b->ll;
   update_lazy(b); update_lazy(a);
   b->ll=nil;
   a->pp=nil;
   update_size(b); update_data(b);
   ensure(b);
   return b;
}

node* at(int ll, int rr){
   part3 = split(root, rr+1);
   part2 = split(root, ll);
   part1 = root;
   update_lazy(part2);
// cout << part1 << " | " << part2 << " | " << part3 << endl;
   ensure(part2);
   return part2;
}

node* reconnect(){
   update_lazy(part2);
// cout << part1 << " | " << part2 << " | " << part3 << endl;
   part1 = rrjoin(part2, at(rrindex(part1), part1));
   part3 = lljoin(part1, at(llindex(part3), part3));
   update_size(part1); update_data(part1);
   update_size(part3); update_data(part3);
   root=part3;
   ensure(root);
   return root;
}


int n, m;

main(){
   int i, p, q, w, option;
   nil=new node(0, 0, nil); nil->size=0;
   scanf("%d%d", &n, &m);
   srand(n+1000+m);
   root=create(1, n);
// cout << root << endl;
   ensure(root);

   for (i=1; i<=m; i++){
      //option = rand() % 2;
      //p=rand()%n+1; q=rand()%n+1; w = rand()%100;
      //if (p>q) swap(p,q);
      //printf(" %d %d %d %d\n", option, p, q, w);

      scanf("%d", &option);
      if (option==0) scanf("%d%d%d", &p, &q, &w);
      else scanf("%d%d", &p, &q);

      if (option==0) { at(p,q)->lazy_add+=w; hard_add(p,q,w); }
      else printf("%d\n", at(p,q)->max_value);
      reconnect();
//    cout << root << endl;
   }
}