#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
   int Value, Size;
   node *ll, *rr;
   node(int V, node* Nil){ Value=V; ll=rr=Nil; Size=1; }
   void update(){ Size=ll->Size+rr->Size+1; }
} *Nil, *Root;

node* first(node* a){ while (a->ll!=Nil) a=a->ll; return a; }
node* last(node* a){ while (a->rr!=Nil) a=a->rr; return a; }
node* link(node* L, node* X, node* R){ X->ll=L, X->rr=R, X->update(); return X; }
node* llzig(node* X, node* Y){ return link(Y->ll, Y, link(Y->rr, X, X->rr)); }
node* rrzig(node* X, node* Y){ return link(link(X->ll, X, Y->ll), Y, Y->rr); }

ostream& operator << (ostream& cout, node* a){
   if (a==Nil) return cout;
   return cout << "(" << a->ll << " " << a->Value << " " << a->rr << ")";
}

node* splay(node* X, int Index){
   node Header(0, Nil), *Left=&Header, *Right=&Header;
     while (X->ll->Size != Index){
      if (Index < X->ll->ll->Size)
         X=llzig(X, X->ll);
      else if (Index > X->ll->Size + 1 + X->rr->ll->Size) 
         X=rrzig(X, X->rr);
      if (X->ll->Size==Index) break;

      if (Index < X->ll->Size) { 
         node *Y=X->ll; X->ll=Nil, X->update();
         Right->ll=X, Right->update(); X=Y; Right=first(Right); 
      } else {
         Index -= X->ll->Size + 1;
         node *Y=X->rr; X->rr=Nil, X->update(); 
         Left->rr=X, Left->update(); X=Y; Left=last(Left);
      }
   }
   Left->rr=X->ll, Left->update();
   Right->ll=X->rr, Right->update();
   X->ll=Header.rr, X->rr=Header.ll, X->update();
   return X;
}

node* split(node* &X, int Index){
   if (X==Nil) return Nil;
   X=splay(X, Index);
   node* Y=X; X=Y->ll; Y->ll=Nil, Y->update();
   return Y;
}

node* join(node* X, node* Y){
   if (Y==Nil) return X;
   Y=splay(Y, 0);
   Y->ll=X, Y->update();
   return Y;
}

main(){
   Nil = new node(0, NULL); Nil->ll=Nil->rr=Nil; Nil->Size=0;
   Root=Nil;
   int x, y;

   while (cin >> x >> y){
      node* Foo = split(Root, x);
      Root=join(join(Root, new node(y, Nil)), Foo);
      cout << Root << endl;
   }
}