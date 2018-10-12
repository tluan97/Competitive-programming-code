/*
	TOPOLOGICAL_SORT
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

int n;
vector<int> a[maxn];
bool vi[maxn];
vector<int> t;

void toposortDFS(int u){
	vi[u]=true;
	for (int i=0;i<a[u].size();i++)
	if (!vi[a[u][i]]){
		toposortDFS(a[u][i]);
	}
	t.push_back(u);
}
void toposortDEG(int u){
	int c[maxn]={};
	stack<int> st;
	while (st.size()) st.pop();
	for (int i=1;i<=n;i++)
	for (int j=0;j<a[i].size();j++){
		c[a[i][j]]++;
	}
	for (int i=1;i<=n;i++)
	if (c[i]==0){
		st.push(i);
	}
	while (st.size()){
		int u=st.top();
		st.pop();
		t.push_back(u);
		for (int i=0;i<a[u].size();i++){
			c[a[u][i]]--;
			if (c[a[u][i]]==0) st.push(a[u][i]);
		}
	}
	reverse(t.begin(),t.end());
}

void test_toposortDFS(){
	n=7;
	a[1].push_back(2);
	a[1].push_back(4);
	a[2].push_back(3);
	a[4].push_back(5);
	a[5].push_back(3);
	a[6].push_back(5);
	a[7].push_back(4);
	memset(vi,false,sizeof(vi));
	t.clear();
	for (int i=1;i<=n;i++)
	if (!vi[i]) toposortDFS(i);
	for (int i=n-1;i>=0;i--)
		cout<<t[i]<<" ";
	cout<<"\n";
}
void test_toposortDEG(){
	n=7;
	a[1].push_back(2);
	a[1].push_back(4);
	a[2].push_back(3);
	a[4].push_back(5);
	a[5].push_back(3);
	a[6].push_back(5);
	a[7].push_back(4);
	memset(vi,false,sizeof(vi));
	t.clear();
	for (int i=1;i<=n;i++)
	if (!vi[i]) toposortDEG(i);
	for (int i=n-1;i>=0;i--)
		cout<<t[i]<<" ";
	cout<<"\n";
}
int main(){
	test_toposortDFS();
	test_toposortDEG();
	return 0;
}
