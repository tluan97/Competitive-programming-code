/*
	PRIORITY_QUEUE
	tested
*/
#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq1;
priority_queue<int,vector<int>,greater<int> > pq2;

void priority_queue_(){
	pq1.push(1);
	pq1.top();
	pq1.pop();
	pq1.size();
	pq1.empty();
}
int main(){
	priority_queue_();
}
