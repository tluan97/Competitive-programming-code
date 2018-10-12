
int n,m;
vector<III> e;
int kruskal(){
	int res=0;
	initDSU();
	sort(e.begin(),e.end());
	for (int i=0;i<e.size();i++){
		if (anc(e[i].Y.X)!=anc(e[i].Y.Y)){
			join(e[i].Y.X,e[i].Y.Y);
			res+=e[i].X;
		}
	}
	return res;
}
