/*
	READ_LINE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

int arr[5];
string in;
void read_line(){
	memset(arr,0,sizeof(arr));
	int t,i=0;
	getline(cin, in);
	stringstream ss(in);
	while (ss>>t) arr[i++]=t;
}

int main(){
	read_line();
	for (int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}
