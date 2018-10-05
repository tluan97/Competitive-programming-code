/*
	MAXSUBSEQ
	Cho mang n phan tu.
	Tim doan con lien tiep co do dai 
		lon hon bang l va
		nho hon bang r sao cho
		co tong la lon nhat.
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn = 1000010;
const LL oooo = 1000111000111000111LL;

int n,l,r;
LL a[maxn];
LL t[maxn];
deque<int> dq;
LL ans;

//void gen(){
//	srand(time(NULL));
//	memset(a,0,sizeof(a));
//	memset(t,0,sizeof(t));
//	while (!dq.empty()) dq.pop_back();
//	n=rand()%1000000+1;
//	l=1;
//	r=n;
//	for (int i=1;i<=n;i++)
//	if (rand()%2==0)
//		a[i]=rand()%1000000000+1;
//	else a[i]=-1*rand()%1000000000+1;
//	
//}
//LL test(){
//	LL res=-oooo;
//	for (int i=1;i<=n;i++){
//		for (int j=i+l-1;j<=i+r-1 && j<=n;j++){
//			res=max(res,t[j]-t[i-1]);
//		}
//	}
//	return res;
//}
int main(){
//while (1){
//	gen();
	cin>>n>>l>>r;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++)
		t[i]=t[i-1]+a[i];
	ans=-oooo;
	for (int i=1;i<=n;i++){
		if (!dq.empty() && i-dq.front()>=l)
			ans=max(ans,t[i]-t[dq.front()]);
		while (i>r && !dq.empty() && i-dq.front()>=r)
			dq.pop_front();
		while (!dq.empty() && t[i]-t[dq.back()]<=0)
			dq.pop_back();
		dq.push_back(i);
	}
	cout<<ans<<"\n";
//	LL res=test();
//	cout<<"--\n";
//	if (res!=ans){
//		cout<<res<<" "<<ans<<"\n";
//		cout<<n<<" "<<l<<" "<<r<<"\n";
//		for (int i=1;i<=n;i++)
//			cout<<a[i]<<" ";
//		cout<<"\n";
//		return 0;
//	}
//}
	return 0;
}
