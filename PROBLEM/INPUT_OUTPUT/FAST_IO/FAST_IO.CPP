/*
	FAST_IO
	tested
*/
#include <bits/stdc++.h>
using namespace std;

int arr[5];
char buff[20];
void fast_io(){
	gets(buff);
	int len=strlen(buff),i=0,m=0;
	while (i<len){
		if (buff[i]!=' '){
			arr[m]=0;
			while (i<len && buff[i]!=' ')
				arr[m]=arr[m]*10+buff[i++]-48;
			m++;
		}
		else i++;
	}
}

int main(){
	fast_io();
	for (int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}
