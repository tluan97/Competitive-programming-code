/*
	DIE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

const int rotations[6][4] = {
	{1, 4, 0, 5}, // left
	{1, 5, 0, 4}, // right
	{4, 3, 5, 2}, // up
	{4, 2, 5, 3}, // down
};
struct Die;
map<int, Die> dieMap;
struct Die {
	int arr[6];
	/* 
		0 right, 1 left, 2 forward, 
		3 backward, 4 top, 5 bottom 
	*/
	Die() { for (int i=0;i<6;i++) arr[i]=i; }
	Die(int cipher) { // 0 -> 23
		if (dieMap.empty())
			puts("Call openDie(die());");
		else (*this) = dieMap[cipher];
	}
	Die move(int dir) {
		Die res = (*this);
		int t = res.arr[rotations[dir][0]];
		for (int i=0;i<3;i++)
			res.arr[rotations[dir][i]] = 
			res.arr[rotations[dir][i+1]];
		res.arr[rotations[dir][3]] = t;
		return res;
	}
	int encrypt() { // 0 -> 23
		int res = arr[0] * 4;
		for (int i=3;i<=5;i++)
			if (arr[i] < arr[2]) 
				res++;
		return res;
	}
	void print(){
		for (int i=0;i<6;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}
};
void openDie(Die t) {
	dieMap[t.encrypt()] = t;
	for (int dir=0;dir<4;dir++)
		if (!dieMap.count(t.move(dir).encrypt()))
			openDie(t.move(dir));
}

void test_die(){
	Die d; d.print();
	openDie(d);
	int n;
	while (cin>>n && 0<=n && n<=3){
		d=d.move(n);
		d.print();
	}
	for (int i=0;i<24;i++){
		Die dd(i);
		cout<<dd.encrypt()<<" : ";
		dd.print();
	}
}
int main(){
	test_die();
	return 0;
}
