/*
	GAUSSIAN
	https://open.kattis.com/problems/equationsolver
	https://open.kattis.com/problems/equationsolverplus
	http://codeforces.com/gym/100211 - E
*/
#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-5;
const int oo = 1000111000;
const int maxn = 110;

//	Gauss-Jordan elimination.
//	Returns: number of solution (0, 1 or oo)
//	When the system has at least one solution, 
//		ans will contains one possible solution.
// 	Possible improvement when having precision errors:
//	- Divide i-th row by a(i, i)
//	- Choosing pivoting row with min absolute value 
//		(sometimes this is better that maximum, 
//		as implemented here)
int gauss(vector<vector<double> > a,vector<double> &ans){
	int n=a.size();
	int m=a[0].size()-1;
	vector<int> where(m,-1);
	for (int col=0,row=0;col<m && row<n;++col){
		int sel=row;
		for (int i=row;i<n;i++)
			if (abs(a[i][col])>abs(a[sel][col]))
				sel=i;
		if (abs(a[sel][col])<EPS)
			continue;
		for (int i=col;i<=m;i++)
			swap(a[sel][i],a[row][i]);
		where[col]=row;
		for (int i=0;i<n;i++)
		if (i!=row){
			double c=a[i][col]/a[row][col];
			for (int j=col;j<=m;j++)
				a[i][j]-=a[row][j]*c;
		}
		row++;
	}
	ans.assign(m,0);
	for (int i=0;i<m;i++)
	if (where[i]!=-1)
		ans[i]=a[where[i]][m]/a[where[i]][i];
	for (int i=0;i<n;i++){
		double sum=0;
		for (int j=0;j<m;j++)
			sum+=ans[j]*a[i][j];
		if (abs(sum-a[i][m])>EPS)
			return 0;
	}
	//	If we need any solution (in case oo solutions),
	//		we should be ok at this point.
    //	If need to solve partially
	//		(get which values are fixed/oo value):
//	for (int i=0;i<m;i++)
//	if (where[i]!=-1){
//		for (int j=0;j<n;j++)
//		if (j!=i && fabs(a[where[i]][j])>EPS){
//			where[i]=-1;
//			ans[i]=oo;
//			break;
//		}
//	} else ans[i]=oo;
	//	Then the variables which has where[i] == -1 --> oo values
	for (int i=0;i<m;i++)
	if (where[i]==-1)
		return oo;
	return 1;
}
//	Gaussian Binary
int gauss(vector<bitset<maxn> > a,bitset<maxn> &ans){
	int n=a.size();
	int m=a[0].size()-1;
	vector<int> where(m,-1);
	for (int col=0,row=0;col<m && row<n;++col){
		for (int i=row;i<n;i++)
		if (a[i][col]){
			swap(a[i],a[row]);
			break;
		}
		if (!a[row][col]) continue;
		where[col]=row;
		for (int i=0;i<n;i++)
		if (i!=row && a[i][col])
			a[i]^=a[row];
		row++;
	}
	//	The rest of implementation is the same as above
}

int n;
double u;
vector<vector<double> > a;
vector<double> b;
void solve_equationsolver(){
	while (cin>>n && n!=0){
		a.clear();
		a.resize(n,vector<double>(n+1,0.0));
		b.clear();
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>u;
				a[i][j]=u;
			}
		}
		for (int i=0;i<n;i++){
			cin>>u;
			a[i][n]=u;
		}
//		for (int i=0;i<a.size();i++){
//			for (int j=0;j<a[i].size();j++){
//				cout<<a[i][j]<<" ";
//			}	cout<<"\n";
//		}	cout<<"-----\n";
		int ans=gauss(a,b);
		if (ans==0) cout<<"inconsistent\n";
		else if (ans==oo) cout<<"multiple\n";
		else {
			for (int i=0;i<n;i++)
				cout<<b[i]<<" ";
			cout<<"\n";
		}
	}
}
void solve_equationsolverplus(){
	while (cin>>n && n!=0){
		a.clear();
		a.resize(n,vector<double>(n+1,0.0));
		b.clear();
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				cin>>u;
				a[i][j]=u;
			}
		}
		for (int i=0;i<n;i++){
			cin>>u;
			a[i][n]=u;
		}
//		for (int i=0;i<a.size();i++){
//			for (int j=0;j<a[i].size();j++){
//				cout<<a[i][j]<<" ";
//			}	cout<<"\n";
//		}	cout<<"-----\n";
		int ans=gauss(a,b);
		if (ans==0) cout<<"inconsistent\n";
		else {
			for (int i=0;i<n;i++)
			if (b[i]==oo) cout<<"? ";
			else cout<<b[i]<<" ";
			cout<<"\n";
		}
	}
}
int main(){
//	solve_equationsolver();
//	solve_equationsolverplus();
	return 0;
}
