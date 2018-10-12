
int arr[5];
string in;
void read_line(){
	memset(arr,0,sizeof(arr));
	int t,i=0;
	getline(cin, in);
	stringstream ss(in);
	while (ss>>t) arr[i++]=t;
}
