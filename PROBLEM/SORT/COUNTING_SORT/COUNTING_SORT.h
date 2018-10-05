
unordered_map<int,int> cs;
unordered_map<int,int>::iterator it;
void countingSort(vector<int> a){
	int n = a.size();
	for (int i=0;i<n;i++)
		cs[a[i]]++;
	for (it=cs.begin();it!=cs.end();it++){
		cout<<it->X<<" "<<it->Y<<"\n";
	}
}
