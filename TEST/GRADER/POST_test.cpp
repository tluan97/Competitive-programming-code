// POST_test
#include <bits/stdc++.h>
using namespace std;

const string NAME = "POST";
const int TEST = 1000;

int main(){
	srand(time(NULL));
	for (int zz=1;zz<=TEST;zz++){
		ofstream inp((NAME + ".INP").c_str());
		system((NAME + "_gen.exe").c_str());
		inp.close();
		
		system((NAME + "_solve.exe").c_str());
		
		clock_t start = clock();
		system((NAME + ".exe").c_str());
		clock_t finish = clock();
		double duration = (finish - start);
        
		if (system(("fc "+NAME+".OUT "+NAME+".ANS").c_str())!=0){
        	cout<<"TEST "<<zz<<": WRONG!\n";
        	system("PAUSE");
        	return 0;
		}
		if (duration>1000){
			cout<<"TEST "<<zz<<": TIME LIMIT!\n";
		} else {
			cout<<"TEST "<<zz<<": CORRECT!\n";
		}
	}
	system("PAUSE");
	return 0;
}
