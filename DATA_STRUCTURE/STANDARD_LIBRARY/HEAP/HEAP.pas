        Const fi='wst.inp';
                fo='wst.out';
        Type Canh = Record
                x,y,z:longint
                End;
        Type Mang = Array [1..200000] Of Canh;
        Var F:text;
                n,m,c,nheap:longint;
                A,HeadC:Mang;
                Head,Link,D,Pos,Heap:Array [1..200000] Of Longint;
                Q:Array [1..1000000] Of Longint;
                KT:Array [1..100000] Of Boolean;
Procedure Nhap;
        Var i,u,v,j:longint;
        Begin
                Assign(f,fi);
                Reset(f);
                Read(f,n,m);
                For i:=1 to m do
                        Begin
                                Read(f,A[i].x,A[i].y,A[i].z);
                                A[i+m].x:=A[i].y;
                                A[i+m].y:=A[i].x;
                                A[i+m].z:=A[i].z;
                        End;
                For i:=m*2 downto 1 do
                        Begin
                                Link[i]:=Head[A[i].x];
                                Head[A[i].x]:=i;
                        End;
                c:=0;
                For i:=1 to n do
                        Begin
                                Read(f,v);
                                if v<>0 then
                                        Begin
                                                c:=c+v;
                                                HeadC[i].x:=c;
                                                HeadC[i].y:=c+v;
                                                For j:=c to c+v do
                                                        Read(f,Q[j]);
                                        End;
                        End;
                Close(f);
        End;
Procedure swap(i,j:longint);
        Var t:longint;
        Begin
                Pos[Heap[j]]:=i; Pos[Heap[i]]:=j;
                t:=Heap[i]; Heap[i]:=Heap[j]; Heap[j]:=t;
        End;
Procedure upheap(i:longint);
        Var j:longint;
        Begin
                j:=i div 2;
                If (i=1) or (D[Heap[j]]<D[Heap[i]]) then exit;
                swap(i,j);
                upheap(j);
        End;
Procedure Push(k:longint);
        Begin
                inc(nheap);
                Heap[nheap]:=k;
                Pos[k]:=nheap;
                upheap(nheap);
        End;
Procedure downheap(i:longint);
        Var j:longint;
        Begin
                j:=i*2;
                if (j>nheap) then exit;
                if (j<nheap) and (D[Heap[j]]>D[Heap[j+1]]) then inc(j);
                if (D[Heap[i]]>D[Heap[j]]) then
                        Begin
                                Swap(i,j);
                                downheap(j);
                        End;
        End;
Function pop:longint;
        Begin
                pop:=Heap[1];
                Heap[1]:=Heap[nHeap];
                pos[heap[nheap]]:=1;
                dec(nheap);
                downheap(1);
        End;
Function tknp(l,r,k:longint):longint;
        Var mid:longint;
        Begin
                While (l<=r) do
                Begin
                        mid:=(l+r) div 2;
                        if k<=Q[mid] then
                                Begin
                                        tknp:=mid;
                                        r:=mid-1;
                                End
                        Else l:=mid+1;
                End;
        End;
Procedure Dijkstra(u:longint);
        Var v,i:longint;
        Begin
                While (nheap<>0) do
                Begin
                        u:=pop;
                        KT[u]:=true;
                        if u=n then exit;
                        v:=Head[u];
                        if HeadC[u].x<>0 then
                                Begin
                                        i:=tknp(HeadC[u].x,HeadC[u].y,D[u]);
                                        While (1<>0) do
                                                Begin
                                                        if Q[i]=D[u] then
                                                                inc(D[u])
                                                        else break;
                                                        inc(i);
                                                End;
                                End;
                        While (v<>0) do
                                Begin
                                        If (A[v].z+D[u]<D[A[v].y])
                                        and (KT[A[v].y]=false) then
                                                Begin
                                                        D[A[v].y]:=A[v].z+D[u];
                                                        if pos[A[v].y]=0 then
                                                                Push(A[v].y)
                                                        Else Upheap(pos[A[v].y]);
                                                End;
                                        v:=link[v];
                                End;
                End;
        End;
Procedure Xuli;
        Var i:longint;
        Begin
                Assign(f,fo);
                Rewrite(f);
                For i:=2 to n do
                        D[i]:=maxlongint;
                D[1]:=0;
                Push(1);
                Dijkstra(1);
                if KT[n]=true then
                Write(f,D[n])
                else Write(f,-1);
                Close(f);
        End;
Begin
        Nhap;
        Xuli;
End.